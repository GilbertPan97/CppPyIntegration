#ifndef SOCKET_SERVER_H
#define SOCKET_SERVER_H

#include <vector>

#ifdef _WIN32
    #include <winsock2.h>
    typedef int socklen_t;      // Use int to represent the length of the socket address structure on Windows
#else
    #include <netinet/in.h>
#endif

class SocketServer {
public:
    SocketServer(int port);
    bool Start();
    bool AcceptAndReceive();
    void Close();

private:
    SOCKET serverSocket; // Use SOCKET type to define serverSocket
    SOCKET newSocket;    // Use SOCKET type to define newSocket
    int portNumber;
    int bufferSize;
    struct sockaddr_in serverAddr;
    struct sockaddr_storage serverStorage;
    socklen_t addr_size;
};

#endif // SOCKET_SERVER_H