#include "Command/Chain.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <sstream>
#include <algorithm>
#include "ScrimParser.hpp"
#include "Scrim.hpp"
#include "Logger.hpp"

namespace prog {

    namespace command {

        Chain::Chain(vector<string> scrims, vector<string> usedScrims) : Command("Chain"), scrims_(scrims), usedScrims_(usedScrims) {}

        Chain::~Chain() {};

        Image *Chain::apply(Image *img) {

            // Add usedScrims_ and scrims
            vector<string> usedScrims(usedScrims_);
            usedScrims.insert(usedScrims.end(), scrims_.begin(), scrims_.end());

            // Create parser
            ScrimParser parser(usedScrims);

            // Cycle through each scrim
            for (string i : scrims_) {
                // Avoid used scrims
                if (count(usedScrims_.begin(), usedScrims_.end(), i) > 0) { continue; }
                // Create Scrim
                Scrim *temp = parser.parseScrim(i);
                
                // Check if pointer isn't null
                if (temp != nullptr) {
                    // Run Commands
                    img = run(img, temp->getCommands());
                }
                // Delete temp scrim
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

        Image *Chain::run(Image *img, vector<Command *> commands) {
            for (Command *c: commands) {
                // Skip save, open and blank commands
                if (c->name() == "Save" || c->name() == "Open" || c->name() == "Blank") { continue; }
                *Logger::out() << "Applying command '" << c->toString() << "'\n";
                img = c->apply(img);
            }

            return img;
        }

    }
}