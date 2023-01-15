#ifndef L_PASSWD
#define L_PASSWD

#include <cstring>
#include <vector>
#include <string>
#include <menu.h>
#include <ncurses.h>


#define PW_LEN 256
#define NAME_LEN  256

namespace l_pass  
{
    class l_passwd{
         public:
          int staty , statx , width, height;
          void InputPasswd();
};

}
#endif  
