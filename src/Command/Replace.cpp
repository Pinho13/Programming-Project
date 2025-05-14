#include "Command/Replace.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <sstream>

namespace prog {

    namespace command {
        
        Replace::Replace(Color color1, Color color2) : Command("Replace") , color1_(color1), color2_(color2) {}

        Replace::~Replace() {};

        Image *Replace::apply(Image *img) {

            // Cycles throught each pixel
            for(int i = 0; i < img->width(); i++) {
                for(int j = 0; j < img->height(); j++) {
                    // Turns all color1 pixels to color2 
                    Color &c_ = img->at(i, j);
                    if (c_.red() == color1_.red() && c_.green() == color1_.green() && c_.blue() == color1_.blue()) {
                        c_ = color2_;
                    }
                }
            }

            return img;
        }

        std::string Replace::toString() const {
            std::ostringstream ss;
            ss << name() << " color1:" << color1_ << " color2:" << color2_;
            return ss.str();
        }
    }
}

