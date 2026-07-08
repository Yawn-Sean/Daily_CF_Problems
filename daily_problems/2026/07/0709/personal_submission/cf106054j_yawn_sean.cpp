#include <bits/stdc++.h>
// #include "atcoder/all"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int t;
    cin >> t;

    vector<vector<int>> v1(t);
    vector<int> w1;

    for (int i = 0; i < t; i ++) {
        int k;
        cin >> k;
        while (k --) {
            int x;
            cin >> x;
            v1[i].emplace_back(x);
            w1.emplace_back(x);
        }
    }

    vector<vector<int>> v2(t);
    vector<int> w2;

    for (int i = 0; i < t; i ++) {
        int k;
        cin >> k;
        while (k --) {
            int x;
            cin >> x;
            v2[i].emplace_back(x);
            w2.emplace_back(x);
        }
    }

    auto equals = [&] (vector<int> &v1, vector<int> &v2) -> bool {
        int k1 = v1.size(), k2 = v2.size();
        if (k1 != k2) return false;

        for (int i = 0; i < k1; i ++) {
            if (v1[i] != v2[i]) {
                return false;
            }
        }

        return true;
    };

    sort(w1.begin(), w1.end());
    sort(w2.begin(), w2.end());

    if (!equals(w1, w2)) cout << 'N';
    else if (t == 1 || t >= 3) cout << 'S';
    else {
        while (!v1[1].empty() && (v1[0].empty() || v1[0].back() >= v1[1].back())) {
            auto v = v1[1].back();
            v1[1].pop_back();
            v1[0].emplace_back(v);
        }
        while (!v2[1].empty() && (v2[0].empty() || v2[0].back() >= v2[1].back())) {
            auto v = v2[1].back();
            v2[1].pop_back();
            v2[0].emplace_back(v);
        }

        if (equals(v1[0], v2[0])) cout << 'S';
        else cout << 'N';
    }

	return 0;
}