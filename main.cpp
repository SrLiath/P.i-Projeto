#include <iostream>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

int main()
{

    setlocale(LC_ALL,"Portuguese");

    string doencas[20] = {"diabete", "diabetes", "hipertensao"};
    char procurarDoenca[20];
    char tentarNovamente;
    bool achou;

       //navegacao
    int navegacao;
    int navegacaoDoenca;

    //dados do usuario
    char nome[30] = {};
    int idade = 0;

    telaUm:

    if(nome[0] == 0 && idade == 0){

            system("clear||cls");
            printf("Ol� usu�rio, Seja Bem Vindo\n\n");
            printf("Informe seu nome: ");
            gets(nome);

            while (nome[0] == 0){
                system("clear||cls");
                printf("Percebi que voc� n�o digitou seu nome.\nPor favor digite seu nome: \n");
                gets(nome);
            }

            printf("Informe a sua idade: ");
            scanf("%d", &idade);

            while (idade <= 0){
                system("clear||cls");
                printf("Por favor informe uma idade v�lida\n");
                scanf("%d", &idade);
                system("clear||cls");
            }

    }

    system("clear||cls");
    printf("----------------------------------------------------------------------\n");
    printf("Seja bem vindo %s.\nNosso aplicativo tem o objetivo de ajudar voc� que est� com problemas de sa�de.\nVamos lhe ajudar listando todos os alimentos que deve comer e evitar de comer, e dicas para melhorar sua sa�de\n\nNome: %s\nIdade: %d\n\n", nome, nome, idade);

    printf("\n^+---------------------------------------------^+");
    printf("\n1 - Listar as doencas\n");
    printf("\n2 - Informar a doenca\n");
    printf("\n^+---------------------------------------------^");
    scanf("%d", &navegacao);

    if(navegacao == 1){

        telaDois:


        system("cls");
        printf("Por favor navegue com os n�meros abaixo\nSeu nome: %s\nSua idade: %d\n\n", nome, idade);
        printf("1 - Diabetes\n2 - Colesterol\n3 - Tela Inicial\n");
        scanf("%d", &navegacaoDoenca);

        if(navegacaoDoenca == 1){

            system("clear||cls");

            FILE *arq;
            char Linha[100];
            char *result;
            int i = 1;

            // Abre um arquivo TEXTO para LEITURA
            arq = fopen("diabetes.txt", "r");
            if (arq == NULL)  // Se houve erro na abertura
            {
                printf("Problemas na abertura do arquivo\n");
                return 0;
            }
            while (!feof(arq))
            {
                // L� uma linha (inclusive com o '\n')
                result = fgets(Linha, 100, arq);  // o 'fgets' l� at� 99 caracteres ou at� o '\n'
                if (result)  // Se foi poss�vel ler
                printf("%s\n",Linha);
                i++;
            }

            fclose(arq);

            printf("\n1 - Tela Anterior");
            scanf("%d", &navegacao);

            if(navegacao == 1){
                goto telaDois;
            }

        }
        else if (navegacaoDoenca == 2){
            system("clear||cls");
            printf("A dupla h�bitos alimentares saud�veis e pr�tica regular de exerc�cios f�sicos � capaz de manter as taxas de colesterol bom (HDL) e ruim (LDL) em perfeito equil�brio, afastando de perto o risco de infarto e derrame cerebral, al�m de outras doen�as como o Mal de Alzheimer. Quem sofre com o problema sabe bem que a solu��o para este mal n�o est� nas p�lulas. Nem que voc� siga � risca os hor�rios e as doses dos rem�dios, sem controlar a alimenta��o, as taxas de colesterol jamais entram nos eixos. Mas o contr�rio at� pode acontecer: h� quem aprenda a montar pratos saud�veis e, desta forma, passe longe da farm�cia. A seguir, confira a lista de alimentos, para encampar uma batalha contra o colesterol alto e sair vencedor (sem, � claro, abrir m�o de comer bem).\n");
            printf("\nPEIXES\n\nEles s�o excelente fonte de �cido graxo �mega 3, um tipo de gordura boa, do tipo insaturada, encontrada nos peixes de �gua fria, como salm�o, atum e truta. �A gordura insaturada ajuda na redu��o dos n�veis de triglicer�deos e colesterol total do sangue; reduz o risco de forma��o de co�gulos, al�m de tornar o sangue mais fluido; sendo, portanto, importante aliada na preven��o das doen�as cardiovasculares�, explica nutricionista da Unifesp Ana Maria Figueiredo Ramos.\n\nAVEIA\n\nAl�m das fibras insol�veis, a aveia cont�m uma fibra sol�vel chamada betaglucana, que exerce efeitos ben�ficos ao nosso organismo. Ela retarda o esvaziamento g�strico, promovendo maior saciedade, melhora a circula��o, controla a glicemia (a��car no sangue) e inibe a absor��o de gordura (colesterol). �A aveia diminui as concentra��es de colesterol total, lip�dios totais e triglicer�deos de forma significativa e aumenta a fra��o do bom colesterol (HDL)�, explica nutricionista da Unifesp Ana Maria Figueiredo Ramos.\n\n");
            printf("1- Tela Anterior");
            scanf("%d", &navegacao);
            if(navegacao == 1){
                goto telaDois;
            }
        }
        else {
            goto telaUm;
        }

    }
    else if (navegacao == 2){

        telaTres:

            do {
            system("clear||cls");
            printf("Informe o nome da doen�a:\n");
            fflush(stdin);
            gets(procurarDoenca);

            int size = sizeof(doencas)/sizeof(doencas[0]);

            for (int i = 0; i < size; i++){
                if (strlwr(procurarDoenca) == doencas[i]){

                    printf("Hipertens�o:\nAlimentos que devem ser consumidos em maiores quantidades\n\nA dieta orienta para o aumento no consumo di�rio de alimentos ricos em fibras, prote�nas, c�lcio, pot�ssio, magn�sio e gorduras insaturadas, como: ");
                    printf("- frutas;\n-carnes magras: preferir peixes, frango e cortes magros de carnes vermelhas;\n- gorduras boas: castanhas, amendoim, nozes, avel�s, azeite;\n-gr�os integrais, como aveia, farinha de trigo integral, arroz integral e quinoa;-legumes e verduras;\n-leite e derivados desnatados.\n� importante observar que al�m de adotar uma alimenta��o saud�vel, a pr�tica regular de atividades f�sicas tamb�m ajuda a reduzir a press�o arterial, al�m de controlar o peso e auxiliar na melhora geral da sa�de.\n");
                    printf("Deseja pesquisar novamente? Y para sim, N para n�o ou V para voltar\n");
                    scanf("%c", &tentarNovamente);

                    if (tolower(tentarNovamente) == ('y')){
                        goto telaTres;
                    }

                    else if(tolower(tentarNovamente) == ('v')){
                        goto telaUm;
                    }

                    achou = true;
                }
            }

            if (achou == true){
                break;
            }

            printf("Infelizmente n�o temos essa doen�a na nossa base de dados\n");
            printf("Deseja pesquisar novamente? Y para sim, N para n�o ou V para voltar\n");
            scanf("%c", &tentarNovamente);

            if(tolower(tentarNovamente) == 'v'){
                goto telaUm;
            }

            } while (tolower(tentarNovamente) == 'y');

            printf("Obrigado por usar nosso aplicativo. Se Cuide!!\n\n");
    }

    return 0;

}

