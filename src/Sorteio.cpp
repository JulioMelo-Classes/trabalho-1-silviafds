#include <iostream>
#include <cstring>
#include <iomanip>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "Validar.h"
#include "Sorteio.h"
using namespace std;


std::vector<int> comparar(int vetor_sorteado[], int quantidade_num, int vetor_num_jogados[], int tam_numeros_jogados){
    vector<int>num_vencidos;

    insertionsort(vetor_sorteado, 20);
    insertionsort(vetor_num_jogados, tam_numeros_jogados);
    
    int x=0;
    for(int i=0; i<20; i++){
        for(int j=0; j<tam_numeros_jogados; j++){
            if(vetor_sorteado[i] == vetor_num_jogados[j]){
                num_vencidos.push_back(vetor_sorteado[i]);
                x++;
            }
        }
    }

    return num_vencidos;
}
