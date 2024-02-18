/**
 * @class Manipulation
 * @brief Class for manipulating multimedia objects and groups.
 * 
 * This class provides methods for creating, finding, displaying, playing, and deleting multimedia objects and groups.
 * It also allows adding multimedia objects to groups.
 */

#ifndef MANIPULATION_H
#define MANIPULATION_H

#include <iostream>
#include <map>
#include <memory>

#include "multimedia.h"
#include "group.h"
#include "photo.h"
#include "video.h"
#include "film.h"

using namespace std;

typedef std::shared_ptr<Multimedia> MultimediaPtr;
typedef std::shared_ptr<Photo> PhotoPtr;
typedef std::shared_ptr<Video> VideoPtr;
typedef std::shared_ptr<Film> FilmPtr;
typedef std::shared_ptr<Group> GroupPtr;


class Manipulation{
    private:
        std::map<std::string, std::shared_ptr<Multimedia>> mediaMap;
        std::map<std::string, std::shared_ptr<Group>> groupMap;
    public:
        Manipulation(){};
        ~Manipulation(){cout << "Manipulation object deleted!" << endl;};

        PhotoPtr createPhoto(std::string name, std::string path, int latitude, int longitude);
        VideoPtr createVideo(std::string name, std::string path, int duration);
        FilmPtr createFilm(std::string name, std::string path, int duration, int *durations, int chapters);
        GroupPtr createGroup(std::string name);

        bool find_displayMedia(std::string mediaName, std::ostream& stream);
        bool find_displayGroup(std::string groupName, std::ostream& stream);

        bool playMedia(std::string mediaName);

        bool deleteMedia(std::string mediaName);
        bool deleteGroup(std::string groupName);

        bool add_to_group(std::string groupname, std::string medianame);
        
};

#endif