#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,r,l) for(int i=r;i>=l;i--)
void solve(){
    int n;cin>>n;
    string s;cin>>s;
    int q;cin>>q;
    while(q--){
        int m;char c;
        cin>>m>>c;
        int j=-1,cnt=0,ans=0;
        rep(i,0,n-1){
            while(j<=n-1&&cnt<=m){
                if(s[j+1]!=c) cnt++;
                j++;
            }
            if(s[i]!=c) cnt--;
            ans=max(ans,j-i);
        }
        cout<<ans<<endl;
    }
}
signed main()
{
std::ios::sync_with_stdio(false);
cin.tie(0);
cout.tie(0);
    solve();
    return 0;
}
