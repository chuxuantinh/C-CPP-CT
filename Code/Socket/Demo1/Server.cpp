/**/
/* Code by KingNNT */
#include <bits/stdc++.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

using namespace std;
#define PORT 8008

void ToUp(char *p);
int main()
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char mess_from_client[225];
    char buffer[1024] = {0};
    char *hello = "Hello from server";
    int continu = 1;

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)))
    {
        perror("Setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0)
    {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 3) < 0)
    {
        perror("Listen");
        exit(EXIT_FAILURE);
    }

    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0)
    {
        perror("Accept");
        exit(EXIT_FAILURE);
    }
    while (continu == 1)
    {
        char str_cli_ip[INET_ADDRSTRLEN];
        struct sockaddr_in *ip_client = (struct sockaddr_in *)&address;
        inet_ntop(AF_INET, &ip_client->sin_addr, str_cli_ip, INET_ADDRSTRLEN);
        cout << "IP Client: " << str_cli_ip << endl;
        char str_cli_port[INET_ADDRSTRLEN];
        cout << "Port: " << ntohs(ip_client->sin_port) << endl;
        cout << "Message from Client: " << endl;
        valread = read(new_socket, buffer, 1024);
        ToUp(buffer);
        hello = buffer;
        cout << buffer << endl;
        send(new_socket, hello, strlen(hello), 0);
    }
    close(new_socket);
    return 0;
}

void ToUp(char *p)
{
    while (*p)
    {
        *p = toupper(*p);
        p++;
    }
}