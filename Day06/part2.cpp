#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string data;
    bool flag;

    cin >> data;

    for (int i = 0; i < data.size() - 14; ++i) {
        string marker = data.substr(i, 14);
        sort(marker.begin(), marker.end());

        flag = true;
        for (int j = 0; j < 13; ++j) {
            if (marker[j] == marker[j + 1]) {
                flag = false;
                break;
            }
        }

        if (flag) {
            cout << i + 14;
            break;
        }
    }

    return 0;
}