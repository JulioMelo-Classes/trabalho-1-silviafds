#ifndef SORTEIO_H
#define SORTEIO_H
#include <vector>
class Sorteio{
    public:
        int vetor_sorteado[20];//valores que foram sorteados.
        int quantidade_num = 20;
        int limite = 80;//do 1 até 80

   
    bool Existe(int vetor_sorteado[],int quantidade_num, int valor);
    void GeraAleatorios(int vetor_sorteado[],int quantidade_num,int limite);
    //void sorteando();

};
std::vector<int> adm(std::vector<int> &arr);
//void sorteando(int num_escolhidos[], int tam, int num_jogadas, int valor_da_aposta);
int comparar(int num_escolhido[], int tam, int num_sorteados[], int tam_num);

#endif