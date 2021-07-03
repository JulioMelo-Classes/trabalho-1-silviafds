#ifndef RESULTADO_H
#define RESULTADO_H
#include <vector>

int calculo(int valor_da_aposta, int num_jogadas, int numero_acertos, int spot);
int calculo_tot(int valor_da_aposta, int num_jogadas, int valor_ganho, int i);
void apresentar(int valor_da_aposta, int num_jogadas);
void apresentar2(std::vector<int> &num_sorteados, std::vector<int> &num_igual, int valor_ganho, int valor_total, int cont, int num_jogadas, int valor_da_aposta);
void sumario(int valor_da_aposta, int valor_total);

#endif