/* Los archivos de header contienen
   1-Definicion de funciones 
   2-Definicion de tipo de datos 
   3-marco */

//Para evitar q se inserte varias veces 
#ifndef LOGIN_H//include guard
#define LOGIN_H
//Marcos 
#define ESC "\x1b"
#define CSI "\x1b[" 
//Key arrow 
#define UP '0;72'    //Ariba 
#define DOWN 80  //abajo
#define RAGTH 77 //drecha 
#define LEFT  75 //izgierda 
//No ponga using declaraciones en sus archivos de encabezado! 
namespace N{ //namespace declaration 

class Login_ACSII{
   bool win_start = false;
   char key;
   char menu_op='0';
   int row , col;
   public:
    Login_ACSII();
   ~Login_ACSII();
   //argumento por de fecto( x = 0,y =0)     
   void gotoxy(int = 0 , int = 0);
   bool kbhit();
   void menu();
   void clear();  
   void window();
   void term();
   void hidecur(); 
};}
namespace C {
  class Color{ 
   public:
     void backgroud();
     void foregroud();
 };
}
#endif /*  LOGIN_H */
