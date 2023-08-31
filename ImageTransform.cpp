#include <iostream>
#include <cmath>
#include <cstdlib>

#include "uiuc/PNG.h"
#include "uiuc/HSLAPixel.h"
#include "ImageTransform.h"

using uiuc::PNG;
using uiuc::HSLAPixel;

//For grayscale image the saturation of the image is set to be 0, i.e removing all the color
PNG grayscale(PNG image){
    for(unsigned i=0;i<image.width();i++){
        for(unsigned j=0;j<image.height();j++){
            HSLAPixel & pixel=image.getPixel(i,j);
            pixel.s=0;
        }
    }
    return image;
}

/*A spotlight adjusts the luminance of a pixel based on the distance the pixel
 is away from the center by decreasing the luminance by 0.5% per 1 pixel euclidean
 distance away from the center.*/
PNG createSpotlight(PNG image, int centerX, int centerY){
    for(unsigned i=0;i<image.width();i++){
        for(unsigned j=0;j<image.height();j++){
            HSLAPixel & pixel=image.getPixel(i,j);

            //calculating the distance from the current pixel to the center
            int disx=labs(i-centerX);
            int disy=labs(j-centerY);
            double dist=sqrt(pow(disx,2)+pow(disy,2));

            if(dist>160){
                pixel.l=pixel.l*0.2;
            }
            else{
                pixel.l=pixel.l+(1-(0.005*dist));
            }
        }
    }
    return image;
}
/*The hue of every pixel is set to the a hue value of either orange or
blue, based on if the pixel's hue value is closer to orange than blue.*/
PNG illinify(PNG image){
    int orange=11;
    int blue=216;
    for(unsigned i=0;i<image.width();i++){
        for(unsigned j=0;j<image.height();j++){
            HSLAPixel & pixel=image.getPixel(i,j);

            int max=360;

            int orangeDistance=std::abs(pixel.h-orange);
            orangeDistance=orangeDistance<max/2?orangeDistance:max-orangeDistance;

            int blueDistance=std::abs(pixel.h-blue);
            blueDistance=blueDistance<max/2?blueDistance:max-blueDistance;

            pixel.h=(orangeDistance<blueDistance)?orange:blue;
        }
    }
    return image;
}
/*The luminance of every pixel of the second image is checked, if that
pixel's luminance is 1 (100%), then the pixel at the same location on
the first image has its luminance increased by 0.2.*/
PNG watermark(PNG firstImage, PNG secondImage){
    unsigned secondImageWidth=secondImage.width();
    unsigned secondImageHeight=secondImage.height();

    for(unsigned i=0;i<firstImage.width();i++){
        for(unsigned j=0;j<firstImage.height();j++){
            HSLAPixel & pixel=firstImage.getPixel(i,j);
            if(i<secondImageWidth && j<secondImageHeight){
                HSLAPixel & secondpixel=secondImage.getPixel(i,j);
                if(secondpixel.l==1){
                    pixel.l=pixel.l<0.8?pixel.l+0.2:1.0;
                }
            }
        }
    }
    return firstImage;
}