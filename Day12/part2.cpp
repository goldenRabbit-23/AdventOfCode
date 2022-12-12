#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    // const int R = 5, C = 8;
    const int R = 41, C = 95;
    const int INF = 1e9;

    /* North, East, South, West */
    const int DIRS = 4;
    const int DR[] = {-1, 0, +1, 0};
    const int DC[] = {0, +1, 0, -1};

    vector<vector<char>> elev(R, vector<char>(C));
    vector<vector<int>> dp(R, vector<int>(C, INF));
    vector<vector<bool>> vis(R, vector<bool>(C, false));
    vector<pair<int, int>> lowest;

    int ER, EC;
    string line;

    for (int i = 0; i < R; ++i) {
        cin >> line;
        for (int j = 0; j < C; ++j) {
            if (line[j] == 'S') {
                elev[i][j] = 'a';
                lowest.push_back({i, j});
            } else if (line[j] == 'E') {
                ER = i;
                EC = j;
                elev[ER][EC] = 'z';
            } else {
                elev[i][j] = line[j];
                if (elev[i][j] == 'a')
                    lowest.push_back({i, j});
            }
        }
    }

    int ans = INF;

    for (int i = 0; i < lowest.size(); ++i) {
        queue<pair<int, int>> q;

        q.push({lowest[i].first, lowest[i].second});
        vis[lowest[i].first][lowest[i].second] = true;
        dp[lowest[i].first][lowest[i].second] = 0;
        while (!q.empty()) {
            pair<int, int> nxt = q.front();
            q.pop();
            for (int i = 0; i < DIRS; ++i) {
                int dr = nxt.first + DR[i];
                int dc = nxt.second + DC[i];
                if (dr >= 0 && dr < R && dc >= 0 && dc < C) {
                    if (!vis[dr][dc]) {
                        if (elev[dr][dc] <= elev[nxt.first][nxt.second] + 1) {
                            dp[dr][dc] = dp[nxt.first][nxt.second] + 1;
                            q.push({dr, dc});
                            vis[dr][dc] = true;
                        }
                    }
                }
            }
        }

        ans = min(ans, dp[ER][EC]);

        for (auto &v : dp)
            fill(v.begin(), v.end(), INF);
        for (auto &v : vis)
            fill(v.begin(), v.end(), false);
    }

    cout << ans;

    return 0;
}