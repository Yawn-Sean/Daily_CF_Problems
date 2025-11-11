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
    int n;
    cin >> n;
    vector<int> minn(2, 1e9), maxn(2, 0);
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        if (i < n / 2) {
            minn[0] = min(minn[0], p[i]);
            maxn[0] = max(maxn[0], p[i]);
        }
        else {
            minn[1] = min(minn[1], p[i]);
            maxn[1] = max(maxn[1], p[i]);
        }
    }

    if (maxn[0] < minn[1] || minn[0] > maxn[1]) {
        cout << 1 << endl;
        cout << n << " " ;
        for (int i = 0; i < n; i++) {
            cout << p[i] << " ";
        }
        cout << endl;
        return;
    }

    cout << 2 << endl;
    vector<int> vis(n + 1, 0);
    deque<int> num;
    for (int i = 0; i < n; i++) {
        if (i < n / 2 && p[i] > n / 2) {
            num.push_back(p[i]);
            vis[p[i]] = 1;
        }
        if (i >= n / 2 && p[i] <= n / 2) {
            num.push_back(p[i]);
            vis[p[i]] = 1;
        }
    }

    cout << num.size() << " ";
    for (int x : num) {
        cout << x << " ";
    }
    cout << endl;
    cout << n - num.size() << " ";
    for (int i = 0; i < n; i++) {
        if (vis[p[i]]) continue;
        cout << p[i] << ' ';
    }
    cout << endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
