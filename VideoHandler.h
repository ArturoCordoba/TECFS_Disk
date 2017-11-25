//
// Created by arturocv on 14/11/17.
//

#ifndef TECFS_DISK_VIDEOHANDLER_H
#define TECFS_DISK_VIDEOHANDLER_H


#include <iostream>
#include <vector>
#include <fstream>
#include <dirent.h>

#include "Singleton.h"
#include "DataStructures/LinkedList.h"

typedef unsigned char byte;

class VideoHandler {
public:
    static int fileSize(const std::string filename);

    static bool emptyFolder(std::string dirname);

    static std::string freeBlock(std::string path);

    static LinkedList<std::vector<byte>> splitFile(std::vector<byte> vector);

    static void savePart(std::string part, std::string fileName);

    static std::string getPart(std::string fileName);

    static LinkedList<std::string> splitString(std::string string, char *splitCharacter);
};


#endif //TECFS_DISK_VIDEOHANDLER_H
