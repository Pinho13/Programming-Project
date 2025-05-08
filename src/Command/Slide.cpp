#include "Command/Slide.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <sstream>

namespace prog {
    namespace command {

        Slide::Slide(int x, int y) : Command("slide"), x_(x), y_(y) {}

        Slide::~Slide() {};

        Image *Slide::apply(Image *img) {
            // Cycle through each pixel
            for (int i = 0; i < img->width(); i++) {
                for (int j = 0; j < img->height(); j++) {
                    Color& c_ = img->at(i, j);
                    // Check if the current new pixel is within boundaries
                    if (i + x_ < img->width() && j + y_ < img->height()) {
                        Color& new_c = img->at(i + x_, j + y_);
                        Color temp = new_c;
                        new_c = c_;
                        c_ = temp;
                    }
                    // Fix pixels that should be white
                    if ((x_ && y_) && ((i < x_ && j >= y_) || (j < y_ && i >= x_))) {
                        c_ = Color(255, 255, 255);
                    }
                }
            }

            return img;
        }

        std::string Slide::toString() const {
            std::ostringstream ss;
            ss << name() << " x:" << x_ << " y:" << y_;
            return ss.str();
        }
    }
}