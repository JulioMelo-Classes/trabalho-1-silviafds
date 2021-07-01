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



//Funçao que verifica se existem numeros iguais sendo gerados.
bool Existe(int valores[],int tam, int valor){
    for(int i = 0;i<tam;i++){
        if(valores[i]==valor)
            return true;
    }
    return false;
}


//Função que gera numeros aleatorios.
void GeraAleatorios(int numeros[],int quantNumeros,int Limite){
    srand(time(NULL)); // gera numeros com base no relogio.

    int v;
    //Percorrer o vetor de numeros.
    for(int i=0;i<quantNumeros;i++){
        v = 1 + (rand() % Limite);
        //Chama a funçao que verifica se existe numeros iguais.
        while(Existe(numeros,i,v)){
            v = 1 + (rand() %  Limite);
        }
        //Coloca os valores dentro do vetor.
        numeros[i] = v;
    }
}

void sorteando(){
    int vetor_sorteado[20];//valores que foram sorteados.
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