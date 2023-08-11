#include<iostream>
#include<queue>
#include<vector>
using namespace std;

// Declaración de constantes y variables
const int MAXN = 1e2 + 7; // Tamaño maximo de entrada
int n, in_degree[MAXN]; // n: almacena el numero de nombres
vector<string> words;
vector<int> grafo[MAXN], ans;

// Verificar si la cadena b es prefijo de la cadena a
bool add_edge(string &a, string &b) {
    for (int i = 0; i < a.length(); i++) {
        if (i >= b.length()) return false;
        if (a[i] == b[i]) continue;
        grafo[a[i] - 'a'].push_back(b[i] - 'a');
        in_degree[b[i] - 'a']++; // Incrementa el grado de entrada de b[i] porque se dirige hacia él una arista
        break;
    }
    return true;
}

int main() {
    cin >> n;
    words.push_back(" "); // Se agrega una palabra vacía para que la indexación coincida con el número de palabras
    bool possible = true; // Bandera para determinar si es posible crear el orden lexicográfico
    for (int i = 1; i <= n; i++) {
        string temp;
        cin >> temp;
        words.push_back(temp);
    } 
    for (int i = 1; i <= n - 1; i++) {
        if (!add_edge(words[i], words[i + 1])) {
            possible = false;
            break;
        }
    }

    priority_queue<int, vector<int>, greater<int>> pq; // Cola de prioridad mínima para ordenar el alfabeto

    for (int i = 0; i < 26 && possible; i++) {
        if (in_degree[i] == 0) pq.push(i);
    }

    while (pq.size() && possible) {
        int current = pq.top(); pq.pop();
        ans.push_back(current);
        for (int i = 0; i < grafo[current].size(); i++) {
            int next = grafo[current][i];
            in_degree[next]--;
            if (in_degree[next] == 0) pq.push(next);
        }
    }

    if (ans.size() < 26 || !possible) {
        cout << "Impossible" << endl;
    } else {
        for (int i = 0; i < ans.size(); i++) {
            cout << (char) (ans[i] + 'a');
        }
    }
}
