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
bool Sorteio::Existe(int valores[],int tam, int valor){
    for(int i = 0;i<tam;i++){
        if(valores[i]==valor)
            return true;
    }
    return false;
}


//Função que gera numeros aleatorios.
void Sorteio::GeraAleatorios(int numeros[],int quantNumeros,int Limite){
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

int Sorteio::sorteando(){
    //int vetor_sorteado[20];//valores que foram sorteados.
    //int quantidade_num = 20;
    //int limite = 80;//do 1 até 80
    Sorteio var2;
    var2.GeraAleatorios(vetor_sorteado, quantidade_num, limite);
    
    cout <<"\n Números sorteados: ";

    //return vetor_sorteado[];

    for(int i=0; i<quantidade_num; i++){
        cout << vetor_sorteado[i] << "\t";
    }
}