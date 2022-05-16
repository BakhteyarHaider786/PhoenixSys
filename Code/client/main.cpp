#include "../common/misc/exit_handler.h"
#include "../common/misc/signal_handler.h"

#include "ftxui/dom/node.hpp"  // for Render
#include "ftxui/screen/color.hpp"  // for Color, Color::Blue, Color::Cyan, Color::White, ftxui

int main(int argc, const char* argv[]) {
    SignalHandler::registerHandler();
    ExitHandler::registerHandler();


    return 0;
}