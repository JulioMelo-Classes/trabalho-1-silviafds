#ifndef RESULTADO_H
#define RESULTADO_H
#include <vector>
int calculo(int valor_bruto_aposta, int numero_de_jogadas, int qtd_num_vencidos, int qtd_num_jogados);
int calculo_tot(int valor_da_aposta, int num_jogadas, int valor_ganho, int i, int resto);
void apresentar(int valor_da_aposta, int  numero_de_jogadas, char *arquivo, int spot, int vetor_num_jogados[]);
void apresentar2(int num_sorteados[], std::vector<int> &num_igual, float valor_ganho, int valor_total, int cont, int num_jogadas, int valor_da_aposta, int numero_acertos, int spot);
void sumario(int valor_da_aposta, int valor_total);

#endif