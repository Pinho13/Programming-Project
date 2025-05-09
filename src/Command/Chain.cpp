#include "Command/Chain.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <sstream>
#include "ScrimParser.hpp"
#include "Scrim.hpp"

namespace prog {

    namespace command {

        Chain::Chain(vector<string> scrims) : Command("Chain"), scrims_(scrims) {}

        Chain::~Chain() {};

        Image *Chain::apply(Image *img) {

            // Create parser
            ScrimParser parser(true);

            // Cycle through each scrim
            for (string i : scrims_) {
                Scrim *temp = parser.parseScrim(i);
                // Check if pointer isn't null
                if (temp != nullptr) {
                    // Run Commands
                    img = temp->run(img);
                }
                // Delete temporary variable
                delete temp;
            }

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