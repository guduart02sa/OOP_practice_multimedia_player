#ifndef SERVER_DECODER_H
#define SERVER_DECODER_H

#include <iostream>
#include <sstream>
#include <string>

#include "manipulation.h"

std::string request_manipulation(std::string request, Manipulation *manipulate)
{
    std::stringstream ss(request);
    std::string command;
    ss >> command;

    std::string type, name;
    ss >> type >> name;

    if (!command.empty())
    {
        if (command == "delete")
        {
            if (!type.empty())
            {
                if (type == "group")
                {
                    if (manipulate->deleteGroup(name))
                    {
                        return "Group " + name + " delete request sent";
                    }
                    else
                    {
                        return "Group not found";
                    }
                }
                else if (type == "media")
                    {
                        if (manipulate->deleteMedia(name))
                        {
                            return "Media " + name + " delete request sent";
                        }
                        else
                        {
                            return "Media not found";
                        }
                    }
                }
            }
            else if (command == "display")
            {
                stringstream a;
                if (!type.empty())
                {
                    if (type == "group")
                    {
                        manipulate->find_displayGroup(name,a);
                        return a.str();
                    }
                    else if (type == "media")
                    {
                        manipulate->find_displayMedia(name,a);
                        return a.str();
                    }
                }
            }
            else if (command == "play")
            {
                if (!type.empty()){
                    if (manipulate->playMedia(name) == true)
                    {
                        return "Play " + name + " request sent";
                    }
                    else
                    {
                        return "Media not found";
                    }
                }
            }
        }

        return "Invalid request";
    }

#endif