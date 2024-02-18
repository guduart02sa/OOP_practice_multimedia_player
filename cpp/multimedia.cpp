#include <iostream>

#include "multimedia.h"

Multimedia::Multimedia(std::string name, std::string path){
    this->name = name;
    this->path = path;
}

void Multimedia::setName(std::string name){
    this->name = name;
}
void Multimedia::setPath(std::string path){
    this->path = path;
}

std::string Multimedia::getName() const{
    return this->name;
}

std::string Multimedia::getPath() const{
    return this->path;
}
void Multimedia::afficher(std::ostream& stream) const{
    stream << "Name: " << this->name << std::endl;
    stream << "Path: " << this->path << std::endl;
}