#include "Command/Chain.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <sstream>
#include "ScrimParser.hpp"
#include "Scrim.hpp"

namespace prog {

    namespace command {

        Chain::Chain(vector<string> scrims, vector<string> usedScrims) : Command("Chain"), scrims_(scrims), usedScrims_(usedScrims) {}

        Chain::~Chain() {};

        Image *Chain::apply(Image *img) {

            // Add usedScrims_ and scrims
            vector<string> usedScrims(usedScrims_);
            usedScrims.insert(usedScrims.end(), scrims_.begin(), scrims_.end());

            // Create parser
            ScrimParser parser(true, usedScrims);

            // Cycle through each scrim
            for (string i : scrims_) {
                // Avoid used scrims
                if (count(usedScrims_.begin(), usedScrims_.end(), i) > 0) { continue; }
                // Create Scrim
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