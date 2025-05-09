//
// Created by JBispo on 05/04/2025.
//
#include "ScrimParser.hpp"

#include "Command/Blank.hpp"
#include "Command/Save.hpp"
#include "Command/Open.hpp"
#include "Command/Invert.hpp"
#include "Command/ToGrayScale.hpp"
#include "Command/Replace.hpp"
#include "Command/Fill.hpp"
#include "Command/HMirror.hpp"
#include "Command/VMirror.hpp"
#include "Command/Add.hpp"
#include "Command/Move.hpp"
#include "Command/Slide.hpp"
#include "Command/Crop.hpp"
#include "Command/Resize.hpp"
#include "Command/RotateLeft.hpp"
#include "Command/RotateRight.hpp"
#include "Command/Scaleup.hpp"
#include "Command/Chain.hpp"
#include "Logger.hpp"

#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>

using std::ifstream;
using std::istream;
using std::string;
using std::vector;

namespace prog {
    ScrimParser::ScrimParser(bool chaining) : chaining_(chaining) {
    };

    ScrimParser::~ScrimParser() {
    };


    Scrim *ScrimParser::parseScrim(std::istream &input) {
        // Create vector where commands will be stored
        vector<Command *> commands;

        // Parse commands while there is input in the stream
        string command_name;
        while (input >> command_name) {
            // If chaining scrims ignore saves/discards
            if (chaining_ && (command_name == "save" || command_name == "open" || command_name == "blank")) { continue; }
            
            Command *command = parse_command(command_name, input);

            if (command == nullptr) {
                // Deallocate already allocated commands
                for (Command *allocated_command: commands) {
                    delete allocated_command;
                }


                *Logger::err() << "Error while parsing command\n";
                return nullptr;
            }

            commands.push_back(command);
        }

        // Create a new image pipeline
        return new Scrim(commands);
    }


    Scrim *ScrimParser::parseScrim(const std::string &filename) {
        ifstream in(filename);
        return parseScrim(in);
    }

    Command *ScrimParser::parse_command(string command_name, istream &input) {
        if (command_name == "blank") {
            // Read information for Blank command
            int w, h;
            Color fill;
            input >> w >> h >> fill;
            return new command::Blank(w, h, fill);
        }

        if (command_name == "save") {
            // Read information for Save command
            string filename;
            input >> filename;
            return new command::Save(filename);
        }

        if (command_name == "open") {
            string filename;
            input >> filename;
            return new command::Open(filename);
        }

        if (command_name == "invert") {
            return new command::Invert();
        }

        if (command_name == "to_gray_scale") {
            return new command::ToGrayScale();
        }

        if (command_name == "replace") {
            // Read information for replace command
            Color color1, color2;
            input >> color1 >> color2;
            return new command::Replace(color1, color2);
        }

        if (command_name == "fill") {
            // Read information for fill command
            int x, y, w, h;
            Color filling_color;
            input >> x >> y >> w >> h >> filling_color;
            return new command::Fill(x, y, w, h, filling_color);
        }

        if (command_name == "h_mirror") {
            return new command::HMirror();
        }

        if (command_name == "v_mirror") {
            return new command::VMirror();
        }

        if (command_name == "add") {
            // Read information for add command
            string filename_;
            Color neutral_color;
            int x = 0, y = 0;
            input >> filename_ >> neutral_color >> x >> y;
            return new command::Add(filename_, neutral_color, x, y);
        }
        
        if (command_name == "move") {
            // Read information for move command
            int x = 0, y = 0;
            input >> x >> y;
            return new command::Move(x, y);
        }

        if (command_name == "slide") {
            // Read information for slide command
            int x = 0, y = 0;
            input >> x >> y;
            return new command::Slide(x, y);
        }

        if (command_name == "crop") {
            // Read information for crop command
            int x, y, w, h;
            input >> x >> y >> w >> h;
            return new command::Crop(x, y, w, h);
        }

        if (command_name == "resize") {
            int x, y, w, h;
            input >> x >> y >> w >> h;
            return new command::Resize(x, y, w, h);
        }

        if (command_name == "rotate_left") {
            return new command::RotateLeft();
        }

        if (command_name == "rotate_right") {
            return new command::RotateRight();
        }

        if (command_name == "scaleup") {
            int x, y;
            input >> x >> y;
            return new command::Scaleup(x, y);
        }
        
        if (command_name == "chain") {
            vector<string> scrims;
            string current;
            while (input >> current) {
                scrims.push_back(current);
                if (current == "end") {
                    break;
                }
            }
            return new command::Chain(scrims);
        }

        *Logger::err() << "Command not recognized: '" + command_name + "'\n";
        return nullptr;
    }
}
