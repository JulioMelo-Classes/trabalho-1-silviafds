#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include "Validar.h"
#include "Sorteio.h"
#include "Resultado.h"
using namespace std;

/*! 
 * @brief Arquivo que irá analisar o resultado do jogo.
 *
 */

// verificar pega o elemento da matriz que será multiplicado pelo valor apostado.
// matriz é a matriz que contém os elementos que serão multiplicado pelo valor apostado com base em quantos números foram apostados(linhas - spot) e quantos números foram iguais aos sorteados(colunas - hits)

double verificar;
double matriz[16][16] = {{0, 3},
                      {0, 1, 9},
                      {0, 1, 2, 16},
                      {0, 0.5, 2, 6, 12},
                      {0, 0.5, 1, 3, 15, 50},
                      {0, 0.5, 1, 2, 3, 30, 75},
                      {0, 0.5, 0.5, 1, 6, 12, 36, 100},
                      {0, 0.5, 0.5, 1, 3, 6, 19, 90, 720},
                      {0, 0.5, 0.5, 1, 2, 4, 8,  20, 80, 1.200},
                      {0, 0, 0.5, 1, 2, 3, 5, 10, 30, 600, 1800},
                      {0, 0, 0.5, 1, 1, 2, 6, 15, 25, 180, 1000, 3000},
                      {0, 0, 0, 0.5, 1, 2, 4, 24, 72, 250, 500, 2000, 4000},
                      {0, 0, 0, 0.5, 0.5, 3, 4, 5, 20, 80, 240, 500, 3000, 6000},
                      {0, 0, 0, 0.5, 0.5, 2, 3, 5, 12, 50, 150, 500, 1000, 2000, 7500},
                      {0, 0, 0, 0.5, 0.5, 1, 2, 5, 15, 50, 150, 300, 600, 1200, 2500, 10000}};

/*! 
 * @brief Função que irá calcular o prêmio de cada rodada do jogador.
 *
 * @param valor_bruto_aposta valor total que o jogador irá apostar no jogo inteiro.
 * @param numero_de_jogadas número de vezes que o jogador quer jogar.
 * @param qtd_num_vencidos quantidade de números apostados que também foram sorteados.
 * @param qtd_num_jogados quantidade de números apostados pelo jogador.
 *
 * @return valor do prêmio que a pessoa que está jogando irá receber no final da rodada.
 *
 */

int calculo(int valor_bruto_aposta, int numero_de_jogadas, int qtd_num_vencidos, int qtd_num_jogados){
    // valor_premio inicia em 0 e irá acumulando conforme os cálculos forem feitos para chegar a um valor final de prêmio para o jogador.
    // aposta_por_jogada é o valor que será apostado a cada rodada do jogo.
    // qtd_acertos inicia em 0 e irá se acumular para ao final, obter a quantidade de números que o jogador apostou e que também foram sorteados pelo programa.

    int valor_premio = 0, aposta_por_jogada, qtd_acertos = 0;
    for(int i = 0; i<15; i++){

    }
    aposta_por_jogada = valor_bruto_aposta/numero_de_jogadas;
    verificar = matriz[qtd_num_jogados-1][qtd_num_vencidos];
    valor_premio = verificar * aposta_por_jogada;

    return valor_premio;
}


/*! 
 * @brief Função que irá calcular o prêmio de cada rodada do jogador.
 *
 * @param valor_da_aposta valor total que o jogador irá apostar no jogo inteiro.
 * @param num_jogadas número de vezes que o jogador quer jogar.
 * @param valor_ganho valor do prêmio que recebeu.
 * @param i contador que incrementa baseado no número de rodadas que o jogo irá realizar.
 * @param resto recebe o valor da aposta completa menos quanto ele já gastou de aposta em cada rodada, somado com o valor do prêmio de cada rodada.
 *
 * @return valor total de crédito caso o número de jogadas seja 1, e retornará o resto caso o número de jogadas seja diferente de 1.
 *
 */


int calculo_tot(int valor_da_aposta, int num_jogadas, int valor_ganho, int i, int resto){
    // aposta_por_jogada é o valor que será apostado a cada rodada do jogo.
    // valor_total é o total de créditos que o jogador possui.
    // resto_da_aposta é o 
    int aposta_por_jogada = 0, valor_total;
    int premio = valor_ganho, cont = i;

    aposta_por_jogada = valor_da_aposta/num_jogadas;


    int x, resultado, resto1;
    x = valor_da_aposta/num_jogadas;

    if(num_jogadas == 1){
        if(valor_ganho <= 0){
            valor_total = 0;
        }else{
            num_jogadas = num_jogadas - 1;
            valor_total = num_jogadas * aposta_por_jogada;
            valor_total = valor_ganho + valor_total;
            cout << "Valor total do crédito: " << valor_total << endl;
            return valor_total;
        }
    }else if (num_jogadas != 1) {

        if (cont == 1){
            resto = valor_da_aposta - x;
            resto1 = resto;
            resultado = valor_ganho;
            resto = resto + resultado;
            
        } else if (i > 1){
            resto = resto - x;
            resto1 = resto;
            resultado = valor_ganho;
            resto = resto + resultado;
        }
    }
    
    return resto;
}


/*! 
 * @brief Função que irá apresentar a parte inicial do jogo à pessoa que irá jogar.
 *
 * @param valor_da_aposta valor total que o jogador irá apostar no jogo inteiro.
 * @param numero_de_jogadas número de vezes que o jogador quer jogar.
 * @param arquivo irá receber o nome do arquivo que o jogador quer que seja lido.
 * @param spot é a quantidade de números que o jogador irá apostar.
 * @param vetor_num_jogados é o vetor de números que o jogador apostou.
 *
 */

void apresentar(int valor_da_aposta, int  numero_de_jogadas, char *arquivo, int spot, int vetor_num_jogados[]){
    int aposta_por_jogada, cont = 0;
    aposta_por_jogada = valor_da_aposta/numero_de_jogadas;

    cout << "Lendo arquivo de apostas [" << arquivo << "], por favor, aguarde." << endl;
    cout << "------------------------------------------------------------------" << endl;
    cout << ">>> Aposta lida com sucesso!";
    cout << "\n    Você apostará um total de $" << valor_da_aposta << " créditos.";
    cout << "\n    Jogará um total de " <<  numero_de_jogadas  << " rodadas, apostando $" << aposta_por_jogada << " créditos por rodada.";

    cout << "\n    Sua aposta tem " << spot << " números, eles são: [ ";
    for (int i = 0; i < spot; i++) {
        cout << vetor_num_jogados[i] << " - ";
    }
    cout << "]" << endl;

    cout << "        HITS     |     RETORNO " << endl;
    for (int j = 0; j <= spot; j++){
        cout << "         " << j  << "       |" << "        " << matriz[spot-1][j] << endl;
    }

    cout << "------------------------------------------------------------------" << endl;

}

/*! 
 * @brief Função que irá apresentar cada rodada ao jogador.
 *
 * @param num_sorteados vetor de números que foram sorteados pelo jogo.
 * @param num_igual vector de números que o jogador apostou e que também foram sorteados pelo jogo.
 * @param valor_ganho valor do prêmio que o jogador recebeu.
 * @param valor_total quantidade de créditos que o jogador acumulou.
 * @param cont contador que incrementa baseado no número de rodadas que o jogo irá realizar.
 * @param num_jogadas número de jogadas que o jogo irá realizar.
 * @param valor_da_aposta valor que o jogador irá apostar.
 * @param numero_acertos quantos números o jogador apostou e que também foram sorteados pelo jogo.
 * @param spot quantidade de números apostados pelo jogador.
 *
 */

void apresentar2(int num_sorteados[], vector<int> &num_igual, float valor_ganho, int valor_total, int cont, int num_jogadas, int valor_da_aposta, int numero_acertos, int spot){
    int valor_aposta = valor_da_aposta/num_jogadas;
    size_t tam_iguais = num_igual . size();

    insertionsort(num_sorteados, 20);

    cout << "Esta é a rodada #" << cont << " de " << num_jogadas << ", sua aposta é " << valor_aposta << ". Boa sorte!";
    cout << "\nOs números sorteados são: [ ";
    for(int i=0; i<20; i++){
       cout <<  num_sorteados[i] << "\t";
    }
    cout << "]";
    cout << "\n\nVocê acertou os números [ ";
    for(int i=0; i<tam_iguais; i++){
       cout <<  num_igual[i] << " ";
    }
    cout << "], um total de " << numero_acertos << " hits de " << spot << "." << endl;
    cout << "\nSua taxa de retorno é de " << verificar << " assim você sai com: $" << valor_ganho;
    cout << "\nVocê possui um total de: "  << valor_total << " créditos.";
    cout << "\n-----------------------------------------------------------------------------\n";

}


/*! 
 * @brief Função que irá apresentar a parte final do jogo.
 *
 * @param valor_da_aposta valor total que o jogador irá apostar no jogo inteiro.
 * @param valor_total quantidade de créditos que o jogador acumulou ao final do jogo.
 *
 */

void sumario(int valor_da_aposta, int valor_total){
    int v_tot = (valor_da_aposta-valor_total);
    int resto_credito = (valor_total - valor_da_aposta);
    cout << "\nvalor total: " << valor_total;
    cout << "\n============ Súmario =============";
    cout << "\n>>> Você gastou um total de $" << valor_da_aposta << " créditos";
    
    if(valor_total < valor_da_aposta){
        cout << "\n>>> Hooray! você perdeu $" << v_tot << " créditos!";
        cout << "\n>>> Você está saindo do jogo com um total de " << valor_total << " créditos.\n";
    }else if(valor_total > valor_da_aposta){
        cout << "\n>>> Hooray! você ganhou $" << resto_credito << " créditos!";
        cout << "\n>>> Você está saindo do jogo com um total de " << valor_total << " créditos.\n";
    }else{
        cout << "\n>>> Hooray! você ganhou $" << valor_da_aposta << " créditos!";
        cout << "\n>>> Você está saindo do jogo com um total de " << valor_total << " créditos.\n";
    }

}
