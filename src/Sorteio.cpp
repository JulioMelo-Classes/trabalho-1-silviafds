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
using std::vector;

int comparar(int num_escolhidos[], int tam, int num_sorteados[], int tam_num){
    insertionsort(num_escolhidos, tam);
    cout << "\nJogo do jogador: ";
    for(int i=0; i<tam; i++){ //3º validação
        cout << num_escolhidos[i] << "\t";
    }
    cout << "\n\n";
    cout << "\n\nNumeros sorteados: ";
    insertionsort(num_sorteados, tam_num);
    for(int i=0; i<tam_num; i++){ //3º validação
        cout << num_sorteados[i] << "\t";
    }
    int num_comum = 0, num_iguais[tam];
    for(int i=0; i<tam_num; i++){
        for(int j=0; j<tam; j++){
            if(num_sorteados[i] == num_escolhidos[j]){
                num_comum++;
                num_iguais[i] = num_sorteados[i];
            }
        }
    }
    cout << "\ntot num comum: " << num_comum << "\n";
    cout << "\nNumeros sorteados em comum: ";
    for(int i=0; i<num_comum; i++){
        cout << num_iguais[i] << "\t";
    }


    return 0;
}

//Funçao que verifica se existem numeros iguais sendo gerados.
bool Sorteio::Existe(int vetor_sorteado[],int quantidade_num, int valor){
    for(int i = 0;i<valor;i++){
        if(vetor_sorteado[i]==valor)
            return true;
    }
    return false;
}

//Função que gera numeros aleatorios.
void Sorteio::GeraAleatorios(int vetor_sorteado[],int quantidade_num,int limite){
    srand(time(NULL)); // gera numeros com base no relogio.

    int v;
    //Percorrer o vetor de numeros.
    for(int i=0;i<quantidade_num;i++){
        v = 1 + (rand() % limite);
        //Chama a funçao que verifica se existe numeros iguais.
        while(Existe(vetor_sorteado,i,v)){
            v = 1 + (rand() %  limite);
        }
        //Coloca os valores dentro do vetor.
        vetor_sorteado[i] = v;
    }
}
vector<int> adm(vector<int> &arr){
    Sorteio var2;
    Sorteio var3;
    Sorteio var4;
    Sorteio var5;
    var2.GeraAleatorios(var4.vetor_sorteado, var3.quantidade_num, var5.limite);
    
   // cout <<"\n Números sorteados: ";
    for(int i=0; i<20; i++){
   //     cout << var4.vetor_sorteado[i] << "\t";
        arr.push_back(var4.vetor_sorteado[i]);
    }

    return arr;
   
}
