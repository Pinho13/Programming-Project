#include "Command/Invert.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <sstream>

namespace prog
{

    namespace command
    {

        Invert::Invert() : Command("Invert") {}

        Invert::~Invert() {};

        Image *Invert::apply(Image *img)
        {

            // Cycles throught each pixel
            for (int i = 0; i < img->width(); i++)
            {
                for (int j = 0; j < img->height(); j++)
                {
                    // Inverts colors
                    Color &c_ = img->at(i, j);
                    c_.red() = 255 - c_.red();
                    c_.green() = 255 - c_.green();
                    c_.blue() = 255 - c_.blue();
                }
            }

            return img;
        }

        std::string Invert::toString() const
        {
            std::ostringstream ss;
            ss << name();
            return ss.str();
        }

    }
}