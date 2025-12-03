#include<bits/stdc++.h>
// #pragma GCC optimize(2)
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,ll> pil;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
#define endl "\n"

void solve(){
    int n; cin >> n;
    vector<int> a(n), b(n), ag(2 * n), get(2 * n), cnt(5e5 + 5, 0), ans(2 * n);
    vector<pii> p(2 * n);
    vector<int> vis(2 * n, 0);
    for (int i = 0; i < 2 * n; i++) {
        auto& [x, y] = p[i];
        cin >> x;
        y = i;
        get[i] = x;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        ag[a[i]] = b[i];
        ag[b[i]] = a[i];
    }
    sort(p.begin(), p.end(), greater<>());
    for (int i = 0, k = 0, temp = 0, j = 0, k1 = 5e5; i < 2 * n; j = i) {
        while (i < 2 * n && p[i].first == p[j].first) {
            i++;
        }

        while (p[k].first > p[j].first + 3) {
            if (!vis[p[k].second]) temp++;
            k++;
        }
        while (k1 > p[j].first + 3) {
            temp += cnt[k1];
            k1--;
        }
        
        for (int o = j; o < i; o++) {
            ans[p[o].second] = temp;
        }
        for (int o = j; o < i; o++) {
            if (!vis[p[o].second] && get[ag[p[o].second]] <= p[j].first + 3 && get[ag[p[o].second]] >= p[o].first) {
                vis[ag[p[o].second]] = 1;
                if (get[ag[p[o].second]] + 1 > p[j].first + 3) {
                    temp++;
                }
                else {
                    cnt[get[ag[p[o].second]] + 1]++;
                }
            }
        }
    }
    for (int x : ans) {
        cout << x + 1 << " ";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
