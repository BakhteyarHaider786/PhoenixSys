//
// Created by Haider on 5/16/2022.
//

#include <ftxui/dom/elements.hpp>
#include <ftxui/dom/table.hpp>
#include <ftxui/component/component.hpp>
#include "list_ui.h"
#include "id_entry_ui.h"
#include "../../common/entry_detail_ui.h"

using namespace ftxui;
using std::vector;
using std::string;

int jump = 8;

void ListUI::show(ScreenInteractive &screen, Storage& storage, int start) {
    auto entries = storage.all();

    vector<vector<string>> table_entries;

    bool next, back;

    Component next_page = Button(" > ", [&] {
        if (next) {
            screen.ExitLoopClosure();
            ListUI::show(screen, storage, start + jump);
        }
    });
    Component back_page = Button(" < ", [&] {
        if (back) {
            screen.ExitLoopClosure();
            ListUI::show(screen, storage, start - jump);
        }
    });
    Component view_button = Button("  View  ", [&] {
        int id;
        IdEntryUI::show(screen, id);
        int index = storage.findById(id);
        auto entry = storage.getByIndex(index);
        EntryDetailUI::show(screen, entry);
    });
    Component add_button = Button("  Add  ", screen.ExitLoopClosure());
    Component delete_button = Button("  Delete  ", [&] {
        int id;
        IdEntryUI::show(screen, id);
        storage.removeById(id);
    });
    Component exit_button = Button("  Exit  ", [] { exit(EXIT_SUCCESS); });
;
    vector<string> header;
    header.emplace_back("   ID   ");
    header.emplace_back("      NID      ");
    header.emplace_back("      AREA      ");
    header.emplace_back("      CATEGORY    ");
    header.emplace_back("      NUMBER      ");
    table_entries.push_back(header);
    int end = start;
    if (start == 0) {
        back = false;
    } else {
        back = true;
    }
    if (end + jump <= entries.size()) {
        end = end + jump;
        next = true;
    } else {
        end = entries.size();
        next = false;
    }
    for (int i = start; i < end; i++) {
        auto entry = entries[i];
        vector<string> vec;
        vec.emplace_back(std::to_string(entry.id));
        vec.emplace_back(entry.nid);
        vec.emplace_back(entry.area);
        vec.emplace_back(entry.category);
        vec.emplace_back(entry.number);
        table_entries.push_back(vec);
    }

    if (end + 1 > entries.size()) {
        next = false;
    } else {
        true;
    }

    auto table = Table({
        table_entries,
    });

    table.SelectAll().Border(LIGHT);
    table.SelectAll().Separator(LIGHT);

    table.SelectAll().DecorateCells(center);

    auto document = table.Render();

    auto component = Container::Horizontal({ back_page, next_page, view_button, add_button, delete_button, exit_button });
    auto view = Renderer(component, [&] {
        return window(text(" Phoenix Systems ") | hcenter | bold, vbox({
            text(" All Entries - " + std::to_string(start + 1) + " to " + std::to_string(end)) | center | color(Color::Green),
            separator(),
            document,
            hbox({ back_page->Render(), next_page->Render(), filler(),
                   view_button->Render(), filler(),
                   add_button->Render(), filler(),
                   delete_button->Render(), filler(),
                   exit_button->Render() }),

        }) | border | center);
    });

    screen.Loop(view);
}
