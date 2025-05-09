#include "Command/Chain.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <sstream>

namespace prog {

    namespace command {

        Chain::Chain(vector<string> scrims) : Command("Chain"), scrims_(scrims) {}

        Chain::~Chain() {};

        Image *Chain::apply(Image *img) {

            // TODO
            return img;
        }


        std::string Chain::toString() const {
            std::ostringstream ss;
            string result;
            for(string i : scrims_) {
                result += " " + i;
            }
            ss << name() << result;
            return ss.str();
        }

    }
}