#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int left1, right1, left2, right2;
    int ans = 0;

    while (cin >> left1 >> right1 >> left2 >> right2) {
        if (!(right1 < left2 || left1 > right2))
            ++ans;
    }

    cout << ans;

    return 0;
}