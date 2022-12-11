#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string cal;
    int cur_cal = 0;
    int max1_cal = 0;
    int max2_cal = 0;
    int max3_cal = 0;

    while (1) {
        getline(cin, cal);

        if (cal == "-1")
            break;

        if (cal == "") {
            if (max1_cal < cur_cal) {
                max3_cal = max2_cal;
                max2_cal = max1_cal;
                max1_cal = cur_cal;
            } else if (max2_cal < cur_cal) {
                max3_cal = max2_cal;
                max2_cal = cur_cal;
            } else if (max3_cal < cur_cal)
                max3_cal = cur_cal;

            cur_cal = 0;
            continue;
        }

        cur_cal += stoi(cal);
    }

    cout << max1_cal + max2_cal + max3_cal;

    return 0;
}