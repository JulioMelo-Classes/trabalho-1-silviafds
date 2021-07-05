#ifndef SORTEIO_H
#define SORTEIO_H
#include <vector>

/*! 
 * @brief Classe que irá realizar o sorteio dos números.
 * 
 * vetor_sorteado atributo que irá conter os números que serão sorteados.
 * quantidade_num atributo que irá conter a quantidade de números que serão sorteados.
 * limite atributo que determinará o número máximo que poderá ser sorteado.
 *
 * Existe método que irá vericar se existem dois números iguais sendo sorteado.
 * Comparar método que irá comparar os números apostados com os números sorteados.
 *
 */

class Sorteio{
    public:
        int vetor_sorteado[20];
        int quantidade_num = 20;
        int limite = 80;

    bool Existe(int vetor_sorteado[],int quantidade_num, int valor);
    

};

std::vector<int> comparar(int vetor_sorteado[], int quantidade_num, int vetor_num_jogados[], int tam_numeros_jogados);

#endif