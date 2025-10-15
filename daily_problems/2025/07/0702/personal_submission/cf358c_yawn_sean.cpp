#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q;
    cin >> q;

    vector<int> cur;
    int v1 = 0, v2 = 0, v3 = 0;

    while (q --) {
        int x;
        cin >> x;

        if (x) {
            if (x > v1) {
                v3 = x;
                swap(v2, v3);
                swap(v1, v2);
            }
            else if (x > v2) {
                v3 = x;
                swap(v2, v3);
            }
            else if (x > v3)
                v3 = x;
            cur.emplace_back(x);
        }
        else {
            vector<string> tmp;

            for (auto &v: cur) {
                if (v == v1) {
                    cout << "pushStack\n";
                    tmp.emplace_back("popStack");
                    v1 = 0;
                }
                else if (v == v2) {
                    cout << "pushQueue\n";
                    tmp.emplace_back("popQueue");
                    v2 = 0;
                }
                else if (v == v3) {
                    cout << "pushFront\n";
                    tmp.emplace_back("popFront");
                    v3 = 0;
                }
                else cout << "pushBack\n";
            }
            cur.clear();

            if (tmp.size()) {
                cout << tmp.size();
                for (auto &x: tmp)
                    cout << ' ' << x;
            }
            else cout << 0;
            cout << '\n';
        }
    }

    for (auto &v: cur) cout << "pushStack\n";

    return 0;
}