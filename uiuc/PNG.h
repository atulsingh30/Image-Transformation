#pragma once

#include<string>
#include<vector>
#include"HSLAPixel.h"
using namespace std;
namespace uiuc{
    class PNG{
        public:
        //Creates an empty PNG image
        PNG();

        //Creates a PNG image of specified dimensions
        PNG(unsigned int width, unsigned int height);

        //Copy Constructor: Creates a new PNG image which is the copy of another existing PNG
        //object. It takes reference to another PNG object, 'other' as the parameter. 
        PNG(PNG const & other);

        //Deconstructor: It frees all the memory associated with the 'PNG' object
        ~PNG();

        //Assignment operator: For setting two PNGs equal to one another, it takes 'other' as the parameter
        // and returns a current PNG object. Allow multiple chaining
        PNG const & operator=(PNG const & other);

        //Equality operator: Checks if two image are equal
        bool operator==(PNG const & other) const;

        //Inequality operator: Checks if two image are different
        bool operator!=(PNG const & other) const;

        //Reads Png image form a file, It can overwrite any current image content in the PNG
        //fileName- name of the file to be read from.
        // Return true if the image was successfully read and loaded
        bool readFromFile(string const & fileName); 

        //Write PNG imafe to a file.
        //fileName- name of the file to be written
        //returns true if the filename has been successfully written
        bool writeToFile(string const & fileName);
        
        //Pixel Access Operator- gets a reference to the pixel at the given coordinates
        //(0,0) is the upper left corner.
        //returns a reference to the pixel at the given reference point
        HSLAPixel & getPixel(unsigned int x, unsigned int y) const;

        //returns the width of the image
        unsigned int width() const;

        //returns the height of the image
        unsigned int height() const;

        //Resize the image 
        void resize(unsigned int newWidth, unsigned int newHeight);

        //Computes the hash contents of the image
        //size_t is an unsigned integral data type which is used to represent the size of objects in bytes
        //Computing a hash of the image contents can generate a unique identifier for the image.
        //Hashing allows for fast comparison of images. Instead of comparing each pixel or the entire image 
        //content, you can compare the hash values to quickly determine if two images are identical or different. 
        std::size_t computeHash() const;

        private:
        unsigned int width_;  //width of the image
        unsigned int height_; //height of the imge
        HSLAPixel *imageData_; //array of pixels
        HSLAPixel defaultPixel_; //default pixels, returned in cases of errors

        //Copies the contents of 'other' to self
        //Copy constructor is called when you create a new object with intializing with an existing object of the same type.
        //It is used to create a copy of the existing object
        //_copy function is a separate member function that purpose is to perform the task of copying contents of one 'PNG' object
        //to another. This copying process involves copying the values of the member variables from one object to another.
        //The _copy function is typically invoked by both the copy constructor and the assignment operator to perform the actual copying process.
        void _copy(PNG const & other);
    };
    //This class is responsible for handling output stream.
    //overloaded stream insertion operators (<<) 
    //This operator overload allows you to output a PNG object to an output stream (std::ostream). The out parameter represents the output stream, 
    //and the pixel parameter is a reference to the PNG object you want to output
    // It returns a reference to the same output stream, std::ostream&, to allow chaining of multiple output operations.
    std::ostream & operator<<(std::ostream & out, PNG const & pixel);
    
    //A stringstream associates a string object with a stream allowing you to read from the string as if it were a stream (like cin). 
    //This operator overload is similar to the previous one, but it specifically allows you to output a PNG object to a string stream (std::stringstream). 
    //The out parameter represents the string stream, and the pixel parameter is a reference to the PNG object you want to output. It returns a reference to 
    //the same string stream, std::stringstream&, to allow chaining of multiple output operations.
    //This operator overload lets you convert a PNG object to a string representation by appending it to a string stream. This can be useful when you want 
    //to capture the formatted representation of the PNG object in a string for further processing or logging purposes.
    std::stringstream & operator<<(std::stringstream & out, PNG const & pixel);
}