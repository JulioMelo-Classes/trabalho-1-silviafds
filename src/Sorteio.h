#ifndef SORTEIO_H
#define SORTEIO_H

class Sorteio{
    public:
        int vetor_sorteado[20];//valores que foram sorteados.
        int quantidade_num = 20;
        int limite = 80;//do 1 até 80

    bool Existe(int valores[],int tam, int valor);
    void GeraAleatorios(int numeros[],int quantNumeros,int Limite);
    void sorteando();

};




#endif