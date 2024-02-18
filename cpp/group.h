/**
 * @file group.h
 * @brief This file contains the declaration of the Group class.
 */

#ifndef GROUP_H
#define GROUP_H

#include <list>
#include <iostream>
#include <memory>
#include "multimedia.h"

#ifdef PART_6_8
class Group : public std::list<Multimedia *> {
    private:
        std::string name;
    public:
        Group(std::string name){this->name = name;}
        ~Group();
        std::string getName() const{
            return name;
        }
        void afficher(std::ostream &out) const {
            out << "Group: " << getName() << std::endl;
            for (const auto& item : *this) {
                item->afficher(out);
            }
        }
};
#endif

#ifndef PART_6_8
typedef std::shared_ptr<Multimedia> MultPtr;

class Group : public std::list<MultPtr>{
    private:
        std::string name;
    public:
        Group(std::string name){this->name = name;}
        std::string getName() const{
            return name;
        }
        void afficher(std::ostream &out) const {
            out << "Group: " << getName() << std::endl;
            for (const auto& item : *this) {
                item->afficher(out);
            }
        }
};
#endif

#endif