#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

bool Existe(int valores[],int tam, int valor){
    for(int i = 0;i<tam;i++){
        if(valores[i]==valor)
            return true;
    }
    return false;
}

void GeraAleatorios(int numeros[],int quantNumeros,int Limite){
    srand(time(NULL));

    int v;
    for(int i=0;i<quantNumeros;i++){
        v = 1 + (rand() % Limite);
        while(Existe(numeros,i,v)){
            v = 1 + (rand() %  Limite);
        }
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