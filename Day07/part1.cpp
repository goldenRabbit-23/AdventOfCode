#include <bits/stdc++.h>
using namespace std;

vector<string> split(const string &s, char delim) {
    vector<string> result;
    stringstream ss(s);
    string item;

    while (getline(ss, item, delim))
        result.push_back(item);

    return result;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    map<string, int> dir_no;
    map<string, string> parent;
    vector<int> dir_sizes;

    string line;
    string cur_dir;
    int cur_no = 0;

    while (getline(cin, line)) {
        vector<string> parsed = split(line, ' ');

        if (parsed[0] == "$") {
            if (parsed[1] == "cd") {
                if (parsed[2] == "/") {
                    cur_dir = "/";
                    dir_no["/"] = cur_no++;
                    parent["/"] = "#";
                    dir_sizes.push_back(0);
                } else if (parsed[2] == "..")
                    cur_dir = parent[cur_dir];
                else
                    cur_dir = cur_dir + parsed[2] + "/";
            }
        } else {
            if (parsed[0] == "dir") {
                dir_no[cur_dir + parsed[1] + "/"] = cur_no++;
                parent[cur_dir + parsed[1] + "/"] = cur_dir;
                dir_sizes.push_back(0);
            } else {
                int file_size = stoi(parsed[0]);
                string dir = cur_dir;
                while (dir != "#") {
                    dir_sizes[dir_no[dir]] += file_size;
                    dir = parent[dir];
                }
            }
        }
    }

    int ans = 0;

    for (int size : dir_sizes) {
        if (size <= 100000)
            ans += size;
    }

    cout << ans;

    return 0;
}