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

vector<int> comparar(vector<int> &num_jogador, vector<int> &num_sorteados){
    size_t tam_sorteados = num_sorteados.size();
    size_t tam_jogador = num_jogador.size();
    vector<int>num_vencidos;
    int vet_jogador[tam_jogador], vet_sorteados[tam_sorteados];
    cout << "\n\nValor de vector c/ num_sorteados: " << tam_sorteados << "\n\n";
    cout << "Valor de vector c/ num_jogador: " << tam_jogador << "\n\n";
    for(int i=0; i<tam_jogador; i++){//preenchendo os vetores
        vet_jogador[i] = num_jogador[i];
    }
    for(int i=0; i<tam_sorteados; i++){
        vet_sorteados[i] = num_sorteados[i];
    }
    insertionsort(vet_jogador, tam_jogador);
    insertionsort(vet_sorteados, tam_sorteados);
    for(int i=0; i<tam_jogador; i++){
        cout << vet_jogador[i] << "\t";
    }
    cout << "\n\n\n";
    for(int i=0; i<tam_sorteados; i++){
        cout << vet_sorteados[i] << "\t";
    }
    int x=0;
    for(int i=0; i<tam_sorteados; i++){
        for(int j=0; j<tam_jogador; j++){
            if(vet_sorteados[i] == vet_jogador[j]){
                num_vencidos.push_back(vet_sorteados[i]);
                x++;
            }
        }
    }
    cout <<"\n\nnumeros iguais: ";
    for(int i=0; i<x; i++){
        cout << num_vencidos[i] << "\t";
    }

    return num_vencidos;
}

//Função que verifica se existem numeros iguais sendo gerados.
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
