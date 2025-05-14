#ifndef PROJECT_CHAIN_HPP
#define PROJECT_CHAIN_HPP

#include "Command.hpp"
#include "Color.hpp"
#include <vector>
#include <string>
#include <algorithm>

using std::string;
using std::vector;

namespace prog
{
    namespace command
    {
        class Chain : public Command
        {
        public:
            Chain(vector<string> scrims);

            ~Chain();

            Image *apply(Image *img) override;

            Image *apply(Image *img, vector<string> usedScrims);

            std::string toString() const override;

        private:
            vector<string> scrims_;
            vector<string> usedScrims_;
            Image *run(Image *img, vector<Command *> commands);
        };
    }
}
#endif // PROJECT_CHAIN_HPP