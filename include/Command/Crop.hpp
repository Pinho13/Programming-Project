#ifndef PROJECT_CROP_HPP
#define PROJECT_CROP_HPP

#include "Command.hpp"
#include <string>

namespace prog {
    namespace command {
        class Crop : public Command {
        public:
            Crop(int x, int y, int w, int h);

            ~Crop();

            Image *apply(Image *img) override;

            std::string toString() const override;
            
        private:
            int x_, y_, w_, h_;
        };
    }
}

#endif // PROJECT_CROP_HPP