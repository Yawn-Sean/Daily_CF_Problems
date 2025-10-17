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
int n,ans,len;
int i,j;
set<int>num;
map<char,int>mp;
void dfs(int step, int x){
    if(x!=0) num.insert(x);
    if(step==len+1) return ;
    if(i!=0 or x!=0)dfs(step+1,x*10+i);
    if(j!=0 or (x!=0))dfs(step+1,x*10+j);
    return ; 
}
void slove(){
	cin>>n;
    string s=to_string(n);
     len=s.length();
    int cnt=0;
    for(auto u:s){
        if(mp[u]==0){
            cnt++;mp[u]=1;
        }
    }
    if(len==10) len--;
    for(i=0;i<=9;i++){
        for( j=0;j<=9;j++){
            if(i==0 && j==0) continue;
            dfs(1,0);
        }
    }
    for(auto u:num){
        if(u*2==n) {
            ans++;
            break;
        }
        if(u*2>n) break;
        int diff=n-u;
        auto pos=num.lower_bound(diff);
        if(*pos==diff) ans++;
    }
    if(cnt<=2) ans++;
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