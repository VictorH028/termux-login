#include "lib/l_passwd.h"
#include <cstring>
#include <ncurses.h>

/*... .............
 * COLOR
 * ..............
 * white ----> blanco
 * yellow ---->  
 *
 *
 */
using namespace l_pass;

WINDOW *new_win;

int main(){

  l_passwd pass;
  
  char name[NAME_LEN];
  char passwdr[PW_LEN];
  const  char *read_passwd = "passwd";
  int i = 0; 
  initscr();//initialize ncurse
  clear();//Limpiar pantalla
  keypad(stdscr, TRUE);//Opteber F1,F2..ect
  raw();//Desactiva buffer de linea

  //initializer color
  start_color();
  use_default_colors(); //C terminal
  //Estableciendo colores
  init_pair(1, COLOR_WHITE, COLOR_BLUE);
  init_pair(2, COLOR_BLUE, COLOR_YELLOW);
  init_pair(3, -1, COLOR_WHITE);

  //Color de fondo
  bkgd(COLOR_PAIR(3));

  pass.height = 15;
  pass.width = 30;
  pass.staty = (LINES - pass.height) / 2;//Calculating for a center placement 
  pass.statx = (COLS - pass.width) / 2;	//of the window

  //create nuw window
  new_win = create_newwin(pass.height, pass.width, pass.staty, pass.statx);
  refresh();
  wbkgd(new_win, COLOR_PAIR(2));
  
  mvwprintw(new_win,0,(pass.width/2),"LOGIN");
  mvwprintw(new_win,2,1,"User name: ");
  wgetstr(new_win,name);
  mvwprintw(new_win,3,1,"Passwd: ");
  refresh();

  wbkgd(new_win, COLOR_PAIR(2));

  pass.passwd_log(new_win);
  

  if(strncmp(read_passwd, passwdr,strlen(read_passwd)) == 0)
  {
  mvwprintw(new_win,4,2,"Correct");
  }else {
  mvwprintw(new_win,4,2,"Wrong");
  }

  //refrescando la ventana
  wrefresh(new_win);
  refresh();
  getchar();//Espera entrada del usuario 
  endwin();//Stop mode line  

return 0;	
}
