#include "Command/Chain.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <sstream>

namespace prog {

    namespace command {

        Chain::Chain(vector<string> scrims) : Command("Chain"), scrims(scrims) {}

        Chain::~Chain() {};

        Image *Chain::apply(Image *img) {

            // TODO
        }


        std::string Chain::toString() const {
            std::ostringstream ss;
            string result;
            for(string i : scrims) {
                result += " " + i;
            }
            ss << name() << result;
            return ss.str();
        }

    }
}