#include <bits/stdc++.h>
using namespace std;

void work() {
    int n; cin >> n;
    vector<pair<int, int>> line(n);

    int mxs = 0, mxs2 = 0;
    int mie = 1e9, mie2 = 1e9;

    for (int i = 0; i < n; i++) {
        cin >> line[i].first >> line[i].second;
        if (line[i].first >= mxs) {
            mxs2 = mxs;
            mxs = line[i].first;
        } else if (line[i].first > mxs2) {
            mxs2 = line[i].first;
        }
        if (line[i].second <= mie) {
            mie2 = mie;
            mie = line[i].second;
        } else if (line[i].second < mie2) {
            mie2 = line[i].second;
        }
    }

    int ans = max(0, mie - mxs);
    for (auto [i, j] : line) {
        int ts = ( mxs == i ) ? mxs2 : mxs;
        int te = ( mie == j ) ? mie2 : mie;
        ans = max(ans, te - ts);
    }

    cout << ans << "\n";
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