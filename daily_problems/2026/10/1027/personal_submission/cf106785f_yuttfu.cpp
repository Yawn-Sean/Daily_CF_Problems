#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n,m;
    cin >> n >> m;
    int ans = 0;
    ans += abs(m-n);
    vector<int> a(n+1,0);
    vector<int> b(m+1,0);
    int x;
    for(int i = 1;i <= n;i++){
        cin >> x;
        a[x] = i; 
    }
    for(int i = 1;i <= m;i++) cin >> b[i];
    auto check = [&](int k) -> bool{
        int last = 0;
        for(int i = 1;i <= m;i++){
            if(b[i] > k) continue;
            int pos = a[b[i]];
            if(pos <= last) return false;
            last = pos;
        }
        return true;
    };
    int nn = min(n,m);
    int l = 0,r = nn+1;
    while(l + 1 < r){
        int mid = l + r >> 1;
        if(check(mid)) l = mid;
        else r = mid;
    }
    ans += 2*(nn-l);
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    cin >> T;
    while(T --){
        solve();
    }
    return 0;
}
