#include <iostream>
using namespace std;

class login_d{
private:
    string hex = "\x1b[";
    string  line, column, color; 
public:
    login_d(string l, string c)//contructor
    :line(l),column(c){};
    void login_txt();
    ~login_d(){};//detructor 
};
