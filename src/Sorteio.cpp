#include <iostream>
#include <cstring>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Validar.h"
#include "Sorteio.h"
using namespace std;

/*! 
 * @brief Método que irá comparar o vetor de números apostados pelo jogador com o vetor de números sorteados aleatoriamente.
 * 
 * @param vetor_sorteado vetor que foi sorteado.
 * @param quantidade_num quantidade de números a serem verificados.
 * @param vetor_num_jogados vetor de números apostados pelo jogador. 
 * @param tam_numeros_jogados tamanho do vetor de números apostados pelo jogador.
 *
 * @return os números que foram, ao mesmo tempo, apostados pelo jogador e sorteados pelo programa. *
 */



std::vector<int> comparar(int vetor_sorteado[], int quantidade_num, int vetor_num_jogados[], int tam_numeros_jogados){
    vector<int>num_vencidos;

    // chamada da função que irá colocar os números sorteados e os números apostados em ordem.
    insertionsort(vetor_sorteado, 20);
    insertionsort(vetor_num_jogados, tam_numeros_jogados);
    
    int x=0;
    for(int i=0; i<20; i++){
        for(int j=0; j<tam_numeros_jogados; j++){
            if(vetor_sorteado[i] == vetor_num_jogados[j]){
                //preenche o vetor de números vencidos com os números que foram apostados e também sorteados.
                num_vencidos.push_back(vetor_sorteado[i]);
                x++;
            }
        }
    }

    return num_vencidos;
}

/*! 
 * @brief Método que verifica se existem números iguais sendo gerados. 
 *
 * @param vetor_sorteado vetor que recebe os valores sorteados.
 * @param quantidade_num quantidade de números verificados.
 * @param valor valores que serão comparados com os elementos do vetor.
 *
 * @return true se os elementos forem iguais e false se forem diferentes.
 *
 */

bool Sorteio::Existe(int vetor_sorteado[],int quantidade_num, int valor){
    for(int i = 0;i<valor;i++){
        if(vetor_sorteado[i]==valor)
            return true;
    }
    return false;
}

