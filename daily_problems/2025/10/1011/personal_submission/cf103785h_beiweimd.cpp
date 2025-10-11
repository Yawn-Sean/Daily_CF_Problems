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
int n;
void slove(){
    cin>>n;
    vector<int > val(n+1,0);
    vector<int > used(n+1,0);
    vector<int > suf(n+1,0);
    vector<int > tmp(n+1,0);
    for(int i=1;i<=n;i++){
        cin>>val[i];
    }
    vector<int>ans;
    for(int cnt=1;cnt<=n;cnt++){
        for(int i=1;i<=n;i++){
            tmp[i]=tmp[i-1]+suf[i];
        }
        int mx=0;
        int target=0;
        for(int i=n;i>=1;i--){
            int pos=i-tmp[i];
            if(used[i]) continue;
            if(pos==val[i] && mx<pos){
                mx=pos;
                target=i;
            }
        }
        if(target==0){
            cout<<"NO";return ;
        }
        else{
            used[target]=1;
            suf[target]++;
            ans.push_back(val[target]);
        }
    }
    reverse(ans.begin(), ans.end());
    cout<<"YES"<<"\n";
    for(auto u:ans) cout<<u<<" ";
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