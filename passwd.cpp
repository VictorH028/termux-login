#include <menu.h>
#include <ncurses.h>

#define PW_PASSWD 256
#define NAME_LEN  256

ITEM   **it;
MENU   *me;
WINDOW  *new_win;

void quit(void)
{
  int i;

  unpost_menu(me);
  free_menu(me);

  for(i=0; i<=4; i++)
  {
    free_item(it[i]);
  }

  free(it);
  delwin(new_win);
 
  endwin();
}

int main(){

  int staty , statx , width, height;

  char name[NAME_LEN];
  char passwd[PW_PASSWD];
  const  char *read_passwd = "passwd";
  //initialize ncurse
  initscr(); //Modo linea.
  keypad(stdscr, TRUE);
  noecho();
  raw();

  height = 15;
  width = 30;
  staty = (LINES - height) / 2;//Calculating for a center placement 
  statx = (COLS - width) / 2;	//of the window

  //initializer color
  start_color();
  init_pair(1, COLOR_WHITE, COLOR_BLUE);
  init_pair(2, COLOR_BLUE, COLOR_YELLOW);


  // creating a window
  new_win = newwin(height, width, staty, statx);
  refresh();
  box(new_win, 0, 0);
  // mover e imprimir en la ventana
  mvwprintw(new_win, 0, width/2, "LOGIN");
  mvwprintw(new_win, 2, 1, "Useriname: ");
  //getstr(name);
  mvwprintw(new_win, 4, 1, "Passwd: ");

  wbkgd(new_win, COLOR_PAIR(2));
  //refrescando la ventana
  wrefresh(new_win);


  refresh();
  getchar();//input 
  endwin();//Stop mode line  

return 0;	
}
