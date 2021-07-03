#ifndef RESULTADO_H
#define RESULTADO_H
#include <vector>

int calculo(int valor_da_aposta, int num_jogadas, int numero_acertos, int spot);
int calculo_tot(int valor_da_aposta, int num_jogadas, int valor_ganho, int i, int resto);
void apresentar(int valor_da_aposta, int num_jogadas, char* arquivo, int spot, std::vector<int> &num_jogador);
void apresentar2(std::vector<int> &num_sorteados, std::vector<int> &num_igual, float valor_ganho, int valor_total, int cont, int num_jogadas, int valor_da_aposta, int numero_acertos, int spot);
void sumario(int valor_da_aposta, int valor_total);

#endif