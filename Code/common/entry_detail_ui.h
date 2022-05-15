#ifndef PHOENIXSYS_ENTRY_DETAIL_UI_H
#define PHOENIXSYS_ENTRY_DETAIL_UI_H

#include "entry_struct.h"

#include <ftxui/component/screen_interactive.hpp>

using namespace ftxui;

class EntryDetailUI {
public:
    static void show(ScreenInteractive& screen, entry_t entry);
};


#endif //PHOENIXSYS_ENTRY_DETAIL_UI_H
