#include "Command/VMirror.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <sstream>

namespace prog {
    namespace command {

        VMirror::VMirror() : Command("VMirror") {}

        VMirror::~VMirror() {};

        Image *VMirror::apply(Image *img) {

            // Switch pixels vertically
            for (int i = 0; i < img->width(); i++) {
                for (int j = 0; j < img->height() / 2; j++) {
                    Color &c_ = img->at(i, j);
                    Color temp = img->at(i, img->height() - 1 - j);
                    img->at(i, img->height() - 1 - j) = c_;
                    c_ = temp;
                }
            }

            return img;
        }

        std::string VMirror::toString() const {
            std::ostringstream ss;
            ss << name();
            return ss.str();
        }
    }
}