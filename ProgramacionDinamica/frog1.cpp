#include <stdio.h>  // incluir librería stdio.h para usar scanf y printf
#include <algorithm> // incluir librería algorithm para usar la función abs y std::min
using namespace std; // usar el espacio de nombres std

int N, H[100100], D[100100]; // declarar variables globales

int main() { // función principal
    scanf("%d", &N); // leer número de piedras

    // leer altura de cada piedra
    for (int i = 1; i <= N; i++) {
        scanf("%d", &H[i]);
    }

    // calcular el mínimo costo de llegar a cada piedra
    for (int i = 2; i <= N; i++) {
        D[i] = D[i - 1] + abs(H[i - 1] - H[i]); // costo de saltar desde piedra i-1
        if (i > 2) { // si no estamos en la segunda piedra
            D[i] = min(D[i], D[i - 2] + abs(H[i - 2] - H[i])); // comparar costo de saltar desde piedra i-2
        }
    }

    printf("%d\n", D[N]); // imprimir el costo mínimo de llegar a la última piedra
    return 0; // retornar un valor entero
}
