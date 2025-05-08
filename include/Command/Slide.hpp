#ifndef PROJECT_SLIDE_HPP
#define PROJECT_SLIDE_HPP

#include "Command.hpp"
#include <string>

namespace prog {
    namespace command {
        class Slide : public Command {
        public:
            Slide(int x_, int y_);

            ~Slide();

            Image *apply(Image *img) override;

            std::string toString() const override;

        private:
            int x_, y_;
        };
    }
}

#endif // PROJECT_SLIDE_HPP