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

    const int N = 8;

    vector<queue<int64_t>> inspect_queue(N);
    vector<string> op(N);
    vector<string> operand(N);
    vector<int> div_by(N);
    vector<int> throw_if_true(N);
    vector<int> throw_if_false(N);
    vector<int64_t> inspect_count(N, 0);

    string line;
    int cur_monkey = 0;
    int modulo = 1;

    while (getline(cin, line)) {
        vector<string> parsed = split(line, ' ');

        if (parsed.size() == 0) {
            ++cur_monkey;
            continue;
        }

        if (parsed[0] == "Monkey")
            continue;
        else if (parsed[0] == "Starting") {
            for (int i = 2; i < parsed.size(); ++i) {
                if (i < parsed.size() - 1) {
                    parsed[i].pop_back();
                    inspect_queue[cur_monkey].push(stoi(parsed[i]));
                } else
                    inspect_queue[cur_monkey].push(stoi(parsed[i]));
            }
        } else if (parsed[0] == "Operation:") {
            op[cur_monkey] = parsed[4];
            operand[cur_monkey] = parsed[5];
        } else if (parsed[0] == "Test:") {
            div_by[cur_monkey] = stoi(parsed[3]);
            modulo *= div_by[cur_monkey];
        } else if (parsed[1] == "true:")
            throw_if_true[cur_monkey] = stoi(parsed[5]);
        else if (parsed[1] == "false:")
            throw_if_false[cur_monkey] = stoi(parsed[5]);
    }

    int round = 0;
    int64_t old_worry, new_worry;

    while (round++ < 10000) {
        for (int monkey = 0; monkey < N; ++monkey) {
            while (!inspect_queue[monkey].empty()) {
                old_worry = inspect_queue[monkey].front();
                inspect_queue[monkey].pop();

                if (operand[monkey] == "old")
                    new_worry = old_worry * old_worry;
                else {
                    if (op[monkey] == "+")
                        new_worry = old_worry + stoi(operand[monkey]);
                    else if (op[monkey] == "*")
                        new_worry = old_worry * stoi(operand[monkey]);
                }

                if (new_worry % div_by[monkey] == 0)
                    inspect_queue[throw_if_true[monkey]].push(new_worry % modulo);
                else
                    inspect_queue[throw_if_false[monkey]].push(new_worry % modulo);

                ++inspect_count[monkey];
            }
        }
    }

    sort(inspect_count.begin(), inspect_count.end());
    cout << inspect_count[N - 2] * inspect_count[N - 1];

    return 0;
}