#ifndef PASS_WIN
#define PASS_WIN


#include <menu.h>
#include <ncurses.h>
#include <cstdlib>
//////////////////
#include <json/json.h>
#include <fstream>
#include <string>
#include <filesystem>

#define CONF "/data/data/com.termux/files/home/termux-login/config/conf.json"

namespace conf{
    class confing{
        public:
           const char *get_confing(std::string _conf){
           std::ifstream file(CONF);
           if (!file.is_open()) {
               endwin();
               exit(EXIT_FAILURE);
           }
           Json::Value  obj;
           Json::Reader reader;
           reader.parse(file, obj);
           return  obj[_conf].asCString();
        };
    };
}


namespace ps_w {
    class cre_menu : public conf::confing {//--> Herencia
        private:
           int nlines{};
           int ncols{};
           int begin_y{};
           int begin_x{};
        public:
        //Contructor   
        cre_menu(int _nlines, int _ncols,int _begin_y, int _begin_x ) {
            /* Inicializa curses */
            initscr();
            start_color();
            cbreak();
            noecho();
            keypad(stdscr, TRUE);
            init_pair(1, COLOR_RED, COLOR_BLACK);

            nlines  = _nlines;
            ncols   = _ncols;
            begin_y = _begin_y;
            begin_x = _begin_x;
        };
        //Detructor
        ~cre_menu() {
            endwin(); 
        };

       ITEM ** create_element_itms(int n_choices,const char *choices[],const char *menu_icon[],int i){
            ITEM ** my_items;
            my_items = (ITEM **)calloc(n_choices, sizeof(ITEM *));
           for ( i = 0; i < n_choices; ++i)
               my_items[i] = new_item(choices[i], menu_icon[i]);
           return my_items;
       };

      void win_main_subwin(MENU *my_menu,WINDOW *my_menu_win,const char *brand_menu){
           set_menu_win(my_menu,my_menu_win);
           set_menu_sub(my_menu, derwin(my_menu_win, 6, 38, 3, 1));
           //Marca del menu 
           set_menu_mark(my_menu, brand_menu);
      };
     void print_in_middle(WINDOW *win, int starty, int startx, int width,char const *string, chtype color){ 
           int length, x, y;
           float temp;
           
           if(win == NULL)
                win = stdscr;
           getyx(win, y, x);//Coordenadas de ventana
           if(startx != 0)
                x = startx;
           if(starty != 0)
                y = starty;
           if(width == 0)
                width = 80;

        length = strlen(string);
        temp = (width - length) / 2;
        x = startx + (int)temp;
        wattron(win, color);
        mvwprintw(win, y, x, "%s", string);
        wattroff(win, color);
        refresh();
     };
    WINDOW *create_win_menu(){
        WINDOW * my_menu_win;
        /*Crear la ventana que sera asociada con el menu*/
        my_menu_win = newwin(nlines, ncols, begin_y, begin_x);
        keypad(my_menu_win, true);
        return my_menu_win;
    }};}


#endif
