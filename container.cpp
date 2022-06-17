#include <sched.h>
#include <iostream>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/mount.h>
#include <cstring>
#include <sys/stat.h>
#include <iostream>
#include <fstream>

#define ERROR_MESSAGE "system error: "
#define INVALID_ARGC "argument count isn't valid"

#define HOSTNAME_INDEX 1
#define FILESYSTEM_INDEX 2
#define NUM_PROCESSES_INDEX 3
#define PATH_INDEX 4
#define ARGS_TO_PROGRAM_INDEXS 5

#define STACK_SIZE 8192
#define CGROUP_PID_PATH std::string("./sys/fs/cgroup/pids")
#define FS_PATH std::string("./sys/fs")
#define CGROUP_PATH std::string("./sys/fs/cgroup")

#define CGROUP_PROCS_PATH std::string("/cgroup.procs")
#define PID_MAX_PATH std::string("/pids.max")
#define NOTIFY_PATH std::string("/notify_on_release")

#define PERMISSION (mode_t) 0755


typedef struct container_arguments {
    int argc;
    char *hostname;
    char *filesystem_dir;
    char *num_processes;
    char *path_to_program;
    char **args_to_program;
} container_arguments;


int run_command(char* path_to_program, char** args_to_program, int argc){
  char *argv[argc + 1];
  for (int i = 0; i < argc; ++i) {
    argv[i] = args_to_program[i];
  }
  argv[argc] = nullptr;
  int ret = execvp(path_to_program, argv);
  return ret;
}

void write_file(const std::string& filename,const std::string& content){
  std::ofstream output ( filename);
  output << content;
  output.close();
  if (errno != 0) {
      std::cout << ERROR_MESSAGE << strerror(errno) << filename << std::endl;
    }
  chmod(filename.c_str(), PERMISSION);
}


int create_container (void* args){
  container_arguments arguments = *(container_arguments *)args;
  // create a new process
  //  1. Change the hostname and root directory

  sethostname (arguments.hostname, strlen(arguments.hostname));

  //  3. Change the working directory into the new root directory
  chroot(arguments.filesystem_dir);
  chdir("/");
  // print the hostname:
  //  4. Mount the new procfs
  // TODO: should we mount before or after the mkdir commands?
  mount("proc", "/proc", "proc", 0, nullptr);

  mkdir(FS_PATH.c_str(), PERMISSION);
  mkdir(CGROUP_PATH.c_str(), PERMISSION);
  mkdir(CGROUP_PID_PATH.c_str(), PERMISSION);

  write_file( CGROUP_PID_PATH + NOTIFY_PATH, std::to_string (1));
  write_file(CGROUP_PID_PATH + PID_MAX_PATH, std::string (arguments.num_processes));
  write_file (CGROUP_PID_PATH + CGROUP_PROCS_PATH, std::to_string (getpid()));

  //  5. Run the terminal/new program
  run_command (arguments.path_to_program, arguments.args_to_program,
               arguments.argc - ARGS_TO_PROGRAM_INDEXS);

  //  3. When shutting down the container make sure to unmount the container’s filesystem from the host.

  remove ((CGROUP_PID_PATH + PID_MAX_PATH).c_str());
  remove ((CGROUP_PID_PATH + NOTIFY_PATH).c_str());
  remove ((CGROUP_PID_PATH + CGROUP_PROCS_PATH).c_str());

  system((std::string("rm ") + CGROUP_PID_PATH + std::string("/*")).c_str());
//  std::cout << "hey - " << (std::string("rm ") + CGROUP_PID_PATH + std::string("/*"))
//  .c_str() << std::endl;

  if (errno != 0) {
      std::cout << ERROR_MESSAGE << strerror(errno) << std::endl;
      return -1;
    }

  rmdir(CGROUP_PID_PATH.c_str());
  rmdir(CGROUP_PATH.c_str());
  rmdir(FS_PATH.c_str());

  umount("/proc"); // TODO: where do this line really belong? father or child?

  if (errno != 0) {
      std::cout << ERROR_MESSAGE << strerror(errno) << std::endl;
      return -1;
    }

  return EXIT_SUCCESS;
}


// ./container <new_hostname> <new_filesystem_directory> <num_processes>
// <path_to_program_to_run_within_container> <args_for_program>

int main (int argc, char *argv[]) {
    if (argc < ARGS_TO_PROGRAM_INDEXS){
      std::cerr << ERROR_MESSAGE << INVALID_ARGC << std::endl;
      exit (EXIT_FAILURE);
    }
  container_arguments args = {argc, argv[HOSTNAME_INDEX],
          argv[FILESYSTEM_INDEX], argv[NUM_PROCESSES_INDEX],
          argv[PATH_INDEX],(char **)argv + ARGS_TO_PROGRAM_INDEXS};

  char *stack = new char[STACK_SIZE];
  char *end_of_stack = stack + STACK_SIZE;

  int container_flags = CLONE_NEWPID | CLONE_NEWUTS | CLONE_NEWNS | SIGCHLD;

  int child_pid = clone(create_container, end_of_stack, container_flags, &args);
  
  wait(nullptr);
  delete [] stack;
  return EXIT_SUCCESS;
}