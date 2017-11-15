//
// Created by arturocv on 13/11/17.
//

#include <iostream>
#include "Singleton.h"

/// Metodo para crear el fichero con la parte correspondiente de la base de datos
/// \param content String que hay que almacenar
void DataBaseHandler::createFile(std::string content) {
    std::string fileName = Singleton::getDirectory() + "/metadata.bin";

    std::ofstream file(fileName, std::ios::out | std::ios::binary);
    file.write(content.c_str(), content.size());
    file.close();
}

/// Metodo para obtener la parte de la base de datos que almacenada en el disco
/// \return Un string con la parte de la base de datos
std::string DataBaseHandler::getData() {
    std::string fileName = Singleton::getDirectory() + "/metadata.bin";

    std::ifstream file(fileName, std::ios::binary);
    std::string data((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();

    return data;
}
