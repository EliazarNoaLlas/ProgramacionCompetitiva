#include <iostream>

using namespace std;

int main() {
    int n, k, e;
    cin >> n >> k >> e;

    int empty_squares = e;
    int covered_squares = n - e - k;

    for (int i = n - k - 1; i >= 0; i--) {
        int tile_width = i + 1;
        int tile_height = min(empty_squares, n - i - k);
        if (tile_height > 0) {
            int covered_by_tile = tile_width * tile_height;
            covered_squares += covered_by_tile;
            empty_squares -= covered_by_tile;
        }
    }

    cout << empty_squares << endl;

    return 0;
}
