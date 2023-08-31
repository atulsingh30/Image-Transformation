#pragma once

#include<cmath>

namespace uiuc{
    typedef struct{
        unsigned  char r, g, b, a; //[0,255]
    } rgbaColor;
    /*unsigned char can store upto a range of 0 to 255, which aligns with the
    representation of the color component values- red, green, blue, alpha*/
    /*aplha represents transparency 0 means complete transparency and 255 means
    completey opacity*/

    typedef struct{
        double h; // angle ranging from 0 to 360
        double s; //[0,1]
        double l; //[0,1]
        double a; //[0,1]
    } hslaColor;

    //converting rgb to hsla
    static hslaColor rgb2hsl(rgbaColor rgb){
        hslaColor hsl;
        double r, g, b, min, max, chroma;

        //Changing rgb to [0,1]
        r=rgb.r/255.0;
        g=rgb.g/255.0;
        b=rgb.b/255.0;

        //HSV Calculations- formula from geeksforgeeks site
        min=(r<g)?r:g;
        min=(min<b)?min:b;

        max=(r>g)?r:g;
        max=(max>b)?max:b;

        chroma=max-min;

        //Comoute A
        hsl.a= rgb.a/255.0;

        //Compute L
        hsl.l=0.5*(max+min);

        /*This is check to avoid zero division errors.*/
        /*L controls white, black and shades of grey, when chroma==0, h is undefined
        and s is always zero this will become true.*/
        if(chroma<0.0001 || max<0.0001){
            hsl.h=hsl.s=0;
            return hsl;
        }

        //Compute S
        hsl.s=chroma/(1-fabs((2*hsl.l)-1));

        //Compute H
        if(max==r){
            hsl.h=fmod((g-b)/chroma,6);
        }
        else if(max==g){
            hsl.h=((b-r)/chroma)+2;
        }
        else{
            hsl.h=((r-g)/chroma)+4;
        }
        hsl.h*=60;
        if(hsl.h<0){
            hsl.h+=360;
        }
        return hsl;
    }

    //converting hsla to rgb
    static rgbaColor hsl2rgb(hslaColor hsl){
        rgbaColor rgb;
        if(hsl.s<=0.001){
            rgb.r=rgb.g=rgb.b=round(hsl.l*255);
        }
        else{
            double c=(1-fabs((2*hsl.l)-1))*hsl.s;
            double hh=hsl.h/60;
            double x=c*(1-fabs(fmod(hh,2)-1));
            double r,g,b;

            if(hh<=1){
                r=c;
                g=x;
                b=0;
            }
            else if(hh<=2){
                r=x;
                g=c;
                b=0;
            }
            else if(hh<=3){
                r=0;
                g=c;
                b=x;
            }
            else if(hh<=4){
                r=0;
                g=x;
                b=c;
            }
            else if(hh<=5){
                r=x;
                g=0;
                b=c;
            }
            else{
                r=c;
                g=0;
                b=x;
            }

            double m=hsl.l-(0.5*c);
            rgb.r=round((r+m)*255);
            rgb.g=round((g+m)*255);
            rgb.b=round((b+m)*255);
        }

        rgb.a=round(hsl.a*255);
        return rgb;
    }
}