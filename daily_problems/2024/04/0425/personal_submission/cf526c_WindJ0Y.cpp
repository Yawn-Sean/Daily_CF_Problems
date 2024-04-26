#include <bits/stdc++.h>
using namespace std;

void work() {
    int C, Hr, Hb, Wr, Wb;
    cin >> C >> Hr >> Hb >> Wr >> Wb;

    int min_mx_count = min(C, static_cast<int>(sqrt(C) + 1));
    long long ans = 0;

    for (int acnt = 0; acnt <= min_mx_count && acnt * Wr <= C; acnt ++) {
        int bcnt = (C - acnt * Wr) / Wb;
        ans = max(ans, 1LL * acnt * Hr + 1LL * bcnt * Hb);
    }   
    for (int bcnt = 0; bcnt <= min_mx_count && bcnt * Wb <= C; bcnt ++) {
        int acnt = (C - bcnt * Wb) / Wr;
        ans = max(ans, 1LL * acnt * Hr + 1LL * bcnt * Hb);
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