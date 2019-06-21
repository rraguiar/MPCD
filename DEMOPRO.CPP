# include <stdio.h>
# include <dos.h>
# include <conio.h>
# include <string.h>
//***************************************************************************
typedef struct filme
{
char titulo[40];
char especie[30];         //declaracao da struct filme
int numero;
char reservado[40];
char lancamento[12];
}LOC;//foi criada a variavel LOC
//*************************************************************************
typedef struct cliente
{
char cod[5];
char nome[40];
char rg[30];
char end[50];       //declaracao da struct cliente
char tel[20];
char filme[40];
char dloc[10];
char ddev[10];
} CLI;//foi criada a variavel CLI
//***************************************************************************
FILE *a1,*a2;//declara os ponteiros de arquivo
LOC dados;//dados foi declarado do tipo LOC          //declaracao global
CLI dados2;//dados2 foi declarado do tipo LOC
//**************************************************************************
//funcao cadastrar
void cadastro()
{
int x,s;
char r;
clrscr();
printf("\n\n\t MENU CADASTRAR FILMES");
printf("\nDigite  sua opcao");
printf("\n\n1 -Acao");
printf("\n\n2 -Comedia");
printf("\n\n3 -Policial");
printf("\n\n4 -Ficcao");
printf("\n\n5 -Terror");
printf("\n\n6 -Romance");
printf("\n\n7 -Infantil");
printf("\n\nDigite a especie: ");
do{//inicio do laco de protecao
scanf("%d",&s);
}while(s!=1&&s!=2&&s!=3&&s!=4&&s!=5&&s!=6&&s!=7);//fim do laco de protecao
//--------------------------------------------------------------------------
if(s==1)
a1=fopen("acao.dat","a+t");
if(s==2)
a1=fopen("comedia.dat","a+t");
if(s==3)
a1=fopen("policial.dat","a+t");
if(s==4)                           //criacao do arquivos de acordo com a
a1=fopen("ficcao.dat","a+t");     //especie tanto para escrita como para atualizacao
if(s==5)
a1=fopen("terror.dat","a+t");
if(s==6)
a1=fopen("romance.dat","a+t");
if(s==7)
a1=fopen("infantil.dat","a+t");
//__________________________________________________________________________
if(a1!=NULL)//protecao contra algum erro
{
fseek(a1,0L,SEEK_END);//coloca o ponteiro na posicao final do arquivo
do{//inicio do laco de repeticao
fseek(a1,0L,SEEK_CUR);//coloca o ponteiro de arquivos na posicao corrente para colocar na ordem que sao gravado os dados
clrscr();
printf("\n\n\t\tCADASTRANDO FILME");
printf("\n\nDigite o nome do filme: ");
fflush(stdin);//limpar o buffer de teclado para nao ler lixo
gets(dados.titulo);
printf("\nEspecie:\n");
gets(dados.especie);
printf("\nNumero:\n");
scanf("%d",&dados.numero);
printf("\nReservado para:\n");
fflush(stdin);
gets(dados.reservado);
printf("\nLancamento\n");
fflush(stdin);
gets(dados.lancamento);
fwrite(&dados,sizeof(dados),1,a1);//escreve no dados no arquivo de acordo de qual foi aberto
printf("\nDeseja continuar (S/N) ?");//pergunta se que continuar o cadastro de filme
do{//laco de protecao para continuar cadastrando
scanf("%c",&r);
}while(r!='s'&&r!='n');//fim do laco para continuar cadastrando
fflush(stdin);
}while(r=='s'&&r!='n');//fim do laco de repeticao
}//fim da protecao
fclose(a1);
}//fim do cadastro
//****************************************************************************_
//funcao procura
void procurar()
{
char r1,nome[40],nome2[40],m;
int e,n,c;
clrscr();
printf("\n\n\tTIPO DE PROCURA");
printf("\n\t1- Por Titulo");
printf("\n\t2- Por Especie");
printf("\n\t3- Por numero de locacoes");
printf("\n\n\t Digite a opcao: ");
do{//laco de protecao
scanf("%d",&m);
}while(m!=1&&m!=2&&m!=3);//fim do laco de protecao
clrscr();
if(m==1)//inicio do procurar por titulo
{
printf("\n\tMENU PROCURAR POR TITULO");
printf("\n\n1 -Acao");
printf("\n\n2 -Comedia");
printf("\n\n3 -Policial");
printf("\n\n4 -Ficcao");
printf("\n\n5 -Terror");
printf("\n\n6 -Romance");
printf("\n\n7 -Infantil");
printf("\n\nDigite a especie:");
do{//inicio do laco de protecao
scanf("%d",&e);
}while(e!=1&&e!=2&&e!=3&&e!=4&&e!=5&&e!=6&&e!=7);//fim do laco de protecao
//_________________________________________________________________________
if(e==1)
a1=fopen("acao.dat","rt");
if(e==2)
a1=fopen("comedia.dat","rt");
if(e==3)
a1=fopen("policial.dat","rt");
if(e==4)
a1=fopen("ficcao.dat","rt");       //abertura do arquivo para leitura que e
if(e==5)                           //feita de acordo com o estilo do filme
a1=fopen("terror.dat","rt");
if(e==6)
a1=fopen("romance.dat","rt");
if(e==7)
a1=fopen("infantil.dat","rt");
//__________________________________________________________________________
rewind(a1);//para voltar o ponteiro de arquivos para a posicao inicial devido a funcao cadastrar deixar o ponteiro sempre no final do arquivo
do{//inicio do laco de  repeticao
clrscr();
printf("\n\n Digite o nome do Filme:");//le o nome do filme procurado
fflush(stdin);//limpa o buffer de teclado
gets(nome);
while(fread(&dados,sizeof(dados),1,a1)==1){//laco de procura
if (!strcmp (nome,dados.titulo))//inicio da condicao
{//inicio do if2
printf("\n\n\t FILME");
printf("\n NOME:\n");
fflush(stdin);
puts(dados.titulo);
printf("\n ESPECIE:\n");
puts(dados.especie);
printf("\n NUMERO:\n");
printf("%d",dados.numero);
printf("\n RESERVADO:\n");
puts(dados.reservado);
printf("\n LANCAMENTO:\n");
puts(dados.lancamento);
getch();
break;
}//fim da condicao
}//fim do laco de procura
if (strcmp (nome,dados.titulo))//condicao definida para indicar que o filme nao foi encontrado
printf("filme nao cadastrado !");
rewind(a1);// voltar o ponteiro de arquivos para o inicio do arquivo para servir como protecao contra filmes cadastrados que nao sao encontrados
printf("\n\tDeseja continuar (S/N) ?\n");//pergunta se que continuar o cadastro de filme
do{//inicio do laco de protecao
scanf("%c",&r1);
}while(r1!='s'&&r1!='n');//fim do laco de protecao
//fflush(stdin);
}while(r1=='s'&&r1!='n');//fim do laco de repeticao
fclose(a1);
}//fim do procurar por titulo
//__________________________________________________________________________
if(m==2)//inicio do procurar por especie
{
printf("\n\n\tMENU PROCURAR POR ESPECIE");
printf("\n1 -Acao");
printf("\n2 -Comedia");
printf("\n3 -Policial");
printf("\n4 -Ficcao");
printf("\n5 -Terror");
printf("\n6 -Romance");
printf("\n7 -Infantil");
printf("\nDigite a especie: ");
do{//inicio do laco de protecao
scanf("%d",&e);
}while(e!=1&&e!=2&&e!=3&&e!=4&&e!=5&&e!=6&&e!=7);//fim do laco de protecao
//____________________________________________________________________________
if(e==1)//tipo acao
a1=fopen("acao.dat","rt");
if(e==2)//tipo policial
a1=fopen("comedia.dat","rt");
if(e==3)//tipo policial
a1=fopen("policial.dat","rt");
if(e==4)//tipo ficcao
a1=fopen("ficcao.dat","rt");      //abertura do arquivo para leitura
if(e==5)//tipo terror            //de acordo com o estilo de filme
a1=fopen("terror.dat","rt");
if(e==6)//tipo romance
a1=fopen("romance.dat","rt");
if(e==7)//tipo infantil
a1=fopen("infantil.dat","rt");
//_________________________________________________________________________
rewind(a1);//para voltar o ponteiro de arquivos para a posicao inicial devido a funcao cadastrar deixar o ponteiro sempre no final do arquivo
do{//inicio laco de repeticao
if(a1=="/0");//verifica se o arquivo estiver vazio pois mesmo voltando o ponteiro de arquivo para o inicio do arquivo ,se o ponteiro estiver apontando para /0-que indica fim de arquivo quer dizer que nenhum filme foi cadastrado
printf("nenhum filme foi cadastrado\n");
while(fread(&dados,sizeof(dados),1,a1)==1)//laco de procura
{
clrscr();
printf("\n\t FILME");
printf("\n NOME:\n");
fflush(stdin);
puts(dados.titulo);
printf("\n ESPECIE:\n");
puts(dados.especie);
printf("\n NUMERO:\n");
printf("%d",dados.numero);
printf("\n RESERVADO:\n");
puts(dados.reservado);
printf("\n LANCAMENTO:\n");
puts(dados.lancamento);
getch();
}//fim do laco de procura
rewind(a1);// voltar o ponteiro de arquivos para o inicio do arquivo para servir como protecao contra filmes cadastrados que nao sao encontrados
printf("Deseja continuar (S/N) ?\n");//pergunta se que continuar o cadastro de filme
do{//inicio laco de protecao
scanf("%c",&r1);
}while(r1!='s'&&r1!='n');//fim do laco de protcao
//fflush(stdin);
}while(r1=='s'&&r1!='n');
fclose(a1);
}//fim do if(funcao procurar o titulo do filme infantil)
//_______________________________________________________________________
if(m==3)
{//inicio do procurar por numero de locacoes
printf("\n\tMENU PROCURAR POR NUMEREO DE LOCACOES");
printf("\n\n1 -Acao");
printf("\n\n2 -Comedia");
printf("\n\n3 -Policial");
printf("\n\n4 -Ficcao");
printf("\n\n5 -Terror");
printf("\n\n6 -Romance");
printf("\n\n7 -Infantil");
printf("\n\nDigite a especie:");
do{//laco de protecao
scanf("%d",&e);
}while(e!=1&&e!=2&&e!=3&&e!=4&&e!=5&&e!=6&&e!=7);//fim do laco de protecao
//_________________________________________________________________________
if(e==1)
a1=fopen("acao.dat","rt");
if(e==2)
a1=fopen("comedia.dat","rt");
if(e==3)
a1=fopen("policial.dat","rt");
if(e==4)
a1=fopen("ficcao.dat","rt");     //abertura do arquivo para leitura
if(e==5)                         //de acordo com estilo de filme
a1=fopen("terror.dat","rt");
if(e==6)
a1=fopen("romance.dat","rt");
if(e==7)
a1=fopen("infantil.dat","rt");
//_________________________________________________________________________
rewind(a1);//para voltar o ponteiro de arquivos para a posicao inicial devido a funcao cadastrar deixar o ponteiro sempre no final do arquivo
do{//laco de repeticao
clrscr();
printf("\n\n Digite o numero de locacoes desejada:");
do{//laco de protecao
scanf("%d",&n);
}while(n>10);//laco de protecao
c=0;//inicia o contador com 0 ele e utlixado para verificar se algum filme foi encontrado com o numero de locacoes digitada
while(fread(&dados,sizeof(dados),1,a1)==1){//laco de procura
if (n==dados.numero)
{//inicio da condicao
printf("\n\n\t FILME");
printf("\n NOME:\n");
fflush(stdin);
puts(dados.titulo);
printf("\n ESPECIE:\n");
puts(dados.especie);
printf("\n NUMERO:\n");
printf("%d",dados.numero);
printf("\n RESERVADO:\n");
puts(dados.reservado);
printf("\n LANCAMENTO:\n");
puts(dados.lancamento);
getch();
c++;
}//fim da condicao
}//fim do laco de procura
rewind(a1);// voltar o ponteiro de arquivos para o inicio do arquivo para servir como protecao contra filmes cadastrados que nao sao encontrados
if(c==0)
printf("nao ha nenhum filme com esse numero de locacoes");
printf("\n\tDeseja continuar (S/N) ?\n");//pergunta se que continuar o cadastro de filme
do{//laco de protecao
scanf("%c",&r1);
}while(r1!='s'&&r1!='n');//fim do laco de protecao
//fflush(stdin);
}while(r1=='s'&&r1!='n');//fim do laco de repeticao
fclose(a1);
}//fim do procurar por numero de locacoes
}//fim da procura do titulo do filme
//***************************************************************************
//funcao imprimir
void imprime()
{//inicio da funcao imprimir
int resp,resp2,d,f;
char resp3,resp4,e,data[15],r1;
do{//inicio do laco de repeticao
clrscr();
printf("Digite o modo de impressao\n");
printf("1- Especie\n");
printf("2- Emprestimos atrasados\n");
printf("3- fitas reservadas\n");
do{//laco de protecao
scanf("%d",&resp2);
}while(resp2!=1&&resp2!=2&&resp2!=3);//fim do laco de protecao
//___________________________________________________________________________
if(resp2==1)
{//inicio de imprimir por especie
clrscr();
printf("Impressao por especie");
do {//inicio do laco de verificao de especie de filme
clrscr();
printf("\n\t MENU IMPRIMIR ESPECIE");
printf("\n\n 1.Acao ");
printf("\n\n 2.Comedia ");
printf("\n\n 3.Terror ");
printf("\n\n 4.Policial ");
printf("\n\n 5.Ficcao ");
printf("\n\n 6.Romance ");
printf("\n\n 7.Infantil \n");
printf("\n\t DIGITE A ESPECIE A SER IMPRIMIDA : ");
scanf("%d",&resp);
}while(resp!=1&&resp!=2&&resp!=3&&resp!=4&&resp!=5&&resp!=6&&resp!=7);//fim do laco de verificacao do tipo de filme
//___________________________________________________________________________
if (resp==1)
a1=fopen("acao.dat","a+t" );
if (resp==2)
a1=fopen("comedia.dat","a+t" );
if (resp==3)
a1=fopen("terror.dat","a+t" );
if (resp==4)                         //abertura do arquivo de acordo
a1=fopen("policial.dat","a+t" );     //com o tipo de filme
if (resp==5)
a1=fopen("ficcao.dat","a+t" );
if (resp==6)
a1=fopen("romance.dat","a+t" );
if (resp==7)
a1=fopen("infantil.dat","a+t" );
//___________________________________________________________________________
rewind(a1);//volta o ponteira de arquivo para a posicao inicial do arquivo para que nao ocorra o perigo de nao encontrar o filme cadsatrado
printf("\n \t IMPRIMINDO OS FILMES....");
while(fread(&dados,sizeof(dados),1,a1)==1){//laco de impressao
fprintf(stdprn,"\r\n NOME:");
delay(500);
fprintf(stdprn,"\r\n\t%s",dados.titulo);
delay(500);
fprintf(stdprn,"\r\n ESPECIE:");
delay(500);
fprintf(stdprn,"\r\n\t%s",dados.especie);
delay(500);
fprintf(stdprn,"\r\n NUMERO DE LOCACOES:");
delay(500);
fprintf(stdprn,"\r\n\t%d",dados.numero);
delay(500);
fprintf(stdprn,"\r\n RESERVADO PARA: ");
delay(500);
fprintf(stdprn,"\r\n\t%s",dados.reservado);
delay(500);
fprintf(stdprn,"\r\n LANCAMENTO: ");
delay(500);
fprintf(stdprn,"\r\n\t%s",dados.lancamento);
delay(500);
}//fim do laco de impressao
printf("\n \n\n\t FIM DE IMPRESSAO.\n");
printf("\n \n\n\t \t \t \t \t pressione qualquer tecla p/ retornar...\n");
getch();
}//fim do modo de impressao por especie
//__________________________________________________________________________
if(resp2==2)
{//inicio do modo de impressao por emprestimos atrasados
printf("Impressao por emprestimos atrasados\n");
a1=fopen("controle.dat","rd");//abre o arquivo controle para leitura
clrscr();//para nao misturar a tela antiga com a tela nova
printf("\nDigite a data de entrega");
fflush(stdin);
gets(data);
d=0;//inicia o contador com 0 ele e utlixado para verificar se algum filme foi encontrado com o numero de locacoes digitada
while(fread(&dados2,sizeof(dados2),1,a1)==1){//laco de impressao
if (strcmp(data,dados2.ddev)>0)//condicao que verifia se esta atrasado e imprime  *
{//inicio da condicao
fprintf(stdprn,"\r\n CODIGO DA FICHA:");
delay(500);
fprintf(stdprn,"\r\n\t%s",dados2.cod);
fprintf(stdprn,"\r\n NOME DO CLIENTE:");
delay(500);
fprintf(stdprn,"\r\n\t%s",dados2.nome);
fprintf(stdprn,"\r\n RG:");
delay(500);
fprintf(stdprn,"\r\n\t%s",dados2.rg);
fprintf(stdprn,"\r\n ENDERECO:");
delay(500);
fprintf(stdprn,"\r\n\t%s",dados2.end);
fprintf(stdprn,"\r\n TELEFONE:");
delay(500);
fprintf(stdprn,"\r\n\t%s",dados2.tel);
fprintf(stdprn,"\r\n FILME:");
delay(500);
fprintf(stdprn,"\r\n\t%s",dados2.filme);
fprintf(stdprn,"\r\n DATA DE LOCACAO:");
delay(500);
fprintf(stdprn,"\r\n\t%s",dados2.dloc);
fprintf(stdprn,"\r\n DATA DE DEVOLUCAO:");
delay(500);
fprintf(stdprn,"\r\n\t%s\n",dados2.ddev);
d++;
}//fim da condicao
}//fim do laco de impressao
if(d==0);
printf("\nnenhum filme esta atrasado\n");
printf("pressione qualquer tecla p/ continuar");
getch();
rewind(a1);// voltar o ponteiro de arquivos para o inicio do arquivo para servir como protecao contra filmes cadastrados que nao sao encontrados
fclose(a1);
}//fim do modo de impressao por emprestimos atrasados
//___________________________________________________________________________
if(resp2==3)
{//inicio do modo de impressao por fitas reservadas
printf("Impressao por fitas reservadas");
do {//verificao da especie de filme
clrscr();
printf("\n\t MENU IMPRIMIR ESPECIE");
printf("\n\n 1.Acao ");
printf("\n\n 2.Comedia ");
printf("\n\n 3.Terror ");
printf("\n\n 4.Policial ");
printf("\n\n 5.Ficcao ");
printf("\n\n 6.Romance ");
printf("\n\n 7.Infantil \n");
printf("\n\t DIGITE A ESPECIE A SER IMPRIMIDA : ");
scanf("%d",&resp);
}while(resp!=1&&resp!=2&&resp!=3&&resp!=4&&resp!=5&&resp!=6&&resp!=7);//fim da verificao da especie de filme
//___________________________________________________________________________
if (resp==1)
a1=fopen("acao.dat","a+t" );
if (resp==2)
a1=fopen("comedia.dat","a+t" );
if (resp==3)
a1=fopen("terror.dat","a+t" );
if (resp==4)                         //abre o arquivo de acordo
a1=fopen("policial.dat","a+t" );     //como o estilo de filme
if (resp==5)
a1=fopen("ficcao.dat","a+t" );
if (resp==6)
a1=fopen("romance.dat","a+t" );
if (resp==7)
a1=fopen("infantil.dat","a+t" );
//__________________________________________________________________________
rewind(a1);//volta o ponteira de arquivo para a posicao inicial do arquivo para que nao ocorra o perigo de nao encontrar o filme cadsatrado
printf("\n\n\tIMPRIMINDO OS FILMES....\n");
f=0;//inicia o contador com 0 ele e utlixado para verificar se algum filme foi encontrado com o numero de locacoes digitada
while(fread(&dados,sizeof(dados),1,a1)==1){//laco de impressao
if(strcmp(dados.reservado," ")>0)
{//inicio da condicao
fprintf(stdprn,"\r\n NOME:");
delay(500);
fprintf(stdprn,"\r\n\t%s",dados.titulo);
delay(500);
fprintf(stdprn,"\r\n ESPECIE:");
delay(500);
fprintf(stdprn,"\r\n\t%s",dados.especie);
delay(500);
fprintf(stdprn,"\r\n NUMERO DE LOCACOES:");
delay(500);
fprintf(stdprn,"\r\n\t%d",dados.numero);
delay(500);
fprintf(stdprn,"\r\n DATA DE LOCACAO: ");
delay(500);
fprintf(stdprn,"\r\n RESERVADO PARA: ");
delay(500);
fprintf(stdprn,"\r\n\t%s",dados.reservado);
delay(500);
fprintf(stdprn,"\r\n LANCAMENTO: ");
delay(500);
fprintf(stdprn,"\r\n\t%s",dados.lancamento);
delay(500);
}//fim da condicao
}//fim do laco de impressao
if(f==0)
printf("\n\n\tNao ha nenhum filme cadastrado");
printf("\n\n\tFIM DE IMPRESSAO.\n");
printf("\n\n\t \t \t \t \t pressione qualquer tecla p/ retornar...");
getch();
}
printf("\nDeseja imprimir outra vez (s/n) ?");//condicao de verificacao se que continuar imprimir
do{//laco de protecao
scanf("%c",&resp3);
}while(resp3!='s'&&resp3!='n');//fim do laco de protecao
}while(resp3=='s'&&resp3!='n');//fim do laco de repeticao
}//fim da funcao imprimir
//****************************************************************************
void cadastroc()
{//inicio da funcao cadasrar cliente
int x,s;
char r;
a1=fopen("cliente.dat","a+t");//cria o arquivo cliente tanto para leitura quanto para atualizacao
fseek(a1,0L,SEEK_END);//coloca o ponteiro na posicao final do arquivo
do{//inicio do laco de repeticao
clrscr();
printf("\n\n\t MENU CADASTRAR CLIENTES");
printf("\nCodigo da Ficha: ");
fflush(stdin);//limpa o buffer de teclado para nao ter leitura de lixo
gets(dados2.cod);
printf("\nNome do Cliente: ");
gets(dados2.nome);
printf("\n\nRG: ");
gets(dados2.rg);
printf("\n\nEndereco: ");
gets(dados2.end);
printf("\n\nTelefone: ");
gets(dados2.tel);
fwrite(&dados2,sizeof(dados2),1,a1);//escreve os dados para o arquivo cliente.dat
printf("\nDeseja continuar (S/N) ?");//pergunta se que continuar o cadastro de filme
do{//inicio do laco de protecao
scanf("%c",&r);
}while(r!='s'&&r!='n');//fim do laco de protecao
//fflush(stdin);
}while(r=='s'&&r!='n');//fim do laco de repeticao
fclose(a1);
}//fim da funcao cadastrar clientes
//***************************************************************************
//funcao controle
void controle()
{
int x,s,e;
char r,nome[40],r1,codigo[5];
do{
a1=fopen("cliente.dat","rt");//abre o arquivo cliente para leitura
rewind(a1);//coloca o ponteiro na posicao final do arquivo
clrscr();
printf("\n\n\t MENU CONTROLE ");
printf("\n\tCodigo da ficha do cliente: ");
fflush(stdin);
gets(codigo);
while(fread(&dados2,sizeof(dados2),1,a1)==1){//inicio do laco de procura
if (!strcmp (codigo,dados2.cod))//condicao de procura
{//inicio do if2
printf("\n\n\t CLIENTE : ");
puts(dados2.nome);
printf("\n CODIGO : ");
puts(dados2.cod);
printf("\n RG: ");
puts(dados2.rg);
printf("\n ENDERECO : ");
puts(dados2.end);
printf("\n TELEFONE : ");
puts(dados2.tel);
a1=fopen("controle.dat","a+t");
fseek(a1,0L,SEEK_END);//coloca o ponteiro na posicao final do arquivo
printf("\n\n FILME : ");
fflush(stdin);
gets(dados2.filme);
printf("\n\n Data de Locacao: ");
fflush(stdin);
gets(dados2.dloc);
printf("\n\n Data de Devolucao: ");
fflush(stdin);
gets(dados2.ddev);
fwrite(&dados2,sizeof(dados2),1,a1);
getch();
}//fim da condicao de procura
}//fim do laco de procura
if(strcmp(codigo,dados2.cod))//condicao a ser executado caso o cliente nao esteje cadastrado
{
clrscr();
printf("\n\tCliente nao cadastrado!!");
printf("\n\tNao e possivel fazer a locacao");
getch();
}
fclose(a1);//fecha o arquivo cliente.dat
if(!strcmp (codigo,dados2.cod))//condicao a ser executado caso o cliente e encontrado
{// inicio da condicao
clrscr();
printf("digite a especie do filme escolhido\n");
printf("1- acao\n");
printf("2- comedia\n");
printf("3- policial\n");
printf("4- ficcao\n");
printf("5- terror\n");
printf("6- romance\n");
printf("7- infantil\n");
do{
scanf("%d",&r);
}while(r!=1&&r!=2&&r!=3&&r!=4&&r!=5&&r!=6&&r!=7);
//____________________________________________________________________________
if(r==1)
a1=fopen("acao.dat","a+t");
if(r==2)
a1=fopen("comedia.dat","rt");
if(r==3)
a1=fopen("policial.dat","rt");
if(r==4)
a1=fopen("ficcao.dat","rt");          //abertura dos arquivos para leitura
if(r==5)
a1=fopen("terror.dat","rt");
if(r==6)
a1=fopen("romance.dat","rt");
if(r==7)
a1=fopen("infantil.dat","rt");
//________________________________________________________________________
a2=fopen("bo.dat","a+t");//cria o arquivo auxiliar
//__________________________________________________________________________
clrscr();
printf("digite o nome do filme");
fflush(stdin);//limpar o buffer de tecado para nao ler lixo
gets(nome);
while(fread(&dados,sizeof(dados),1,a1))
{
if (strcmp (nome,dados.titulo)&&feof(a1))//se o nome do filme for diferente grava no arquivo sem modificacao
fwrite(&dados,sizeof(dados),1,a2);
if(!strcmp(nome,dados.titulo)&&!feof(a1))//se o nome do filme for igual incrementa o numero de locacoes do filme e e guardado no arquivo
dados.numero=dados.numero+1;
fwrite(&dados.titulo,sizeof(dados),1,a2);
}//fim do while
}//fim da condicao
fcloseall();
//____________________________________________________________________________
if(r==1)
{
remove("acao.dat");//PEGA O ARQUIVO ANTIGO E APAGA
rename("bo.dat","acao.dat");//RENOMEIA O AUXILIAR PARA O ANTIGO NOME ISTO E O ARQUIVO MODIFICADO
}
if(r==2)
{
remove("comedia.dat");//PEGA O ARQUIVO ANTIGO E APAGA
rename("bo.dat","comedia.dat");//RENOMEIA O AUXILIAR PARA O ANTIGO NOME ISTO E O ARQUIVO MODIFICADO
}
if(r==3)
{
remove("policial.dat");//PEGA O ARQUIVO ANTIGO E APAGA
rename("bo.dat","policial.dat");//RENOMEIA O AUXILIAR PARA O ANTIGO NOME ISTO E O ARQUIVO MODIFICADO
}
if(r==4)
{
remove("ficcao.dat");//PEGA O ARQUIVO ANTIGO E APAGA
rename("bo.dat","ficcao.dat");//RENOMEIA O AUXILIAR PARA O ANTIGO NOME ISTO E O ARQUIVO MODIFICADO
}
if(r==5)
{
remove("terror.dat");//PEGA O ARQUIVO ANTIGO E APAGA
rename("bo.dat","terror.dat");//RENOMEIA O AUXILIAR PARA O ANTIGO NOME ISTO E O ARQUIVO MODIFICADO
}
if(r==6)
{
remove("romance.dat");//PEGA O ARQUIVO ANTIGO E APAGA
rename("bo.dat","romance.dat");//RENOMEIA O AUXILIAR PARA O ANTIGO NOME ISTO E O ARQUIVO MODIFICADO
}
if(r==7)
{
remove("infantil.dat");//PEGA O ARQUIVO ANTIGO E APAGA
rename("bo.dat","infantil.dat");//RENOMEIA O AUXILIAR PARA O ANTIGO NOME ISTO E O ARQUIVO MODIFICADO
}
printf("\n\tDeseja alugar outro filme (S/N) ?\n");//pergunta se que continuar o cadastro de filme
do{
scanf("%c",&r1);
}while(r1!='s'&&r1!='n');
fflush(stdin);
}while(r1=='s'&&r1!='n');
fclose(a1);
}

//***************************************************************************
void apaga()
{//inicio da funcao apagar
char r1,nome[40],nome2[40],m;
int e,n,w;
clrscr();
do{
rewind(a1);
clrscr();//para nao ter mistura da tela anterior com a nova
printf("\n\tDIGITE A ESPECIE ONDE O FILME A SER EXCLUIDO SE ENCONTRA");
printf("\n\n1 -Acao");
printf("\n\n2 -Comedia");
printf("\n\n3 -Policial");
printf("\n\n4 -Ficcao");
printf("\n\n5 -Terror");
printf("\n\n6 -Romance");
printf("\n\n7 -Infantil");
printf("\n\nDigite a especie:");
do{//inicio do laco de protecao
scanf("%d",&e);
}while(e!=1&&e!=2&&e!=3&&e!=4&&e!=5&&e!=6&&e!=7);//fim do laco de protecao
//___________________________________________________________________________
if(e==1)
a1=fopen("acao.dat","rt");
if(e==2)
a1=fopen("comedia.dat","rt");
if(e==3)
a1=fopen("policial.dat","rt");
if(e==4)                          //abre o arquivo de acordo com o estilo de
a1=fopen("ficcao.dat","rt");      //filme tanto para leitura
if(e==5)
a1=fopen("terror.dat","rt");
if(e==6)
a1=fopen("romance.dat","rt");
if(e==7)
a1=fopen("infantil","a+t");
//___________________________________________________________________________
a2=fopen("bo.dat","a+t");//cria o arquivo auxiliar para atualizacao
//____________________________________________________________________________
rewind(a1);//para voltar o ponteiro de arquivos para a posicao inicial devido a funcao cadastrar deixar o ponteiro sempre no final do arquivo
rewind(a2);//para voltar o ponteiro de arquivos para a posicao inicial devido a funcao cadastrar deixar o ponteiro sempre no final do arquivo
clrscr();//servepara nao misturrar a tela anterior com a nova tela
printf("\n\n Digite o nome do Filme:");
fflush(stdin);//limpar o buffer d teclado
gets(nome);
while(fread(&dados,sizeof(dados),1,a1)==1)
{//inicio do laco de apagar
if(strcmp(dados.titulo,nome)&&!feof(a1))
fwrite(&dados,sizeof(dados),1,a2);
}//fim do de apagar
fcloseall();//fecha todos os arquivos
//____________________________________________________________________________
if(e==1)
{
remove("acao.dat");//PEGA O ARQUIVO ANTIGO E APAGA
rename("bo.dat","acao.dat");//RENOMEIA O AUXILIAR PARA O ANTIGO NOME ISTO E O ARQUIVO MODIFICADO
}
if(e==2)
{
remove("comedia.dat");//PEGA O ARQUIVO ANTIGO E APAGA
rename("bo.dat","comedia.dat");//RENOMEIA O AUXILIAR PARA O ANTIGO NOME ISTO E O ARQUIVO MODIFICADO
}
if(e==3)
{
remove("policial.dat");//PEGA O ARQUIVO ANTIGO E APAGA
rename("bo.dat","policial.dat");//RENOMEIA O AUXILIAR PARA O ANTIGO NOME ISTO E O ARQUIVO MODIFICADO
}
if(e==4)
{
remove("ficcao.dat");//PEGA O ARQUIVO ANTIGO E APAGA
rename("bo.dat","ficcao.dat");//RENOMEIA O AUXILIAR PARA O ANTIGO NOME ISTO E O ARQUIVO MODIFICADO
}
if(e==5)
{
remove("terror.dat");//PEGA O ARQUIVO ANTIGO E APAGA
rename("bo.dat","terror.dat");//RENOMEIA O AUXILIAR PARA O ANTIGO NOME ISTO E O ARQUIVO MODIFICADO
}
if(e==6)
{
remove("romance.dat");//PEGA O ARQUIVO ANTIGO E APAGA
rename("bo.dat","romance.dat");//RENOMEIA O AUXILIAR PARA O ANTIGO NOME ISTO E O ARQUIVO MODIFICADO
}
if(e==7)
{
remove("infantil.dat");//PEGA O ARQUIVO ANTIGO E APAGA
rename("bo.dat","infantil.dat");//RENOMEIA O AUXILIAR PARA O ANTIGO NOME ISTO E O ARQUIVO MODIFICADO
}
//__________________________________________________________________________
printf("\n\tDeseja apagar outro filme (S/N) ?\n");//pergunta se que continuar o cadastro de filme
do{//laco de protecao
scanf("%c",&r1);
}while(r1!='s'&&r1!='n');//fim do laco de protecao
//fflush(stdin);
}while(r1=='s'&&r1!='n');
fcloseall();
}//fim da funcao apagar
//***************************************************************************
//funcao principal
void main()
{
int op;
do{//inicio do laco de repeticao
clrscr();
printf("\n\n\t MENU PRINCIPAL ");
printf("\n1- Cadastrar Filmes");
printf("\n2- Pesquisar");
printf("\n3- Imprimir");
printf("\n4- Cadastrar Clientes");
printf("\n5- Controle de emprestimos");
printf("\n6- Apagar");
printf("\n7- Sair\n");
printf("\n\n\tDigite a opcao :");
scanf("%d",&op);
switch(op)
{//inicio do menu
case 1:cadastro();
	break;
case 2:procurar();
	break;
case 3:imprime();
	break;
case 4:cadastroc();
	break;
case 5:controle();
	break;
case 6:apaga();
	break;
}//fim do menu
}while(op!=7);//fim do laco de repeticao
}//fim da funcao principal
//****************************************************************************