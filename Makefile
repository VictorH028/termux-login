main: lib/pass_win.h passwor_win.cpp
	clang++ -ggdb passwor_win.cpp -o passwor_win -lncurses -lmenu -ljsoncpp


