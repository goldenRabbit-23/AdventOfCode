#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    char dir;
    int num;
    vector<pair<int, int>> coords;

    int headX = 0, headY = 0;
    int tailX = 0, tailY = 0;
    int prev_headX, prev_headY;

    coords.push_back({0, 0});

    while (cin >> dir >> num) {
        while (num--) {
            prev_headX = headX;
            prev_headY = headY;

            if (dir == 'L')
                --headX;
            else if (dir == 'R')
                ++headX;
            else if (dir == 'U')
                ++headY;
            else if (dir == 'D')
                --headY;

            if (abs(headX - tailX) == 2 || abs(headY - tailY) == 2) {
                tailX = prev_headX;
                tailY = prev_headY;
                if (find(coords.begin(), coords.end(), make_pair(tailX, tailY)) == coords.end())
                    coords.push_back({tailX, tailY});
            }
        }
    }

    cout << coords.size();

    return 0;
}