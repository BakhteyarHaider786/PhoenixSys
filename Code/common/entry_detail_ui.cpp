#include <ftxui/component/component.hpp>
#include "entry_detail_ui.h"
#include "qr_code_gen.h"

void EntryDetailUI::show(ScreenInteractive &screen, entry_t entry) {

    Component back_button = Button("  Back  ", screen.ExitLoopClosure());
    Component qr_button = Button("  QR  ", [&] {
        QrCodeGen::saveToFile(entry);
    });

    char format[] = " Details of ID - 000 ";
    sprintf(format, " Details of ID - %d ", entry.id);

    auto container = Container::Horizontal({
        back_button, qr_button
    });

    auto view = Renderer(container, [&] {
        return window(text(" Phoenix Systems ") | hcenter | bold, vbox({
                                                                                text(format) | center | color(Color::Red),
                                                                                separator(),
                                                                                hbox(text(" NID   ") | color(Color::Green), text(" : "), text(entry.nid)),
                                                                                separator(),
                                                                                hbox(text(" AREA  ") | color(Color::Green), text(" : "), text(entry.area)),
                                                                                separator(),
                                                                                hbox(text(" CLASS ") | color(Color::Green), text(" : "), text(entry.category)),
                                                                                separator(),
                                                                                hbox(text(" NUMBER") | color(Color::Green), text(" : "), text(entry.number)),
                                                                                separator(),
                                                                                hbox({text(" "), back_button->Render(), filler(), qr_button->Render(), text(" ")})
                                                                        }) | size(ftxui::WIDTH, ftxui::EQUAL, 40) | size(ftxui::HEIGHT, ftxui::EQUAL, 13) |
                                                                   border | center);
    });

    screen.Loop(view);
}

