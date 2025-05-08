#ifndef PROJECT_SCALEUP_HPP
#define PROJECT_SCALEUP_HPP

#include "Command.hpp"
#include <string>

namespace prog {
    namespace command {
        class Scaleup : public Command {
        public:
            Scaleup(int x_factor, int y_factor);

            ~Scaleup();

            Image *apply(Image *img) override;

            std::string toString() const override;

        private:
            int x_factor_, y_factor_;
        };
    }
}

#endif // PROJECT_SCALEUP_HPP