/*Trabalho Final de LAPROI
Julia de Lemos Santos
Professor Marco Mangan
Confetes v(1.0)
PUCRS 2014*/

/*Download para a biblioteca da Conio2.h
https://github.com/Fernando-Lafeta/Biblioteca-Conio-2
Créditos: Fernando Lafeta*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio2.h>

void GerarMatriz(int Matriz[9][9]); /*Declaração da função geradora da matriz principal.*/
void MostrarMatriz(int Matriz[9][9]); /*Declaração da função de mostrar a matriz.*/
void MovimentoJogador(int *Matriz[9][9]); /*Declaração da função da jogada.*/
int ConferirHorizontal(int Matriz[9][9]); /*Declaração da função que confere se há elementos iguais na horizontal.*/
int ConferirVertical(int Matriz[9][9]); /*Conferir se há elementos iguais na vertical*/
void EliminarHorizonal(int Matriz[9][9], int i, int j, int k, int cont);
/*Declaração da função que troca os elementos iguais na horizontal por 0.*/
void EliminarVertical(int Matriz[9][9], int i, int j, int k, int cont);
/*Declaração da função que troca os elementos iguais na vertical por 0.*/
void Subir(int *Matriz[9][9],int i, int j);
/*Declaração da função que sobe todos os elementos que são zero para o topo da matriz.*/
void PreecherZero(int *Matriz[9][9]);
/*Declaração da função que troca os elementos que são zero por números aleatórios.*/
int TemJogo(int Matriz[9][9]);
/*Declaração da função que verifica se existe o jogo.*/

int pont; /*Varíavel global da pontuação.*/
int combo = 1; /*Variável global dos combos.*/
int cv; /*Variável global de conferir a vertical.*/
int ch; /*Variável global de conferir a horizontal.*/

int main() /*Função principal(Main).*/
{
    pont = 0; /*Variável da pontuação*/
    int Matriz[9][9]; /*Matriz Principal.*/
    int Menu = 1; /*Variável do menu do jogo.*/
    int jogo; /*Variável do jogo.*/

    printf("    Bem vindo ao Confeitos(v.1.0)!   \n\n    Deseja:\n\n 1)Jogar o jogo\n 2)Sair\n\n");
    printf(" Opção escolhida: ");
    do
    {
        scanf("%i", &Menu);
        printf("\n");
        if(Menu==2) /*Caso o usuário tenha digitado 2, o jogo será finalizado.*/
            return 1;
    }
    while(Menu!=1); /*O laço será repetido até que uma posição válida seja digitada.*/

    if(Menu==1) /*Caso o usuário digite a opção de iniciar o jogo(opção 1), o laço irá chamar as funções.*/
    {

        GerarMatriz(Matriz); /*Chama a função que gera a matriz.*/

        MostrarMatriz(Matriz); /*Chama a função que mostra a matriz.*/

        do
            /*Enquato o CH ou o CV for 1, as variáveis vão receber o valor que as funções retornam, sendo eles 1 ou 0.*/
            /*As variáveis receberam o valor 1 na sua declaração para evitar erros/loop infinito.*/
        {
            ch = ConferirHorizontal(Matriz);
            /*A variável global recebe o resultado da função de conferir a horizontal.*/
            cv = ConferirVertical(Matriz);
            /*A variável global recebe o resultado da função de conferir a vertical.*/
            printf("\nCH: %i\n", ch);
            /*Informa qual valor está na variável conferir horizontal.*/
            printf("CV: %i\n", cv);
            /*Informa qual valor está na variável conferir vertical.*/
            if(cv==1 || ch == 1)
                /*Caso as funções tenham retornado 1, a variável "combo" será incrementada em 1.*/
                combo++;
        }
        while(ch == 1 || cv ==1);

        printf("\nCombo: %i\n", combo);
        MostrarMatriz(Matriz);
        /*Chama a função que mostra a matriz, desta vez com valores atualizados.*/
        jogo = TemJogo(Matriz);
        printf("Tem jogo: %i", jogo);
        while(TemJogo(Matriz) == jogo)
        {
            MovimentoJogador(Matriz);
            /*Chama a função que lê o movimento que o jogador deseja realizar.*/
            MostrarMatriz(Matriz);
            jogo = TemJogo(Matriz);
            /*A variável jogo vai receber o valor que é retornado da função TemJogo*/
        }
    }
    return 0;
}

void GerarMatriz(int Matriz[9][9])
{
    /*Função para gerar a matriz principal com números aleatórios.*/
    int i; /*Índice da linha.*/
    int j; /*Índice da coluna.*/
    int x; /*Número aleatório.*/

    const char *const green = "\033[0;40;32m"; /*Verde*/
    const char *const yellow = "\033[0;40;33m"; /*Amarelo*/
    const char *const red = "\033[0;40;31m"; /*Vermelho*/
    const char *const blue = "\033[0;40;34m"; /*Azul*/
    const char *const normal = "\033[0m"; /*Normal*/

    srand(time(NULL));

    for(i=0; i<9; i++) /*Para percorrer a matriz de índice [0][j] até [8][j].*/
    {
        for(j=0; j<9; j++) /*Para percorrer a matriz de índice [0][0] até [8][8].*/
        {
            x=1+(rand() % 4);
            Matriz[i][j]=x; /*A matriz em uma determinada posição recebe o valor aleatório.*/
        }
    }
}

void MostrarMatriz(int Matriz[9][9])
{
    /*Função para mostrar a matriz logo após ter sido construída.*/
    /*A função também será utilizada para mostrar a matriz logo após alterações e jogadas.*/
    int i; /*Índice da linha.*/
    int j; /*Índice da coluna.*/
    char z;
    printf("------------------------------\n  0 1 2 3 4 5 6 7 8\n\n");
    for(i=0; i<9; i++) /*Para percorrer a matriz de índice [0][j] até [8][j].*/
    {
        printf("%i ",i);
        for(j=0; j<9; j++) /*Para percorrer a matriz de índice [0][0] até [8][8].*/

        {

            switch(Matriz[i][j])
            /*Switch para trocar números por letras.*/
            {
                case 1:
                    textcolor(RED);
                    z = 'R';
                    printf("%c ",z);
                    break;
                case 2:
                    textcolor(YELLOW);
                    z = 'Y';
                    printf("%c ",z);
                    break;
                case 3:
                    textcolor(GREEN);
                    z = 'G';
                    printf("%c ",z);
                    break;
                case 4:
                    textcolor(BLUE);
                    z = 'B';
                    printf("%c ",z);
                    break;
                default:
                    textcolor(LIGHTGRAY);
                    printf(". ");
                    break;
            }
        }
        textcolor(LIGHTGRAY);
        printf(" %i\n",i); /*Para criar o formato de uma matriz, no caso, 9x9*/
    }
    printf("\n  0 1 2 3 4 5 6 7 8\n------------------------------\nPontos: %i\nCombo: %i\n------------------------------\n", pont, combo);
}

void MovimentoJogador(int *Matriz[9][9])
{
    /*Função que recebe a o movimento que o jogador deseja realizar e faz a mudança na matriz.*/
    int imov1; /*Coordenada da linha do primeiro elemento.*/
    int imov2; /*Coordenada da lnha do segundo elemento.*/
    int jmov1; /*Coordenada da coluna do primeiro elemento.*/
    int jmov2; /*Coordenada da coluna do segundo elemento.*/
    int aux; /*Primeira variável auxiliar.*/
    int aux2=0; /*Segunda variável auxiliar.*/

    printf("\nDigite 4 valores para indicar as coordenadas para realizar um movimento.\n");
    /*De acordo com as regras do jogo, somente peças adjacentes podem ser movidas.*/
    /*Caso contrário, o movimento não será realizado.*/
    do
    {
        scanf("%d", &imov1);
        scanf("%d", &jmov1);
        scanf("%d", &imov2);
        scanf("%d", &jmov2);

        if (imov1<9 && imov1>=0 && jmov1<9 && jmov1>=0)
        /*Condição para que a informação que o usuário digitou seja válida.*/
        {
            if (abs(imov1-imov2)<=1 && abs(jmov1-jmov2)<=1)
            /*De acordo com as regras do jogo, o movimento só será valido se respeitar a fórmula.*/
            {
                aux = Matriz[imov1][jmov1];
                /*A variável auxiliar vai receber o valor que está na posição [i][j].*/
                Matriz[imov1][jmov1] = Matriz[imov2][jmov2];
                /*A matriz na posição [i][j] vai receber o valor que está na segunda coordenada.*/
                Matriz[imov2][jmov2] = aux;
                /*A segunda coordenada recebe, na verdade, o valor da primeira coordenada.*/
                aux2 = 1;
            }
        }

    }
    while(aux2 != 1);/*Condição que verifica se a troca é válida.*/

    printf("Realizando checagem.");
    /*Realiza checagem para ver se é necessário modificar algum valor utilizando as outras funções.*/
    cv = ConferirVertical(Matriz);
    /*Cv vai receber o valor retornado pela função.*/
    ch = ConferirHorizontal(Matriz);
    /*Ch vai receber o valor retornado pela função.*/
    if (cv==1 || ch==1)
        combo++;
    if (cv==0 && ch==0)
    /*Caso seja zero, a função para de conferir.*/
    {
        combo = 1;
        aux = Matriz[imov1][jmov1];
        Matriz[imov1][jmov1] = Matriz[imov2][jmov2];
        Matriz[imov2][jmov2] = aux;
        /*Repete o procedimento anterior.*/
    }
    else
    {
        do
        {
            ch = ConferirHorizontal(Matriz);
            cv = ConferirVertical(Matriz);
            if(cv== 1 || ch == 1) combo++;
            /*Caso Conferir retornar 1, incrementa o combo em 1.*/
        }
        while(cv ==1 || ch == 1);
        /*Caso existam mais elementos iguais a função continua a verificar.*/
    }

}

int ConferirHorizontal(int Matriz[9][9])
{
    int i; /*Variável da linha da matriz.*/
    int j; /*Variável da linha da coluna.*/
    int k; /*Variável auxiliar.*/
    int cont = 0; /*Variável do contador.*/
    int z = 0; /*Variável que se associa a eliminação, dizendo se houve ou não eliminação.*/

    for (i=0; i<9; i++)
    {
        j = 0;
        k = 0;
        cont = 0;
        do
        {
            j=k;
            while (Matriz[i][j]==Matriz[i][k] && j < 9 && Matriz[i][j]!=0 && k<9)
            /*i e j são pivos, centro da análise.*/
            /*k é onde modifica a matriz e avança a análise.*/
            {
                cont++;
                k++;
                /*Caso seja igual, cont é incrementado em 1 e k é incrementado em 1.*/
            }
            if (cont>=3)
            /*Apartir do momento que cont é igual ou maior que 3 outra função é chamada.*/
            /*Incrementa z caso haja eliminação.*/
            {
                EliminarHorizonal(Matriz, i, j, k, cont);
                z++;
            }
            cont = 0;
            /*Cont passa a valer zeri para verificar o resto da matriz.*/
        }
        while(j<9 && k<9);
    }
    if(z!=0)
        return 1; /*Continua conferindo.*/
    else
        return 0; /*Para de conferir.*/
}

int ConferirVertical (int Matriz[9][9])
{
    int i; /*Variável da linha.*/
    int j; /*Variável da coluna.*/
    int k; /*Variável auxiliar.*/
    int cont = 0; /*Variável do contador.*/
    int z = 0; /*Variável que se associa a eliminação, dizendo se houve ou não eliminação.*/

    for (j=0; j<9; j++)
    /*Diferente da função anterior, essa move o índice da coluna, e não da linha.*/
    {
        i = 0;
        k = 0;
        cont = 0;
        do
        {
            i=k;
            /*i recebe o valor de k para começar a análise.*/
            while (Matriz[i][j]==Matriz[k][j] && j < 9 && Matriz[i][j]!=0 && k<9)
            /*i e j são pivos, centro da análise.*/
            /*k é onde modifica a matriz e avança a análise.*/
            {
                cont++;
                k++;
            /*Caso seja igual, cont é incrementado em 1 e k é incrementado em 1.*/
            }
            if (cont>=3)
            /*Apartir do momento que cont é igual ou maior que 3 outra função é chamada.*/
            /*Incrementa z caso haja eliminação.*/
            {
                EliminarVertical(Matriz, i, j, k, cont);
                z++;
            }
            cont = 0;
            /*Cont passa a valer zeri para verificar o resto da matriz.*/
        }
        while(i<9 && k<9);
    }
    if(z!=0)
        return 1; /*Continua conferindo.*/
    else
        return 0; /*Para de conferir.*/
}

void EliminarHorizonal(int Matriz[9][9], int i, int j, int k, int cont)
{
    int z; /*Índice auxiliar.*/

    pont+=(cont*combo);

    printf("\n ----------------------------- \n Eliminando horizontal: %i %i %i\n Combo: %i\n Pontos: %i\n", i, j, k, combo, pont);
    /*Indica coordenadas do ponto a ser eliminado.*/

    for (z=j; z<k; z++)
    /*Z assume o valor de j, sendo um índice auxiliar porque k virá com os valoes da função antes usada.*/
    {
        Matriz[i][z] = 0;
        if(i!=0)
        {
            Subir(Matriz,i,z);
            /*A função é chamada para colocar os zero no topo da função.*/
        }
    }
    MostrarMatriz(Matriz);
    /*Mostra a matriz atualizada.*/
    PreecherZero(Matriz);
    /*Troca os zero por números aleatórios.*/
    printf("\n");
}

void EliminarVertical(int Matriz[9][9], int i, int j, int k, int cont)
{
    int z; /*Índice auxiliar.*/

    pont+=(cont*combo);

    printf("\n ----------------------------- \n Eliminando vertical: %i %i %i\n Combo: %i \nPontos: %i\n", i, j, k, combo, pont);
    /*Indica coordenadas do ponto a ser eliminado.*/

    for (z=i; z<k; z++)
    /*Z assume o valor de i, sendo um índice auxiliar porque k virá com os valoes da função antes usada.*/
    {
        Matriz[z][j] = 0;
        if(i!=0)
        {
            Subir(Matriz,z,j);
        /*A função é chamada para colocar os zero no topo da função.*/
        }
    }
    MostrarMatriz(Matriz);
    /*Mostra a matriz atualizada.*/
    PreecherZero(Matriz);
    /*Troca os zero por números aleatórios.*/
    printf("\n\n");
}

void Subir(int *Matriz[9][9],int i,int j)
{
    int z=i-1; /*Z recebe o índice subtraido de um para retornar uma posição na matriz.*/
    int y=i; /*Variável auxiliar do indice.*/
    int aux; /*Variável auxiliar.*/

    if(i!=0) /*Não há porque mudar a primeira posição, pois ela já foi modificada.*/
    {
        while(y!=0 && Matriz[z][j]!=0) /*Condição para a troca de posição dos valores.*/
        /*Não há necessidade de mudar um valor que já seja zero e já esteja no topo da matriz.*/
        {
            aux = Matriz[y][j]; /*A variável auxiliar recebe o elemento da matriz em determinada posição.*/
            Matriz[y][j] = Matriz[z][j]; /*A nova posição recebe o número modificado.*/
            Matriz[z][j] = aux; /*O número que não mudou desce uma posição.*/
            y--;
            z--;
        }
    }
}

void PreecherZero(int *Matriz[9][9])
{
    int i; /*Variável da linha.*/
    int j; /*Variável da coluna.*/
    int x; /*Variável auxiliar.*/

    srand(time(NULL)); /*Numero aleatório.*/

    printf("\n Queda de confeitos!!!! \n"); /*Indica a mudança dos confeitos.*/
    for(i=0; i<9; i++) /*Para percorrer a matriz de índice [0][j] até [8][j].*/
    {
        for(j=0; j<9; j++) /*Para percorrer a matriz de índice [0][0] até [8][8].*/
        {
            if(Matriz[i][j]==0)
            {
                x=1+(rand() % 4); /*O número que antes era zero agora recebe um novo valor aleatório.*/
                Matriz[i][j]=x;
            }
        }
    }
    printf("\n----------------------------------\n");
}

int TemJogo(int Matriz[9][9])
{
    int j; /*Variável da coluna.*/
    int i; /*Variável da linha.*/
    for(i=0; i<9; i++) /*Para percorrer a matriz de índice [0][j] até [8][j].*/
    {
        for(j=0; j<9; j++) /*Para percorrer a matriz de índice [0][0] até [8][8].*/
        {
            if(i==0 && j!=0 && j != 8) /*Início da condição para ver se existe alguma movimentação que possa ser feita.*/
            {
                if(Matriz[i+1][j]==Matriz[i][j-1]) /*Verifica as pontas para detectar movimentos.*/
                    if(Matriz[i-1][j]==Matriz[i][j+1])
                        return 1; /*Continua verificando.*/
            }
            else if(i==8 && j!=0 && j!=8) /*Início da condição para ver se existe alguma movimentação que possa ser feita.*/
            {
                if(Matriz[i][j-1]==Matriz[i][j+1])
                    if(Matriz[i][j-1]== Matriz[i-1][j])
                        return 1; /*Continua verificando.*/
            }
            /*O programa continua a verificar todos os elementos, de acordo com a regra do jogo.*/
            else if(j==0 && i!=0 && i!=8)
            {
                if(Matriz[i-1][j] == Matriz[i+1][j])
                    if(Matriz[i-1][j]== Matriz[i][j+1])
                        return 1;
            }
            else if(j==8 && i!=0 && i!=8)
            {
                if(Matriz[i-1][j]== Matriz[i+1][j])
                    if(Matriz[i-1][j] == Matriz[i][j-1])
                        return 1;
            }
            else if(i!=0 && i!=8 && j!=0 && j!=8)
            {
                if(Matriz[i][j-1]==Matriz[i][j+1])
                {
                    if(Matriz[i][j-1]== Matriz[i-1][j])
                        return 1;
                }
                else if(Matriz[i+1][j]==Matriz[i][j-1])
                {
                    if(Matriz[i-1][j]==Matriz[i][j+1])
                        return 1;
                }
                else if(Matriz[i-1][j] == Matriz[i+1][j])
                {
                    if(Matriz[i-1][j]== Matriz[i][j+1])
                        return 1;
                }
                else if(Matriz[i-1][j]== Matriz[i+1][j])
                {
                    if(Matriz[i-1][j] == Matriz[i][j-1])
                        return 1;
                }
            }
        }
    }
}
/*Caso o valor retornado da primeira vez seja diferente do valor retornado pela segunda vez, não existe movimentações.*/
/*Logo o jogo está finalizado.*/
