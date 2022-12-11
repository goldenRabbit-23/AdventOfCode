#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    const int N = 99;

    int grid[N][N];
    string line;

    for (int i = 0; i < N; ++i) {
        cin >> line;
        for (int j = 0; j < N; ++j)
            grid[i][j] = line[j] - '0';
    }

    int ans = 4 * N - 4;
    bool up, down, left, right;

    for (int i = 1; i < N - 1; ++i) {
        for (int j = 1; j < N - 1; ++j) {
            up = down = left = right = true;

            for (int r = 0; r < i; ++r) {
                if (grid[i][j] <= grid[r][j]) {
                    up = false;
                    break;
                }
            }

            for (int r = i + 1; r < N; ++r) {
                if (grid[i][j] <= grid[r][j]) {
                    down = false;
                    break;
                }
            }

            for (int c = 0; c < j; ++c) {
                if (grid[i][j] <= grid[i][c]) {
                    left = false;
                    break;
                }
            }

            for (int c = j + 1; c < N; ++c) {
                if (grid[i][j] <= grid[i][c]) {
                    right = false;
                    break;
                }
            }

            ans += up || down || left || right;
        }
    }

    cout << ans;

    return 0;
}