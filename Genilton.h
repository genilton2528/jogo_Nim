#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>

#define ACIMA 72
#define ABAIXO 80
#define DIREITA 77
#define ESQUERDA 75
#define ENTER 13
#define ESC 27
#define PALITO 219
#define ESPACO 32

typedef struct sColuna
{
	int cond;
	int select;
}COLUNA;

int inteligenciaArtificial(COLUNA a[], COLUNA b[], COLUNA c[]);

int verificaSelecionados(COLUNA a[], COLUNA b[], COLUNA c[]);

int verificaCor(COLUNA v[], int pos);

int verificaAlteracao(COLUNA v[], int ult);

int setPlayer(int player, COLUNA a[], COLUNA b[], COLUNA c[]);

int verificaVencedor(COLUNA a[], COLUNA b[], COLUNA c[]);

int caixaDialogo(int a, int b);

int contaPalito(COLUNA v[], int ult);

int converteDec(int v[]);

void tirarPalitos(COLUNA v[], int qtd);

void verificaJogada(int v[], int col1[], int col2[], int col3[]);

void converteBin(int qt, int v[]);

void desenhaColunas(COLUNA a[], COLUNA b[], COLUNA c[]);

void desenhaPalito(COLUNA C[], int x, int pos);

void inicializaColuna(COLUNA c[], int tam);

void cortexto (int COR);
	
void selecionaPalito(COLUNA v[], int pos, int ult);

void seta(int x, int y);

void cortexto (int COR);

void janela(int x, int y);

void gotoxy(short x, short y);

void esperar(int segundos);

int verificaCor(COLUNA v[], int pos)
{
	if(v[pos].select==0)
	{
		return 113;
	}
	return 121;
}

void cortexto (int COR){
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),COR);
}

void janela(int x, int y)
{
    system("title Jogo Nim - Genilton");
    system("color 71");
  
	COORD outbuff;
	outbuff.X = x;
	outbuff.Y = y;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleScreenBufferSize(hConsole, outbuff);
	Sleep(130);
	SMALL_RECT windowSize = {0, 0, x-1, y-1};
	SetConsoleWindowInfo(hConsole, TRUE, &windowSize);
}

void gotoxy(short x, short y) 
{
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void esperar(int segundos)
{
	clock_t cicloFinal;
	cicloFinal= clock() + segundos * CLOCKS_PER_SEC;
	while (clock() < cicloFinal); 
}

void seta(int x, int y)
{
	gotoxy(x,y);
	printf("%c",30);
}

void selecionaPalito (COLUNA v[], int pos, int ult)
{
	switch(v[pos].select)
	{
		case 1:
			v[pos].select=0;
			v[ult].cond= verificaAlteracao(v,ult);
		break;
		
		case 0:
			v[pos].select=1;
			v[ult].cond=1;
		break;
		
		case 2:
			gotoxy(10,28);
			printf("Voce nao pode selecionar esse palito");
		break;
	}
}

int verificaAlteracao(COLUNA v[], int ult)
{
	int i;
	
	for(i=0;i<ult;i++)
	{
		if(v[i].select==1)
		{
			return 1;
		}
	}
	return 0;
}


int setPlayer(int player, COLUNA a[], COLUNA b[], COLUNA c[])
{	
	a[3].cond=0;
	b[5].cond=0;
	c[7].cond=0;
			
	if(player==0) return 1;
	if(player==1) return 0;
}

void inicializaColuna(COLUNA c[], int tam)
{
	int i;
	for(i=0;i<tam;i++)
	{
		c[i].cond=219;
		c[i].select=0;
	}
}

void desenhaPalito(COLUNA c[], int x, int pos)
{
	gotoxy(x,17); printf("%c",  c[pos].cond); 
	gotoxy(x,18); printf("%c",  c[pos].cond); 
	gotoxy(x,19); printf("%c",  c[pos].cond);
}

void desenhaColunas(COLUNA a[], COLUNA b[], COLUNA c[])
{
	cortexto(verificaCor(a,0)); 		
	desenhaPalito(a, 15, 0);
		
	cortexto(verificaCor(a,1)); 		
	desenhaPalito(a, 18, 1);
	
	cortexto(verificaCor(a,2)); 
	desenhaPalito(a, 21, 2);		

	cortexto(verificaCor(b,0)); 
	desenhaPalito(b, 30, 0);		
		
	cortexto(verificaCor(b,1)); 
	desenhaPalito(b, 33, 1);	
			
	cortexto(verificaCor(b,2)); 
	desenhaPalito(b, 36, 2);	
			
	cortexto(verificaCor(b,3)); 
	desenhaPalito(b, 39, 3);	
			
	cortexto(verificaCor(b,4)); 
	desenhaPalito(b, 42, 4);	
			
	cortexto(verificaCor(c,0)); 
	desenhaPalito(c, 50, 0);	
			
	cortexto(verificaCor(c,1)); 
	desenhaPalito(c, 53, 1);	
			
	cortexto(verificaCor(c,2)); 
	desenhaPalito(c, 56, 2);	
			
	cortexto(verificaCor(c,3)); 
	desenhaPalito(c, 59, 3);	
			
	cortexto(verificaCor(c,4)); 
	desenhaPalito(c, 62, 4);	
			
	cortexto(verificaCor(c,5)); 
	desenhaPalito(c, 65, 5);	
			
	cortexto(verificaCor(c,6)); 
	desenhaPalito(c, 68, 6);		
		
	cortexto(113); 
	
	gotoxy(10,31);
	printf(" [ Espaco ] Seleciona      [ Enter ] Exclui        %c  %c  %c ",17, 197,16);
}

int verificaVencedor(COLUNA a[], COLUNA b[], COLUNA c[])
{
	int p=0, i;
	
	for(i=0;i<3;i++)
	{
		if(a[i].select==1)
		{
			a[i].cond=32;
			a[i].select=2;
		}
	}
	
	for(i=0;i<5;i++)
	{
		if(b[i].select==1)
		{
			b[i].cond=32;
			b[i].select=2;
		}
	}

	for(i=0;i<7;i++)
	{
		if(c[i].select==1) 
		{
			c[i].cond=32;
			c[i].select=2;
		}
	}
		
	for(i=0;i<3;i++)
	{
		if(a[i].cond==219)
		{
			break;
		}
		p++;		
	}
	
	for(i=0;i<5;i++)
	{
		if(b[i].cond==219)
		{
			break;
		}
		p++;		
	}

	for(i=0;i<7;i++)
	{
		if(c[i].cond==219)
		{
			break;
		}
		p++;		
	}
	return p;
}

int caixaDialogo(int a, int b)
{
	int car;
	switch(a)
	{
		case 1:
			gotoxy(10,7);	
			printf("                                         ");
			gotoxy(10,8);	
			printf(" _____________________________________ ");
			gotoxy(10,9);	
			printf(" %c                                   %c ", 219, 219);
			gotoxy(10,10);	
			printf(" %c        Jogador %d Venceu           %c ", 219, b+1, 219);
			gotoxy(10,11);	
			printf(" %c                                   %c ", 219, 219);
			gotoxy(10,12);	
			printf(" %c        Voce quer sair%c            %c ", 219, 63,219);
			gotoxy(10,13);	
			printf(" %c                                   %c ", 219, 219);
			gotoxy(10,14);	
			printf(" %c     [Esc] Sair    [Enter] Replay  %c ", 219, 219);
			gotoxy(10,15);	
			printf(" %c                                   %c ", 219, 219);
			gotoxy(10,16);	
			printf(" %c___________________________________%c ", 219, 219);
			gotoxy(10,17);	
			printf("                                         \n\n\n\n");
			
			while(0==0)
			{
				car= getch();
				switch(car)
				{
					case ESC:
						return ESC;
					break;

					case ENTER:
						return ENTER;
					break;
				}
			}
		break;
		
		case 2:
			gotoxy(10,29);
			printf("Voce tem que tirar pelo menos um palito!!");
		break;
		
		case 3:
			gotoxy(10,10);	
			printf("                                         ");
			gotoxy(10,11);	
			printf(" _____________________________________ ");
			gotoxy(10,12);	
			printf(" %c        Voce quer sair%c            %c ", 219, 63,219);
			gotoxy(10,13);	
			printf(" %c                                   %c ", 219, 219);
			gotoxy(10,14);	
			printf(" %c     [Esc] Sim    [Enter] Nao      %c ", 219, 219);
			gotoxy(10,15);	
			printf(" %c                                   %c ", 219, 219);
			gotoxy(10,16);	
			printf(" %c___________________________________%c ", 219, 219);
			gotoxy(10,17);	
			printf("                                         \n\n\n\n");
			
			while(0==0)
			{
				car= getch();
				switch(car)
				{
					case ESC:
						return ESC;
					break;

					case ENTER:
						return 0;
					break;
				}
			}	
		break;
		
		case 4:
			system("cls");
			gotoxy(10,7);	
			printf("                                         ");
			gotoxy(10,8);	
			printf(" _____________________________________ ");
			gotoxy(10,9);	
			printf(" %c                                   %c ", 219, 219);
			gotoxy(10,10);	
			printf(" %c       O computador Venceu!        %c ", 219, 219);
			gotoxy(10,11);	
			printf(" %c                                   %c ", 219, 219);
			gotoxy(10,12);	
			printf(" %c        Voce quer sair             %c ", 219, 219);
			gotoxy(10,13);	
			printf(" %c                                   %c ", 219, 219);
			gotoxy(10,14);	
			printf(" %c     [Esc] Sair    [Enter] Replay  %c ", 219, 219);
			gotoxy(10,15);	
			printf(" %c                                   %c ", 219, 219);
			gotoxy(10,16);	
			printf(" %c___________________________________%c ", 219, 219);
			gotoxy(10,17);	
			printf("                                         \n\n\n\n");
			
			while(0==0)
			{
				car= getch();
				switch(car)
				{
					case ESC:
						return ESC;
					break;

					case ENTER:
						return ENTER;
					break;
				}
			}
		break;
	}
}

int verificaSelecionados(COLUNA a[], COLUNA b[], COLUNA c[])
{
	int cont, i;
	
	for(i=0;i<3;i++)
	{
		if(a[i].select==1)
		{
			cont++;
		}
	}
	
	for(i=0;i<5;i++)
	{
		if(b[i].select==1)
		{
			cont++;		}
	}

	for(i=0;i<7;i++)
	{
		if(c[i].select==1) 
		{
			cont++;
		}
	}	
	
	return cont;
}

int contaPalito(COLUNA v[], int ult)
{
	int i, cont=0;
	
	for(i=0;i<ult;i++)
	{
		if(v[i].cond==219)
		{
			cont++;
		}
	}
	return cont;	
}

int inteligenciaArtificial(COLUNA a[], COLUNA b[], COLUNA c[])
{
	int qtCol1=contaPalito(a,3);
	int qtCol2=contaPalito(b,5);
	int qtCol3=contaPalito(c,7);
	
	int col1[3], col2[3], col3[3];
	
	converteBin(qtCol1, col1);
	converteBin(qtCol2, col2);
	converteBin(qtCol3, col3);
	
	int v[3];
	
	verificaJogada(v, col1, col2, col3);
	
	tirarPalitos(a, qtCol1-converteDec(col1));
	tirarPalitos(b, qtCol2-converteDec(col2));
	tirarPalitos(c, qtCol3-converteDec(col3));
	
	if(verificaVencedor(a, b, c)==15)
	{
		return 15;
	}
	
	return 0;
}

void converteBin(int qt, int v[])
{
	int i, aux;
	
	v[0]=0;
	v[1]=0;
	v[2]=0;

	for(i=0;qt>=1;i++)
	{
		v[i]=qt%2;
		qt=qt/2;
	}
	v[i]=qt;
	
	aux=v[2];
	v[2]=v[0];
	v[0]=aux;
}

void verificaJogada(int v[], int col1[], int col2[], int col3[])
{
	v[0]=col1[0]+col2[0]+col3[0];
	v[1]=col1[1]+col2[1]+col3[1];
	v[2]=col1[2]+col2[2]+col3[2];

	if((v[0]%2==0)&&(v[1]%2==0)&&(v[2]%2==0))
	{
		if(col3[0]!=0) //coluna 3
		{
			col3[0]=0;
		}
		else if(col2[0]!=0) //coluna 2
		{
			col2[0]=0;
		}
		else if(col1[0]!=0) //coluna 1
		{
			col1[0]=0;			
		}
		else if(col3[1]!=0) //coluna 3
		{
			col3[1]=0;
		}
		else if(col2[1]!=0) //coluna 2
		{
			col2[1]=0;
		}
		else if(col1[1]!=0) //coluna 1
		{
			col1[1]=0;			
		}
		else if(col3[2]!=0) //coluna 3
		{
			col3[2]=0;
		}
		else if(col2[2]!=0) //coluna 2
		{
			col2[2]=0;
		}
		else if(col1[2]!=0) //coluna 1
		{
			col1[2]=0;			
		}			
	}
	else if((v[0]%2)!=0)
	{
		if(col3[0]!=0) //coluna 3
		{
			col3[0]=0;
			
			if(v[1]%2!=0)
			{
				if(col3[1]==1)
				{
					col3[1]=0;
				}
				else
				{
					col3[1]=1;
				}
			}
			if(v[2]%2!=0)
			{
				if(col3[2]==1)
				{
					col3[2]=0;
				}
				else
				{
					col3[2]=1;
				}
			}			
		}
		else if(col2[0]!=0) //coluna 2
		{
			col2[0]=0;
			
			if(v[1]%2!=0)
			{
				if(col2[1]!=0)
				{
					col2[1]=0; 	
				}
				else
				{
					col2[1]=1; 
				}
			}
			if(v[2]%2!=0)
			{
				if(col2[2]!=0)
				{
					col2[2]=0; 	
				}
				else
				{
					col2[2]=1; 
				}
			}
		}
		else if(col1[0]!=0) //coluna 1
		{
			col1[0]=0;
			
			if(v[1]%2!=0)
			{
				if(col1[1]!=0)
				{
					col1[1]=0; 	
				}
				else
				{
					col1[1]=1; 
				}
			}
			if(v[2]%2!=0)
			{
				if(col1[2]!=0)
				{
					col1[2]=0; 	
				}
				else
				{
					col1[2]=1; 
				}
			}
		}
	}
	else if((v[1]%2)!=0)
	{
		if(col3[1]!=0) //coluna 3
		{
			col3[1]=0;
			
			if(v[2]%2!=0)
			{
				if(col3[2]==1)
				{
					col3[2]=0;
				}
				else
				{
					col3[2]=1;
				}
			}			
		}
		else if(col2[1]!=0) //coluna 2
		{
			col2[1]=0;
			
			if(v[2]%2!=0)
			{
				if(col2[2]!=0)
				{
					col2[2]=0; 	
				}
				else
				{
					col2[2]=1; 
				}
			}			
		}
		else if(col1[1]!=0) //coluna 1
		{
			col1[1]=0;
			
			if(v[2]%2!=0)
			{
				if(col1[2]!=0)
				{
					col1[2]=0; 	
				}
				else
				{
					col1[2]=1; 
				}
			}
		}
	}
	else if((v[2]%2)!=0)
	{
		if(col3[2]!=0) //coluna 3
		{
			col3[2]=0;			
		}
		else if(col2[2]!=0) //coluna 2
		{
			col2[2]=0;
		}
		else if(col1[2]!=0) //coluna 1
		{
			col1[2]=0;			
		}
	}
}

int converteDec(int v[])
{
	int dec=0, i;
	for(i=0;i<3;i++)
	{
		if(v[i]==1)
		{
			switch(i)
			{
			case 0:
				dec+=4;
			break;
			case 1:
				dec+=2;
			break;
			case 2:
				dec+=1;
			break;
			}
		}
	}
	return dec;
}

void tirarPalitos(COLUNA v[], int qtd)
{
	int i;
	for(i=0;qtd>0;i++)
	{
		if(v[i].cond==219)
		{
			v[i].cond=32;
			qtd--;
		}
	}
}
