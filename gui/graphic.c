/*   Váriaveis de controle   */
int temCor = 0;

/*   Setup   */
void inicializar_curses();  // Inicializa a tela
void finalizar_curses();    // Encerra o controle da tela

/*   Utils Curses   */
// Cria uma janela
WINDOW * criar_jan(int altura, int largura, int y, int x);
// Printar no meio de uma faixa
void print_meio(WINDOW * win, int y, int x, int largura, char * string, int negrito);

/*   Telas   */
void tela_config();         // Tela de configurações

/*   Função Principal   */
void modo_grafico(){
    inicializar_curses();

    // Tela de configurações
    refresh();
    tela_config();
    finalizar_curses();
}





/*   Implementação Setup    */
void inicializar_curses(){
    initscr();
    raw();
    noecho();
    keypad(stdscr, TRUE);
    temCor = has_colors();
    if(temCor){
        init_pair(1, COLOR_CYAN, COLOR_BLACK);
        start_color();
    }
}

void finalizar_curses(){
    endwin();
}

/*   Implementação Utils   */
WINDOW * criar_jan(int altura, int largura, int y, int x){
    WINDOW * janela;
    janela = newwin(altura, largura, y, x);
    // wborder(janela, '|', '|', '_', '_', '\\','/', '\\', '/');
    box(janela, 0, 0);
    wrefresh(janela);
    return janela;
}

void print_meio(WINDOW * win, int y, int x, int largura, char * string, int negrito){
    if(negrito)
        wattron(win, A_BOLD);
    x = (largura - strlen(string)) / 2;
    mvwprintw(win, y, x, string);
    if(negrito)
        wattroff(win, A_BOLD);
    wrefresh(win);
}

/*   Implementação Telas    */
void tela_config(){
    // Inicialização
    WINDOW * menu, * display;                       // Janelas
    Vetor   tamanho_menu = {25, 20},                // Tamanhos
            tamanho_display = {60, 20},
            pos_menu = {1, 1},                      // Posições
            pos_display = {tamanho_menu.x + 2, 1};
    
    // Criação de janelas
    menu    = criar_jan(tamanho_menu.y, tamanho_menu.x, pos_menu.y, pos_menu.x);
    display = criar_jan(tamanho_display.y, tamanho_display.x, pos_display.y, pos_display.x);
    
    // Títulos
    if(temCor){
        wattron(menu, COLOR_PAIR(1));
        wattron(display, COLOR_PAIR(1));
    }    
    print_meio(menu, 1, 2, tamanho_menu.x, "Menu", 1);
    print_meio(display, 1, 2, tamanho_display.x, "Display", 1);
    wrefresh(display);
    
    
}