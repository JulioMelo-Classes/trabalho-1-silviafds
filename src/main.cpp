#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include "Validar.h"
#include "Sorteio.h"
#include "Resultado.h"
using namespace std;

int main(int argc, char *argv[]){
    int v[5], i = 0, x, num_jogadas, j = 0, tam = 0, tam1 = 0;//tam = tamanho do vetor
    float v_float[17], valor_da_aposta, y, vetor[17];
    stringstream xx;
    int recebedora;
    ifstream arquivo_tst_keno;
    string linha;
    string linha2;
    int teste_valor_linhas = 0, linha_vazia = 0, cont = 0;
    vector<int> num_jogador;

    
    if(argc < 2){
        recebedora = 1;
        cout << "ERRO! VOCÊ NÃO INSERIU NENHUM ARQUIVO.";
    } else {
        arquivo_tst_keno.open(argv[1], ios::binary)  ;
        if(arquivo_tst_keno.is_open()){
            while(getline(arquivo_tst_keno, linha)){
                //cout << linha << endl;
                xx << linha << endl;
                if(linha.empty()){
                    linha_vazia++;
                }
                teste_valor_linhas++;
            }
            if(linha_vazia == teste_valor_linhas){
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
                            vetor[j] = y;
                            num_jogador.push_back(y);//preenche vector com numeros apostado
                            cont++;
                        }
                        j++;
                        tam++;
                    }

                    valor_da_aposta = v_float[0];
                   // cout << "\nValor da aposta: " << valor_da_aposta <<  fixed << setprecision(1) << "\n";

                    num_jogadas = v_float[1];
                    //cout << "\nNumero de jogadas: " << num_jogadas << "\n";

                    tam = tam - 2;
                    int num_escolhidos[tam], jj = 2;
                    

                    for(int l = 0; l<tam; l++){//preenchendo vetor com números escolhidos
                        num_escolhidos[l] = v_float[jj];
                        jj++;
                    }

                    recebedora = val(num_escolhidos, tam);//faz a validação
                }    
            }
        } 
    }   

    vector<int>num_sorteados;//recebe numeros sorteados aleatorio
    vector<int>arr;//passei na func adm para me retornar vetor de num sorteado
    vector<int>num_igual;//vetor q guardar os hits
    cout << "\n\n";
    int xy = 0;//variavel q receve valor total de crédito do jogador
    int resto = 0;
    if(recebedora == 1){
        //cout << "\nERRO! JOGO INVÁLIDO\n";

    }else{
        size_t spot = num_jogador . size();
        apresentar(valor_da_aposta, num_jogadas, argv[1], spot, num_jogador);//fica fora o for

       // for(int i=1; i<=2; i++){

            for(int i = 1; i <= num_jogadas; i++) {
                num_sorteados = adm(arr, i);//recebe vetor num sorteado
                num_igual = comparar(num_jogador, num_sorteados);//recbe vetor hits
                size_t spot = num_jogador . size();//pego tamanho de vector
                size_t numero_acertos = num_igual . size();//valor incomum

                float valor_ganho, valor_total;
                valor_ganho = calculo(valor_da_aposta, num_jogadas, numero_acertos, spot);//valor do premio
                valor_total = calculo_tot(valor_da_aposta, num_jogadas, valor_ganho, i, resto);//soma credito + premio 
                resto = valor_total;
                apresentar2(num_sorteados, num_igual, valor_ganho, valor_total, i, num_jogadas, valor_da_aposta, numero_acertos, spot);
                num_sorteados.clear();
                num_igual.clear();
                arr.clear();
                xy = valor_total;
            }
            //num_sorteados.erase(num_sorteados.begin(), num_sorteados.end());
            //num_igual.erase(num_igual.begin(), num_igual.end());
        //}

        sumario(valor_da_aposta, xy);
    }

    return 0;
    
}