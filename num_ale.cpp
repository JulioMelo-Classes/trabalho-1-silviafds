#include <iostream>
#include <time.h>
#include <stdlib.h>

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

int main(){
    int numeros[20];
    GeraAleatorios(numeros,20,81);
    for(int i = 0;i<20;i++){
        cout<<numeros[i]<<" - ";
    }

    return 0;
}