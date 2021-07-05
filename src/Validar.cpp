#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include "Validar.h"
using namespace std;

void insertionsort(int num_escolhidos[], int tam){//função de ordenação
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


int val(int vetor_numeros_apostados[], int cont){
   
    insertionsort(vetor_numeros_apostados, cont);//chamada da funcão de ordenação

    for(int i=0; i<cont; i++){//1º validação -- numeros repetidos
        if(vetor_numeros_apostados[i] == vetor_numeros_apostados[i+1]){
            cout << "ERRO! SEU ARQUIVO POSSUI NÚMEROS DE APOSTAS IGUAIS, O QUE NÃO É PERMITIDO!" << endl;
            return 1;       
        }
    }

    if(cont > 15){ //2º validação -- quantidade de numeros apostados maior que 20.
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
