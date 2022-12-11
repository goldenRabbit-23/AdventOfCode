#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<char>> crates(10);

    crates[1].push_back('B');
    crates[1].push_back('S');
    crates[1].push_back('V');
    crates[1].push_back('Z');
    crates[1].push_back('G');
    crates[1].push_back('P');
    crates[1].push_back('W');

    crates[2].push_back('J');
    crates[2].push_back('V');
    crates[2].push_back('B');
    crates[2].push_back('C');
    crates[2].push_back('Z');
    crates[2].push_back('F');

    crates[3].push_back('V');
    crates[3].push_back('L');
    crates[3].push_back('M');
    crates[3].push_back('H');
    crates[3].push_back('N');
    crates[3].push_back('Z');
    crates[3].push_back('D');
    crates[3].push_back('C');

    crates[4].push_back('L');
    crates[4].push_back('D');
    crates[4].push_back('M');
    crates[4].push_back('Z');
    crates[4].push_back('P');
    crates[4].push_back('F');
    crates[4].push_back('J');
    crates[4].push_back('B');

    crates[5].push_back('V');
    crates[5].push_back('F');
    crates[5].push_back('C');
    crates[5].push_back('G');
    crates[5].push_back('J');
    crates[5].push_back('B');
    crates[5].push_back('Q');
    crates[5].push_back('H');

    crates[6].push_back('G');
    crates[6].push_back('F');
    crates[6].push_back('Q');
    crates[6].push_back('T');
    crates[6].push_back('S');
    crates[6].push_back('L');
    crates[6].push_back('B');

    crates[7].push_back('L');
    crates[7].push_back('G');
    crates[7].push_back('C');
    crates[7].push_back('Z');
    crates[7].push_back('V');

    crates[8].push_back('N');
    crates[8].push_back('L');
    crates[8].push_back('G');

    crates[9].push_back('J');
    crates[9].push_back('F');
    crates[9].push_back('H');
    crates[9].push_back('C');

    int cnt, from, to;

    while (cin >> cnt >> from >> to) {
        for (int i = 0; i < cnt; ++i) {
            char top = crates[from].back();
            crates[from].pop_back();
            crates[to].push_back(top);
        }
    }

    for (int i = 1; i < crates.size(); ++i)
        cout << crates[i].back();

    return 0;
}