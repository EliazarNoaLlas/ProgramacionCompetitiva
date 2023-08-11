#include<iostream>
#include<bits/stdc++.h> // Necesario para usar la función reverse


using namespace std;

const int N = 1e4+7;

vector<int> grafo[N], toposort; // grafo es el grafo de la ciudad, orden_topologico es el vector que almacenará el orden topológico
bool visitado1[N], visitado2[N];// visitado1 y visitado2 son los vectores que indicarán si se ha visitado un nodo en las dfs correspondientes

int n, m;// n es la cantidad de nodos, m es la cantidad de aristas
// Función dfs1 que realiza la primera dfs necesaria para obtener el orden topológico
void dfs1(int town) {
    visitado1[town] = 1;
    for (int u: grafo[town]) {
        if (!visitado1[u]) dfs1(u);
    }
    toposort.push_back(town);// Almacenamos el nodo actual en el orden topológico
}

// Función dfs2 que realiza la segunda dfs necesaria para obtener la cantidad de pipelines necesarios
void dfs2(int town) {
    visitado2[town] = 1;
    for (int v: grafo[town]) {
        if (!visitado2[v]) dfs2(v);
    }
}

int main() {
    while (cin >> n >> m) {
        // Lectura del grafo
        for (int i = 0; i < m; ++i) {
            int from, to;
            cin >> from >> to;
            grafo[from].push_back(to);
        }
        // Realizamos la primera dfs para obtener el orden topológico
        for (int i = 0; i <= n; ++i) {
            if (!visitado1[i]) dfs1(i);
        }        
        std::reverse(toposort.begin(), toposort.end());
        // Realizamos la segunda dfs contando la cantidad de pipelines necesarios
        dfs2(0);
        int pipelines = 0;
        for (int i: toposort) {
            if (!visitado2[i]) {
                dfs2(i);
                pipelines++;
            }
        }
        // Imprimimos la cantidad de pipelines necesarios para abastecer toda la ciudad
        cout << pipelines << endl;
        for (int i = 0; i <= n; ++i) {
            visitado1[i] = 0;
            visitado2[i] = 0;
            grafo[i].clear();
        }
        toposort.clear();
    }
    return 0;
}
