main: lib/pass_win.cpp passwor_win.cpp
	clang++ -ggdb lib/pass_win.cpp passwor_win.cpp -o passwor_win -lncurses -lmenu -ljsoncpp


