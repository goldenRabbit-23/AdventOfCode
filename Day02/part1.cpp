#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    char opp, you;
    int score = 0;

    while (1) {
        cin >> opp >> you;

        if (opp == 'Q')
            break;

        if (opp == 'A') {
            if (you == 'X')
                score += 1 + 3;
            else if (you == 'Y')
                score += 2 + 6;
            else
                score += 3 + 0;
        } else if (opp == 'B') {
            if (you == 'X')
                score += 1 + 0;
            else if (you == 'Y')
                score += 2 + 3;
            else
                score += 3 + 6;
        } else {
            if (you == 'X')
                score += 1 + 6;
            else if (you == 'Y')
                score += 2 + 0;
            else
                score += 3 + 3;
        }
    }

    cout << score;

    return 0;
}