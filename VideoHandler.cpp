//
// Created by arturocv on 14/11/17.
//

#include "VideoHandler.h"
#include "Singleton.h"

/// Metodo para almacenar en memoria la parte del video recibida
/// \param part String con la parte del video
/// \param fileName Nombre del video
void VideoHandler::savePart(std::string part, std::string fileName) {
    std::vector<byte> vector(part.begin(), part.end());
    std::ofstream file;
    file.open(Singleton::getDirectory() + "/" + fileName + ".bin", std::ios::out | std::ios::binary);
    file.write((const char*) &vector[0], vector.size());
    file.close();
}

/// Metodo para obtener la parte del video que se encuentra almacenada
/// \param fileName Nombre del fichero
/// \return Un string con la parte del video
std::string VideoHandler::getPart(std::string fileName) {
    std::ifstream file1(Singleton::getDirectory() + "/" + fileName + ".bin", std::ios::binary);
    std::vector<byte> vector((std::istreambuf_iterator<char>(file1)), std::istreambuf_iterator<char>());

    if(!file1.is_open()){
        std::cout << "Couldn't open the file " << fileName << ".bin" << std::endl;
    }

    file1.close();

    std::string part = std::string(vector.begin(), vector.end());
    return part;
}
