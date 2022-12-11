#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    char dir;
    int num;
    vector<pair<int, int>> tail_coords;
    vector<pair<int, int>> cur_coords(10, {0, 0});

    tail_coords.push_back({0, 0});

    while (cin >> dir >> num) {
        while (num--) {
            if (dir == 'L')
                --cur_coords[0].first;
            else if (dir == 'R')
                ++cur_coords[0].first;
            else if (dir == 'U')
                ++cur_coords[0].second;
            else if (dir == 'D')
                --cur_coords[0].second;

            for (int i = 1; i < 10; ++i) {
                if (abs(cur_coords[i - 1].first - cur_coords[i].first) == 2 || abs(cur_coords[i - 1].second - cur_coords[i].second) == 2) {
                    if (cur_coords[i - 1].first == cur_coords[i].first) {
                        if (cur_coords[i - 1].second > cur_coords[i].second)
                            ++cur_coords[i].second;
                        else
                            --cur_coords[i].second;
                    } else if (cur_coords[i - 1].second == cur_coords[i].second) {
                        if (cur_coords[i - 1].first > cur_coords[i].first)
                            ++cur_coords[i].first;
                        else
                            --cur_coords[i].first;
                    } else {
                        if (cur_coords[i - 1].first > cur_coords[i].first && cur_coords[i - 1].second > cur_coords[i].second) {
                            ++cur_coords[i].first;
                            ++cur_coords[i].second;
                        } else if (cur_coords[i - 1].first < cur_coords[i].first && cur_coords[i - 1].second > cur_coords[i].second) {
                            --cur_coords[i].first;
                            ++cur_coords[i].second;
                        } else if (cur_coords[i - 1].first < cur_coords[i].first && cur_coords[i - 1].second < cur_coords[i].second) {
                            --cur_coords[i].first;
                            --cur_coords[i].second;
                        } else {
                            ++cur_coords[i].first;
                            --cur_coords[i].second;
                        }
                    }

                    if (i == 9 && find(tail_coords.begin(), tail_coords.end(), make_pair(cur_coords[9].first, cur_coords[9].second)) == tail_coords.end())
                        tail_coords.push_back({cur_coords[9].first, cur_coords[9].second});
                }
            }
        }
    }

    cout << tail_coords.size();

    return 0;
}