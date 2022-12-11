#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string item_list;
    int sum = 0;
    vector<bool> exist(52, false);

    while (cin >> item_list) {
        int len = item_list.size();

        for (int i = 0; i < len / 2; ++i) {
            char item = item_list[i];

            if (item >= 'a' && item <= 'z')
                exist[item - 'a'] = true;
            else
                exist[item - 'A' + 26] = true;
        }

        for (int i = len / 2; i < len; ++i) {
            char item = item_list[i];

            if (item >= 'a' && item <= 'z') {
                if (exist[item - 'a']) {
                    sum += item - 'a' + 1;
                    break;
                }
            } else {
                if (exist[item - 'A' + 26]) {
                    sum += item - 'A' + 27;
                    break;
                }
            }
        }

        fill(exist.begin(), exist.end(), false);
    }

    cout << sum;

    return 0;
}