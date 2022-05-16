#include "../common/misc/exit_handler.h"
#include "../common/misc/signal_handler.h"
#include "../common/storage/storage.h"
#include "../lib/qr/qrcodegen.hpp"
#include "ui/login_ui.h"
#include "ui/incorrect_access_ui.h"
#include "ui/dashboard_ui.h"

#include <iostream>
#include <thread>
#include <ftxui/component/screen_interactive.hpp>

using namespace ftxui;
using std::cout;
using std::endl;

static std::uint64_t counter = 0;

#define STORAGE_NAME "storage.data"

int main() {
    SignalHandler::registerHandler();
    ExitHandler::registerHandler();
    ExitHandler::addFunction([=] {
        system("cls");
        std::cout << "Total Run : " << counter << std::endl;
    });

    auto screen = ScreenInteractive::Fullscreen();

   LoginUI login_ui;
   login_ui.show(screen);

   if (login_ui.getUsername() != "admin" || login_ui.getPassword() != "admin") {
       IncorrectAccessUI::show(screen);
   }

    Storage storage(STORAGE_NAME);
    DashboardUI::show(screen, storage);

    return 0;
}
