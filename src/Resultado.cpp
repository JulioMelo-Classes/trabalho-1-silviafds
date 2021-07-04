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
                      {0, 0, 0.5, 1, 2, 3, 5, 10, 30, 600, 1.800},
                      {0, 0, 0.5, 1, 1, 2, 6, 15, 25, 180, 1.000, 3.000},
                      {0, 0, 0, 0.5, 1, 2, 4, 24, 72, 250, 500, 2.000, 4.000},
                      {0, 0, 0, 0.5, 0.5, 3, 4, 5, 20, 80, 240, 500, 3.000, 6.000},
                      {0, 0, 0, 0.5, 0.5, 2, 3, 5, 12, 50, 150, 500, 1.000, 2.000, 7.500},
                      {0, 0, 0, 0.5, 0.5, 1, 2, 5, 15, 50, 150, 300, 600, 1200, 2500, 10000}};


//spot - spot que é a coluna
//num_acertos = hits que é a coluna
int calculo(int valor_bruto_aposta, int numero_de_jogadas, int qtd_num_vencidos, int qtd_num_jogados){
    int valor_premio = 0, aposta_por_jogada, qtd_acertos = 0;
    //descobrir número de acerto
    for(int i = 0; i<15; i++){

    }
    aposta_por_jogada = valor_bruto_aposta/numero_de_jogadas;//valorda 1º aposta

    //cout << "\nValor por aposta: " << aposta_por_jogada << endl;

    verificar = matriz[qtd_num_jogados-1][qtd_num_vencidos];
    //cout << "Hit: " << numero_acertos << endl;
    //cout << "Verificar elemento da matriz: " << verificar << endl;

    valor_premio = verificar * aposta_por_jogada;
    //cout << "Valor do prêmio: " << valor_premio << endl;

    return valor_premio;
}


int calculo_tot(int valor_da_aposta, int num_jogadas, int valor_ganho, int i, int resto){
    int aposta_por_jogada = 0, valor_total;
    int resto_da_aposta, premio = valor_ganho, cont = i;

    aposta_por_jogada = valor_da_aposta/num_jogadas;//valor aposta cada rodada


    int x, resultado, resto1;
    x = valor_da_aposta/num_jogadas;//valor aposta cada rodada
    //cout << "\n Quem é i= " << i << endl;

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
            resto = valor_da_aposta - x;//descobre o resto
            resto1 = resto;
            resultado = valor_ganho;
            resto = resto + resultado;
            
        } else if (i > 1){
            //cout << "\nentrei no else if\n " << endl;
            resto = resto - x;
            resto1 = resto;
            resultado = valor_ganho;
            resto = resto + resultado;
        }
        /*cout << "\n";
        cout << "valor bruto da aposta " << valor_da_aposta << endl;
        cout << "valor de x -> aposta de cada rodada " << x << endl;
        cout << "[valor do resto inicial " << resto1 << endl;
        cout << "[valor do premio " << resultado << endl;
        cout << "[valor do resto (resto+vlr premio) " << resto << endl;
        cout << "\n";*/
    }
    
    return resto;
}

void apresentar(int valor_da_aposta, int  numero_de_jogadas, char *arquivo, int spot, int vetor_num_jogados[]){
    int aposta_por_jogada, cont = 0;
    aposta_por_jogada = valor_da_aposta/numero_de_jogadas;
    //size_t numeros_do_jogador = num_jogador . size(); 

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

void sumario(int valor_da_aposta, int valor_total){
   //int cred_ganhado = valor_total - valor_da_aposta;
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
    //cout << "\n>>> Você está saindo do jogo com um total de " << cred_ganhado << " créditos.\n";

}
