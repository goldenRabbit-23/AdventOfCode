#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string item_list1, item_list2, item_list3;
    int sum = 0;
    vector<int> count(52, 0);

    while (cin >> item_list1 >> item_list2 >> item_list3) {
        for (int i = 0; i < item_list1.size(); ++i) {
            char item = item_list1[i];

            if (item >= 'a' && item <= 'z')
                count[item - 'a'] = 1;
            else
                count[item - 'A' + 26] = 1;
        }

        for (int i = 0; i < item_list2.size(); ++i) {
            char item = item_list2[i];

            if (item >= 'a' && item <= 'z') {
                if (count[item - 'a'] == 1)
                    count[item - 'a'] = 2;
            } else {
                if (count[item - 'A' + 26] == 1)
                    count[item - 'A' + 26] = 2;
            }
        }

        for (int i = 0; i < item_list3.size(); ++i) {
            char item = item_list3[i];

            if (item >= 'a' && item <= 'z') {
                if (count[item - 'a'] == 2) {
                    sum += item - 'a' + 1;
                    break;
                }
            } else {
                if (count[item - 'A' + 26] == 2) {
                    sum += item - 'A' + 27;
                    break;
                }
            }
        }

        fill(count.begin(), count.end(), 0);
    }

    cout << sum;

    return 0;
}