#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    while (cin>>n && n) {
        vector<pair<int,int>> items(n);
        int S = 0;
        for (auto&[a,b] : items) {
            cin>>a>>b;
            S+=b;
        }
        int m=max(1, n - S);
        sort(items.begin(), items.end());
        long long ans = 0;
        int chosen = -1;
        for (int i =0; i < n; ++i) {
            if (items[i].second > 0) {
                chosen=i;
                ans+=items[i].first;
                --m;
                break;
            }
        }
        for (int i = 0; i < n && m > 0; ++i) {
            if (i==chosen) continue;
            ans += items[i].first;
            --m;
        }
        cout << ans<<endl;
    }
}