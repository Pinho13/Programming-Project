#ifndef PROJECT_FILL_HPP
#define PROJECT_FILL_HPP

#include "Command.hpp"
#include "string"

namespace prog
{
    namespace command
    {
        class Fill : public Command
        {
        public:
            Fill(int x, int y, int w, int h, Color &filling_color);

            ~Fill();

            Image *apply(Image *img) override;

            std::string toString() const override;

        private:
            int x, y, w, h;
            Color filling_color;
        };
    }
}
#endif // PROJECT_FILL_HPP