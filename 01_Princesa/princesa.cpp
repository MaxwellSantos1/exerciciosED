#include <stdio.h>
#include <iostream>
#include <list>


void rodar(std::list<int> &lista){
    lista.push_back(lista.front());
    lista.pop_front();
}


void mostrar(std::list<int> &lista){
    for(int x : lista)
        std::cout << x << " ";
    std::cout << "\n";
}


int main(){
    int espada,qtd;

    std::cout << "Digite quantidade e primeiro" << std::endl;
    scanf("%i", &qtd);

    std::cin >> espada;

    std::list<int> lista;

    for(int i = 1; i <= qtd; i++)
        lista.push_back(i);

    while(lista.front() != espada)
        rodar(lista);

    while(lista.size() > 1){
        lista.pop_front();
        if(lista.front() == 3 || lista.front() == 1){
            rodar(lista);
            lista.pop_front();              // REALIZA O SALTO 2X CASO SEJA 3 OU 1
            rodar(lista);
            lista.pop_front();
        }
            rodar(lista);
            lista.pop_front();               // CASO NAO SEJA NAO EXECUTA N SALTOS
    }

    printf("Vencedor: ");

    mostrar(lista);

    return 0;
}
