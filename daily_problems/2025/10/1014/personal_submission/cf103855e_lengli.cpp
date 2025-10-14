#include <bits/stdc++.h>
using namespace std;

struct BubbleRockPaper {
    int n, t;
    string s;

    void solve_segment(int l, int r) {
        unordered_map<char, vector<int>> pos;
        for (int i = l; i < r; ++i)
            pos[s[i]].push_back(i);

        auto fill_all = [&](char c) {
            for (int i = l; i < r; ++i) s[i] = c;
        };

        // Case 1: only R/S present
        if (!pos.count('P')) {
            fill_all('R');
            int cur = l - 1;
            for (int p : pos['S']) {
                cur = max(cur + 1, p - t);
                s[cur] = 'S';
            }
        }
        // Case 2: only S/P present
        else if (!pos.count('R')) {
            fill_all('S');
            int cur = l - 1;
            for (int p : pos['P']) {
                cur = max(cur + 1, p - t);
                s[cur] = 'P';
            }
        }
        // Case 3: only R/P present
        else {
            fill_all('P');
            int cur = l - 1;
            for (int p : pos['R']) {
                cur = max(cur + 1, p - t);
                s[cur] = 'R';
            }
        }
    }

    void run() {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        cin >> n >> t >> s;

        set<char> kinds;
        int seg_start = 0;

        for (int i = 0; i < n; ++i) {
            kinds.insert(s[i]);
            if (kinds.size() == 3) {
                solve_segment(seg_start, i);
                seg_start = i;
                kinds = {s[i]};
            }
        }
        solve_segment(seg_start, n);

        cout << s << '\n';
    }
};

int main() {
    BubbleRockPaper().run();
    return 0;
}
