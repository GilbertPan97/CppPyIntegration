// SocketServer.cpp

#include "SocketServer.h"
#include <iostream>
#include <cstring>
#if WIN32
#   include <winsock2.h>
#else
#   include <netinet/in.h>
#endif

SocketServer::SocketServer(int port) : serverSocket(INVALID_SOCKET), portNumber(port), bufferSize(1024) {}

bool SocketServer::Start() {
#if WIN32
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "Failed to initialize Winsock" << std::endl;
        return false;
    }
#endif

    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == INVALID_SOCKET) {
        std::cerr << "Error creating socket" << std::endl;
#if WIN32
        WSACleanup();
#endif
        return false;
    }

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(portNumber);
    serverAddr.sin_addr.s_addr = INADDR_ANY;

    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        std::cerr << "Error binding socket" << std::endl;
        closesocket(serverSocket);
#if WIN32
        WSACleanup();
#endif
        return false;
    }

    if (listen(serverSocket, 10) == SOCKET_ERROR) {
        std::cerr << "Error listening on socket" << std::endl;
        closesocket(serverSocket);
#if WIN32
        WSACleanup();
#endif
        return false;
    }

    return true;
}

bool SocketServer::AcceptAndReceive() {
    addr_size = sizeof(serverStorage);
    newSocket = accept(serverSocket, (struct sockaddr*)&serverStorage, &addr_size);
    if (newSocket == INVALID_SOCKET) {
        std::cerr << "Error accepting connection" << std::endl;
        closesocket(serverSocket);
#if WIN32
        WSACleanup();
#endif
        return false;
    }

    std::vector<char> buffer(bufferSize);
    int bytesRead = recv(newSocket, buffer.data(), bufferSize, 0);
    if (bytesRead == SOCKET_ERROR) {
        std::cerr << "Error receiving data" << std::endl;
        closesocket(newSocket);
        closesocket(serverSocket);
#if WIN32
        WSACleanup();
#endif
        return false;
    }

    std::cout << "Received data from client: " << buffer.data() << std::endl;

    closesocket(newSocket);
    return true;
}

void SocketServer::Close() {
    if (serverSocket != INVALID_SOCKET) {
        closesocket(serverSocket);
        serverSocket = INVALID_SOCKET;
#if WIN32
        WSACleanup();
#endif
    }
}