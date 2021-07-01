#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include "Validar.h"
#include "Sorteio.h"
using namespace std;



void sorteando(int tam){
    int vetor_sorteado[20];//atributo
    int quantidade_num = 20;
    int limite = 80;//do 1 até 80

    for(int i=0; i<quantidade_num; i++){
        vetor_sorteado[i] = 1 + (rand() % limite);
    }
    
    /*cout <<"\n Números sorteados: ";

    for(int i=0; i<quantidade_num; i++){
        cout << vetor_sorteado[i] << "\t";
    }*/

}