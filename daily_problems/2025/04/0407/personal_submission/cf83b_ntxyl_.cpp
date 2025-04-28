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
    int n,k;
    cin>>n>>k;
    int sum=0;
    vector<int>a(n+1);
    for(int i=1;i<=n;i++) cin>>a[i],sum+=a[i];
    if(sum<k){
        cout<<-1<<endl;
        return;
    }

    int l=0,r=1e9;
    auto check=[&](int x)->bool{
        int ans=0;
        for(int i=1;i<=n;i++){
            if(a[i]<=x) ans+=a[i];
            else ans+=x;
        }
        // if(x==3) cout<<ans<<endl;
        return ans<=k;
    };
    while(l<r){
        int mid=l+r+1>>1;
        if(check(mid)) l=mid;
        else r=mid-1;
    }
    // cout<<l<<endl;
    int res=0;
    for(int i=1;i<=n;i++){
        res+=min(a[i],l);
        a[i]=max(0ll,a[i]-l);
    }
    // cout<<res<<endl;
    vector<int>ans;
    int t=n+1;
    for(int i=1;i<=n;i++){
        if(res==k){
            if(a[i]) ans.push_back(i),t=min(t,i);
        }
        else{
            if(a[i]) res++,a[i]--;
        }
    }
    for(int i=1;i<t;i++) if(a[i]) ans.push_back(i);
    for(auto x:ans) cout<<x<<' ';
}
signed main() {
    fastio;
    int T;
 T = 1;
    // cin>>T;
    while (T--) solve();

    return 0;
}
