#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    /*
        长度为n的数组 切成k part
        其中正好有p格part 偶数和
        k-p part是奇数和

        tot_sum
        前缀和是 偶数 切掉一部分 tot_sum 奇偶性不变

    */
    int n, k, p;
    cin >> n >> k >> p;
    
    vector<int> odds, evens;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x & 1) {
            odds.emplace_back(x);
        } else {
            evens.emplace_back(x);
        }
    }

    int odd_cnt = k - p;
    int l1 = odds.size(), l2 = evens.size();
    if (l1 < odd_cnt || (l1 - odd_cnt) % 2 != 0 || ((l1 - odd_cnt) / 2 + l2 < p) ) {
        cout << "NO\n";
        return 0;
    }

    vector<vector<int>> odds_res(odd_cnt), even_res(p);
    for (int i = 0; i < odd_cnt; i++) {
        odds_res[i].emplace_back(odds.back());
        odds.pop_back();
    }
    for (int i = 0; i < p; i++) {
        if (!evens.empty()) {
            even_res[i].emplace_back(evens.back());
            evens.pop_back();
        } else {
            even_res[i].emplace_back(odds.back());
            odds.pop_back();
            even_res[i].emplace_back(odds.back());
            odds.pop_back();
        }
    }
    
    if (p > 0) {
        for (auto& v: odds) { 
            even_res[0].emplace_back(v);
        }
        for (auto& v: evens) {
            even_res[0].emplace_back(v);
        }
    } else {
        for (auto& v: odds) { 
            odds_res[0].emplace_back(v);
        }
        for (auto& v: evens) {
            odds_res[0].emplace_back(v);
        }
    }


    cout << "YES\n";
    for (int i = 0; i < odd_cnt; i++) {
        cout << odds_res[i].size() << ' ';
        for (auto& v: odds_res[i]) {
            cout << v << ' ';
        }
        cout << '\n';
    }
    for (int i = 0; i < p; i++) {
        cout << even_res[i].size() << ' ';
        for (auto& v: even_res[i]) {
            cout << v << ' ';
        }
        cout << '\n';
    }

    return 0;
}
