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

/*
Avaliação
Processamento do Arquivo de Entrada: 0,6 (faltou o erro do arquivo inexistente, presença de carateres, formatação diferente)
Execução correta: 0.8 (no sorteio não podem haver numeros repetidos)
Interfcace Textual: 1
Documentação: 1
Compilação automatizada: 1
Organização em src, include, build, data: 0,8 (faltou o uso do "data" para guardar os arquivos de teste)

Observações:
- Gostei que vocês tentaram usar mais classes, porém vocês ainda não entenderam a real utilidade de guardar atributos nas classes.
Um exemplo claro é a classe Sorteio. Uma forma melhor de organziar o código seria se ela tivesse um método "realizar_sorteio" que fizesse
o processamento que está sendo feito na parte "realiza sorteio dos números".
- Em muitos pontos vcs optaram por usar vetores de int[], lembrem do que eu falei, em c++ a gente usa std::vector ou std::array em tudo
que der. Usando vector vcs poderiam usar a função std::find para descobrir se um elemento está no vetor, sem precisar daquele método "Existe"
da classes sorteio.
- Adicionei um arquivo "teste_arquivo.dat" e também removi o srand(time(null)) do main para que vcs possam ver que aparecem números repetidos
no sorteio, apenas executem o programa com aquele arquivo.
*/


/*! 
 * @brief Função principal do programa.
 * 
 * @param argc recebe a quantidade de argumentos que foram passados ao chamar o programa.
 * @param argv é um vetor de char que contém os argumentos passados na linha de comando.
 *
 * @return 0 para informar que o programa terminou de maneira normal.
 */


int main(int argc, char *argv[]){
    int numero_de_jogadas, teste_valor_linhas = 0, linha_vazia = 0, recebedora, j = 0, x, cont = 0;
    double valor_da_aposta;
    vector<int> numeros_jogador;
    float v_float[17], y;
    string linha;
    stringstream xx;
    ifstream arquivo_tst_keno;
    //srand((unsigned)time(0));

    // verifica se o arquivo foi passado como argumento ao chamar o programa, caso nenhum arquivo tenha sido passado, uma mensagem será exibida ao jogador.
    if(argc < 2){
        recebedora = 1;
        cout << "ERRO! VOCÊ NÃO INSERIU NENHUM ARQUIVO.";
    } else {

        // abertura do arquivo que foi passado como argumento.
        arquivo_tst_keno.open(argv[1]);

        // verifica se o arquivo foi, de fato, aberto.
        if(arquivo_tst_keno.is_open()){
            while(getline(arquivo_tst_keno, linha)){
                // enquanto houver linhas para pegar, o xx irá receber o conteúdo das linhas.
                xx << linha << endl;

                //verifica se há linhas vazias.
                if(linha.empty()){
                    linha_vazia++;
                }
                teste_valor_linhas++;
            }

            //verifica se o arquivo é vazio com base no número de linahs que o arquivo possui.
            if(linha_vazia == teste_valor_linhas){
                recebedora = 1;
                cout<< "ERRO! ARQUIVO VAZIO";

            }else{
                //verifica o número de linhas que o arquivo possui e emite uma mensagem caso o número de linhas seja diferente do necessário.
                if(teste_valor_linhas < 3 || teste_valor_linhas > 3){
                    recebedora = 1;
                    cout << "\nERRO! TAMANHO INVÁLIDO DE LINHAS" << endl;
                }else{
                    
                    while(xx >> y){
                        //preenchendo o vetor com o conteúdo de y, que é preenchido pelo conteúdo de xx, que coletou o conteúdo das linhas do arquivo.
                        v_float[j] = y;

                        //o vetor é preenchido pelos números apostados pelo jogador.
                        if(j>=2){
                            numeros_jogador.push_back(y);
                            cont++;
                        }
                        j++;
                    }
                    valor_da_aposta = v_float[0];
                    numero_de_jogadas = v_float[1];
                    int vetor_numeros_apostado[cont];

                    //o vetor será preenchido com os números do jogador.
                    for(int i = 0; i < cont ; i++){
                        vetor_numeros_apostado[i] = numeros_jogador[i];
                    }

                    //aqui é chamada a função que irá realizar a validação do arquivo.
                    recebedora = val(vetor_numeros_apostado, cont);

                }    
            }
        } 
    } 
    //tamanho do vetor que possui os números apostados pelo jogador.
    size_t tam_numeros_jogados = numeros_jogador . size();
    int vetor_num_jogados[tam_numeros_jogados];
    for(int u = 0; u < tam_numeros_jogados; u++){
        vetor_num_jogados[u] = numeros_jogador[u];
    }
    Sorteio a;
    Sorteio b;
    Sorteio c;
    Sorteio d;
    vector<int> numeros_vencedores;

    float valor_ganho, valor_total;
    int vv[20];
    int resto = 0, xy, v;
    if(recebedora == 1){
        //cout << "\nJogo inválido!\n";

    }else{
        size_t spot = numeros_jogador . size();
        //cout << "\nJogo válido!\n";
        apresentar(valor_da_aposta, numero_de_jogadas, argv[1], spot, vetor_num_jogados);

        for(int i = 1; i<=numero_de_jogadas; i++){    
            //realiza o sorteio dos números.
            for(int j = 0; j < c.quantidade_num; j++){
                v = 1 + (rand() % b.limite);
                while(d.Existe(a.vetor_sorteado, j, v)){
                    v = 1 + (rand() % b.limite);
                }
                a.vetor_sorteado[j] = v;
            }
            cout << "\n";

            //o método de comparação é chamada para comparar o vetor de números sorteados com o vetor de números apostados pelo jogador.
            numeros_vencedores = comparar(a.vetor_sorteado, c.quantidade_num, vetor_num_jogados, tam_numeros_jogados);
            size_t qtd_num_vencidos = numeros_vencedores . size();
            size_t qtd_num_jogados = numeros_jogador . size();
            //chama a função para calcular o valor do prêmio por rodada.
            valor_ganho = calculo(valor_da_aposta,  numero_de_jogadas, qtd_num_vencidos, qtd_num_jogados);
            //chama a função que irá calcular os créditos totais.
            valor_total = calculo_tot(valor_da_aposta, numero_de_jogadas, valor_ganho, i, resto);
            resto = valor_total;
            apresentar2(a.vetor_sorteado, numeros_vencedores, valor_ganho, valor_total, i, numero_de_jogadas, valor_da_aposta, qtd_num_vencidos, qtd_num_jogados);
            xy = valor_total;
        }
        sumario(valor_da_aposta, xy);

    }

    return 0;
}