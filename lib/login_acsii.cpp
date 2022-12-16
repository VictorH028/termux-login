// login.cpp 
#include <cstdio>
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include "login_acsii.h" // header in local directory
#include <iostream>// header in standard library
#include <string> 

using namespace N;
using namespace C;
using std::cout;
using std::endl;
using std::to_string;
//Bienvenida
Login_ACSII::Login_ACSII(){
  struct winsize w;
  ioctl(STDOUT_FILENO,TIOCGWINSZ,&w);  
  row =  w.ws_row;
  col =  w.ws_col;
}
Login_ACSII::~Login_ACSII(){//Detructor
    cout<<(CSI "0m");
    cout<<(ESC "(B"); // exit line drawing mode
    cout<<(CSI "?25h");// Pantalla de cursores 
}
//key pres 
bool Login_ACSII::kbhit()
{
    termios term;
    tcgetattr(0, &term);

    termios term2 = term;
    term2.c_lflag &= ~ICANON;
    tcsetattr(0, TCSANOW, &term2);

    int byteswaiting;
    ioctl(0, FIONREAD, &byteswaiting);

    tcsetattr(0, TCSANOW, &term);

    return byteswaiting > 0;
}
//Menu del programa 
void Login_ACSII::menu(){
    clear();
    while(menu_op == '0'){
    cout<<":::::::::MENU:::::::"<<endl;
    cout<<" "<<endl;
    cout<<"1)Crear cuenta"<<endl;
    cout<<"2)"<<endl;
    cout<<"\n\nElegir una opcion y precionear ::Enter::"<<endl;
     //Logica de el menu     
    menu_op = getchar();
    clear();
    switch (menu_op) {
       case '1':
        cout<<"En proceso"<<endl;
        break;
       case '2':
        cout<<"Hat vamos"<<endl;
            break;
       default:
           cout<<"Deves de elegir una opcion"<<endl;
           menu_op='0';
        }
    }
}
//window 
void Login_ACSII::window(){
    int x=10 , y=10;
    while (!win_start) {
        gotoxy(x,y);cout<<"*";
        hidecur();
        if(kbhit()){
           gotoxy(x,y);cout<<" ";
           key = getchar();
           if (key == 'i') x--;
           if (key == 'k') x++;
           if (key == 'j') y--;
           if (key == 'l') y++;
           gotoxy(x,y);cout<<"*";
        }
    usleep(30);       
    }      
}
//clear sceed
void Login_ACSII::clear(){
  cout<<(CSI "2J");}
//prepiedades de terinal 
void Login_ACSII::term() 
{
    cout<<"row: "<<row<<endl;
    cout<<"col: "<<col<<endl;
}
void Login_ACSII::gotoxy(int x,int y){
   //printf("%c[%d;%df",0x1B,y,x);
  cout<<(CSI+to_string(x)+";"+to_string(y)+"H");
}
//hide corsor
void Login_ACSII::hidecur(){ 
   cout<<(CSI"?25l");
}


