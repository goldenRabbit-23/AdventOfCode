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

    int cycle = 0;
    int sprite = 1;
    string line;

    while (getline(cin, line)) {
        vector<string> parsed = split(line, ' ');

        if (parsed[0] == "noop") {
            int crt = (++cycle - 1) % 40;

            if (crt == sprite - 1 || crt == sprite || crt == sprite + 1)
                cout << '#';
            else
                cout << '.';

            if (cycle % 40 == 0)
                cout << '\n';
        } else {
            int reg = stoi(parsed[1]);

            for (int i = 0; i < 2; ++i) {
                int crt = (++cycle - 1) % 40;

                if (crt == sprite - 1 || crt == sprite || crt == sprite + 1)
                    cout << '#';
                else
                    cout << '.';

                if (cycle % 40 == 0)
                    cout << '\n';
            }

            sprite += reg;
        }
    }

    return 0;
}