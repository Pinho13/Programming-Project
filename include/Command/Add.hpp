#ifndef PROJECT_ADD_HPP
#define PROJECT_ADD_HPP

#include "Command.hpp"
#include <string>

namespace prog {
    namespace command {
        class Add : public Command {
        public:
            Add(std::string filename_, Color neutral_color, int x, int y);

            ~Add();

            Image *apply(Image *img) override;

            std::string toString() const override;

        private:
            std::string filename_;
            Color neutral_color;
            int x, y;
        };
    }
}


#endif // PROJECT_ADD_HPP