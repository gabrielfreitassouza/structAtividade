//Texto normal
#define BLK "\e[0;30m" // Preto
#define RED "\e[0;31m" // Vermelho
#define GRN "\e[0;32m" // Verde
#define YEL "\e[0;33m" // Amarelo
#define BLU "\e[0;34m" // Azul
#define MAG "\e[0;35m" // Magenta
#define CYN "\e[0;36m" // Ciano
#define WHT "\e[0;37m" // Branco

//Texto em negrito normal
#define BBLK "\e[1;30m"
#define BRED "\e[1;31m"
#define BGRN "\e[1;32m"
#define BYEL "\e[1;33m"
#define BBLU "\e[1;34m"
#define BMAG "\e[1;35m"
#define BCYN "\e[1;36m"
#define BWHT "\e[1;37m"

//Texto sublinhado normal
#define UBLK "\e[4;30m"
#define URED "\e[4;31m"
#define UGRN "\e[4;32m"
#define UYEL "\e[4;33m"
#define UBLU "\e[4;34m"
#define UMAG "\e[4;35m"
#define UCYN "\e[4;36m"
#define UWHT "\e[4;37m"

//Plano de fundo normal
#define BLKB "\e[40m" // Preto
#define REDB "\e[41m" // Vermelho
#define GRNB "\e[42m" // Verde
#define YELB "\e[43m" // Amarelo
#define BLUB "\e[44m" // Azul
#define MAGB "\e[45m" // Magenta
#define CYNB "\e[46m" // Ciano
#define WHTB "\e[47m" // Branco

//Fundo de alta intensidade
#define BLKHB "\e[0;100m"
#define REDHB "\e[0;101m"
#define GRNHB "\e[0;102m"
#define YELHB "\e[0;103m"
#define BLUHB "\e[0;104m"
#define MAGHB "\e[0;105m"
#define CYNHB "\e[0;106m"
#define WHTHB "\e[0;107m"

//Texto de alta intensidade
#define HBLK "\e[0;90m"
#define HRED "\e[0;91m"
#define HGRN "\e[0;92m"
#define HYEL "\e[0;93m"
#define HBLU "\e[0;94m"
#define HMAG "\e[0;95m"
#define HCYN "\e[0;96m"
#define HWHT "\e[0;97m"

//Texto em negrito de alta intensidade
#define BHBLK "\e[1;90m"
#define BHRED "\e[1;91m"
#define BHGRN "\e[1;92m"
#define BHYEL "\e[1;93m"
#define BHBLU "\e[1;94m"
#define BHMAG "\e[1;95m"
#define BHCYN "\e[1;96m"
#define BHWHT "\e[1;97m"

// Resetar as cores para padrão do teminal
#define reset "\e[0m"

//Trocar cor
void color(char color[8]) {
  printf(color);
}

// Limpar Tela Windows/Linux
void limpar() {
  system("cls||clear");
}

// Tema Escuro/Claro 
void temas(int op) {
  if (op == 1) {
    (tema == 1) ? color(WHTB): color(BLKB);
    limpar();
    (tema == 1) ? color(BLU): color(YEL); // texto
    (tema == 1) ? color(WHTB): color(BLKB); // fundo
  } else if (2) {
    (tema == 1) ? color(YEL): color(GRN);
    (tema == 1) ? color(WHTB): color(BLKB);
  } else {
    (tema == 1) ? color(BLU): color(YEL);
    (tema == 1) ? color(WHTB): color(BLKB);
  }
}

// Espera  a pessoa precionar teclar para continuar
void espera() {
  color(RED);
  (tema == 1) ? color(WHTB): color(BLKB);
  printf("\nPrecione ENTER para continuar...", fflush(stdin));
  getchar();
}
