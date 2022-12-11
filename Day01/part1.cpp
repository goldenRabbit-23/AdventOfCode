#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string cal;
    int cur_cal = 0;
    int max_cal = 0;

    while (1) {
        getline(cin, cal);

        if (cal == "-1")
            break;

        if (cal == "") {
            max_cal = max(max_cal, cur_cal);
            cur_cal = 0;
            continue;
        }

        cur_cal += stoi(cal);
    }

    cout << max_cal;

    return 0;
}