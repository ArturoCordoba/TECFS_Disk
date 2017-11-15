//
// Created by arturocv on 14/11/17.
//

#ifndef TECFS_DISK_VIDEOHANDLER_H
#define TECFS_DISK_VIDEOHANDLER_H


#include <iostream>
#include <vector>
#include <fstream>

typedef unsigned char byte;

class VideoHandler {
public:
    static void savePart(std::string part, std::string fileName);

    static std::string getPart(std::string fileName);
};


#endif //TECFS_DISK_VIDEOHANDLER_H
