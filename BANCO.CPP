# include <string.h>
# include <stdio.h>
# include <conio.h>
# include <ctype.h>
# include <process.h>
#define LEFT_TOP  0xC9
#define RIGHT_TOP 0xBB
#define HORIZ     0xCD
#define VERT      0xBA
#define LEFT_BOT  0xC8
#define RIGHT_BOT 0xBC
struct cliente
	  {
	  char nome[40];
	  char conta[11];
	  float saldod;
	  float saldol;
	  int carac;
	  };
void cadastro (struct cliente *v);
void deposito (struct cliente *v);
void saque (struct cliente *v);
void saldo (struct cliente *v);
void alteracao (struct cliente *v);
void margem();
void limpar();
void limpar1();
int verif(char *);
void main ()
{
struct cliente vetor[5],*p;
int n;
char op='1';
p = vetor;
for (n=0;n<5;n++,p++)
	{
	strcpy(p->nome,"\0");
	strcpy(p->conta,"\0");
	p->saldod=0;
	p->saldol=0;
	p->carac=0;
	}
margem();
while (op != '6')
	{
	limpar();
	//clrscr();
	gotoxy (12,7);
	printf ("Cadastro - Banco");
	gotoxy (7,9);
	printf ("1 - Cadastrar Clientes");
	gotoxy (7,10);
	printf ("2 - Deposito");
	gotoxy (7,11);
	printf ("3 - Saque");
	gotoxy (7,12);
	printf ("4 - Saldo");
	gotoxy (7,13);
	printf ("5 - Alteracao");
	gotoxy (7,14);
	printf ("6 - Sair");
	gotoxy (7,16);
	printf ("Digite a opcao: ");
	op=getche();
	switch (op)
		{
		case '1':cadastro(vetor);
			 break;
		case '2':deposito(vetor);
			 break;
		case '3':saque(vetor);
			 break;
		case '4':saldo(vetor);
			 break;
		case '5':alteracao(vetor);
			 break;
		}
	}
getch();
clrscr();
}
void cadastro (struct cliente *v)
{
FILE *fp;
int c,r=0;
char op;
//clrscr();
limpar1();
fflush(stdin);
fp = fopen ("c:\\cadastro.dat","ab");
gotoxy (50,7);
printf ("Cadastro de Cliente");
gotoxy (42,9);
fflush (stdin);
printf ("Nome:");
gets(v->nome);
//r=verif(v->nome);/* Verifica se ja existe esse nome*/
if (r==1)
	{
	gotoxy(47,10);
	printf("Cliente ja cadastrado!");
	getch();
	goto fim;
	}
gotoxy (42,10);
printf ("Conta:");
fflush (stdin);
scanf("%s",&v->conta);
rep:gotoxy (42,11);
printf ("Cliente Especial ?(S/N) ");
op=getche();
op=toupper(op);
if (op!='S' && op!='N')
	{
	gotoxy (52,13);
	printf("Opcao invalida.");
	gotoxy (51,14);
	printf("Digite novamente!");
	getch();
	gotoxy (52,13);
	printf("               ");
	gotoxy (51,14);
	printf("                 ");
	gotoxy (42,11);
	printf ("                          ");
	goto rep;
	}
if (op=='S')
	v->carac=1;
else
	v->carac=0;
v->saldod = 0;
if (v->carac==1)
	v->saldol = 1000;
else
	v->saldol = 0;
gotoxy (42,12);
printf ("Saldo disponivel: %2.f",v->saldod);
gotoxy (42,13);
printf ("Saldo limite: %2.f",v->saldol);
fwrite (v,sizeof(struct cliente),1,fp);
fim:
fclose (fp);
getch();
limpar1();
}
void deposito (struct cliente *v)
{
FILE *fp;
struct cliente *v1;
int r,w=0,prot=0;
char n[11];
float D;
//clrscr();
limpar1();
fflush(stdin);
fp = fopen ("c:\\cadastro.dat","rb");
v1=v;
gotoxy(55,7);
printf ("Deposito");
rep1:gotoxy(42,9);
printf ("Digite o numero da conta:");
scanf("%s",&n);
while(!feof(fp))
	{
	fread(v,sizeof(struct cliente),1,fp);
	if (!strcmp(v->conta,n))
		{
		w=1;
		goto cont;
		}
	}
cont:
fclose(fp);
fp = fopen("c:\\cadastro.dat","r+b");
if (w==0)
	{
	prot++;
	if (prot==3)
		{
		gotoxy(39,11);
		printf("Pressione <ENTER> para sair do programa!");
		getch();
		exit(0);
		}
	gotoxy(47,11);
	printf("Numero de conta invalido!");
	gotoxy(51,13);
	printf("Pressione <ENTER>");
	gotoxy(45,14);
	printf("e digite novamente o numero!");
	getch();
	gotoxy(42,9);
	printf("                         ");
	gotoxy(47,11);
	printf("                              ");
	gotoxy(51,13);
	printf("                              ");
	gotoxy(45,14);
	printf("                                   ");
	v=v1;
	goto rep1;
	}
gotoxy(42,10);
printf ("Nome: %s",v->nome);
gotoxy(42,11);
printf ("Conta: %s",v->conta);
gotoxy(42,12);
printf ("Saldo disponivel: %2.f",v->saldod);
gotoxy(42,13);
printf ("Saldo limite: %2.f",v->saldol);
gotoxy(42,14);
printf ("Digite o valor a ser depositado: ");
scanf ("%f",&D);
if (v->carac==1)
	if (v->saldod<0)
		{
		v->saldol = v->saldol + D;
		if (v->saldol > 1000)
			v->saldol = 1000;
		}
v->saldod = v->saldod + D;
gotoxy(42,15);
printf ("Saldo disponivel = %2.f",v->saldod);
gotoxy(42,16);
printf ("Saldo limite = %2.f",v->saldol);
fwrite (v,sizeof(struct cliente),1,fp);
fclose (fp);
getch();
limpar1();
}
void saque(struct cliente *v)
{
FILE *fp;
struct cliente *v1;
int c,w=0,prot=0;
char n[11];
float D,R;
//clrscr();
limpar1();
fp = fopen ("c:\\cadastro.dat","rb");
v1=v;
fflush(stdin);
gotoxy(56,7);
printf ("Saque");
rep:gotoxy(42,9);
printf ("Digite o numero da conta:");
scanf("%s",&n);
while(!feof(fp))
	{
	fread(v,sizeof(struct cliente),1,fp);
	if (!strcmp(v->conta,n))
		{
		w=1;
		goto cont;
		}
	}
cont:
fclose(fp);
fp = fopen("c:\\cadastro.dat","r+b");
if (w==0)
	{
	prot++;
	if (prot==3)
		{
		gotoxy(39,11);
		printf("Pressione <ENTER> para sair do programa!");
		getch();
		exit(0);
		}
	gotoxy(47,11);
	printf("Numero de conta invalido!");
	gotoxy(51,13);
	printf("Pressione <ENTER>");
	gotoxy(45,14);
	printf("e digite novamente o numero!");
	getch();
	gotoxy(42,9);
	printf("                             ");
	gotoxy(47,11);
	printf("                               ");
	gotoxy(51,13);
	printf("                               ");
	gotoxy(45,14);
	printf("                               ");
	v=v1;
	goto rep1;
	}
gotoxy(42,10);
printf ("Nome: %s",v->nome);
gotoxy(42,11);
printf ("Conta: %s",v->conta);
gotoxy(42,12);
printf ("Saldo disponivel: %2.f",v->saldod);
gotoxy(42,13);
printf ("Saldo limite: %2.f",v->saldol);
rep1:gotoxy(42,14);
printf ("Digite o valor a ser retirado: ");
scanf ("%f",&D);
if (D > v->saldod + v->saldol)
	{
	gotoxy(45,16);
	printf("Valor nao pode ser retirado!");
	getch();
	gotoxy(45,16);
	printf("                             ");
	gotoxy(42,14);
	printf("                                ");
	goto rep1;
	}
if (D > v->saldod)
	if (v->saldod < 0)
		v->saldol = v->saldol - D;
	else
		{
		R = v->saldod - D;
		v->saldol = v->saldol + R;
		}
v->saldod = v->saldod - D;
gotoxy(42,15);
printf ("Saldo disponivel = %2.f",v->saldod);
gotoxy(42,16);
printf ("Saldo limite = %2.f",v->saldol);
fwrite (v,sizeof(struct cliente),1,fp);
fclose (fp);
getch();
limpar1();
}
void saldo(struct cliente *v)
{
FILE *fp;
struct cliente *v1;
int w=0,prot=0;
char n[11];
limpar1();
//clrscr();
if ((fp = fopen("c:\\cadastro.dat","rb"))==NULL)
	{
	gotoxy (35,10);
	puts("Arquivo nao encontrado");
	getch();
	goto fim;
	}
v1=v;
fflush(stdin);
gotoxy(56,7);
printf ("Saldo");
rep:gotoxy(42,9);
printf ("Digite o numero da conta:");
scanf("%s",&n);
while(!feof(fp))
	{
	fread(v,sizeof(struct cliente),1,fp);
	if (!strcmp(v->conta,n))
		{
		w=1;
		goto cont;
		}
	}
cont:
if (w==0)
	{
	prot++;
	if (prot==3)
		{
		gotoxy(39,11);
		printf("Pressione <ENTER> para sair do programa!");
		getch();
		exit(0);
		}
	gotoxy(47,11);
	printf("Numero de conta invalido!");
	gotoxy(51,13);
	printf("Pressione <ENTER>");
	gotoxy(45,14);
	printf("e digite novamente o numero!");
	getch();
	gotoxy(42,9);
	printf("                         ");
	gotoxy(47,11);
	printf("                              ");
	gotoxy(51,13);
	printf("                              ");
	gotoxy(45,14);
	printf("                              ");
	v=v1;
	goto rep;
	}
gotoxy(42,10);
printf ("Nome: %s",v->nome);
gotoxy(42,11);
printf ("Conta: %s",v->conta);
gotoxy(42,12);
printf ("Saldo disponivel: %2.f",v->saldod);
gotoxy(42,13);
printf ("Saldo limite: %2.f",v->saldol);
getch();
fim: fclose(fp);
limpar1();
}
void alteracao(struct cliente *v)
{
FILE *fp;
struct cliente *v1;
int w=0,prot=0;
char op;
char n[11];
//clrscr();
limpar1();
fp = fopen("c:\\cadastro.dat","rb");
v1=v;
gotoxy(55,7);
printf("Alteracao");
rep:gotoxy(42,9);
printf ("Digite o numero da conta:");
scanf("%s",&n);
while(!feof(fp))
	{
	fread(v,sizeof(struct cliente),1,fp);
	if (!strcmp(v->conta,n))
		{
		w=1;
		goto cont;
		}
	}
cont:
fclose(fp);
fp = fopen("c:\\cadastro.dat","r+b");
if (w==0)
	{
	prot++;
	if (prot==3)
		{
		gotoxy(39,11);
		printf("Pressione <ENTER> para sair do programa!");
		getch();
		exit(0);
		}
	gotoxy(47,11);
	printf("Numero de conta invalido!");
	gotoxy(51,13);
	printf("Pressione <ENTER>");
	gotoxy(45,14);
	printf("e digite novamente o numero!");
	getch();
	gotoxy(42,9);
	printf("                         ");
	gotoxy(47,11);
	printf("                             ");
	gotoxy(51,13);
	printf("                             ");
	gotoxy(45,14);
	printf("                             ");
	v=v1;
	goto rep1;
	}
gotoxy(42,10);
printf ("Nome: %s",v->nome);
gotoxy(42,11);
printf ("Conta: %s",v->conta);
gotoxy(42,12);
printf ("Saldo disponivel: %2.f",v->saldod);
gotoxy(42,13);
printf ("Saldo limite: %2.f",v->saldol);
rep1:gotoxy (46,14);
printf ("Cliente Especial ?(S/N) ");
op=getche();
op=toupper(op);
if (op!='S' && op!='N')
	{
	gotoxy (51,15);
	printf("Opcao invalida.");
	gotoxy (50,16);
	printf("Digite novamente!");
	getch();
	gotoxy (51,15);
	printf("               ");
	gotoxy (50,16);
	printf("                 ");
	gotoxy (42,14);
	printf ("                        ");
	goto rep1;
	}
if (op=='S')
	v->carac=1;
else
	v->carac=0;
if (v->carac==1)
	v->saldol = 1000;
else
	v->saldol = 0;
gotoxy(42,16);
printf("Saldo disponivel: %2.f",&v->saldod);
gotoxy(42,17);
printf("Saldo limite: %2.f",&v->saldol);
fwrite (v,sizeof(struct cliente),1,fp);
fclose (fp);
getch();
limpar1();
}
void margem()
{
char l, c;
int h;
clrscr();
putchar(LEFT_TOP);
for (c=0; c<=77; c++)
	putchar(HORIZ);
putchar(RIGHT_TOP);
for (l=0; l<=2; l++)
	{
	putchar(VERT);
	for (c=0; c<=77; c++)
		putchar(' ');
	putchar(VERT);
	}
putchar(0xCC);
for (c=0; c<=76; c++)
	{
	if (c==38)
		putchar(0xD1);
	putchar(HORIZ);
	}
putchar(0xB9);
for (l=3; l<=16; l++)
	{
	for (c=0; c<=77; c++)
		{
		if (c==0)
			putchar(VERT);
		if (c==77)
			{
			putchar(VERT);
			goto fim;
			}
		if (c==38)
			putchar(0xB3);
		putchar(' ');
		fim;
		}
	}
putchar(0xCC);
for (c=0; c<=76; c++)
	{
	if (c==38)
		putchar(0xCF);
	putchar(HORIZ);
	}
putchar(0xB9);
for (l=0; l<=2; l++)
	{
	putchar(VERT);
	for (c=0; c<=77; c++)
		putchar(' ');
	putchar(VERT);
	}
putchar(LEFT_BOT);
for (c=0; c<=77; c++)
	putchar(HORIZ);
putchar(RIGHT_BOT);
gotoxy(27,2);
textcolor(7);
cprintf(" A.M.R. & L.F.O.C. Company ");
gotoxy(10,4);
printf("Software - Banco de Dados - Cadastro de Clientes de um Banco");
}
void limpar()
{
int l=16,c=7;
for (;c<36;c++)
	{
	gotoxy(c,l);
	printf(" ");
	}
/*for (l=6;l<20;l++)
	for (c=3;c<36;c++)
		{
		gotoxy(c,l);
		printf(" ");
		}*/
}
void limpar1()
{
int l,c;
for (l=6;l<20;l++)
	for (c=41;c<80;c++)
		{
		gotoxy(c,l);
		printf(" ");
		}
}
/*int verif (char *v1)
{
FILE *fp;
int w=0;
struct cliente *v;
while(!feof(fp))
	{
	fread(v,sizeof(struct cliente),1,fp);
	if (!strcmp(v->nome,v1))
		{
		w=1;
		goto cont;
		}
	}
cont:
return(w);
}*/