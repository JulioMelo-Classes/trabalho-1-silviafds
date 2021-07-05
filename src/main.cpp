#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <array>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include "Validar.h"
#include "Sorteio.h"
#include "Resultado.h"
using namespace std;

int main(int argc, char *argv[]){
    int numero_de_jogadas, teste_valor_linhas = 0, linha_vazia = 0, recebedora, j = 0, x, cont = 0;
    double valor_da_aposta;
    vector<int> numeros_jogador;
    float v_float[17], y;
    string linha;
    stringstream xx;
    ifstream arquivo_tst_keno;
    srand((unsigned)time(0));

    //inicio da leitura e validação do jogo
    if(argc < 2){//valida se existe arquivo
        recebedora = 1;
        cout << "ERRO! VOCÊ NÃO INSERIU NENHUM ARQUIVO.";
    } else {

        arquivo_tst_keno.open(argv[1]);

        if(arquivo_tst_keno.is_open()){//abre arquivo
            while(getline(arquivo_tst_keno, linha)){
                xx << linha << endl;//preenche xx com o conteúdo do arquivo
                if(linha.empty()){
                    linha_vazia++;
                }
                teste_valor_linhas++;
            }
            if(linha_vazia == teste_valor_linhas){//valida se arquivo é vazio ou não
                recebedora = 1;
                cout<< "ERRO! ARQUIVO VAZIO";

            }else{
                //cout << "\nArquivo com coisas";
                if(teste_valor_linhas < 3 || teste_valor_linhas > 3){//verifica numero de linhas
                    recebedora = 1;
                    cout << "\nERRO! TAMANHO INVÁLIDO DE LINHAS" << endl;
                }else{
                    //cout<<"\ntamanho de linhas ok" << endl;
                    while(xx >> y){//aplicando stringstream
                        v_float[j] = y;//guardando no vetor
                        if(j>=2){
                            numeros_jogador.push_back(y);//preenche vector com numeros apostado pelo jogador
                            cont++;
                        }
                        j++;
                    }

                    valor_da_aposta = v_float[0];///preenche valor bruto da aposta

                    numero_de_jogadas = v_float[1];//preenche o número total de jogadas

                    int vetor_numeros_apostado[cont];//vetor contém os numeros escolhidos pelo jogador

                    for(int i = 0; i < cont ; i++){//preenche vetor de int com números do jogador
                        vetor_numeros_apostado[i] = numeros_jogador[i];
                    }

                    recebedora = val(vetor_numeros_apostado, cont);//faz a validação

                }    
            }
        } 
    } 
    size_t tam_numeros_jogados = numeros_jogador . size();
    int vetor_num_jogados[tam_numeros_jogados];//vetor de inteiro apenas com os númeos do jogador
    for(int u = 0; u < tam_numeros_jogados; u++){
        vetor_num_jogados[u] = numeros_jogador[u];
    }
    Sorteio a;
    Sorteio b;
    Sorteio c;
    Sorteio d;
    vector<int> numeros_vencedores;//numeros do jogador que são iguais aos sorteados

    float valor_ganho, valor_total;
    int vv[20];
    int resto = 0, xy, v;
    if(recebedora == 1){
        cout << "\nJogo invalido!\n";

    }else{
        size_t spot = numeros_jogador . size();
        cout << "\nJogo valido!\n";
        apresentar(valor_da_aposta, numero_de_jogadas, argv[1], spot, vetor_num_jogados);//fica fora o for

        for(int i = 1; i<=numero_de_jogadas; i++){    

            for(int j = 0; j < c.quantidade_num; j++){//sorteando os números
                v = 1 + (rand() % b.limite);
                while(d.Existe(a.vetor_sorteado, j, v)){
                    v = 1 + (rand() % b.limite);
                }
                a.vetor_sorteado[j] = v;
            }
            cout << "\n";

            numeros_vencedores = comparar(a.vetor_sorteado, c.quantidade_num, vetor_num_jogados, tam_numeros_jogados);
            size_t qtd_num_vencidos = numeros_vencedores . size();
            size_t qtd_num_jogados = numeros_jogador . size();
            valor_ganho = calculo(valor_da_aposta,  numero_de_jogadas, qtd_num_vencidos, qtd_num_jogados);
            valor_total = calculo_tot(valor_da_aposta, numero_de_jogadas, valor_ganho, i, resto);//soma credito + premio
            resto = valor_total;
            apresentar2(a.vetor_sorteado, numeros_vencedores, valor_ganho, valor_total, i, numero_de_jogadas, valor_da_aposta, qtd_num_vencidos, qtd_num_jogados);
            xy = valor_total;
        }
        sumario(valor_da_aposta, xy);

    }

    return 0;
}