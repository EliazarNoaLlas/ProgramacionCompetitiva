#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

const int MAXN = 1 << 17;

int N, ans;
int dad[MAXN];

struct evnt {
    int lo, hi, id, top;
};

map<int, vector<evnt>> M;

int FIND(int x) {
    return (x == dad[x]) ? x : dad[x] = FIND(dad[x]);
}

void JOIN(int x, int y) {
    x = FIND(x);
    y = FIND(y);
    if (x != y) {
        ans--;
        dad[x] = y;
    }
}

bool cmp_1(const evnt &a, const evnt &b) {
    if (a.hi != b.hi) 
        return a.hi < b.hi;
    return (a.top < b.top);
}

bool cmp_2(const evnt &a, const evnt &b) {
    if (a.lo != b.lo) 
        return a.lo > b.lo; 
    return (a.top < b.top);
}

int main() {
    scanf("%d", &N);
    // Lectura de bloques
    for (int i = 0; i < N; i++) {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        // Se guarda el evento que representa la parte superior del bloque
        M[y1].push_back((evnt){x1, x2, i, 1});
        // Se guarda el evento que representa la parte inferior del bloque
        M[y2].push_back((evnt){x1, x2, i, 0});
    }
    
    ans = N;
    for (int i = 0; i < N; i++)
        dad[i] = i;
    // Procesamiento de los eventos por cada valor de y
    for (auto it = M.begin(); it != M.end(); it++) {
        vector<evnt> &V = it->second;
        vector<evnt> bot;

        // Caso 1: Se procesan los eventos de la parte superior de los bloques
        bot.clear();
        sort(V.begin(), V.end(), cmp_1);
        for (int i = 0; i < V.size(); i++) {
            if (V[i].top) {// Evento de parte superior del bloque
                for (int j = bot.size() - 1; j >= 0; j--) {
                    if (V[i].lo < bot[j].hi)
                        JOIN(V[i].id, bot[j].id);
                    else
                        break;
                }
            } else {// Evento de parte inferior del bloque
                bot.push_back(V[i]);
            }
        }
    
        // Caso 2: Se procesan los eventos de la parte inferior de los bloques
        bot.clear();
        sort(V.begin(), V.end(), cmp_2);
        for (int i = 0; i < V.size(); i++) {
            if (V[i].top) {       
                for (int j = bot.size() - 1; j >= 0; j--) {
                    if (V[i].hi > bot[j].lo)
                        JOIN(V[i].id, bot[j].id);
                    else
                        break;
                }
            } else {
                bot.push_back(V[i]);
            }
        }
    }
    
    printf("%d\n", ans);

    return 0;
}
