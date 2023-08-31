//Represents pixel in HSLA color space

#pragma once 
/*This directive ensures that the header file is included only once during the compilation process, preventing multiple 
inclusion and the associated problems. */

#include<iostream>
#include<sstream>
/*<sstream> provides header files for string stream operations, which provide functionality for printing, reading and 
manipulating strings.This involves converting numeric values to strings, parsing and extracting data from strings, or
formatting strings with specific content*/

/*Using specific namespace allows to define your own namespace to encapsulate your code. This helps prevent naming 
conflicts with other namespaces or libraries, promotes code organization, and allows for better code modularity and 
reusability.*/
namespace uiuc{
    class HSLAPixel {
    public:
    double h; //hue- dominant wavelength of light that determines the perceived color, values ranges between 0 to 360degree
    double s; //saturation- intensity of light(dull or vibrant), values between 0(gray color) and 1(saturated color)
    double l; //luminance- represents the brightness of color, Higher luminance values indicate brighter colors,
    // while lower values indicate darker colors, values between 0(black) and 1(white)
    double a; //alpha- transparency of color, values between 0(fully transparent) and 1(fully opaque(visible completely))
};
}


