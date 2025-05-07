#ifndef PROJECT_ROTATERIGHT_HPP
#define PROJECT_ROTATERIGHT_HPP

#include "Command.hpp"
#include <string>

namespace prog {
    namespace command {
        class RotateRight : public Command {
            public:
                RotateRight();

                ~RotateRight();

                Image *apply(Image *img) override;

                std::string toString() const override;
        };
    }
}

#endif