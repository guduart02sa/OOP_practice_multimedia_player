/**
 * @class Video
 * @brief Represents a video file.
 * 
 * The Video class is a derived class of the Multimedia class.
 * It adds the functionality to store and retrieve the duration of the video.
 */

#ifndef VIDEO_H
#define VIDEO_H

#include <iostream>
#include "multimedia.h"

using namespace std;

class Video : public Multimedia{
    private:
        int duration{}; /**< The duration of the video in seconds. */
    public:
        /**
         * @brief Constructor for the Video class.
         * @param name The name of the video.
         * @param path The path to the video file.
         * @param duration The duration of the video in seconds.
         */
        Video(std::string name, std::string path, int duration)
            : Multimedia(name, path), duration(duration) {}
        
        /**
         * @brief Destructor for the Video class.
         * 
         * Prints a message indicating that the video has been deleted.
         */
        ~Video(){cout << "Video " << this->getName() << " deleted!" << endl;};

        /**
         * @brief Sets the duration of the video.
         * @param duration The duration of the video in seconds.
         */
        void setDuration(int duration){
            this->duration = duration;
        }

        /**
         * @brief Gets the duration of the video.
         * @return The duration of the video in seconds.
         */
        int getDuration() const{
            return this->duration;
        }

        /**
         * @brief Displays the video information.
         * @param stream The output stream to display the information.
         */
        virtual void afficher(std::ostream& stream) const override{
            Multimedia::afficher(stream);
            stream << "Duration: " << this->duration << std::endl;
        }

        /**
         * @brief Plays the video.
         * 
         * Uses the 'mpv' command-line tool to play the video file.
         */
        void play() const override{
            system(("mpv " + getPath() + " &").c_str());
        }
        
};

#endif