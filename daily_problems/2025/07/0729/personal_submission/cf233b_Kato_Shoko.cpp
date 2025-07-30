#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 2e5 + 5, mod = 998244353, inf = 1e18;
const double esp=1e-3;
double PI=3.1415926;

il void solve(){
    string s,t;
    cin>>s>>t;
    int n=s.size(),m=t.size();

    vector<int>L(n+5),R(n+5);//最多前/后缀能放几个
    for(int i=0,k=0;i<n;i++){
        if(k<m&&s[i]==t[k]){
            k++;
        }
        L[i+1]=k;
    }
    if(L[n]<m){
        cout<<"No";
        return ;
    }

    for(int i=n-1,k=0;i>=0;i--){
        if(k<m&&s[i]==t[m-k-1]){
            k++;
        }
        R[i+1]=k;
    }
    vector<vector<int>>pos(26);
    for(int i=0;i<m;i++){
        pos[t[i]-'a'].push_back(i+1);
    }
    for(int i=1;i<=n;i++){
        int ch=s[i-1]-'a';
        //可行区间
        int l=max(1,m-R[i+1]),r=min(m,L[i-1]+1);
        if(l>r){
            cout<<"No";
            return ;
        }
        auto v=pos[ch];
        auto it=lower_bound(v.begin(),v.end(),l);
        if(it==v.end()||*it>r){
            cout<<"No";
            return ;
        }
    }
    cout<<"Yes";
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
