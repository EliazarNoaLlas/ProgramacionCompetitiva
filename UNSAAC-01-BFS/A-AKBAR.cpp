/*
• Author:   Eliazar Noa Llasccanoa
• @Date: 2023-03-31 00:17:11
*/
#include<bits/stdc++.h>
#include<bits/extc++.h>

// Se define la macro debug(x) para imprimir valores de variables en tiempo de ejecución
#define debug(x) std::cerr << #x << "=" << x <<< std::endl;

// Se definen las macros _for y _rep para facilitar la escritura de ciclos for
#define _for(i, a, b) for(int i = (a); i < (b); i++) 
#define _rep(i, a, b) for(int i = (a); i <= (b); i++)

using namespace std;

using ll  = long long; 
using PII = std::pair<int, int>;

using namespace __gnu_pbds;
using namespace __gnu_cxx;

constexpr int INF = 0x3f3f3f3f;
constexpr int mod = 1e9 + 7;

void solve(){

    // Lectura de la entrada
    int num_ciudades, num_rutas, num_soldados; 
    std::cin>> num_ciudades >> num_rutas >> num_soldados;

    // Se crea un vector de vectores para representar el grafo
    std::vector<std::vector<int>> grafo(num_ciudades + 1, std::vector<int>()); 

    // Se lee cada una de las rutas y se agrega a la lista de adyacencia del grafo
    for (int i = 1; i <= num_rutas; i++){
        int u, v;
        std::cin >> u >> v;
        grafo[u].emplace_back(v);
        grafo[v].emplace_back(u);
    }

    // Se utiliza una cola para recorrer el grafo en anchura
    std::queue<PII> cola;
    std::vector<int> visitado(num_ciudades + 1); 

    // Se lee cada uno de los soldados y se agrega a la cola de búsqueda en anchura
    for (int i = 0; i < num_soldados; i++){ 
        int ciudad, alcance;
        std::cin >> ciudad >> alcance;
        cola.emplace(ciudad, alcance);
        visitado[ciudad] = ciudad;    
    }

    // Búsqueda en anchura
    while (!cola.empty()){
        auto [ciudad, alcance] = cola.front(); cola.pop();
        for(int ady : grafo[ciudad]){
            if(alcance == 0) continue;
            if (visitado[ady] && visitado[ciudad] != visitado[ady]){
                std::cout << "No" << '\n';
                return;
            }
            visitado[ady] = visitado[ciudad]; 
            cola.emplace(ady, alcance-1);
        }
    }

    // Si existen ciudades que no han sido visitadas por ningún soldado, se imprime "No"
    for(int i = 1; i <= num_ciudades; i ++){
        if( !visitado[i]){
            std::cout << "No" << '\n';
            return;
        }
    }

    // Si todas las ciudades están protegidas por al menos un soldado, se imprime "Yes"
    std::cout << "Yes" << '\n';
}

int main()
{
    // Se desactiva la sincronización con la entrada y salida estándar para aumentar la velocidad de lectura
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // Se lee los casos de pruba
    int tt = 1;
    std::cin>> tt;
    // solucion para cada caso de prueba
    while(tt--) solve();
    return 0;
}