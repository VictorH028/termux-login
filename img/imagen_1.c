#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 1024

// Función para imprimir la imagen convertida en ASCII o ANSI
void print_image(char *filename) {
    FILE *file = fopen(filename, "r");
    if(file == NULL) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        return;
    }
    char line[BUF_SIZE];
    while(fgets(line, BUF_SIZE, file)) {
        printw("%s", line);
    }
    fclose(file);
}

int main() {
    // Inicializa ncurses
    initscr();
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    
    // Convierte la imagen a ASCII o ANSI
    system("jp2a --color IMG.jpg > imagen.txt");
    
    // Imprime la imagen convertida en ASCII o ANSI
    print_image("imagen.txt");
    
    // Refresca la pantalla y esperar un input
    refresh();
    getch();

    // Limpia y termina ncurses
    endwin();
    return 0;
}
