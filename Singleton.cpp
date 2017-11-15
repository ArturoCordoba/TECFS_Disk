//
// Created by arturocv on 13/11/17.
//

#include "Singleton.h"

Singleton* Singleton::instance = nullptr;
sf::TcpSocket* Singleton::server = nullptr;
std::string Singleton::directory = "disk";

Singleton::Singleton() {

}

/// Metodo para instanciar el unico objeto de la clase Singleton
/// \return
Singleton *Singleton::getInstance() {
    //Se crean las instancias si estan no existian previamente
    if(instance == nullptr){
        instance = new Singleton(); //Se crea la instancia de la clase
        server = new sf::TcpSocket(); //Se crea el servidor

        ///Lectura del XML para obtener la ip del servidor

        sf::IpAddress ip = "127.0.0.1";
        server->connect(ip, 2001);

        //Se le indica al servidor que se trata de un disco
        sf::Packet data;
        data << "Disk";
        server->send(data);
    }

    return instance;
}

sf::TcpSocket *Singleton::getServer() {
    if(instance == nullptr){
        getInstance();
    }

    return server;
}

std::string Singleton::getDirectory() {
    return directory;
}

/// Metodo para crear la carpeta donde se van a almacenar los datos del disco
/// \param diskNum
void Singleton::createDiskDirectory(int diskNum) {
    Singleton::directory = "disk" + std::to_string(diskNum);
    mkdir(directory.c_str(), 0777);
}


