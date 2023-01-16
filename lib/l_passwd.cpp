#include "l_passwd.h"

using namespace l_pass;

WINDOW *create_newwin(int height, int width, int starty, int startx)
{ WINDOW *local_win;

  local_win = newwin(height, width, starty, startx);
  box(local_win, 0, 0);           /* 0, 0 pone los caracteres por
                                   * defecto para las lineas vertical
                                   * y horizontal                       */
  wrefresh(local_win);            /* Muestra la caja                    */

  return local_win;
}

void l_passwd::destroy_win(WINDOW *local_win)
{
  /* box(local_win, ' ', ' '); : Esto no produce el resultado deseado
   * de borrar la ventana. Deja las cuatro esquinas como un feo residuo
   * de la ventana.
   */
  wborder(local_win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
  /* Los parametros tomados son
   * 1. win: la ventana sobre la que operar
   * 2. ls: caracter a utilizar para el lado izquierdo de la ventana
   * 3. rs: caracter a utilizar para el lado derecho de la ventana
   * 4. ts: caracter a utilizar para el lado superior de la ventana
   * 5. bs: caracter a utilizar para el lado inferior de la ventana
   * 6. tl: caracter a utilizar para la esquina superior isquierda de la ventana
   * 7. tr: caracter a utilizar para la esquina superior derecha de la ventana
   * 8. bl: caracter a utilizar para la esquina inferior izquierda de la ventana
   * 9. br: caracter a utilizar para la esquina inferior derecha de la ventana
   */
  wrefresh(local_win);
  delwin(local_win);
}
  
void l_passwd::passwd_log(WINDOW *local_win)
{
int i = 0;
char passwdr[PW_LEN];

cbreak();
noecho();//Desactiva el eco
std::memset(passwdr, '\0',sizeof(passwdr));
while (i < PW_LEN) {
   passwdr[i] = wgetch(local_win);
   if (passwdr[i]== '\n') {
        break;
   }
 mvwprintw(local_win, 3, 20+i, "*");
 refresh();
 i++;
}
echo();//Activar eco
nocbreak();
}


