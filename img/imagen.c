#include <ncurses.h>

int main() {
    initscr();
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    FILE *file = fopen("IMG.xpm", "r");
    int y = 0;
    char linea[BUFSIZ];
    while (fgets(linea, sizeof linea, file) != NULL) {
        mvprintw(y, 0, "%s", linea);
        y++;
    }
    fclose(file);
    refresh();
    getch();
    endwin();
    return 0;
}
