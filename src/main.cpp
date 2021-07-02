#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iomanip>
#include "Validar.h"
#include "Sorteio.h"
using namespace std;

int main(int argc, char *argv[]){
    int v[5], i = 0, x, num_jogadas, j = 0, tam = 0, tam1 = 0;//tam = tamanho do vetor
    float v_float[22], valor_da_aposta, y, vetor[22];
    stringstream xx;
    int recebedora;
    ifstream arquivo_tst_keno;
    string linha;
    string linha2;
    int teste_valor_linhas = 0, linha_vazia = 0, cont = 0;
    vector<int>num_jogador;
    
    if(argc < 2){
        recebedora = 1;
        cout << "não tem arquivo";
    } else {
        arquivo_tst_keno.open(argv[1]);
        if(arquivo_tst_keno.is_open()){
            while(getline(arquivo_tst_keno, linha)){
                cout << linha << endl;
                xx << linha << endl;
                if(linha.empty()){
                    linha_vazia++;
                }
                teste_valor_linhas++;
            }
            if(linha_vazia == teste_valor_linhas){
                recebedora = 1;
                cout<< "ARQUIVO VAZIO";
            }else{
                cout << "\narquivo com coisas";
                if(teste_valor_linhas < 3 || teste_valor_linhas > 3){//verifica numero de linhas
                    recebedora = 1;
                    cout << "\ntamanho invalido de linhas";
                }else{
                    cout<<"\ntamanho de linhas ok";
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

                    /*cout << "\n==CONVERTIDOS==\n";
                    for(int i=0; i<tam;i++){
                        cout << v_float[i] << "\t";
                    }*/

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
    vector<int>num_sorteados;
    vector<int>arr;
    vector<int>num_igual;
    cout << "\n\n";
    
    if(recebedora == 1){
        cout << "\nJogo invalido!\n";
    }else{
        cout << "\nJogo correto!\n";
        num_sorteados = adm(arr);
        num_igual = comparar(num_jogador, num_sorteados);

    }

    return 0;
    
}