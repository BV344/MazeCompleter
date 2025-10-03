#include <iostream>
#include "CImg.h"

using namespace cimg_library;

int main() {
    CImg<unsigned char> img("input.bmp");

    //Convert to GrayScale
    CImg<unsigned char> gray = img.get_RGBtoYCbCr().channel(0);
    gray.threshold(127);

    // Force to RGB for compatibility
    CImg<unsigned char> rgbGray = gray.get_normalize(0,255).resize(-100,-100,1,3);

    //Saving for Debugging Purposes
    rgbGray.save("output_grayscale.bmp");

    img = rgbGray;

    img(100,100,0,0) = 255;


    img.display("RGBGRAY");
    return 0;
}
