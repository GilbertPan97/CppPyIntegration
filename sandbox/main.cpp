#include "SocketServer.h"

#include <iostream>

int main() {
    int portNumber = 8080; // Replace this with the desired port number

    // Create a SocketServer instance with the specified port number
    SocketServer server(portNumber);

    // Start the server
    if (!server.Start()) {
        std::cerr << "Failed to start the server" << std::endl;
        return 1;
    }

    std::cout << "Server started on port " << portNumber << std::endl;

    // Accept and receive data from clients in a loop
    while (true) {
        if (server.AcceptAndReceive()) {
            // Do something with the received data
        } else {
            std::cerr << "Error accepting/receiving data from client" << std::endl;
        }
    }

    // Close the server (this won't be reached in the above loop)
    server.Close();

    return 0;
}
