#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include "Validar.h"
#include "Sorteio.h"
#include "Resultado.h"
using namespace std;

double matriz[16][16] = {{0, 3},
                      {0, 1, 9},
                      {0, 1, 2, 16},
                      {0, 0.5, 2, 6, 12},
                      {0, 0.5, 1, 3, 15, 50},
                      {0, 0.5, 1, 2, 3, 30, 75},
                      {0, 0.5, 0.5, 1, 6, 12, 36, 100},
                      {0, 0.5, 0.5, 1, 3, 6, 19, 90, 720},
                      {0, 0.5, 0.5, 1, 2, 4, 8,  20, 80, 1.200},
                      {0, 0, 0.5, 1, 2, 3, 5, 10, 30, 600, 1.800},
                      {0, 0, 0.5, 1, 1, 2, 6, 15, 25, 180, 1.000, 3.000},
                      {0, 0, 0, 0.5, 1, 2, 4, 24, 72, 250, 500, 2.000, 4.000},
                      {0, 0, 0, 0.5, 0.5, 3, 4, 5, 20, 80, 240, 500, 3.000, 6.000},
                      {0, 0, 0, 0.5, 0.5, 2, 3, 5, 12, 50, 150, 500, 1.000, 2.000, 7.500},
                      {0, 0, 0, 0.5, 0.5, 1, 2, 5, 15, 50, 150, 300, 600, 1.200, 2.500, 10.000}};


//spot - spot que é a coluna
//num_acertos = hits que é a coluna
int calculo(int valor_da_aposta, int num_jogadas, int numero_acertos, int spot){
    int valor_premio = 0, aposta_por_jogada;
    aposta_por_jogada = valor_da_aposta/num_jogadas;    
    cout << "\nValor por aposta: " << aposta_por_jogada << endl;

    double verificar = matriz[spot-1][numero_acertos];
    cout << "Hit: " << numero_acertos << endl;
    cout << "Verificar elemento da matriz: " << verificar << endl;

    valor_premio = verificar * aposta_por_jogada;
    cout << "Valor do prêmio: " << valor_premio << endl;
    

    return valor_premio;
}