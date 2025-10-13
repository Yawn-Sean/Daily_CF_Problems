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
const int maxn=6e5;
const ll INF=1e17;
using namespace std;
int n;
ll ans=1ll;
int a[maxn];
int pre_max[maxn];
void slove(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        pre_max[i]=pre_max[i-1];
        if(a[pre_max[i]]<=a[i]) pre_max[i]=i;
    }
    int pos=pre_max[n];
    while(1){
        //cout<<pos<<endl;
        int nex_pos=pre_max[pos-1];
        if(pos==1) break;
        ans=ans*(pos-nex_pos+1);
        pos=nex_pos;
        ans%=mod;
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