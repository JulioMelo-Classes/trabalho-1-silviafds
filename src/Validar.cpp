#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include "Validar.h"
using namespace std;


int val(int num_escolhidos[], int tam){
    int aux;
    for(int i=0; i<tam; i++){//números em ordem crescente
        for(int j=0; j<tam;j++){
            if(num_escolhidos[i] < num_escolhidos[j]){
                aux = num_escolhidos[i];
                num_escolhidos[i] = num_escolhidos[j];
                num_escolhidos[j] = aux;
            }
        }
    }
    int ordenar_crescente(int num_escolhidos, int tam);
    cout << "\nOrdem crescente ";
    for(int i=0; i<tam; i++){//números em ordem crescente
        cout << num_escolhidos[i] << "\t";
    }


    for(int i=0; i<tam; i++){//1º validação
        if(num_escolhidos[i] == num_escolhidos[i+1]){
            return 1;
            break;
        }
    }

    if(tam > 20){ //2º validação
        return 1;
    }

    for(int i=0; i<tam; i++){ //3º validação
        if(num_escolhidos[i] != 6){
            return 1;
            break;
        }
    }

    return 0;
}