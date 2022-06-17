/*
 * Clone - Example
 * CLONE_NEWPID – new namespace of process IDs.
 * SIGCHLD – send a signal to parent when child is done.
 * Return values check omitted due to space constraints
 */

#include<stdio.h>
#include<sched.h>

#define STACK 8192

int child(void* msg) {
  printf("%s\n", (char*)msg);
  return 0;
}

int main(int argc, char* argv[]) {
  void* stack = malloc(STACK);
  char[] msg = "Hello from parent";
  int child_pid = clone(child, stack+STACK, CLONE_NEWPID | SIGCHLD, msg);
  wait(NULL);
}

/*
 * Execvp - Example
 * Running "echo" through the bash shell.
 */
#include<unistd.h>

int main(int argc, char* argv[]) {
  char* _args[] ={"/bin/echo", argv + 1, (char *)0}
  int ret = execvp("/bin/echo", _args);
}


/*
 * Sethostnae - Example
 * Return values check omitted due to space constraints
 */
#include<stdio.h>
#include<sched.h>

#define STACK 8192

int child(void* arg) {
  char* name = (char *)arg;
  sethostname(name, strlen(name));
  return 0;
}

int main(int argc, char* argv[]) {
  void* stack = malloc(STACK);
  char[] name = "container";
  int child_pid = clone(child, stack+STACK, CLONE_NEWUTS | SIGCHLD, name);
  wait(NULL);
}
