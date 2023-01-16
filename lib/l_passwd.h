#ifndef L_PASSWD
#define L_PASSWD

#include <cstring>
#include <vector>
#include <string>
#include <menu.h>
#include <ncurses.h>

#define PW_LEN 256
#define NAME_LEN  256

WINDOW *create_newwin(int height,int width,int starty, int startx);


namespace l_pass  
{
    class l_passwd{
         public:
          int staty , statx , width, height;
          void destroy_win(WINDOW *local_win);
          void passwd_log(WINDOW *local_win);
};
}
#endif  
