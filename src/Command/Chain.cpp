#include "Command/Chain.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include <sstream>
#include <algorithm>
#include "ScrimParser.hpp"
#include "Scrim.hpp"
#include "Logger.hpp"

namespace prog
{

    namespace command
    {

        Chain::Chain(vector<string> scrims) : Command("Chain"), scrims_(scrims) {}

        Chain::~Chain() {};

        Image *Chain::apply(Image *img)
        {

            // Create parser
            ScrimParser parser = ScrimParser();

            // Cycle through each scrim
            for (string i : scrims_)
            {
                // Avoid used scrims
                if (count(usedScrims_.begin(), usedScrims_.end(), i) > 0)
                {
                    continue;
                }
                // Create Scrim
                Scrim *temp = parser.parseScrim(i);

                // Check if pointer isn't null
                if (temp != nullptr)
                {
                    // Run Commands
                    img = run(img, temp->getCommands());
                }
                // Delete temp scrim
                delete temp;
            }

            return img;
        }

        Image *Chain::apply(Image *img, vector<string> usedScrims)
        {
            // Add used Scrims and apply
            usedScrims_.insert(usedScrims_.end(), usedScrims.begin(), usedScrims.end());
            return apply(img);
        }

        std::string Chain::toString() const
        {
            std::ostringstream ss;
            string result;
            for (string i : scrims_)
            {
                result += " " + i;
            }
            ss << name() << result;
            return ss.str();
        }

        Image *Chain::run(Image *img, vector<Command *> commands)
        {
            // Cycle through commands
            for (Command *c : commands)
            {
                // Skip save, open and blank commands
                if (c->name() == "Save" || c->name() == "Open" || c->name() == "Blank")
                {
                    continue;
                }
                else if (c->name() == "Chain")
                {
                    // Add usedScrims_ and scrims
                    vector<string> allScrims(usedScrims_);
                    allScrims.insert(allScrims.end(), scrims_.begin(), scrims_.end());
                    // Call apply from child
                    static_cast<Chain *>(c)->apply(img, allScrims);
                    continue;
                }
                *Logger::out() << "Applying command '" << c->toString() << "'\n";
                img = c->apply(img);
            }

            return img;
        }

    }
}