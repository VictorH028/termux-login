#include "lib/pass_win.h"
#include <ncurses.h>

using namespace ps_w;
using namespace conf;


#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[10]))

//Menu opviones 
char const *choices[] = {
         "[+] [Crear una cuenta   ]",
         "[+] [Ya estoy registrado]",
         "[+] [Salir  ]",
         //(char *)NULL,
};

char const  *menu_icon[] = {" ❤️  ", " 🧡 ", " 💔 ",};



int main(){
 

  ITEM **my_items;
  MENU *my_menu;
  WINDOW *my_menu_win;
  int n_choices, i;
  int c;

  //Objeto 
  ps_w::cre_menu menu_root(10 ,40, 4, 4);
  conf::confing config; 

  //Color de fondo
  wbkgd(stdscr, COLOR_PAIR(2));

   /*Crea los elementos */
  n_choices = ARRAY_SIZE(choices);
  my_items = menu_root.create_element_itms(n_choices, choices, menu_icon, i);

  /* Crea el menu */
  my_menu = new_menu((ITEM **)my_items);

  /* Crea la ventana que sera asociada con el menu */
  //keypad = TRUE)
  my_menu_win = menu_root.create_win_menu();


  /* Establece la ventana principal y la subventana */ 
  menu_root.win_main_subwin(my_menu, my_menu_win, config.get_confing("brand_menu"));
  

  /* Imprime un margen alrededor de la ventana pricipal e imprime el titulo */
  box(my_menu_win, 0, 0);
  menu_root.print_in_middle(my_menu_win, 1, 0, 40, "Mi Menu", COLOR_PAIR(1));
  mvwaddch(my_menu_win, 2, 0, ACS_LTEE);
  mvwhline(my_menu_win, 2, 1, ACS_HLINE, 38);
  mvwaddch(my_menu_win, 2, 39, ACS_RTEE);
  
  //refresh();

  /* Publica el menu */
  post_menu(my_menu);
  wrefresh(my_menu_win);

  while((c = wgetch(my_menu_win)) != KEY_F(1)){
    switch(c){
    case KEY_DOWN:
      menu_driver(my_menu, REQ_DOWN_ITEM);
      break;
    case KEY_UP:
      menu_driver(my_menu, REQ_UP_ITEM);
      break;
    default:
      mvprintw(LINES - 2, 0, "Caracter presionado = %3d Ojala se imprima como '%c'", c, c);
      refresh();
      break;
    }
    wrefresh(my_menu_win);
  }
  /* remueve el menu y libera toda la memoria tomada */
  unpost_menu(my_menu);
  free_menu(my_menu);
  for(i = 0; i < n_choices; ++i)
    free_item(my_items[i]);
};


