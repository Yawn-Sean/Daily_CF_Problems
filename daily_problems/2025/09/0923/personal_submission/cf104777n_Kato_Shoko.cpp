#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 2e5 + 5, mod =1e9+7, inf = 2e18;
const double esp=1e-9;
double PI=3.1415926;

int tot=1,n,son[N*25][2],en[N*25];//e[i]表示第i个节点有多少个数经过
void insert(ll x){
   int o=1;//从1号点进入
   en[o]++;//o号点的经过的数的个数+1
   for(int i=30;i>=0;i--){
      int y=x>>i&1;//取出x的第i位
      if(!son[o][y]){
         son[o][y]=++tot;
      }
      o=son[o][y];
      en[o]++;//经过+1
   }
}
ll query(ll x){
   ll o=1,res=0;
   //判断x与字典树中的元素异或的最大值
   for(int i=30;i>=0;i--){
      int y=x>>i&1;
      //贪心的走，如果y==1,就走0，y==0就走1
      if(son[o][!y]){
         res|=(1<<i);//第i位对res的贡献加上去
         o=son[o][!y];
      }else{
         o=son[o][y];
      }
      if(o==0)break;
   }
   return res;
}

void remove(ll x){
   //撤销树中的x
   //无法修改边，那么就直接修改权值，若e[i]==0,说明这条边不存在了
   int o=1;
   en[o]--;
   for(int i=30;i>=0;i--){
      int y=x>>i&1;//取x的第i位
      if(!son[o][y])son[o][y]=++tot;
      o=son[o][y];
      en[o]--;//将这个数的所有经过的点的权值-1
   }
}

il void solve(){
    int n;
    cin>>n;
    vector<ll>a(n-1);
    for(auto &i:a)cin>>i;
    vector<ll>p(n);
    for(int i=1;i<n;i++){
        p[i]=p[i-1]^a[i-1];
    }
    ll maxp=*max_element(p.begin(),p.end());
    for(auto v:p)insert(v);

    ll find=0;
    for(int x=0;x<n;x++){
        ll mx=query(x);
        if(mx==n-1){
            find=x;
            break;
        }
    }
    for(int i=0;i<n;i++){
        ll b=p[i]^find;
        cout<<b<<" ";
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t = 1;

    //cin >> t;

    while (t--) {

        solve();

    }

    return 0;
}
