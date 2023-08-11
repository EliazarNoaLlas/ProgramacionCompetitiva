#include <bits/stdc++.h>
using namespace std;

class Graph{
    // Parametros del grafo
    int V;          // -- numero de vertices 
    list<int> *adj; // -- lista de enteros
    public:
        Graph(int V);
        void addEdge(int v, int w);
        void printGraph();
};
Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
}
void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
    adj[w].push_back(v);
}
void Graph::printGraph() {
    for (int v = 0; v < V; ++v) {
        cout << "Lista de adyacencia del vértice " << v << ": ";
        for (auto x : adj[v])
            cout << x << " ";
        cout << endl;
    }
}
int main(){
    int V = 5;
    Graph g(V);
    g.addEdge(0,1);
    g.printGraph();
    return 0;
}