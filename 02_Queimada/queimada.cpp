#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;


const int nc = 60;
const int nl = 20;

struct Par
{
    int l, c;
    Par(int l = 0, int c = 0) {
        this->l = l;
        this->c = c;
    }
};

vector<Par> getNeiber(Par p) {
    vector<Par> v;
    v.push_back(Par(p.l, p.c + 1));
    v.push_back(Par(p.l, p.c - 1));
    v.push_back(Par{p.l + 1, p.c});
    v.push_back(Par{p.l - 1, p.c});
    return v;
}

void mostrar(vector<string>& mat){
    cout << string(50, '\n');
    for(string s : mat)
        cout << s << endl;
    getchar();
}

vector<Par> shuffle(vector<Par> vet){
    for(int i = 0; i < (int) vet.size();i++){
        int random = rand() % vet.size();
//        int aux = vet[i];
//        vet[i] = vet[random];
//        vet[random] = aux;
        std::swap(vet[i], vet[random]);
    }
    return vet;
}

int queimar(vector<string> &mat, int l, int c, int nivel){

        if(l < 0 || l >= nl)
                return 0;
        if(c < 0 || c >= nc)
                return 0;
        if(mat[l][c] != '#')
                return 0;

        int contador = 0;
        mat[l][c] = '0' + nivel%10;
        contador += 1;
        mostrar(mat);

//        vector<int> v1 = {3,5,1,2};
//        vector<int> v2 = shuffle(v1);
//        vector<int> v3 = std::random_shuffle(begin(v1), end(v1));

        for(Par p : shuffle(getNeiber(Par(l, c))))
          contador += queimar(mat, p.l, p.c, nivel + 1);
//        queimar(mat, l, c + 1);
//        queimar(mat, l, c - 1);
//        queimar(mat, l - 1, c);
//        queimar(mat, l + 1, c);

        mat[l][c] = ' ';

        mostrar(mat);

        return contador;
}


int main()
{
    srand(time(NULL));
    //os containers tem uma construção padrao
    //container<tipo> nome(qtd, elemento_default)
    //cria um vetor de string
    //com nl elementos da string default
    //a string default sao 30 char ' '
    vector<string> mat(nl, string(nc, ' '));
    int narvores = nl * nc * 1.5;
    //insere varias arvores em lugares aleatorios
    //muitas serao superpostas
    for(int i = 0; i < narvores; i++){
        mat[rand() % nl][rand() % nc] = '#';
    }

    mostrar(mat);
    int total = queimar(mat, 0, 0, 0);
    cout << total << " arvores queimaram\n";

    return 0;
}
