
#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <unistd.h>


#define TRUE 1
#define FALSE 0
#define GENERIC_ERROR_SIGNAL -1

#define MAX_CLIENTS 5
#define BUFFER_SIZE 256
#define BASE 10

#define CLIENT_ARG "client"
#define SERVER_ARG "server"

// ERRORS: //
#define ERROR_MASSAGE "system error: "
#define INVALID_ARGC "argument count isn't valid"
#define INVALID_FIRST_ARG "First argument is not valid"
#define INVALID_PORT_ARG "Given port is not valid"
#define SOCKET_ERROR "socket failed to start"
#define BIND_ERROR "bind failed"
#define LISTEN_ERROR "listen failed"
#define ACCEPT_ERROR "accept failed"
#define READ_ERROR "read failed"
#define WRITE_ERROR "write failed"
#define CONNECT_ERROR "connecting to the server failed"
#define EXECUTION_FAIL "Failed execution the command from client"


void handle_error(int signal, const std::string& error_message){
  if (signal == GENERIC_ERROR_SIGNAL){
      std::cerr << ERROR_MASSAGE << error_message << std::endl;
      exit(EXIT_FAILURE);
    }
}

void execute_command(char* command){
  // TODO: handle execution failure, can we abort?
  int result = system(command);
  if (result != FALSE) handle_error (GENERIC_ERROR_SIGNAL, EXECUTION_FAIL);
}


int read_data(int socket_server, char *buffer, int buffer_size) {
  int bcount =0, br = 0; // counts bytes read,  bytes read this pass

  while (bcount <= buffer_size) {
      br = read(socket_server, buffer, buffer_size - bcount);
      if (br > 0)  {
          bcount += br;
          buffer += br;
      }
      else return EXIT_FAILURE;
    }
  return bcount;
}

void reset_buffer(char *buffer, int buffer_size) {
  memset(buffer, 0, buffer_size);
}


void initiateServer (int port)
{
  int server_fd;
  // Creating socket file descriptor
  server_fd = socket (AF_INET, SOCK_STREAM, 0);
  handle_error (server_fd, SOCKET_ERROR);

  int opt = TRUE;
  handle_error (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, (char *)&opt,
                           sizeof(opt)), SOCKET_ERROR);

  // bind the socket server to the port:
  struct sockaddr_in address;
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons (port);

  handle_error (bind (server_fd, (struct sockaddr *) &address, sizeof (address)),BIND_ERROR);

  // make the socket listen to maximum 5 clients:
  handle_error (listen (server_fd, MAX_CLIENTS), LISTEN_ERROR);

  // call for function if the client is connected:
  int new_socket;
  struct sockaddr_in client_address;
  int address_length = sizeof (client_address);

  // call for function if the client is connected:
  char buffer[BUFFER_SIZE] = { 0 };

  fd_set clientsfds;
  fd_set readfds;

  FD_ZERO(&clientsfds);
  FD_SET(server_fd, &clientsfds);
  // TODO: check about the fileno flag
  FD_SET(STDIN_FILENO, &clientsfds);

  // TODO: when do we end? never? or for some command?
  while (true) {
    readfds = clientsfds;

    if (select(MAX_CLIENTS + 1, &readfds, nullptr, nullptr, nullptr) < 0) {
        break;
    }
    if (FD_ISSET(server_fd, &readfds)) {
        //will also add the client to the clientsfds
        handle_error (new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)
            &address_length), ACCEPT_ERROR);

        FD_SET(new_socket, &readfds);
        FD_CLR(STDIN_FILENO, &readfds);
      }

    if (!FD_ISSET(STDIN_FILENO, &readfds)){
        //will check each client if it’s in readfds
        //and then receive a message from him
        for (int fd = 0; fd < MAX_CLIENTS; ++fd) {
            reset_buffer (buffer, BUFFER_SIZE);
            if (FD_ISSET(fd, &readfds) && fd != server_fd) {
                handle_error (read_data (fd, buffer, BUFFER_SIZE), READ_ERROR);
                execute_command (buffer);
                close (fd);
                FD_CLR(fd, &clientsfds);
              }
          }
      }
  }

  shutdown(server_fd, SHUT_RDWR);
  }

void initiateClient (int port, char *terminalCommand)
{
  // open a new socket for the client:
    int client_fd;
    client_fd = socket (AF_INET, SOCK_STREAM, 0);
    handle_error (client_fd, SOCKET_ERROR);
  // connect the socket to the server:
    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons (port);

    handle_error (connect(client_fd, (struct sockaddr *) &address, sizeof(address)),
                  CONNECT_ERROR);

    // write the terminal command to the server:
    handle_error (write (client_fd, terminalCommand, strlen (terminalCommand)), WRITE_ERROR);

    // close the socket:
    close(client_fd);
}

int main (int argc, char *argv[])
{
  if (argc < 3)
    {
      std::cerr << ERROR_MASSAGE << INVALID_ARGC << std::endl;
      exit (EXIT_FAILURE);
    }

  int port = (int) strtol (argv[2], nullptr, BASE);
  if (port == FALSE)
    {
      std::cerr << ERROR_MASSAGE << INVALID_PORT_ARG << std::endl;
      exit (EXIT_FAILURE);
    }

  if (strcmp (argv[1], CLIENT_ARG) == 0) initiateClient (port, argv[3]);
  else if (strcmp (argv[1], SERVER_ARG) == 0) initiateServer (port);
  else
    {
      std::cerr << ERROR_MASSAGE << INVALID_FIRST_ARG << std::endl;
      exit (EXIT_FAILURE);
    }
  return 0;
}