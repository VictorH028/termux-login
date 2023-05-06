#include "pass_win.h"


void pass_win::pass_win::win_main_subwin(MENU *my_menu,WINDOW *my_menu_win,const char *brand_menu){
    set_menu_win(my_menu,my_menu_win);
    set_menu_sub(my_menu, derwin(my_menu_win, 6, 38, 3, 1));
    //Marca del menu 
    set_menu_mark(my_menu, brand_menu);
};


ITEM **  pass_win::pass_win::create_element_itms(int n_choices,const char *choices[],const char *menu_icon[]){
    ITEM ** my_items;
    my_items = (ITEM **)calloc(n_choices, sizeof(ITEM *));
    for ( i = 0; i < n_choices; ++i)
        my_items[i] = new_item(choices[i], menu_icon[i]);
    return my_items;
};

void pass_win::pass_win::print_in_middle(WINDOW *win, int starty, int startx, int width,char const *string, chtype color)
{ int length, x, y;
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
  temp = width - (length / 2);
  x = startx + (int)temp;
  wattron(win, color);
  mvwprintw(win, y, x, "%s", string);
  wattroff(win, color);
  refresh();
};

WINDOW *  pass_win::pass_win::create_win_menu(int height, int width, int starty, int startx){
    WINDOW * my_menu_win;
    /*Crear la ventana que sera asociada con el menu*/
    my_menu_win = newwin(height, width, starty, startx);
    keypad(my_menu_win, true);
    return my_menu_win;
}



pass_win::pass_win() { 
  /* Inicializa curses */
  initscr();
  start_color();
  cbreak();
  noecho(); 
}

pass_win::~pass_win() {
  endwin(); 
};
