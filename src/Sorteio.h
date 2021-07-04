#ifndef SORTEIO_H
#define SORTEIO_H
#include <vector>
class Sorteio{
    public:
        int vetor_sorteado[20];//valores que foram sorteados.
        int quantidade_num = 20;
        int limite = 80;//do 1 até 80

};

std::vector<int> comparar(int vetor_sorteado[], int quantidade_num, int vetor_num_jogados[], int tam_numeros_jogados);

#endif