#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include "Validar.h"
#include "Sorteio.h"
using namespace std;

int main(int argc, char *argv[]){
    int v[5], i = 0, x, num_jogadas, j = 0, tam = 0;//tam = tamanho do vetor
    float v_float[22], valor_da_aposta, y;
    stringstream xx;

    ifstream arquivo_tst_keno;
    string linha;

    arquivo_tst_keno.open(argv[1]);
    if(arquivo_tst_keno.is_open()){
        while(getline(arquivo_tst_keno, linha)){
            cout << linha << endl;
            xx << linha << endl;
        }
    } else{
        cout << "NÃO FOI POSSIVEL ABRIR O ARQUIVO\n";
    }
   
    while(xx >> y){//aplicando o stringstream
        v_float[j] = y;//guardando na variavel
        j++;
        tam++;
    }

    cout << "\n==CONVERTIDOS==\n";
    for(int i=0; i<5;i++){
        cout << v_float[i] << endl;
    }
    
    valor_da_aposta = v_float[0];
    cout << "\nValor da aposta: " << valor_da_aposta <<  fixed << setprecision(1) << "\n";

    num_jogadas = v_float[1];
    cout << "\nNúmero de jogadas: " << num_jogadas << "\n";

    tam = tam - 2;
    int num_escolhidos[tam], jj = 2;

    for(int l=0; l<tam; l++){//preenchendo vetor com os números
        num_escolhidos[l] = v_float[jj];
        jj++;
    }
    cout << "\nVetor de números do jogador: ";
    for(i = 0; i<tam; i++){
        cout << num_escolhidos[i] << "\t";
    }
    int recebedora;

    recebedora = val(num_escolhidos, tam);

    if(recebedora == 1){
        cout << "\nJogo invalido\n";
    }else{
        cout << "\nJogo correto\n";
        sorteando(tam);
    }


    return 0;
}