#include "Command/Crop.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <sstream>

namespace prog {

    namespace command {

        Crop::Crop(int x, int y, int w, int h): Command("Crop"), x_(x), y_(y), w_(w), h_(h) {}

        Crop::~Crop() {};
        
        Image *Crop::apply(Image *img){

            // Creates a new image with the given dimensions
            Image *new_img =  new Image{w_, h_};
            // Cycles throught each pixel of the new image
            for(int i = 0; i < w_; i++) {
                for(int j = 0; j < h_; j++) {
                    // Turns the pixel into the corresponding one of the old image
                    Color &c_ = new_img->at(i, j);
                    c_ = img->at(i + x_, j + y_);
                }
            }
            delete img;
            return new_img;
        }
        std::string Crop::toString() const {
            std::ostringstream ss;
            ss << name() << " x:" << x_ << " y:" << y_ << " w:" << w_ << " h:" << h_;
            return ss.str();
        }

    }
}