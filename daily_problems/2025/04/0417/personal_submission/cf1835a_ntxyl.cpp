#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define int long long
#define all(v) v.begin(), v.end()
//#define x first
//#define y second

using namespace std;
typedef pair<int, int> PII;

const int N = 1e5 + 10;

void solve() {
    int a,b,c,k;
    cin>>a>>b>>c>>k;
    if(a>c||b>c){
        cout<<-1<<endl;
        return;
    }
    auto f=[&](int x)->PII{
        int l=1,r=10;
        while(x>1) x--,l*=10,r*=10;
        return {l,r-1};
    };

    // cout<<f(5).first<<' '<<f(5).second<<endl;
    auto [la, ra] = f(a);
    auto [lb, rb] = f(b);
    auto [lc, rc] = f(c);
    for(int i=la;i<=ra;i++){
        int l=max(lb,lc-i),r=min(rb,rc-i);
        if(l<=r){
            int d=r-l+1;
            if(k<=d){
                int x=l+k-1;
                cout<<i<<" + "<<x<<" = "<<i+x<<endl;
                return;
            }
            else k-=d;
        }
    }
    cout<<-1<<endl;
}
signed main() {
    fastio;
    int T;
//  T = 1;
    cin>>T;
    while (T--) solve();

    return 0;
}
