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


int val(int num_escolhidos[], int tam){
   
    insertionsort(num_escolhidos, tam);//chamada da funcão de ordenação
    
    int ordenar_crescente(int num_escolhidos, int tam);
    //cout << "\nOrdem crescente ";
    //for(int i=0; i<tam; i++){//números em ordem crescente
      /*  cout << num_escolhidos[i] << "\t";
    }*/


    for(int i=0; i<tam; i++){//1º validação -- numeros repetidos
        if(num_escolhidos[i] == num_escolhidos[i+1]){
            cout << "Nao sera possivel abrir o arquivo. Numeros iguais." << endl;
            return 1;            
            break;
        }
    }

    if(tam > 17){ //2º validação -- quantidade de numeros apostados maior que 20.
        cout << "Não vai abrir o arquivo. Números demais." << endl;
        return 1;
        
    }


    /*for(int i=0; i<tam; i++){ //3º validação
        if(num_escolhidos[i] != 6){
            cout << "I can't open this file." << endl;
            return 1;
            break;
        }
    }*/

    return 0;
}