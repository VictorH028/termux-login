#include "lib/pass_win.h"





//Menu opviones 
char const *choices[] = {
         "[+] [Crear una cuenta   ]",
         "[+] [Ya estoy registrado]",
         "[+] [Salir  ]",(char *)NULL,
};

char const  *menu_icon[] = {" ❤️  ", " 🧡 ", " 💔 ",};



int main(){
  
  ITEM **my_items;

  int c;
  MENU *my_menu;
  WINDOW *my_menu_win;
  //int n_choices, i;

  keypad(stdscr, TRUE);
  init_pair(1, COLOR_RED, COLOR_BLACK);
  //Objeto 
  pass_win menu_root;

 
   /*Crea los elementos */
  menu_root.n_choices = ARRAY_SIZE(choices);
  my_items = menu_root.create_element_itms(menu_root.n_choices, choices, menu_icon);

  /* Crea el menu */
  my_menu = new_menu((ITEM **)my_items);

  /* Crea la ventana que sera asociada con el menu */
  //keypad = TRUE)
  my_menu_win = menu_root.create_win_menu(10, 40, (LINES - 10)/2, (COLS - 40)/2);


  /* Establece la ventana principal y la subventana */
  menu_root.win_main_subwin(my_menu, my_menu_win, "👉");
  

  /* Imprime un margen alrededor de la ventana pricipal e imprime el titulo */
  box(my_menu_win, 0, 0);
  menu_root.print_in_middle(my_menu_win, 1, 0, 40, "Mi Menu", COLOR_PAIR(1));
  mvwaddch(my_menu_win, 2, 0, ACS_LTEE);
  mvwhline(my_menu_win, 2, 1, ACS_HLINE, 40);
  mvwaddch(my_menu_win, 2, 39, ACS_RTEE);
  mvprintw(LINES - 2, 0, "F1 para Salir");
  refresh();

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
    }
    wrefresh(my_menu_win);
  }

  /* remueve el menu y libera toda la memoria tomada */
  unpost_menu(my_menu);
  free_menu(my_menu);
  for(menu_root.i = 0; menu_root.i < menu_root.n_choices; ++menu_root.i)
  free_item(my_items[menu_root.i]);
};


