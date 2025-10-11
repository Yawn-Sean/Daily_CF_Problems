// ！！！！！！！！！！！！！！！！！！！！！！！！！！！计算几何不要使用abs 使用fabs！！！！！！
// inv[i]=(p-p/i)*inv[p%i]%p; 正推 线性求出1-n的逆元
// 先求出阶乘fac 快速幂算出fac[n]的阶乘 线性倒推fac[n-1-1]的逆元 invfac[i-1]=invfac[i]*i 
//单个数的逆元是 inv[i]=fact[i-1]*invfact[i]
#include <bits/stdc++.h>
typedef long long ll;
typedef long double db;
const ll mod=1e9+7;
const db pi=acos(-1);
const db eps=1e-10;
const int maxn=3e5;
const ll INF=1e17;
using namespace std;
int n,l,r;
void slove(){
    cin>>n>>l>>r;
	vector<ll>val(n+1);
    ll sum=0ll;
    for(int i=1;i<=n;i++){
        cin>>val[i];
        sum+=val[i];
    }
    int lef=l-1;
    int rig=n-r;
    int cnt=min(lef,rig);
    vector<ll>real;
    for(int i=n-cnt;i>=1;i--){
        real.push_back(val[i]);
    }
    ll ans=0ll;
    sort(real.begin(),real.end(),greater<ll>());
    for(int i=0;i<r-l+1;i++){
        ans+=real[i];
    }
    cout<<ans;
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
		slove();
    }
    return (0-0);
}