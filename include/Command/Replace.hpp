#ifndef PROJECT_REPLACE_HPP
#define PROJECT_REPLACE_HPP

#include "Command.hpp"
#include "string"

namespace prog
{
    namespace command
    {
        class Replace : public Command
        {
        public:
            Replace(Color color1, Color color2);

            ~Replace();

            Image *apply(Image *img) override;

            std::string toString() const override;

        private:
            Color color1_;
            Color color2_;
        };
    }
}
#endif // PROJECT_REPLACE_HPP