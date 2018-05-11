/*   Constantes   */
#define MENU_W 25
#define DISPLAY_W 60
#define JANELA_H 20
#define MARGEM_EXT 1
#define MARGEM_INT 1

/*   Váriaveis de controle   */
int temCor = 0,             // Se o terminal suporta cores
    passo_config = 1,       // Em que passo da configuração o usuário está
    entrada_matriz = 0

    
    
    ;
// Janelas
WINDOW * menu, * display;  
// Posições e tamanhos das janelas 
Vetor   tamanho_menu = { MENU_W, JANELA_H },
        tamanho_display = { DISPLAY_W, JANELA_H },
        pos_menu = {MARGEM_EXT, MARGEM_EXT},  
        pos_display = {MENU_W + MARGEM_EXT * 2, MARGEM_EXT};

/*   Setup   */
void inicializar_curses();  // Inicializa a tela
void finalizar_curses();    // Encerra o controle da tela

/*   Utils Curses   */
// Cria uma janela
WINDOW * criar_jan(int altura, int largura, int y, int x);
// Printar no meio de uma faixa
void print_meio(WINDOW * win, int y, int x, int largura, char * string, int negrito);

/*   Telas   */
// Tela de configurações
void init_tela_config();
void atualizar_config_menu();
void config_display_tamanho_matriz();
void config_display_entrada_matriz();
void config_display_fonte_palavras();
void atualizar_config_display();
void tela_config();


/*   Função Principal   */
void modo_grafico(){
    // Setup
    inicializar_curses();

    // Tela de configurações
    tela_config();

    // Encerramento
    finalizar_curses();
}





/*   Implementação Setup    */
void inicializar_curses(){
    initscr();
    raw();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(0);
    temCor = has_colors();
    if(temCor){
        init_pair(1, 0, 6);
        start_color();
    }
    refresh();
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

void print_meio(WINDOW * win, int y, int x, int largura, char * string, int estilo){
    if(estilo == 1)
        wattron(win, A_BOLD);
    if(estilo == 2)
        wattron(win, A_ITALIC);
    x = (largura - strlen(string)) / 2;
    mvwprintw(win, y, x, string);
    if(estilo == 1)
        wattroff(win, A_BOLD);
    if(estilo == 2)
        wattroff(win, A_ITALIC);
    wrefresh(win);
}

/*   Implementação Telas    */
void init_tela_config(){
    // Criação de janelas
    menu    = criar_jan(tamanho_menu.y, tamanho_menu.x, pos_menu.y, pos_menu.x);
    display = criar_jan(tamanho_display.y, tamanho_display.x, pos_display.y, pos_display.x);
}

void atualizar_menu_config(){
    int i;
    char * passos[] = {"Matriz", "Tamanho", "Entrada", "Palavras", "Entrada"};
    werase(menu);
    box(menu, 0, 0);
    print_meio(menu, MARGEM_INT, MARGEM_INT + 1, tamanho_menu.x + MARGEM_INT + 1, "Opções", 1);
    for(i = 0; i < 5; i++){
        if((passo_config > 3 && i < 3) || (passo_config < 3 && i >= 3))
            wattron(menu, A_DIM);
        if((passo_config > 0 && passo_config < 3 && i == 0) || (passo_config == 4 && i == 3))
            wattron(menu, A_BOLD);        
        if(i != 0 && i != 3 && i == passo_config)
            wattron(menu, A_UNDERLINE);    
        mvwprintw(menu, 3 + i, (i == 0 || i == 3) ? 3 : 5, passos[i]);
        if((passo_config > 3 && i < 3) || (passo_config < 3 && i > 3))
            wattroff(menu, A_DIM);
        if((passo_config > 0 && passo_config < 3 && i == 0) || (passo_config == 4 && i == 3))
            wattroff(menu, A_BOLD);            
        if(i != 0 && i != 3)
            wattroff(menu, A_UNDERLINE);    
    }
    wrefresh(menu);
}

void config_display_tamanho_matriz(){
    // Titulo
    print_meio(display, 2, 1, tamanho_display.x - 1, "dimensões da matriz", 2);
    // Labels
    mvwprintw(display, 5, 6, "Largura:");
    mvwprintw(display, 6, 7, "Altura:");
    // Campos
    wattron(display, A_UNDERLINE);
    mvwprintw(display, 5, 15, " ");
    echo();
    mvwscanw(display, 5, 15, "%d", &W);
    wattroff(display, A_UNDERLINE);
    wattron(display, A_BOLD);
    mvwprintw(display, 5, 15, "%02d  ", W);
    wattroff(display, A_BOLD);
    wrefresh(display);
    wattron(display, A_UNDERLINE);
    mvwprintw(display, 6, 15, " ");
    mvwscanw(display, 6, 15, "%d", &H);
    wattroff(display, A_UNDERLINE);
    wattron(display, A_BOLD);
    mvwprintw(display, 6, 15, "%02d  ", H);
    wattroff(display, A_BOLD);
    noecho();
    wrefresh(display);
    passo_config++;
    atualizar_menu_config();
    atualizar_display_config();
}    

void config_display_entrada_matriz(){
    char * opcoes[] = {"Dados do teclado", "Carregar arquivo", "Gerar aleatoriamente"};
    int i;
    print_meio(display, 2, 1, tamanho_display.x - 2, "entrada da matriz", 2);
    mvwprintw(display, 4, 6, "Escolha a forma de entrada");
    for(i = 0; i < 3; i++)
        mvwprintw(display, 6 + i, 8, opcoes[i]);
    wrefresh(display);
    
}

void config_display_fonte_palavras(){}

void atualizar_display_config(){
    // Setup
    werase(display);
    box(display, 0, 0);
    print_meio(display, MARGEM_INT, MARGEM_INT + 1, tamanho_display.x - MARGEM_INT - 1, "Configurar", 1);
    
    // Telas
    if(passo_config == 1)
        config_display_tamanho_matriz();
    else if(passo_config == 2)
        config_display_entrada_matriz();
    else if(passo_config == 4)
        config_display_fonte_palavras();
}

void tela_config(){
    int key;
    // Inicializa as janelas
    init_tela_config();
    while(passo_config < 5){
        refresh();
        atualizar_menu_config();
        atualizar_display_config();
        key = getch();
        if(key == KEY_RIGHT){
            passo_config++;
            if(passo_config == 3) passo_config++;
        }
        if(key == KEY_LEFT){
            passo_config--;
            if(passo_config == 0)
                passo_config++;
            else if(passo_config == 3)
                passo_config--;
        }
    }
}