#include <iostream>
#include <vector>

#include "multimedia.h"
#include "photo.h"
#include "video.h"
#include "film.h"
#include "group.h"
#include "manipulation.h"
#include "tcpserver.h"
#include "server_decoder.h"


#define PART_11

const int PORT = 3331;

int main(int argc, const char* argv[]){
    #ifdef PART_6_9
    #ifdef PART_6_8
    Photo* photo1 = new Photo("Disney", "/home/INF224/Media/photo.jpg", 1, 1);
    Photo* photo2 = new Photo("Le chat 1", "/home/INF224/Media/gato1.jpg", 1, 1);
    Photo* photo3 = new Photo("Le chat 2", "/home/INF224/Media/gato2.jpg", 1, 1);

    Video* video1 = new Video("Animation", "/home/INF224/Media/animation.mp4", 1);
    Video* video2 = new Video("LoL gameplay", "/home/INF224/Media/lol1.mp4", 1);

    std::vector<Multimedia*> mediaList;
    #endif

    #ifdef PART_9
        shared_ptr<Photo> photo1_ptr(new Photo("Disney", "/home/INF224/Media/photo.jpg", 1, 1));
        shared_ptr<Photo> photo2_ptr(new Photo("Le chat 1", "/home/INF224/Media/gato1.jpg", 1, 1));
        shared_ptr<Photo> photo3_ptr(new Photo("Le chat 2", "/home/INF224/Media/gato2.jpg", 1, 1));

        shared_ptr<Video> video1_ptr(new Video("Animation", "/home/INF224/Media/animation.mp4", 1));
        shared_ptr<Video> video2_ptr(new Video("LoL gameplay", "/home/INF224/Media/lol1.mp4", 1));
    #endif

    Group* Group1 = new Group("Cat photos");
    Group* Group2 = new Group("Some videos");

    Group1->push_back(photo1_ptr);
    Group1->push_back(photo2_ptr);

    Group2->push_back(photo1_ptr);
    Group2->push_back(video2_ptr);

    Group1->afficher(std::cout);
    Group2->afficher(std::cout);
    #endif

    #ifdef PART_11
    Manipulation* manager = new Manipulation();

    manager->createPhoto("Disney", "../Media/photo.jpg", 1, 1);
    manager->createPhoto("Le chat 1", "../Media/photo.jpg", 1, 1);
    manager->createPhoto("Le chat 2", "../Media/photo.jpg", 1, 1);
    manager->createVideo("Animation", "../Media/animation.mp4", 1);
    manager->createVideo("LoL gameplay", "../Media/lol1.mp4", 1);
    
    manager->createGroup("Cat photos");
    manager->add_to_group("Cat photos", "Le chat 1");
    manager->add_to_group("Cat photos", "Le chat 2");

    manager->createGroup("Some videos");
    manager->add_to_group("Some videos", "Animation");


    auto* server = new TCPServer([&](std::string const& request, std::string& response) {
        std::cout << "request: " << request << std::endl;

        response = request_manipulation(request, manager);

        return true;
    });

    std::cout << "Starting Server on port " << PORT << std::endl;
    int status = server->run(PORT);

    if (status < 0) {
        std::cerr << "Could not start Server on port " << PORT << std::endl;
        return 1;
    }
    #endif

    return 0;
}