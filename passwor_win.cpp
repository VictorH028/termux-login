#include <menu.h>
#include <ncurses.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[10]))
#define CTRLD   4

//Menu opviones 
char const *choices[] = {
         "[+] [Crear una cuenta   ]",
         "[+] [Ya estoy registrado]",
         "[+] [Salir  ]",
};

struct {
  int choice;
  int c;
  int n_choices;
  int highlight;
} menu_var;



class pass_win{
     public:
       int height, width, starty, startx, row, col , ch;
       WINDOW *create_newwin(int height, int width, int starty, int startx);
       void *destroy_win(WINDOW *local_win);
       pass_win(int height,int width,int starty,int startx);
       void mov_win(WINDOW *name);
       void print_menu(WINDOW *menu_win, int highlight);
       void mov_menu(WINDOW *name);
};

int main(){
  
  WINDOW *my_win;
  WINDOW *menu_win;

  initscr();//Modo curses (stdscr)
  clear();  
  noecho();
  cbreak();//Buffer de linea desactivado
  

  //Inicia el color
  start_color();
  use_default_colors();

  //Estableser Color
  init_color(COLOR_BLACK, 255, 224, 224);//fondo
/* param 1     : nombre de color
 * param 2, 3, 4 : contenido rgb min = 0, max = 1000 */
  init_pair(1, -1, COLOR_BLACK); 

  //COLOR FONDO
  bkgd(COLOR_PAIR(1));
  
  //Objeto
  pass_win root_win(8,30,(LINES - 25)/2,(COLS - 30)/2);//menu

  
  //Menu var
  menu_var.n_choices = ARRAY_SIZE(choices);
  menu_var.choice = 0;
  menu_var.highlight = 1;
  
  //Creando menu
  menu_win = newwin(root_win.height, root_win.width, root_win.starty, root_win.startx);
  keypad(menu_win, TRUE);
  mvprintw(0, 0, "Utilice las flechas, Presione enter para elegir");
  refresh();
  root_win.print_menu(menu_win, menu_var.highlight);
  root_win.mov_menu(menu_win);
  mvprintw(23, 0, "Elegiste la opcion %d con la cadena %s\n", menu_var.choice, choices[menu_var.choice - 1]);

  switch (menu_var.choice) {
     case 1:
       clear();
       refresh();
       my_win = root_win.create_newwin(10, 30, (LINES - 25)/2, (COLS - 30)/2);
       break;
     case 2:
       clear();
       refresh();
       my_win = root_win.create_newwin(10, 30, (LINES - 25)/2, (COLS - 30)/2);
       break;
  }
  clrtoeol();
  refresh();
  getch();
  endwin();
  return 0;
}
void pass_win::mov_menu(WINDOW *name){
  while(1)
    { menu_var.c = wgetch(name);
      switch(menu_var.c) {
        case KEY_UP:
          if(menu_var.highlight == 1)
            menu_var.highlight = menu_var.n_choices;
          else
            --menu_var.highlight;
          break;
        case KEY_DOWN:
          if(menu_var.highlight == menu_var.n_choices)
            menu_var.highlight = 1;
          else
            ++menu_var.highlight;
          break;
        case 10:
          menu_var.choice = menu_var.highlight;
          break;
        default:
          mvprintw(24, 0, "Caracter presionado = %3d Ojala se imprima como '%c'", menu_var.c, menu_var.c);
          refresh();
          break;
        }
  print_menu(name, menu_var.highlight);
      if(menu_var.choice != 0) /* El usuario eligio salir del bucle infinito */
        break;
    }
 
};


void pass_win::mov_win(WINDOW *name){
   while((ch = getch()) != KEY_F(1))
    {   switch(ch)
        {   case KEY_UP:
            destroy_win(name);
            name = create_newwin(height, width, starty, --startx);
            break;
        case KEY_DOWN:
          destroy_win(name);
          name = create_newwin(height, width, starty, ++startx);
          break;
        case KEY_LEFT:
          destroy_win(name);
          name = create_newwin(height, width, --starty, startx);
          break;
        case KEY_RIGHT:
          destroy_win(name);
          name = create_newwin(height, width, ++starty, startx);
          break;
        }
    }
}

pass_win::pass_win(int height, int width,int starty, int startx){
   this->height = height;
   this->width  = width;
   this->starty = starty;
   this->startx = startx;
}
WINDOW *pass_win::create_newwin(int height, int width, int startx, int starty){
  WINDOW * local_win;
  local_win = newwin(height, width, startx, starty);
  box(local_win, 0, 0);
  wrefresh(local_win);  
  return local_win;
}; 


void *pass_win::destroy_win(WINDOW *local_win){
     /* box(local_win, ' ', ' '); : Esto no produce el resultado deseado
   * de borrar la ventana. Deja las cuatro esquinas como un feo residuo
   * de la ventana.
   */
  wborder(local_win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
  wrefresh(local_win);
  delwin(local_win); 
  return local_win;
};

void pass_win::print_menu(WINDOW *menu_win,int highlight){
    int x, y, i;
    x = 2;
    y = 2;
    box(menu_win, 0, 0);
    for (i=0; i<menu_var.n_choices; ++i) {
        if(highlight == i + 1){
            wattron(menu_win, A_REVERSE);
            mvwprintw(menu_win, y, x, "%s", choices[i]);
            wattroff(menu_win, A_REVERSE);
        }else
            mvwprintw(menu_win, y, x, "%s", choices[i]);
                 ++y;
        }
         wrefresh(menu_win);
};

