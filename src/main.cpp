#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

int main(int argc, char *argv[]){
    int v[5];
    int i = 0, x, num_jogadas;
    float valor;
    stringstream ss;

    ifstream arquivo_tst_keno;
    string linha;

    arquivo_tst_keno.open(argv[1]);
    if(arquivo_tst_keno.is_open()){
        while(getline(arquivo_tst_keno, linha)){
            cout << linha << endl;
            ss << linha << endl;
        }
    } else{
        cout << "NÃO FOI POSSIVEL ABRIR O ARQUIVO\n";
    }
    while(ss >> x){//aplicando o stringstream
        //cout << x*1 << endl;
        v[i] = x*1;//guardando na variavel
        i++;
    }
    cout << "\n==CONVERTIDOS==\n";
    for(int i=0; i<5;i++){
        cout << v[i] << endl;
    }
    valor = v[0];
    float valor_aposta = (float)valor;//valor da aposta
    num_jogadas = v[1];

    cout << "\nValor convertido: " << valor_aposta << fixed << setprecision(1) << "\n";
    cout << "\nNúmero de jogadas: " << num_jogadas << "\n";

    float n = valor_aposta;
    cout << "\n" << n << endl;
    return 0;
}