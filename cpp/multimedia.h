/**
 * @class Multimedia
 * @brief Represents a multimedia object with a name and a path.
 * 
 * The Multimedia class is an abstract base class that provides common functionality for multimedia objects.
 * It contains methods to set and get the name and path of the object, as well as a virtual method to display
 * the object's information. The class also declares a pure virtual method play(), which must be implemented
 * by derived classes.
 */
#ifndef MULTIMEDIA_H
#define MULTIMEDIA_H

#include <string>
#include <iostream>

using namespace std;


class Multimedia{
    private:
        std::string name{};
        std::string path{};
    public:
        /**
         * @brief Default constructor for Multimedia class.
         */
        Multimedia();
        
        /**
         * @brief Constructor for Multimedia class.
         * @param name The name of the multimedia object.
         * @param path The path of the multimedia object.
         */
        Multimedia(std::string name, std::string path);

        /**
         * @brief Virtual destructor for Multimedia class.
         * 
         * This destructor will be called when a derived class object is deleted.
         * It displays a message indicating that the multimedia object has been deleted.
         */
        virtual ~Multimedia(){cout << "Multimedia " << this->getName() << " deleted!" << endl;};

        /**
         * @brief Set the name of the multimedia object.
         * @param name The name to set.
         */
        void setName(std::string name);
        
        /**
         * @brief Set the path of the multimedia object.
         * @param path The path to set.
         */
        void setPath(std::string path);

        /**
         * @brief Get the name of the multimedia object.
         * @return The name of the multimedia object.
         */
        std::string getName() const;
        
        /**
         * @brief Get the path of the multimedia object.
         * @return The path of the multimedia object.
         */
        std::string getPath() const;
        
        /**
         * @brief Display the multimedia object's information.
         * @param stream The output stream to display the information to.
         */
        virtual void afficher(std::ostream& stream) const;

        /**
         * @brief Pure virtual method to play the multimedia object.
         * 
         * This method must be implemented by derived classes.
         */
        virtual void play() const = 0;
};

#endif