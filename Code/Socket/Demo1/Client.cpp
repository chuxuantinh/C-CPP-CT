/**/
/* Code by KingNNT */
#include <bits/stdc++.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

using namespace std;
#define PORT 8008

int main()
{
    struct sockaddr_in address;
    struct sockaddr_in serv_addr;
    int sock = 0, valread;
    char *hello = "Hello from client";
    char buffer[1024] = {0};
    char add[225];
    int continu = 1;
    cout << "Fill IP Address: " << endl;
    cin >> add;

#pragma region Create Socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("\n Socket creation error \n");
        return -1;
    }
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
#pragma endregion Create Socket

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, add, &serv_addr.sin_addr) <= 0)
    {
        cout << endl
             << "Invalid address/ Address not supported" << endl;
        return -1;
    }

#pragma region Connect
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        cout << endl
             << "Connection Failed" << endl;
        return -1;
    }
    while (continu == 1)
    {
        char mess_from_client[225];
        cout << "Send message to Server from Client: " << endl;
        cin >> mess_from_client;
        fflush(stdin);
        hello = mess_from_client;

        cout << "Message from Server: " << endl;
        send(sock, hello, strlen(hello), 0);
        valread = read(sock, buffer, 1024);
        printf("%s\n", buffer);

        if (strcmp(mess_from_client, "bye") == 0)
        {
            continu = 0;
        }
        fflush(stdin);
    }
    close(sock);
#pragma endregion Connect
    return 0;
}