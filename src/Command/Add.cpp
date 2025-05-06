#include "Command/Add.hpp"
#include "Command/Open.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <sstream>

namespace prog {
    namespace command {

        Add::Add(std::string filename_, Color neutral_color, int x, int y) : Command("add"), filename_(filename_), neutral_color(neutral_color), x(x), y(y) {}

        Add::~Add() {};

        Image *Add::apply(Image *img) {
            // create instance of Open()
            prog::command::Open open_object(filename_);

            // open PNG image provided
            Image *png_image = open_object.apply(nullptr);

            // copy the PNG image to the desired place
            for (int i = 0; i < img->width() && i < png_image->width(); i++) {
                for (int j = 0; j < img->height() && j < png_image->height(); j++) {
                    // Check if the current position is within boundaries
                    if (i + x < img->width() && j + y < img->height())
                    {
                        Color& c_png = png_image->at(i, j);
                        // Check if the currennt color from the PNG image is not neutral
                        if (!(c_png.red() == neutral_color.red() && c_png.green() == neutral_color.green() && c_png.blue() == neutral_color.blue()))
                        {
                            Color& c_ = img->at(i + x, j + y);
                            c_ = png_image->at(i, j);
                        }
                    }
                }
            }

            delete png_image;
            return img;
        }

        std::string Add::toString() const {
            std::ostringstream ss;
            ss << name() << " filename:" << filename_ << " neutral_color:" << neutral_color << " x:" << x << " y:" << y;
            return ss.str();
        }
    }
}