#include "Command/ToGrayScale.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <sstream>

namespace prog {

    namespace command {

        ToGrayScale::ToGrayScale() : Command("to_gray_scale") {}

        ToGrayScale::~ToGrayScale() {};

        Image *ToGrayScale::apply(Image *img) {

            // Cycles throught each pixel
            for(int i = 0; i < img->width(); i++) {
                for(int j = 0; j < img->height(); j++) {
                    // Grays the colors
                    Color &c_ = img->at(i, j);
                    c_.red() = c_.green() = c_.blue() = (c_.red() + c_.green() + c_.blue()) / 3;
                }
            }
            
            return img;
        }


        std::string ToGrayScale::toString() const {
            std::ostringstream ss;
            ss << name();
            return ss.str();
        }

    }
}