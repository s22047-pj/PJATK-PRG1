#include <arpa/inet.h>
#include <fcntl.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include <iostream>
#include <string>
#include <vector>
#include <array>

auto main() -> int
{
    // stworzenie nowego cocketu - nasłuchiwanie na połączenie albo
    // nazwiązywanie połączenia z kilentem
    auto sock = socket(AF_INET, SOCK_STREAM, 0);
    
    auto const ip = std::string{"127.0.0.1"};
    auto const port = uint16_t{8080};

    std::cout << "ip: " << ip << "\n";
    std::cout << "port: " << port << "\n";  

    // określenie połączenia
    sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port   = htobe16(port);
    inet_pton(addr.sin_family, ip.c_str(), &addr.sin_addr);

    // przygotowanie połączenia
    bind(sock, reinterpret_cast<sockaddr*>(&addr), sizeof(addr));
    

    // nasłuchiwanie na połączenie
    listen(sock, SOMAXCONN);
    auto client_sock = accept(sock, nullptr, nullptr);

    close(sock);
    
    std::array<char, 4096> buf {0};
    while (true){

        int bytesReceived = read(client_sock, buf.data(), buf.size());
        std::cout << std::string{buf.data(), static_cast<size_t>(4096)};
        
        if (bytesReceived == -1)
        {
            perror("Error. Quitting\n");
            break;
        }
        if (bytesReceived == 0)
        {
            std::cout << "Client disconnected\n";
            break;
        }

        //std::cout << std::string(buf, 0, bytesReceived) << std::endl;
        write(client_sock, buf.data(), buf.size());

    }

    shutdown(sock, SHUT_RDWR);
    // koniec połączenia
    close(client_sock);

    return 0;
}
