#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>      // fork, read, write, close
#include <arpa/inet.h>

#define SERVER_IP "167.172.159.73"
#define SERVER_PORT 5000
#define BUFFER_SIZE 1024
#define NAME_SIZE 100

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char name[NAME_SIZE]; // buffer to store input
    char msg[NAME_SIZE + BUFFER_SIZE];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) { perror("socket"); exit(1); }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);


    printf("Enter your name: ");
    if (fgets(name, sizeof(name), stdin) != NULL) {
        // fgets keeps the newline, remove it if you want
        size_t len = strlen(name);
        if (len > 0 && name[len - 1] == '\n') {
            name[len - 1] = '\0';
        }
        printf("Hello, %s!\n", name);
    }
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    printf("Connected. Type messages. Ctrl+D to quit.\n");

    pid_t pid = fork();
    if (pid == 0) {
        // Child process: read from socket and print
        while (1) {
            int n = read(sockfd, buffer, sizeof(buffer)-1);
            if (n <= 0) break;
            buffer[n] = '\0';
            printf("%s", buffer);
            fflush(stdout);
        }
        exit(0);
    } else {
        // Parent process: read from stdin and send to server
        while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            memset(msg, 0, sizeof(msg));
            strcpy(msg, "[");
            strcat(msg, name);
            strcat(msg,"]");
            strcat(msg, buffer);
            send(sockfd, msg, strlen(msg), 0);
            //send(sockfd, buffer, strlen(buffer), 0);
        }
        close(sockfd);
        printf("Disconnected.\n");
        exit(0);
    }

    return 0;
}
