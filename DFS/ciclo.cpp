#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
// Estructura de datos para almacenar un borde de graph
struct Edge {
    int src, dest;
};
 
// Una clase para representar un objeto graph
class Graph
{
public:
    // un vector de vectores para representar una lista de adyacencia
    vector<vector<int>> grafoList;
 
    // Constructor de graph
    Graph(vector<Edge> const &edges, int n)
    {
        // cambiar el tamaño del vector para contener `n` elementos de tipo `vector<int>`
        grafoList.resize(n);
 
        // agrega bordes al grafo no dirigido
        for (auto &edge: edges)
        {
            grafoList[edge.src].push_back(edge.dest);
            grafoList[edge.dest].push_back(edge.src);
        }
    }
};
 
// Nodo para almacenar el vértice y su información principal en BFS
struct Node {
    int v, parent;
};
 
// Realiza BFS en el graph a partir del vértice `src` y
// devuelve verdadero si se encuentra un ciclo en el graph
bool BFS(Graph const &graph, int src, int n)
{
    // para realizar un seguimiento de si se descubre un vértice o no
    vector<bool> discovered(n);
 
    // marca el vértice de origen como descubierto
    discovered[src] = true;
 
    // crea una queue para hacer BFS y
    // poner en queue el vértice fuente
    queue<Node> q;
    q.push({src, -1});
 
    // bucle hasta que la queue esté vacía
    while (!q.empty())
    {
        // quitar la queue del nodo frontal e imprimirlo
        Node node = q.front();
        q.pop();
 
        // hacer para cada borde (v, u)
        for (int u: graph.grafoList[node.v])
        {
            if (!discovered[u])
            {
                // marcarlo como descubierto
                discovered[u] = true;
 
                // construye el nodo de queue que contiene inarray
                // sobre el vértice y ponerlo en queue
                q.push({ u, node.v });
            }
 
            // `u` se descubre, y `u` no es un padre
            else if (u != node.parent)
            {
                // encontramos un borde cruzado, es decir, se encuentra el ciclo
                return true;
            }
        }
    }
 
    // no se encontraron bordes cruzados en el graph
    return false;
}
 
int main()
{
    // inicializa los bordes
    vector<Edge> edges =
    {
        {0, 1}, {0, 2}, {0, 3}, {1, 4}, {1, 5}, {4, 8},
        {4, 9}, {3, 6}, {3, 7}, {6, 10}, {6, 11}, {5, 9}
        // borde {5, 9} introduce un ciclo en el graph
    };
 
    // número total de nodos en el graph (0 a 11)
    int n = 12;
 
    // construye un graph a partir de los bordes dados
    Graph graph(edges, n);
 
    // Realizar el recorrido BFS en componentes conectados de un graph
    if (BFS(graph, 0, n)) {
        cout << "The graph contains a cycle";
    }
    else {
        cout << "The graph doesn't contain any cycle";
    }
 
    return 0;
}
