#include "manipulation.h"

PhotoPtr Manipulation::createPhoto(std::string name, std::string path, int latitude, int longitude){
    PhotoPtr photo(new Photo(name, path, latitude, longitude));
    mediaMap[name] = photo;
    return photo;
}

VideoPtr Manipulation::createVideo(std::string name, std::string path, int duration){
    VideoPtr video(new Video(name, path, duration));
    mediaMap[name] = video;
    return video;
}

FilmPtr Manipulation::createFilm(std::string name, std::string path, int duration,int * durations, int chapters){
    FilmPtr film(new Film(name, path, duration, chapters));
    film->setChapters(chapters, durations);
    mediaMap[name] = film;
    return film;
}

GroupPtr Manipulation::createGroup(std::string name){
    GroupPtr group(new Group(name));
    groupMap[name] = group;
    return group;
}

bool Manipulation::find_displayMedia(std::string mediaName, std::ostream& stream) {
    if(mediaMap.find(mediaName) != mediaMap.end()){
        mediaMap[mediaName]->afficher(stream);
        return true;
    }
    return false;
}

bool Manipulation::find_displayGroup(std::string groupName, std::ostream& stream) {
    if(groupMap.find(groupName) != groupMap.end()){
        groupMap[groupName]->afficher(stream);
        return true;
    }
    return false;
}

bool Manipulation::playMedia(std::string mediaName){
    if(mediaMap.find(mediaName) != mediaMap.end()){
        mediaMap[mediaName]->play();
        return true;
    }
    return false;
}

bool Manipulation::deleteMedia(std::string mediaName){
    if(mediaMap.find(mediaName) != mediaMap.end()){
        mediaMap.erase(mediaName);
        return true;
    }
    return false;
}

bool Manipulation::deleteGroup(std::string groupName){
    if(groupMap.find(groupName) != groupMap.end()){
        groupMap.erase(groupName);
        return true;
    }
    return false;
}

bool Manipulation::add_to_group(std::string groupName, std::string mediaName){
    if (groupMap.find(groupName) != groupMap.end() && mediaMap.find(mediaName) != mediaMap.end()) {
        groupMap[groupName]->push_back(mediaMap[mediaName]);
        return true;
    }
    return false;
}



