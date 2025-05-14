#include "Command/Slide.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <sstream>

namespace prog
{
    namespace command
    {

        Slide::Slide(int x, int y) : Command("slide"), x_(x), y_(y) {}

        Slide::~Slide() {};

        Image *Slide::apply(Image *img)
        {
            // Slide to the right
            for (int i = 0; i < img->width(); i++)
            {
                for (int j = 0; j < img->height(); j++)
                {
                    Color &c_ = img->at(i, j);
                    // Check if the pixels accessed are within boundaries
                    if (i + x_ < img->width())
                    {
                        Color &new_c = img->at(i + x_, j);
                        Color temp = new_c;
                        new_c = c_;
                        c_ = temp;
                    }
                }
            }

            // Slide down
            for (int i = 0; i < img->width(); i++)
            {
                for (int j = 0; j < img->height(); j++)
                {
                    Color &c_ = img->at(i, j);
                    // Check if the pixels accessed are within boundaries
                    if (j + y_ < img->height())
                    {
                        Color &new_c = img->at(i, j + y_);
                        Color temp = new_c;
                        new_c = c_;
                        c_ = temp;
                    }
                }
            }

            return img;
        }

        std::string Slide::toString() const
        {
            std::ostringstream ss;
            ss << name() << " x:" << x_ << " y:" << y_;
            return ss.str();
        }
    }
}