#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;

    vector<int> prime_factor(n + 1);
    iota(prime_factor.begin(), prime_factor.end(), 0);

    for (int i = 2; i <= n; i ++) {
        if (prime_factor[i] == i) {
            for (int j = i; j <= n; j += i)
                prime_factor[j] = i;
        }
    }

    vector<char> status(n + 1, 0);
    vector<vector<int>> prime_note(n + 1);

    while (q --) {
        char c;
        int x;
        cin >> c >> x;

        if (c == '-') {
            if (status[x]) {
                status[x] = 0;
                cout << "Success";
            }
            else cout << "Already off";
        }
        else {
            if (status[x]) cout << "Already on";
            else {
                int v = x;
                vector<int> pr;

                while (v > 1) {
                    int p = prime_factor[v];
                    pr.emplace_back(p);
                    while (v % p == 0)
                        v /= p;
                }

                int conflict = -1;
                for (auto &p: pr) {
                    while (!prime_note[p].empty() && !status[prime_note[p].back()])
                        prime_note[p].pop_back();
                    if (!prime_note[p].empty()) conflict = prime_note[p].back();
                }

                if (conflict != -1) cout << "Conflict with " << conflict;
                else {
                    for (auto &p: pr) prime_note[p].emplace_back(x);
                    status[x] = 1;
                    cout << "Success";
                }
            }
        }

        cout << '\n';
    }

    return 0;
}
