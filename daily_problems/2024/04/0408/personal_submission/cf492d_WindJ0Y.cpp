#include <bits/stdc++.h>
using namespace std;

void work() {
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> ans;

    int lfx = y, lfy = x;
    for (;;) {
        int m = min(lfx, lfy);
        lfx -= m;
        lfy -= m;
        if (lfx == 0 && lfy == 0) {
            ans.push_back(2);
            ans.push_back(2);
            break;
        } else if (lfx == 0) {
            ans.push_back(0);
            lfx += y;
        } else if (lfy == 0) {
            ans.push_back(1);
            lfy += x;
        }
    }

    for (int i = 0; i < n; i++) {
        int v;
        cin >> v;
        v--;
        int c_ans = ans[v % ans.size()];
        if (c_ans == 2) {
            cout << "Both\n";
        } else if (c_ans == 0) {
            cout << "Vanya\n";
        } else if (c_ans == 1) {
            cout << "Vova\n";
        }
    }
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