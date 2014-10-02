#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <unistd.h>


main () {
  // NOTE use "strace -f" to trace forked processes
  if (fork() == 0) {
    struct sockaddr_in server_in;
    server_in.sin_family = AF_INET;
    server_in.sin_port = htons(6666);
    server_in.sin_addr.s_addr = INADDR_ANY;

    int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    bind(sock, (struct sockaddr*)&server_in, sizeof(server_in));
    listen(sock, 2);

    struct sockaddr_in client_addr;
    int buf;
    while (1) {
      int client = accept(sock, NULL, NULL);
      recv(client, &buf, sizeof(int), 0);
    }
  }
} 