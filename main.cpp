#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <cstring>
#include <iostream>
#include "DataBaseHandler.h"
#include "Singleton.h"
#include "VideoHandler.h"

int main(){
    int num;
    std::cout << "Ingrese el numero de disco: ";
    std::cin >> num;
    Singleton::createDiskDirectory(num);
    std::cout << "Disco creado" << std::endl;

    sf::TcpSocket* server = Singleton::getServer();

    while(true){
        sf::Packet receivePacket;
        if(server->receive(receivePacket) == sf::Socket::Done){
            //Se solicita informacion de la base de datos
            std::string act;
            receivePacket >> act;
            char* action = (char*) act.c_str();

            //Se solicita gestion de la base de datos
            if(strcmp(action, "database") == 0){
                std::string action2;
                receivePacket >> action2;
                std::string content;
                receivePacket >> content;

                //Se solicita la creacion de la tabla
                if(strcmp(action2.c_str(), "save") == 0){
                    DataBaseHandler::createFile(content);

                //Se solicita la informacion almacenada en el disco
                } else if(strcmp(action2.c_str(), "get") == 0){
                    std::string data = DataBaseHandler::getData();
                    std::cout << data << std::endl;
                    sf::Packet packet;
                    packet << data;
                    server->send(packet);
                }

            //Se solicita el guardado de una parte del video
            } else if(strcmp(action, "savePart") == 0){
                std::string fileName;
                std::string part;
                receivePacket >> fileName;
                receivePacket >> part;
                VideoHandler::savePart(part, fileName);

            //Se solicita el envio de la parte del video almacenada
            } else if(strcmp(action, "getPart") == 0){
                std::string fileName;
                receivePacket >> fileName;
                std::string part = VideoHandler::getPart(fileName);
                sf::Packet responsePacket;
                responsePacket << part;
                server->send(responsePacket);
            }
        }
    }

    return 0;
}