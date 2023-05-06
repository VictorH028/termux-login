#ifndef PASS_WIN
#define PASS_WIN

#include <fstream>
#include <json/json.h>
#include <filesystem>
////////////////////
#include <string.h>
#include <cstdlib>
#include <ncurses.h>
#include <menu.h>


#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[10]))

namespace conf {
    class config{// ---> ~/.termux_login_conf.json
        void get_config(const char *file_name){
            Json::Value root;
            std::ifstream file(file_name);
        };

    };
}


namespace pass_win {
    class pass_win{
        public:
        // items
            int n_choices{};
            int i{};

            int height{};
            int width{};
            int startx{};
            int starty{};

            ITEM **  create_element_itms(int n_choices,const char *choices[],const char *menu_icon[]);
            WINDOW *  create_win_menu(int height, int width, int starty, int startx);
            void win_main_subwin(MENU *my_menu,WINDOW *my_menu_win,const char *brand_menu);
            void print_in_middle(WINDOW *win, int starty, int startx, int width, char const *string, chtype color);
       
            pass_win();// --> Inicializa curses 
            ~pass_win();
    };
}
#endif 
