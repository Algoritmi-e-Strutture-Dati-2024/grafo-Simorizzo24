#include <iostream>
#include <string>
using namespace std;

int main() {
    Grafo<string> grafo;

    grafo.aggiungiNodo("Milano");
    grafo.aggiungiNodo("Roma");
    grafo.aggiungiNodo("Napoli");
    grafo.aggiungiNodo("Torino");
    grafo.aggiungiNodo("Bologna");

    grafo.aggiungiArco("Milano", "Roma", 10);
    grafo.aggiungiArco("Milano", "Napoli", 15);
    grafo.aggiungiArco("Roma", "Torino", 12);
    grafo.aggiungiArco("Napoli", "Bologna", 10);
    grafo.aggiungiArco("Torino", "Bologna", 2);
    grafo.aggiungiArco("Roma", "Bologna", 5);

    cout << "Matrice di Adiacenza:" << endl;
    grafo.stampa();

    if (grafo.verificaNodo("Milano")) {
        cout << "Il nodo Milano esiste nel grafo." << endl;
    }

    grafo.nodiAdiacenti("Roma");

    if (grafo.verificaArco("Milano", "Roma")) {
        cout << "Esiste un arco da Milano a Roma." << endl;
    }

    grafo.rimuoviNodo("Napoli");
    cout << "Dopo aver rimosso Napoli, matrice di adiacenza aggiornata:" << endl;
    grafo.stampa();

    grafo.rimuoviArco("Roma", "Bologna");
    cout << "Dopo aver rimosso l'arco tra Roma e Bologna, matrice di adiacenza aggiornata:" << endl;
    grafo.stampa();

    grafo.aggiungiNodo("Firenze");
    grafo.aggiungiArco("Bologna", "Firenze", 8);
    cout << "Dopo aver aggiunto Firenze e l'arco tra Bologna e Firenze, matrice di adiacenza aggiornata:" << endl;
    grafo.stampa();

    if (grafo.verificaConnettivita("Milano", "Bologna")) {
        cout << "Milano e Bologna sono connessi." << endl;
    } else {
        cout << "Milano e Bologna non sono connessi." << endl;
    }

    pair<string, int> arcoMinore = grafo.arcoPesoMinore("Roma");
    if (arcoMinore.second != -1) {
        cout << "Arco con peso minore da Roma: " << arcoMinore.first << " con peso " << arcoMinore.second << endl;
    }

 

    return 0;
}




    Milano
     /   \
   10/    \15
   /       \
 Roma     Napoli
   |        |
  12|      10
   |        |
 Torino   Bologna
   |        |
   2|       5
   |        |

