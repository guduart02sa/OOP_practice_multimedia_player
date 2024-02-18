/**
 * @file film.h
 * @brief This file contains the declaration of the Film class.
 */

#ifndef FILM_H
#define FILM_H

#include <vector>
#include <iostream>

#include "video.h"
#include "multimedia.h"

using namespace std;

/**
 * @class Film
 * @brief Represents a film that inherits from the Video class.
 */
class Film : public Video {
private:
    int *durations_chapters = nullptr; /**< Array of chapter durations */
    unsigned int n_chapters{}; /**< Number of chapters */

public:
    /**
     * @brief Constructor for the Film class.
     * @param name The name of the film.
     * @param path The path of the film.
     * @param duration The duration of the film.
     * @param n_chapters The number of chapters in the film.
     */
    Film(std::string name, std::string path, int duration, int n_chapters)
        : Video(name, path,duration), n_chapters(n_chapters) {}

    /**
     * @brief Destructor for the Film class.
     */
    ~Film(){delete [] durations_chapters; cout << "Film "<< this->getName() << " deleted!" << endl;}

    /**
     * @brief Get the number of chapters in the film.
     * @return The number of chapters.
     */
    int getNumberOfChapters() const{
        return this->n_chapters;
    }

    /**
     * @brief Get the durations of the chapters in the film.
     * @return A pointer to the array of chapter durations.
     */
    int* getChaptersdurations() const{
        return this->durations_chapters;
    }

    /**
     * @brief Set the chapters of the film.
     * @param n_chapters_arg The number of chapters.
     * @param durations_chapters_ptr A pointer to the array of chapter durations.
     */
    void setChapters(unsigned int n_chapters_arg, const int *durations_chapters_ptr) {
        delete[] this->durations_chapters;                  //CLEAN
        this->durations_chapters = nullptr;                 
        this->n_chapters = n_chapters_arg;                  

        if(n_chapters > 0 && durations_chapters_ptr != nullptr){
            for(unsigned int i = 0; i < n_chapters; i++){
                durations_chapters[i] = durations_chapters_ptr[i];
            }
        }
    }

    /**
     * @brief Print the film details.
     * @param out The output stream to print to.
     */
    void afficher(std::ostream &out) const override{
        Video::afficher(out);
        for(unsigned int i = 0; i < n_chapters; i++){
            out << "Capitre : " << i << " " << "Duration du capitre: " << durations_chapters[i] << endl; 
        }
    }
};

#endif