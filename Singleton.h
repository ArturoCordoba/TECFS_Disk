//
// Created by arturocv on 13/11/17.
//

#ifndef TECFS_DISK_SINGLETON_H
#define TECFS_DISK_SINGLETON_H


#include <SFML/Network/TcpSocket.hpp>
#include <SFML/Network/IpAddress.hpp>
#include <SFML/Network/Packet.hpp>

#include "DataBaseHandler.h"
#include <sys/stat.h>

class Singleton {
public:
    static Singleton* getInstance();

    static sf::TcpSocket* getServer();

    static std::string getDirectory();

    static void createDiskDirectory(int diskNum);

private:
    Singleton();

    static Singleton* instance;

    static sf::TcpSocket* server;

    static std::string directory;
};


#endif //TECFS_DISK_SINGLETON_H
