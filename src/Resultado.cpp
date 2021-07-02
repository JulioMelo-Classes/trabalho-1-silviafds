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

double matriz[16][16] = {{0, 3},
                      {0, 1, 9},
                      {0, 1, 2, 16},
                      {0, 0.5, 2, 6, 12},
                      {0, 0.5, 1, 3, 15, 50},
                      {0, 0.5, 1, 2, 3, 30, 75},
                      {0, 0.5, 0.5, 1, 6, 12, 36, 100},
                      {0, 0.5, 0.5, 1, 3, 6, 19, 90, 720},
                      {0, 0.5, 0.5, 1, 2, 4, 8,  20, 80, 1.200},
                      {0, 0, 0.5, 1, 2, 3, 5, 10, 30, 600, 1.800},
                      {0, 0, 0.5, 1, 1, 2, 6, 15, 25, 180, 1.000, 3.000},
                      {0, 0, 0, 0.5, 1, 2, 4, 24, 72, 250, 500, 2.000, 4.000},
                      {0, 0, 0, 0.5, 0.5, 3, 4, 5, 20, 80, 240, 500, 3.000, 6.000},
                      {0, 0, 0, 0.5, 0.5, 2, 3, 5, 12, 50, 150, 500, 1.000, 2.000, 7.500},
                      {0, 0, 0, 0.5, 0.5, 1, 2, 5, 15, 50, 150, 300, 600, 1.200, 2.500, 10.000}};


//spot - spot que é a coluna
//num_acertos = hits que é a coluna
int calculo(int valor_da_aposta, int num_jogadas, int numero_acertos, int spot){
    int valor_premio = 0, aposta_por_jogada;
    aposta_por_jogada = valor_da_aposta/num_jogadas;    
    cout << "\nValor por aposta: " << aposta_por_jogada << endl;

    double verificar = matriz[spot-1][numero_acertos];
    cout << "Hit: " << numero_acertos << endl;
    cout << "Verificar elemento da matriz: " << verificar << endl;

    valor_premio = verificar * aposta_por_jogada;
    cout << "Valor do prêmio: " << valor_premio << endl;

    return valor_premio;
}

int calculo_tot(int valor_da_aposta, int num_jogadas, int valor_ganho){
    int aposta_por_jogada = 0, valor_total;

    aposta_por_jogada = valor_da_aposta/num_jogadas;
    num_jogadas = num_jogadas - 1;
    valor_total = num_jogadas * aposta_por_jogada;
    valor_total = valor_ganho + valor_total;
    cout << "Valor total do crédito: " << valor_total << endl;
    return valor_total;
}

void apresentar(int valor_da_aposta, int num_jogadas){
    int aposta_por_jogada;
    aposta_por_jogada = valor_da_aposta/num_jogadas;

    cout << ">>> Aposta lida com sucesso!";
    cout << "\n    Você apostara um total de $" << valor_da_aposta << " créditos";
    cout << "\n    Jogará um total de " <<  num_jogadas  << " rodadas, apostando $" << aposta_por_jogada << " créditos por rodada\n";
}

void apresentar2(vector<int> &num_sorteados, vector<int> &num_igual, int valor_ganho, int valor_total, int cont, int num_jogadas, int valor_da_aposta){
    int valor_aposta = valor_da_aposta/num_jogadas;

    size_t tam_sorteados = num_sorteados . size();
    size_t tam_iguais = num_igual . size();

    int vetor_sort[tam_sorteados];
    for(int i=0; i<tam_sorteados; i++){
        vetor_sort[i] = num_sorteados[i];
    }
    insertionsort(vetor_sort, tam_sorteados);

    cout << "Esta é a rodada #" << cont << " de " << num_jogadas << ", sua aposta é " << valor_aposta << ". Boa sorte!";
    cout << "\nOs números sorteados são: [ ";
    for(int i=0; i<tam_sorteados; i++){
       cout <<  vetor_sort[i] << "\t";
    }
    cout << "]";
    cout << "\n\nVocê acertou os números [ ";
    for(int i=0; i<tam_iguais; i++){
       cout <<  num_igual[i] << "\t";
    }
    cout << "], (acrescentar info)";
    cout << "\nSua taxa de retorno é de (add info), assim você sai com: $" << valor_ganho;
    cout << "\nVocê possui um total de: "  << valor_total << " créditos.";
    cout << "\n-----------------------------------------------------------------------------\n";

}

void sumario(int valor_da_aposta, int valor_total){
    int cred_ganhado = valor_total + valor_da_aposta;   
    
    cout << "\n\n============ Súmario =============";
    cout << "\n>>> Você gastou um total de $" << valor_da_aposta << " créditos";
    if(cred_ganhado > 1){
        cout << "\n>>> Hooray! você ganhou $" << valor_total << " créditos!";
    }else{
        cout << "\n>>> Hooray! você perdeu $" << valor_total << " créditos!";
    }
    cout << "\n>>> Você está saindo do jogo com um total de " << cred_ganhado << " créditos.\n";

}