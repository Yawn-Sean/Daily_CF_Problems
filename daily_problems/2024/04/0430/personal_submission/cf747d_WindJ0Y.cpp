#include <bits/stdc++.h>
using namespace std;

void work() {
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int& x : a) {
        cin >> x;
        x = (x >= 0 ? 1 : -1);
    }

    int opcnt = 0;
    vector<pair<int, int>> gaps;

    for (int i = 0; i < n; i ++) {
        int curv = a[i];
        int prev = (i ? a[i - 1]: 1);
        bool need_flip = (prev * a[i] < 0);

        if (a[i] < 0) {
            k --;
        }
        if (need_flip) {
            opcnt ++;
        } 
        if (curv > 0) {
            if (prev < 0) {
                gaps.push_back({1, ((i == n - 1) ? -1: -2)});
            } else {
                if (!gaps.empty()) {
                    gaps.back().first ++;
                    if (i == n - 1) {
                        gaps.back().second = -1;
                    }
                }
            }
        }
    }
    
    sort(gaps.begin(), gaps.end());

    auto gans = [&gaps, k, opcnt](bool skip){
        int tmp_k = k, tmp_opcnt = opcnt;
        for (auto [elm, v] : gaps) {
            if (v == -1 && skip) {continue;}
            if (elm <= tmp_k) {
                tmp_k -= elm;
                tmp_opcnt += v;
            }
        }
        return tmp_k >= 0 ? tmp_opcnt : 1e9;
    };

    int ans = min(gans(false), gans(true));
    if (ans == 1e9) ans = -1;
    cout << ans << endl;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T {1};
    // cin >> T;

    while (T--) {
        work();
    }
}