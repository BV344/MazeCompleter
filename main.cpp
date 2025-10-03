#include <iostream>
#include "CImg.h"

using namespace cimg_library;
using namespace std;

void breadthFirstSearch(CImg<unsigned char> &inputImg) {
    int x = inputImg.width();
    int y = inputImg.height();

    cout << "X: " << x << " Y: " << y << endl;

    for (int i = 0; i < x/2; i++) {
        for (int j = 0; j < y/2; j++) {
            inputImg(i,j,0,0) = 255;


        }
    }
}

void bestFirstSearch(CImg<unsigned char> &inputImg) {}



int main() {
    CImg<unsigned char> img("input.bmp");

    //Convert to GrayScale
    CImg<unsigned char> gray = img.get_RGBtoYCbCr().channel(0);
    gray.threshold(127);

    // Force to RGB for compatibility
    CImg<unsigned char> rgbGray = gray.get_normalize(0,255).resize(-100,-100,1,3);

    //Saving for Debugging Purposes
    // rgbGray.save("output_grayscale.bmp");

    img = rgbGray;

    img(100,100,0,0) = 255;

    breadthFirstSearch(img);


    img.display("RGBGRAY");
    return 0;
}
