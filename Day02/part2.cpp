#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    char opp, rule;
    int score = 0;

    while (1) {
        cin >> opp >> rule;

        if (opp == 'Q')
            break;

        if (opp == 'A') {
            if (rule == 'X')
                score += 3 + 0;
            else if (rule == 'Y')
                score += 1 + 3;
            else
                score += 2 + 6;
        } else if (opp == 'B') {
            if (rule == 'X')
                score += 1 + 0;
            else if (rule == 'Y')
                score += 2 + 3;
            else
                score += 3 + 6;
        } else {
            if (rule == 'X')
                score += 2 + 0;
            else if (rule == 'Y')
                score += 3 + 3;
            else
                score += 1 + 6;
        }
    }

    cout << score;

    return 0;
}