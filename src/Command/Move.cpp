#include "Command/Move.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <sstream>

namespace prog {
    namespace command {

        Move::Move(int x, int y) : Command("Move"), x_(x), y_(y) {}

        Move::~Move() {};

        Image *Move::apply(Image *img) {
            // Cycle through each pixel
            for (int i = 0; i < img->width(); i++) {
                for (int j = 0; j < img->height(); j++) {
                    Color& c_ = img->at(i, j);
                    // Check if the current new pixel is within boundaries
                    if (i + x_ < img->width() && j + y_ < img->height()) {
                        Color& new_c = img->at(i + x_, j + y_);
                        new_c = c_;
                        c_ = Color(255, 255, 255);
                    }
                    // Fill every pixel that was not changed but now is now to up or to the left of (x_, y_)
                    if (i < x_ || j < y_) {
                        c_ = Color(255, 255, 255);
                    }
                }
            }

            return img;
        }

        std::string Move::toString() const {
            std::ostringstream ss;
            ss << name() << " x:" << x_ << " y:" << y_;
            return ss.str();
        }
    }
}