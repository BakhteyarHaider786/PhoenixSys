#include <ftxui/component/component.hpp>
#include "login_ui.h"

string LoginUI::getUsername() {
    return username;
}

string LoginUI::getPassword() {
    return password;
}

void LoginUI::show(ScreenInteractive &screen) {
    Component input_username = Input(&username, "enter your username");

    InputOption password_option;
    password_option.password = true;
    Component input_password = Input(&password, "enter your password", password_option);

    Component exit_button = Button("  Exit  ", [] { exit(EXIT_SUCCESS); });
    Component login_button = Button("  Login  ", screen.ExitLoopClosure());

    auto component = Container::Vertical({
                                                 input_username,
                                                 input_password,
                                                 login_button,
                                                 exit_button
                                         });

    auto view = Renderer(component, [&] {
        return window(text(" Phoenix Systems ") | hcenter | bold, vbox({
                            text(" Enter Login Credentials ") | center | color(Color::Red),
                            separator(),
                            filler(),
                            hbox(text(" Username") | color(Color::Green), text(" : "), input_username->Render()),
                            filler(),
                            hbox(text(" Password") | color(Color::Green), text(" : "), input_password->Render()),
                            filler(),
                            hbox({  text(" "), login_button->Render() | center | color(Color::Blue),
                                   filler(),
                                 exit_button->Render() | center | color(Color::Red), text(" ") })
                    }) | size(ftxui::WIDTH, ftxui::EQUAL, 40) | size(ftxui::HEIGHT, ftxui::EQUAL, 10) |
               border | center);
    });

    screen.Loop(view);
}
