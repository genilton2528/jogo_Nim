#include "Genilton.h"

int jogo(int j){
	
	int car, player=0, control=0;
	int x=15, y=20;
	
	COLUNA a[4], b[6], c[8];
	
	inicializaColuna(a, 4);
	inicializaColuna(b, 6);
	inicializaColuna(c, 8);	

	while(control==0)
	{	
		if((j==1)&&(player==1))
		{
			gotoxy(3,7); printf("E a vez do Computador");
			player= inteligenciaArtificial(a, b, c);
			
			if(player==15)
			{
				control= caixaDialogo(4, 0);				
				continue;
			}
			gotoxy(10,10); printf("Pensando...");			
			esperar(2);
			system("cls");
			gotoxy(3,7); printf("E a vez do jogador 1");
		}
		else
		{
			gotoxy(3,7); printf("E a vez do jogador %d",  player+1);
		}
		
		gotoxy(15,1);	
		printf("_____________________________________");
		gotoxy(15,2);	
		printf("%c                                   %c", 219, 219);
		gotoxy(15,3);	
		printf("%c              Jogo Nim             %c", 219, 219);
		gotoxy(15,4);	
		printf("%c___________________________________%c", 219, 219);
		
		if((j==1)&&(player==1))
		{
			gotoxy(3,7); printf("E a vez do Computador");
			player= inteligenciaArtificial(a, b, c);
			
			if(player==15)
			{
				control= caixaDialogo(4, 0);				
				continue;
			}
			gotoxy(10,10); printf("Pensando...");			
			esperar(2);
			
		}
		else
		{
			gotoxy(3,7); printf("E a vez do jogador %d",  player+1);
		}
		
		desenhaColunas(a, b, c);
		
		seta(x,y);
		
		fflush(stdin);
		car=getch();
		fflush(stdin);
		system("cls");
		
		switch(car)
		{
			case ACIMA:
				seta(x, y);
			break;
			
			case ABAIXO:
				seta(x, y);			
			break;
			
			case ENTER:
				if(verificaSelecionados(a, b, c)==0)
				{
					caixaDialogo(2, 0);
					break;
				}				
				
				if(verificaVencedor(a, b, c)==15)
				{
					control= caixaDialogo(1, player);				
					continue;
				}
				
				player= setPlayer(player, a, b, c);
			break;
			
			case ESQUERDA:
				switch(x)
				{
					case 30:
						x=21;
						seta(x, y);
					break;
					
					case 50:
						x=42;
						seta(x, y);
					break;
					
					case 15:
						x=68;
						seta(x, y);
					break;
					
					default:
						x=x-3;
						seta(x, y);
					break;
				}
			break;
			
			case DIREITA:
				switch(x)
				{
					case 21:
						x=30;
						seta(x, y);
					break;
					
					case 42:
						x=50;
						seta(x, y);
					break;
					
					case 68:
						x=15;
						seta(x, y);
					break;
					
					default:
						x=x+3;
						seta(x, y);
					break;
				}
			break;
			
			case ESPACO:
				switch(x)
				{
					case 15:
						if((b[5].cond==1)||(c[7].cond==1))
						{
							gotoxy(10,28);
							printf("Voce so pode tirar de uma coluna por vez!!!");
						}
						else
						{
							selecionaPalito(a,0,3);
						}
						seta(x, y);
					break;
					
					case 18:
						if((b[5].cond==1)||(c[7].cond==1))
						{
							gotoxy(10,28);
							printf("Voce so pode tirar de uma coluna por vez!!!");
						}
						else
						{
							selecionaPalito(a,1,3);
						}
						seta(x, y);
					break;
					
					case 21:
						if((b[5].cond==1)||(c[7].cond==1))
						{
							gotoxy(10,28);
							printf("Voce so pode tirar de uma coluna por vez!!!");
						}
						else
						{
							selecionaPalito(a,2,3);
						}
						seta(x, y);
					break;
								
					case 30:
						if((a[3].cond==1)||(c[7].cond==1))
						{
							gotoxy(10,28);
							printf("Voce so pode tirar de uma coluna por vez!!!");
						}
						else
						{
							selecionaPalito(b,0,5);
						}
						seta(x, y);
					break;
					
					case 33:
						if((a[3].cond==1)||(c[7].cond==1))
						{
							gotoxy(10,28);
							printf("Voce so pode tirar de uma coluna por vez!!!");
						}
						else
						{
							selecionaPalito(b,1,5);
						}
						seta(x, y);
					break;
							
					case 36:
						if((a[3].cond==1)||(c[7].cond==1))
						{
							gotoxy(10,28);
							printf("Voce so pode tirar de uma coluna por vez!!!");
						}
						else
						{
							selecionaPalito(b,2,5);
						}
						seta(x, y);
					break;
					
					case 39:
						if((a[3].cond==1)||(c[7].cond==1))
						{
							gotoxy(10,28);
							printf("Voce so pode tirar de uma coluna por vez!!!");
						}
						else
						{
							selecionaPalito(b,3,5);
						}
						seta(x, y);
					break;
								
					case 42:
						if((a[3].cond==1)||(c[7].cond==1))
						{
							gotoxy(10,28);
							printf("Voce so pode tirar de uma coluna por vez!!!");
						}
						else
						{
							selecionaPalito(b,4,5);
						}
						seta(x, y);
					break;
								
					case 50:
						if((a[3].cond==1)||(b[5].cond==1))
						{
							gotoxy(10,28);
							printf("Voce so pode tirar de uma coluna por vez!!!");
						}
						else
						{
							selecionaPalito(c,0,7);
						}
						seta(x, y);
					break;
								
					case 53:
						if((a[3].cond==1)||(b[5].cond==1))
						{
							gotoxy(10,28);
							printf("Voce so pode tirar de uma coluna por vez!!!");
						}
						else
						{
							selecionaPalito(c,1,7);
						}
						seta(x, y);
					break;
								
					case 56:
						if((a[3].cond==1)||(b[5].cond==1))
						{
							gotoxy(10,28);
							printf("Voce so pode tirar de uma coluna por vez!!!");
						}
						else
						{
							selecionaPalito(c,2,7);
						}
						seta(x, y);
					break;
								
					case 59:
						if((a[3].cond==1)||(b[5].cond==1))
						{
							gotoxy(10,28);
							printf("Voce so pode tirar de uma coluna por vez!!!");
						}
						else
						{
							selecionaPalito(c,3,7);
						}
						seta(x, y);
					break;
							
					case 62:
						if((a[3].cond==1)||(b[5].cond==1))
						{
							gotoxy(10,28);
							printf("Voce so pode tirar de uma coluna por vez!!!");
						}
						else
						{
							selecionaPalito(c,4,7);
						}
						seta(x, y);
					break;
								
					case 65:
						if((a[3].cond==1)||(b[5].cond==1))
						{
							gotoxy(10,28);
							printf("Voce so pode tirar de uma coluna por vez!!!");
						}
						else
						{
							selecionaPalito(c,5,7);
						}
						seta(x, y);
					break;
					
					case 68:
						if((a[3].cond==1)||(b[5].cond==1))
						{
							gotoxy(10,28);
							printf("Voce so pode tirar de uma coluna por vez!!!");
						}
						else
						{
							selecionaPalito(c,6,7);
						}
						seta(x, y);
					break;
				}
			break;
			
			case ESC:
				control= caixaDialogo(3, 0);
				system("cls");
			break;
		}
	}
	return control;
}

void menu()
{
	int car, control;
	int x=11, y=9;

	while(true)
	{
		gotoxy(10,6);
		printf("Menu:  ");
		gotoxy(12,9);
		printf(" 1 Jogador");
		gotoxy(12,11);
		printf(" 2 Jogadores");
		gotoxy(12,13);
		printf(" Sair");

		gotoxy(60,23);
		printf(" %c ", 30);
		gotoxy(60,25);
		printf(" %c ", 197);
		gotoxy(60,27);
		printf(" %c ", 31);
		
		fflush(stdin);
		car=getch();
		fflush(stdin);
		system("cls");
		
		switch(car)
		{
			case ACIMA:
				if(y==9)
				{
					y=15;
				}
				y=y-2;
				gotoxy(11,y);
				printf("%c",16);
			break;
			
			case ABAIXO:
				if(y==13)
				{
					y=7;
				}
				y=y+2;
				gotoxy(11,y);
				printf("%c",16);
			break;
			
			case ENTER:
				switch(y)
				{
					case 13:
						exit(0);
					break;

					case 9:
						do
						{
							system("cls");
							control= jogo(1);
						}
						while(control==ENTER);
						system("cls");
					break;

					case 11:
						do
						{
							system("cls");
							control= jogo(2);
						}
						while(control==ENTER);
						system("cls");
					break;
				}
			break;
			
			case ESQUERDA:
				gotoxy(11,y);
				printf("%c",16);
			break;
			
			case DIREITA:
				gotoxy(11,y);
				printf("%c",16);
			break;
		}
	}
}

int main()
{
	janela(90,33);
	
	esperar(1);
	gotoxy(10,5);
	printf("            ллллллл    ллллллл  лллл     ллл    лллллл             ");
	gotoxy(10,6);
	printf("          ллл    ллл  ллллллл  ллл лл   ллл    лллллллл            ");
	gotoxy(10,7);
	printf("         ллл          лл       ллл  лл  ллл   ллл    ллл           ");
	gotoxy(10,8);
	printf("        ллл          лллллл   ллл   лл ллл   ллл     ллл           ");
	gotoxy(10,9);
	printf("        ллл    лллл  лл       ллл    лллл   лллллллллллл           ");
	gotoxy(10,10);
	printf("         ллл     лл  лллллл  ллл     ллл    ллл       ллл          ");
	gotoxy(10,11);
	printf("          лллллллл  лллллл   ллл     ллл   ллл        ллл          ");
	gotoxy(10,12);	
	printf("                                                                   ");
	gotoxy(10,13);	
	printf("     ллллллл       лллллл       лллл     ллл     ллллллл   лллллл  ");
	gotoxy(10,14);	
	printf("   ллл    ллл     лллллллл     ллл лл   ллллл   ллллллл  ллл    лл ");
	gotoxy(10,15);	
	printf("  ллл            ллл    ллл    ллл лл  лл  лл   лл         ллл     ");
	gotoxy(10,16);	
	printf(" ллл            ллл     ллл   ллл   лл лл  лл  лллллл        ллл   ");
	gotoxy(10,17);	
	printf(" ллл    лллл   лллллллллллл   ллл   лллл  лл   лл             ллл  ");
	gotoxy(10,18);	
	printf("  ллл     лл   ллл       ллл  ллл    лл   лл   ллллл    ллл   ллл  ");
	gotoxy(10,19);	
	printf("   лллллллл   ллл        ллл ллл          лл  ллллл      лллллл    ");
	
	esperar(2);
	system("cls");
	
	menu();
	
	return 0;
}
