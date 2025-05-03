#include "Command/Fill.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <sstream>

namespace prog {

    namespace command {
        Fill::Fill(int x, int y, int w, int h,  Color& filling_color) : Command("fill"), x(x), y(y), w(w), h(h), filling_color(filling_color) {}

        Fill::~Fill() {};

        Image *Fill::apply(Image *img) {

            // Cycles throught each rectangle pixel
            for (int i = x; i < x + w; i++) {
                for (int j = y; j < y + h; j++) {
                    // Fill in the rectangle with the desired color
                    Color &c_ = img->at(i, j);
                    c_ = filling_color;
                }
            }
            
            return img;
        }


        std::string Fill::toString() const {
            std::ostringstream ss;
            ss << name() << " x:" << x << " y:" << y << " w:" << w << " h:" << h << " filling_color:" << filling_color;
            return ss.str();
        }

    }
}