/*
• Author:   Eliazar Noa Llasccanoa
• @Date: 2023-03-31 00:18:12
*/

#include <bits/stdc++.h>
using namespace std;

const int inf = 99; // Variable que indica el límite superior de las coordenadas del tablero
const int N = 18; // Tamaño del tablero

bool visited[N][N]; // Arreglo que almacena si una casilla ha sido visitada o no

int dx[] = {-1, -2, 1, 2, -2, 1, 2, -1}; // Movimientos en x que puede hacer el caballo
int dy[] = {-2, -1, 2, 1, 1, -2, -1, 2}; // Movimientos en y que puede hacer el caballo

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    int t; 
    cin >> t; // Lee el número de casos de prueba

    while (t--) {
        string start, end; 
        cin >> start >> end; // Lee las coordenadas de inicio y fin

        int start_x = (int)(start[0] - 'a') + 1; // Calcula la coordenada x del inicio
        int start_y = (int)(start[1] - '0'); // Calcula la coordenada y del inicio
        int end_x = (int)(end[0] - 'a') + 1; // Calcula la coordenada x del final
        int end_y = (int)(end[1] - '0'); // Calcula la coordenada y del final

        queue<pair<int, int>> q; // Cola para almacenar las casillas por visitar
        q.push({start_x, start_y}); // Agrega la casilla de inicio a la cola
        q.push({inf, inf}); // Agrega un par de coordenadas que indica que se terminó de visitar una capa de casillas
        int moves = 0; // Inicializa la cantidad de movimientos en cero

        while (!q.empty()) {
            auto curr = q.front(); 
            q.pop(); 
            int curr_x = curr.first;
            int curr_y = curr.second; 

            // Si llegamos a la casilla final, terminamos la búsqueda
            if (curr_x == end_x && curr_y == end_y) {
                break;
            }

            // Si llegamos al final de una capa de casillas, aumentamos la cantidad de movimientos
            if (curr_x == inf && curr_y == inf) {
                q.push({inf, inf});
                moves++; 
                continue;
            }

            // Revisamos todas las casillas adyacentes que aún no han sido visitadas
            for (int i = 0; i < 8; i++) {
                int next_x = curr_x + dx[i];
                int next_y = curr_y + dy[i];

                if (next_x >= 1 && next_x <= 8 && next_y >= 1 && next_y <= 8 && !visited[next_x][next_y]) {
                    q.push({next_x, next_y}); 
                    visited[next_x][next_y] = true;
                } 
            }
        }

        // Imprimimos la cantidad de movimientos necesarios para llegar a la casilla final
        cout << moves << '\n'; 

        // Limpiamos el arreglo de visitados para el siguiente caso de prueba
        memset(visited, 0, sizeof visited);
    } 
    return 0; 
}