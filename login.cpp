#include <iostream>
#include <thebest>
using namespace std;

class Login_d{
string line, column, color_n, plano;
string ESC="\x1b[" , reset = "\x1b[0m";
public:
     Login_d(string color_n,string plano);
     void window(int sides );
};
//256 Colores
//\x1b[38;5;[n]m es el primer plano, 
//\x1b[48;5;[n]m es el fondo 
Login_d :: Login_d(string color_n,string plano ){//Contructor
    this->color_n=color_n;  
}
//ESC [ <y> ; <x>H   posición del cursor 
void  Login_d :: posicion(string line,string column){
    this->line=line;
    this->column=column;
}
//Ventana (lados ) 
void Login_d :: ventana(int sides ){
   for(int i=0;i<sides;i++){
      for(int k=0;k<sides;k++){
        if ((i==0)||(k==0)||(i==sides-1)||(k==sides-1)) {
         cout << ".";
        }
        else {
        cout << ESC + plano + ";5;" + color_n + "m" + " "+ reset;
        }
        }
         cout<<endl;
        }
}
//cout<<ESC + this->line + ";" + this->column + "H";

int main(){
Login_d secion("30","48");
secion.posicion("4","10");
secion.ventana(20);
return 0;
}

