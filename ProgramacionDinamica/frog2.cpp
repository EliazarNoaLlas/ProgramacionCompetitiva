#include <stdio.h>
#include <algorithm>
using namespace std;

int N, K, H[100100], D[100100];
int main()
{
    // Se lee la cantidad de piedras y el límite de saltos
    scanf("%d %d", &N, &K);

    // Se leen las alturas de cada piedra
    for (int i=1;i<=N;i++) scanf("%d", &H[i]);

    // Para cada piedra i a partir de la segunda
    for (int i=2;i<=N;i++){
        // Se calcula el costo mínimo para llegar a la piedra i
        // Si se salta de la piedra i-1 a la i
        D[i] = D[i-1] + abs(H[i-1]-H[i]);

        // Se consideran los saltos previos k
        for (int k=2;k<=K;k++){
            // Si es posible saltar desde la piedra i-k a la i
            // con un costo menor que el anterior, se actualiza el costo
            if (i > k && D[i] > D[i-k] + abs(H[i-k]-H[i]))
                D[i] = D[i-k] + abs(H[i-k]-H[i]);
        }
    }

    // Se imprime el costo mínimo para llegar a la piedra N
    printf("%d\n", D[N]);

    return 0;
}


