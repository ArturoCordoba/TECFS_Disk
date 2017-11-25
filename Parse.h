#ifndef TECFS_DISK_PARSE_H
#define TECFS_DISK_PARSE_H

#include <SFML/Network.hpp>
#include <iostream>
#include <fstream>


using namespace std;

void parse(std::string xml, sf::IpAddress *ip, int *port, std::string *path)
{
    string line;
    ifstream in(xml);

    bool beginIp = false;
    bool beginPort = false;
    bool beginPath = false;
    while(getline(in,line))
    {
        std::string temp;
        for(int i = 0; i < line.length(); i++)
        {
            if(line[i] == ' ' && temp.size() == 0)
            {
            }
            else
            {
                temp += line[i];
            }
        }

        ///IP
        if(temp == "<Ip>")
        {
            beginIp = true;
            continue;
        }
        else if(temp == "</Ip>")
        {
            beginIp = false;
        }
        if(beginIp)
        {
            *ip = temp;
        }

        ///PORT
        if(temp == "<Port>")
        {
            beginPort = true;
            continue;
        }
        else if(temp == "</Port>")
        {
            beginPort = false;
        }
        if(beginPort)
        {

            *port = atoi(temp.c_str());
        }

        ///PATH
        if(temp == "<Path>")
        {
            beginPath = true;
            continue;
        }
        else if(temp == "</Path>")
        {
            beginPath = false;
        }
        if(beginPath)
        {
            *path = temp;
        }
    }
}

#endif //TECFS_DISK_PARSE_H
