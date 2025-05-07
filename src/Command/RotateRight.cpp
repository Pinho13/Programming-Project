#include "Command/RotateRight.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <sstream>

namespace prog {

    namespace command {

        RotateRight::RotateRight() : Command("RotateRight") {}

        RotateRight::~RotateRight() {};
        
        Image *RotateRight::apply(Image *img){

            // Creates a new image with the given dimensions
            Image *new_img =  new Image(img->height(), img->width());
            // Cycles throught each pixel of the new image
            for(int i = 0; i < img->width(); i++) {
                for(int j = 0; j < img->height(); j++) {
                    // Gets the pixels with rotated coords in the same order as the normal coords
                    Color &c_ = new_img->at(img->height() - 1 - j, i);
                    // Turns the pixel into the corresponding one of the old image
                    c_ = img->at(i, j);
                }
            }
            delete img;
            return new_img;
        }
        std::string RotateRight::toString() const {
            std::ostringstream ss;
            ss << name();
            return ss.str();
        }

    }
}