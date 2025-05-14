#include "Command/Resize.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <sstream>

namespace prog
{

    namespace command
    {

        Resize::Resize(int x, int y, int w, int h) : Command("Resize"), x_(x), y_(y), w_(w), h_(h) {}

        Resize::~Resize() {};

        Image *Resize::apply(Image *img)
        {

            // Creates a new image with the given dimensions
            Image *new_img = new Image(w_, h_);
            // Cycles throught each pixel of the new image
            for (int i = 0; i < w_; i++)
            {
                for (int j = 0; j < h_; j++)
                {
                    // Avoids offbounds access
                    if (img->width() <= i + x_ || img->height() <= j + y_)
                    {
                        break;
                    }
                    // Turns the pixel into the corresponding one of the old image
                    Color &c_ = new_img->at(i, j);
                    c_ = img->at(i + x_, j + y_);
                }
            }

            // Dispose of given image
            delete img;
            return new_img;
        }

        std::string Resize::toString() const
        {
            std::ostringstream ss;
            ss << name() << " x:" << x_ << " y:" << y_ << " w:" << w_ << " h:" << h_;
            return ss.str();
        }

    }
}