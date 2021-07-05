#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include "Validar.h"
using namespace std;

/*! 
 * @brief Função para ordenar o vetor de números apostados pelo jogador. 
 *
 * @param num_escolhidos vetor de números apostados pelo jogador.
 * @param tam tamanho do vetor.
 *
 */

void insertionsort(int num_escolhidos[], int tam){
    int i, key, j;

    for(i=1; i<tam; i++){
        key = num_escolhidos[i];
        j = i - 1;

        while (j >= 0 && num_escolhidos[j] > key){
            num_escolhidos[j+1] = num_escolhidos[j];
            j = j - 1;
        }
        num_escolhidos[j+1] = key;
    }
}

/*! 
 * @brief Função que irá validar o arquivo do jogador.
 * 
 * @param vetor_numeros_apostados vetor que recebe os valores apostados pelo jogador.
 * @param cont quantidade de números apostados.
 *
 * @return 1 caso o arquivo tenha números repetidos ou a quantidade de valores apostados for superior a 15 e retorna 0 ao terminar a função normalmente.
 *
 */


int val(int vetor_numeros_apostados[], int cont){
   
    insertionsort(vetor_numeros_apostados, cont);

    for(int i=0; i<cont; i++){
        if(vetor_numeros_apostados[i] == vetor_numeros_apostados[i+1]){
            cout << "ERRO! SEU ARQUIVO POSSUI NÚMEROS DE APOSTAS IGUAIS, O QUE NÃO É PERMITIDO!" << endl;
            return 1;       
        }
    }

    if(cont > 15){ 
        cout << "ERRO! VOCÊ SÓ PODE APOSTAR ATÉ 15 NÚMEROS!" << endl;
        return 1;
    }

    /*for(int i=0; i<cont; i++){ //3º validação
        if(vetor_numeros_apostados[i] == '?'){
            cout << "I can't open this file." << endl;
            return 1;
        }
    }*/

    return 0;
}
