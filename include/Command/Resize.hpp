#ifndef PROJECT_RESIZE_HPP
#define PROJECT_RESIZE_HPP

#include "Command.hpp"
#include <string>

namespace prog {
    namespace command {
        class Resize : public Command {
            public:
                Resize(int x, int y, int w, int h);

                ~Resize();

                Image *apply(Image *img) override;

                std::string toString() const override;
                
            private:
                int x_, y_, w_, h_;
        };
    }
}


#endif // PROJECT_RESIZE_HPP