// LUOGU_RID: 168194766
#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define mem(a) memset(a,0, sizeof(a))
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,r,l) for(int i=r;i>=l;i--)
int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}
void solve(){
    int n;cin>>n;
    vector<int>a(n);
    int g=0;
    for(auto &x:a) cin>>x,g=gcd(x,g);
    int ans=0;
    if(g==1){
        rep(i,0,n-1){
            if(a[i]&1){
                a[i]=2;
                if((i==n-1&&a[i-1]%2==0)||(i==0&&a[i+1]%2==0)){
                    ans+=2;
                }
                else if(i>0&&i<n-1&&a[i-1]%2+a[i+1]%2==0) ans+=2;
                else{
                    a[i+1]=2;
                    ans++;
                }
            }   
        }        
    }
    cout<<"YES\n"<<ans<<"\n";
}
signed main()
{
    solve();
    return 0;
}
