
#include "ServerSocket.h"
#include "SocketException.h"
#include <string>
#include <iostream>

int main(int argc, char* argv[]) {
    try {
        // Create the Socket
        ServerSocket server(30000);

        while(true) {
            ServerSocket new_sock;
            server.accept(new_sock);

            try {
                while(true) {
                    std::string data;
                    new_sock >> data;
                    std::cout << "[Received]\t" << data << std::endl;

                    /* CODE BEGIN */
                    new_sock << data;
                    /* CODE  END  */
                }
            } catch(SocketException&) {}
        }
    } catch(SocketException& e) {
        std::cout<< "Exception caught: " << e.description() << std::endl;
    }

    return 0;
}

