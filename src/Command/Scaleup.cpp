#include "Command/Scaleup.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <sstream>

namespace prog {

    namespace command {

        Scaleup::Scaleup(int x_factor, int y_factor) : Command("Scaleup"), x_factor_(x_factor), y_factor_(y_factor) {}

        Scaleup::~Scaleup() {};

        Image *Scaleup::apply(Image *img) {

            // Creates a new image considering the scaling factors
            Image *new_img =  new Image{img->width() * x_factor_, img->height() * y_factor_};
            // // Cycles through each pixel of the old image
            for(int i = 0; i < img->width(); i++) {
                for(int j = 0; j < img->height(); j++) {
                    Color c_ = img->at(i, j);
                    // Fills the new image with the scaled up pixels of the old image
                    for (int k = i * x_factor_; k < i * x_factor_ + x_factor_; k++) {
                        for (int l = j * y_factor_; l < j * y_factor_ + y_factor_; l++) {
                            Color &new_c_ = new_img->at(k, l);
                            new_c_ = c_;
                        }
                    }
                }
            }
            delete img;
            return new_img;
        }

        std::string Scaleup::toString() const {
            std::ostringstream ss;
            ss << name() << " x:" << x_factor_ << " y:" << y_factor_;
            return ss.str();
        }
    }
}