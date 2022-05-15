//
// Created by Haider on 5/16/2022.
//

#ifndef PHOENIXSYS_LIST_UI_H
#define PHOENIXSYS_LIST_UI_H

#include "../../common/entry_struct.h"
#include "../../common/storage.h"
#include <vector>
#include <ftxui/component/screen_interactive.hpp>

class ListUI {
public:
    static void show(ftxui::ScreenInteractive &screen, Storage& storage, int start = 0);
};


#endif //PHOENIXSYS_LIST_UI_H
