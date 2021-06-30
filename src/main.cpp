#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
using namespace std;

int main(int argc, char *argv[]){
    int i = 0, x, num_jogadas, j = 0, tam = 0;
    float v_float[5], valor_da_aposta, y;
    stringstream ss;
    stringstream xx;

    ifstream arquivo_tst_keno;
    string linha;

    arquivo_tst_keno.open(argv[1]);
    if(arquivo_tst_keno.is_open()){
        while(getline(arquivo_tst_keno, linha)){
            cout << linha << endl;
            ss << linha << endl;
            xx << linha << endl;
        }
    } else{
        cout << "NÃO FOI POSSIVEL ABRIR O ARQUIVO\n";
    }
   
    while(xx >> y){//aplicando o stringstream
        //cout << y*1 << endl;
        v_float[j] = y;//guardando na variavel
        j++;
        tam++;
    }

    cout << "\n==CONVERTIDOS==\n";
    for(int i=0; i<5;i++){
        cout << v_float[i] << endl;
    }
    
    valor_da_aposta = v_float[0];
    cout << "\nValor da aposta: " << valor_da_aposta << fixed << setprecision(1) << "\n";

    num_jogadas = v_float[1];
    cout << "\nNúmero de jogadas: " << num_jogadas << "\n";
    cout << "\nTamanho do vetor: " << tam << "\n";

    tam = tam - 2;
    int num_escolhidos[tam], jj = 2;

    vector<int> v1;
    for(int l=0; l<tam; l++){
        v1.push_back(v_float[jj]);
        jj++;
    }
    for(i = 0; i<tam; i++){
        cout << v1[i] << endl;
    }

    return 0;
}