#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while(t--){
        int n, m;
        cin >> n >> m;

        vector<int> cnt(m, 0);

        for(int _ = 0; _ < n; ++_) {
            string s;
            cin >> s;

            if(s[m - 1] == '1') {
                cnt[m - 1] += 1;
            }

            for(int i = 0; i < m - 1; ++i) {
                if(s[i] != s[i + 1]) {
                    cnt[i] += 1;
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < m; ++i) {
            ans += min(cnt[i], n - cnt[i]);
        }

        cout << ans << "\n";
    }

    return 0;
}
