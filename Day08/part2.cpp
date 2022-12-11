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

    int ans = 0;
    int up, down, left, right;

    for (int i = 1; i < N - 1; ++i) {
        for (int j = 1; j < N - 1; ++j) {
            up = down = left = right = 0;

            for (int r = i - 1; r >= 0; --r) {
                ++up;
                if (grid[i][j] <= grid[r][j])
                    break;
            }

            for (int r = i + 1; r < N; ++r) {
                ++down;
                if (grid[i][j] <= grid[r][j])
                    break;
            }

            for (int c = j - 1; c >= 0; --c) {
                ++left;
                if (grid[i][j] <= grid[i][c])
                    break;
            }

            for (int c = j + 1; c < N; ++c) {
                ++right;
                if (grid[i][j] <= grid[i][c])
                    break;
            }

            ans = max(ans, up * down * left * right);
        }
    }

    cout << ans;

    return 0;
}