/**
 * Created by 5cm/s on 2024/03/26 14:05:16.
 * 诸天神佛，佑我上分！
 **/
#include <bits/stdc++.h>
using namespace std;

#define itr(it) begin(it), end(it)
#define endl '\n'
#define YES() void(cout << "YES\n")
#define NO() void(cout << "NO\n")

void elysia() {
    int n;
    cin >> n;
    vector<pair<char, int>> ops(n * 2);
    vector<int> stk;
    for (int i: views::iota(0, n * 2)) {
        auto &[op, x] = ops[i];
        cin >> op;
        if (op == '+') {
            stk.emplace_back(i);
        } else {
            cin >> x;
            if (stk.empty()) return NO();
            ops[stk.back()].second = x;
            stk.pop_back();
        }
    }
    multiset<int> S;
    for (auto &[op, x]: ops) {
        if (op == '+') {
            S.insert(x);
        } else {
            if (*S.begin() != x) return NO();
            S.erase(S.begin());
        }
    }
    YES();
    for (auto &[op, x]: ops) {
        if (op == '+') {
            cout << x << ' ';
        }
    }
    cout << endl;
}

int main() {
#ifdef MEGURINE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
    clock_t start = clock();
#endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T = 1;
//    cin >> T;
    cout << fixed << setprecision(12);
    while (T--) elysia();
#ifdef MEGURINE
    cout << "\nRunning Time: " << double(clock() - start) / CLOCKS_PER_SEC * 1000 << "ms" << endl;
#endif
    return 0;
}
