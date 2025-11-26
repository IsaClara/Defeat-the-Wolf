#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>

// VARI�VEIS GLOBAIS //
#define atkIn 10
#define atkPlayer 5
int opcao, pocao = 3;


// CORES DO PROJETO //
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define GOLD    "\033[33m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"


// STATUS DO INIMIGO //
int hpIn = 40;
char movimentoIn[150] = "O lobo te encara fixamente.";


// STATUS DO PLAYER //
int hpPlayer = 50;



int main();
void menu();
void acaoInimigo();
void atacarInimigo();
void defender();
void usarPocao();




/////////////////////////////////// INIMIGO ///////////////////////////////////////
// A��O DO INIMIGO //
void acaoInimigo(){
	system("cls");

    char localMsg[150];
    snprintf(localMsg, sizeof(localMsg), "O lobo rosna, pronto para atacar.");
    strncpy(movimentoIn, localMsg, sizeof(movimentoIn)-1);
    movimentoIn[sizeof(movimentoIn)-1] = '\0';
	// ASCII DO LOBO
	printf("                        ,     ,\n");
	printf("                        |\\---/|\n");
	printf("                       /  , , |\n");
	printf("                  __.-'|  / \\ /\n");
	printf("         __ ___.-'        ._O|\n");
	printf("      .-'  '        :      _/       " RED " %s" RESET "\n", movimentoIn);
	printf("     / ,    .        .     |\n");
	printf("    :  ;    :        :   _/\n");
	printf("    |  |   .'     __:   /\n");
	printf("    |  :   /'----'| \\  |\n");
	printf("    \\  |\\  |      | /| |\n");
	printf("     '.'| /       || \\ |\n");
	printf("     | /|.'       '.l \\\\_\n");
	printf("     || ||             '-'\n");
	printf("     '-''-'\n\n\n");

	getch();

	int resultado = rand() % 2;

	if (resultado == 0) {
		printf(RED "Voc� � mordido pelo lobo.\n" RESET);
		if (opcao == 2) {
			printf("Voc� defendeu, voc� n�o perde vida!\n");
		} else {
			printf("Voc� perde vida!\n");
			hpPlayer = hpPlayer - atkIn;
		}
	    getch();
	}else {
  	  	printf("O lobo n�o consegue te morder.");
	    getch();
	}

}



/////////////////////////////////// PLAYER ////////////////////////////////////////
// ATACAR INIMIGO //
void atacarInimigo(){
	system("cls");

	printf(GOLD "===========================================================\n" RESET);
	printf(BOLD GREEN "Pressione qualquer tecla para ver se voc� consegue atacar!\n" RESET);
	printf(GOLD "===========================================================\n" RESET);
    getch();

    int resultado = rand() % 2;

	if (resultado == 0) {
	    printf("Voc� acertou o ataque!\n");
	    hpIn = hpIn - atkPlayer;
	    getch();
	} else {
	    printf(RED "Voc� errou o ataque...\n" RESET);
	    getch();
	}
}


// DEFENDER //
void defender(){
	system("cls");

	printf(GOLD "===========================================================\n" RESET);
	printf(BOLD GREEN "Voc� passa essa rodada defendendo!\n" RESET);
	printf(GOLD "============================================================\n" RESET);
	getch();
}


// USAR PO��O //
void usarPocao(){
	system("cls");

    if (pocao > 0) {
        pocao--;
        hpPlayer += 5;
        if (hpPlayer > 50) hpPlayer = 50;
        printf(GOLD "===========================================================\n" RESET);
		printf(BOLD GREEN "Voc� usou uma po��o e recuperou 5 HP!\n" RESET);
    	printf(GOLD "===========================================================\n" RESET);
        printf("Po��es restantes: %d", pocao);
        printf("\nHP agora: %d\n", hpPlayer);
    } else {
        printf("\nVoc� n�o tem mais po��es!\n");
    }
    getch();
}



/////////////////////////////////// MENU ////////////////////////////////////////
void menu(){
	system("cls");

	// ASCII DO LOBO
	printf("                        ,     ,\n");
	printf("                        |\\---/|\n");
	printf("                       /  , , |\n");
	printf("                  __.-'|  / \\ /      HP: %d \n", hpIn);
	printf("         __ ___.-'        ._O|\n");
	printf("      .-'  '        :      _/       " RED " %s" RESET "\n", movimentoIn);
	printf("     / ,    .        .     |\n");
	printf("    :  ;    :        :   _/\n");
	printf("    |  |   .'     __:   /\n");
	printf("    |  :   /'----'| \\  |\n");
	printf("    \\  |\\  |      | /| |\n");
	printf("     '.'| /       || \\ |\n");
	printf("     | /|.'       '.l \\\\_\n");
	printf("     || ||             '-'\n");
	printf("     '-''-'\n");


	// STATUS DO JOGADOR
	printf(GOLD "=====================================\n" RESET);
	printf(BOLD GREEN "        STATUS DO AVENTUREIRO\n" RESET);
	printf(GOLD "=====================================\n" RESET);

	printf("       HP: %d\t\tATK: %d\n", hpPlayer, atkPlayer);

	printf(GOLD "=====================================\n" RESET);

	printf(BOLD GREEN "            MENU DE A��ES\n" RESET);
	printf(GOLD "=====================================\n" RESET);

	printf(GOLD "[1]" RESET  " Atacar o inimigo\n");
	printf(GOLD "[2]" RESET " Defender\n");
	printf(GOLD "[3]" RESET " Usar po��o de vida (%d)\n", pocao);
	printf(GOLD "[4]" RESET " Correr\n");

	printf(GOLD "=====================================\n" RESET);

	// === INPUT ===
	printf("\nEscolha sua a��o: ");
	if (scanf("%d", &opcao) != 1) {
	    while (getchar() != '\n');
	    opcao = 0;
	}

   switch (opcao) {
    case 1:
		atacarInimigo();
		break;
    case 2:
		defender();
        break;
	case 3:
		usarPocao();
		break;
	case 4:
        break;
   default:
		printf("\nEscolha inv�lida. Tente novamente.\n");
        getch();
        break;
   }

   if (opcao != 4 && hpIn > 0 && hpPlayer > 0) {
        acaoInimigo();
    }
}



/////////////////////////////////// MAIN ////////////////////////////////////////
int main(){
	setlocale(LC_ALL, "portuguese");
	srand((unsigned) time(NULL));
	while (opcao != 4 && hpPlayer > 0 && hpIn > 0){
		menu();
	}
	if(opcao == 4){
		system("cls");
		printf(BOLD GREEN"\nVoc� correu do Lobo...\n" RESET);
		getch();
	} else if(hpPlayer <= 0){
		system("cls");
        printf(RED "Voc� foi derrotado pelo lobo...\n" RESET);
        getch();
	} else if (hpIn <= 0){
		system("cls");
        printf(GREEN BOLD "Voc� derrotou o lobo! Parab�ns!\n" RESET);
		getch();
	}

	printf(BOLD GREEN"\nFim do jogo, obrigado por jogar!\n\n" RESET);
	printf("Criado por: Isa Clara");
	return 0;
}