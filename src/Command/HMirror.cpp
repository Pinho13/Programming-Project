#include "Command/HMirror.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <sstream>

namespace prog {
    namespace command {

        HMirror::HMirror() : Command("HMirror") {}

        HMirror::~HMirror() {};

        Image *HMirror::apply(Image *img) {

            // Switch pixels horizontally
            for (int i = 0; i < img->width() / 2; i++) {
                for (int j = 0; j < img->height(); j++) {
                    Color &c_ = img->at(i, j);
                    Color temp = img->at(img->width() - 1 - i, j);
                    img->at(img->width() - 1 - i, j) = c_;
                    c_ = temp;
                }
            }

            return img;
        }


        std::string HMirror::toString() const {
            std::ostringstream ss;
            ss << name();
            return ss.str();
        }
    }
}
