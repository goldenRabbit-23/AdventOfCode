#include <bits/stdc++.h>
using namespace std;

vector<string> split(const string &s, char delim) {
    vector<string> result;
    stringstream ss(s);
    string item;

    while (getline(ss, item, delim))
        result.push_back(item);

    return result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int X = 1;
    int cycle = 0;
    int ans = 0;
    string line;

    while (getline(cin, line)) {
        vector<string> parsed = split(line, ' ');

        if (parsed[0] == "noop") {
            ++cycle;
            if ((cycle - 20) % 40 == 0)
                ans += cycle * X;
        } else {
            int reg = stoi(parsed[1]);

            for (int i = 0; i < 2; ++i) {
                ++cycle;
                if ((cycle - 20) % 40 == 0)
                    ans += cycle * X;
            }

            X += reg;
        }
    }

    cout << ans;

    return 0;
}