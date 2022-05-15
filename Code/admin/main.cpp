#include "../common/exit_handler.h"
#include "../common/signal_handler.h"
#include "../common/storage.h"
#include "ui/login_ui.h"
#include "ui/incorrect_access_ui.h"
#include "ui/list_ui.h"
#include "../lib/qr/qrcodegen.hpp"

#include <iostream>
#include <thread>
#include <ftxui/component/screen_interactive.hpp>

using std::cout;
using std::endl;

static std::uint64_t counter = 0;

#define STORAGE_NAME "storage.data"

int main(int argc, char* argv[]) {
    SignalHandler::registerHandler();
    ExitHandler::registerHandler();

    ExitHandler::addFunction([=] {
        system("cls");
        std::cout << "Total Run : " << counter << std::endl;
    });

    auto screen = ScreenInteractive::Fullscreen();

    LoginUI login_ui;

    login_ui.show(screen);

    if (login_ui.getUsername() != "admin" || login_ui.getPassword() != "admin123") {
        IncorrectAccessUI incorrectAccessUi;
        incorrectAccessUi.show(screen);
    }

    Storage storage(STORAGE_NAME);
    ListUI::show(screen, storage);

    return 0;
}
