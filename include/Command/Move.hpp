#ifndef PROJECT_MOVE_HPP
#define PROJECT_MOVE_HPP

#include "Command.hpp"
#include <string>

namespace prog
{
    namespace command
    {
        class Move : public Command
        {
        public:
            Move(int x_, int y_);

            ~Move();

            Image *apply(Image *img) override;

            std::string toString() const override;

        private:
            int x_, y_;
        };
    }
}

#endif // PROJECT_MOVE_HPP