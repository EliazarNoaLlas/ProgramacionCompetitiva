#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100;
int r, c;
int grid[MAXN][MAXN];
bool visited[MAXN][MAXN];
int directions[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

bool valid(int x, int y) {
    return (x >= 0 && x < r && y >= 0 && y < c);
}

int dfs(int x, int y, int step) {
    visited[x][y] = true;
    if (grid[x][y] == step) {
        if (step == r*c) return 1;
        step++;
    }
    int max_steps = 0;
    for (int i = 0; i < 4; i++) {
        int nx = x + directions[i][0];
        int ny = y + directions[i][1];
        if (valid(nx, ny) && !visited[nx][ny]) {
            int res = dfs(nx, ny, step);
            max_steps = max(max_steps, res);
        }
    }
    visited[x][y] = false;
    return max_steps;
}

int main() {
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> grid[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            ans = max(ans, dfs(i, j, 1));
        }
    }
    cout << ans << endl;
    return 0;
}
