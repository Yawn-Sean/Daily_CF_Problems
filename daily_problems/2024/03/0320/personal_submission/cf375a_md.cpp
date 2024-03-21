#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    array<string, 7> precalc{""};
    auto calculate = [&](string val) {
        for (int i = 0; i <= 6; ++i) {
            if (!empty(precalc[i])) {
                continue;
            }
            int sum = stoi(val) + i * 1e4;
            if (sum % 7 == 0) {
                precalc[i] = val;
            }
        }
    };

    string trail = "1689";
    calculate(trail);
    while (next_permutation(trail.begin(), trail.end())) {
        calculate(trail);
    }

    string input;
    cin >> input;
    array<int, 10> freq{};
    for (char c : input) {
        ++freq[c - '0'];
    }

    for (char c : trail) {
        --freq[c - '0'];
    }

    int remain = 0;
    string ret{};
    for (int d = 1; d <= 9; ++d) {
        ret += string(freq[d], d + '0');
        for (int i = 0; i < freq[d]; ++i) {
            remain = remain * 10 + d;
            remain %= 7;
        }
    }

    ret += precalc[remain];
    ret += string(freq[0], '0');

    cout << ret << endl;
    return 0;
}