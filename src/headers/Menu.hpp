//
// Created by alex on 9/4/26.
//

#ifndef PONG_CPP_MENU_HPP
#define PONG_CPP_MENU_HPP

#include <string>

class Menu {
    const std::string title;
    const std::string subtitle;

public:
    Menu(const std::string &title, const std::string &subtitle);

    void Draw() const;

};


#endif //PONG_CPP_MENU_HPP
