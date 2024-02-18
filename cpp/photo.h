/**
 * @class Photo
 * @brief Represents a photo object derived from the Multimedia base class.
 * 
 * The Photo class stores information about a photo, including its name, path, latitude, and longitude.
 * It provides methods to set and get the latitude and longitude, as well as display the photo's information
 * and play the photo using an external image viewer.
 */

#ifndef PHOTO_H
#define PHOTO_H

#include <iostream>

#include "multimedia.h"

class Photo : public Multimedia{
    private:
        float latitude{}; /**< The latitude of the photo's location. */
        float longitude{}; /**< The longitude of the photo's location. */
    public:
        /**
         * @brief Constructs a Photo object with the given name, path, latitude, and longitude.
         * @param name The name of the photo.
         * @param path The path to the photo file.
         * @param latitude The latitude of the photo's location.
         * @param longitude The longitude of the photo's location.
         */
        Photo(std::string name, std::string path, float latitude, float longitude)
            : Multimedia(name, path), latitude(latitude), longitude(longitude) {}

        /**
         * @brief Destroys the Photo object and prints a message indicating the deletion.
         */
        ~Photo(){cout << "Photo " << this->getName() << " deleted!" << endl;};

        /**
         * @brief Sets the latitude of the photo's location.
         * @param latitude The latitude to set.
         */
        void setLatitude(float latitude){
            this->latitude = latitude;
        }

        /**
         * @brief Sets the longitude of the photo's location.
         * @param longitude The longitude to set.
         */
        void setLongitude(float longitude){
            this->longitude = longitude;
        }

        /**
         * @brief Gets the latitude of the photo's location.
         * @return The latitude of the photo's location.
         */
        float getLatitude() const{
            return this->latitude;
        }

        /**
         * @brief Gets the longitude of the photo's location.
         * @return The longitude of the photo's location.
         */
        float getLongitude() const{
            return this->longitude;
        }

        /**
         * @brief Displays the photo's information, including its name, path, latitude, and longitude.
         * @param stream The output stream to display the information to.
         */
        void afficher(std::ostream& stream) const override{
            Multimedia::afficher(stream);
            stream << "Latitude: " << this->latitude << std::endl;
            stream << "Longitude: " << this->longitude << std::endl;
        }

        /**
         * @brief Plays the photo by opening it with an external image viewer.
         */
        void play() const override{
            system(("imagej " + getPath() + "&").c_str());
        }
};

#endif