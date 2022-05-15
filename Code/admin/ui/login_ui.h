#ifndef PHOENIXSYS_LOGIN_UI_H
#define PHOENIXSYS_LOGIN_UI_H

#include <ftxui/component/screen_interactive.hpp>
#include <string>

using namespace ftxui;
using std::string;

class LoginUI {
private:
    string username;
    string password;

public:
    void show(ScreenInteractive &screen);
    string getUsername();
    string getPassword();
};


#endif //PHOENIXSYS_LOGIN_UI_H
