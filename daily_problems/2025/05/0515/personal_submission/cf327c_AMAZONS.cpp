#include<bits/stdc++.h>
using namespace std;
const int N =2e5 + 10;
const int mod=1e9+7;
typedef long long ll;
//555555
ll ksm(ll a,ll b){
    ll cur=1,ans=1;
    while(b)
    {
        if(b&1)ans=(ans*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return ans;
}
ll modInverse(ll a) {
    return ksm(a, mod - 2);
}
void solve(){
	string s;cin>>s;ll k;cin>>k;
    ll ans=0,cnt=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='0'||s[i]=='5'){
            cnt=i;
            ans=(ans+ksm(2,cnt)%mod)%mod;
            // cout<<cnt<<endl;
        }
        
    }
    cout<<ans*(ksm(2,k*(ll)s.size())-1ll)%mod*ksm(ksm(2,s.size())-1,mod-2)%mod;
}
int main(){
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {solve();}
    return 0;
}
