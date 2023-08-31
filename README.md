# Image-Transformation
## How the project works:
### For loading and saving PNG files:

- **bool PNG::readFromFile(const std::string & fileName)** loads an image based on the provided file name, a text string. The return value shows success or failure. it means a direct reference to the memory is being passed, similar to a pointer.
- **bool PNG::writeToFile(const std::string & fileName)** writes the current image to the providedfile name (overwriting existing files).

### For retrieving pixel and image information:

- **unsigned int PNG::width()** constreturns the width of the image.
- **unsigned int PNG::height()** constreturns the height of the image.
- **HSLAPixel & getPixel(unsigned int x, unsigned int y)** returns a direct reference to a pixel at the specified location.
