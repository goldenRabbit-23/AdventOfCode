#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string data;

    cin >> data;

    for (int i = 3; i < data.size(); ++i) {
        if (data[i - 3] != data[i - 2] && data[i - 3] != data[i - 1] && data[i - 3] != data[i] && data[i - 2] != data[i - 1] && data[i - 2] != data[i] && data[i - 1] != data[i]) {
            cout << i + 1;
            break;
        }
    }

    return 0;
}