#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 3e5 + 5, mod = 998244353, inf = 1e18;
const double esp=1e-3;
double PI=3.1415926;

il void solve(){
    int n,m;
    cin>>n>>m;
    vector<pair<char,int>>pa(m+1);
    for(int i=1;i<=m;i++){
        auto &[x,y]=pa[i];
        cin>>x>>y;
    }
    vector<bool>vis(n+1);
    vector<char>ops(n+1,0);//第一次出现的信息
    vector<ll>pos(n+1,inf);

    for(int i=1;i<=m;i++){
        auto [op,id]=pa[i];
        if(!vis[id]){
            vis[id]=true;
            ops[id]=op;
            pos[id]=i;
        }
    }
    vector<int>ans;
    for(int i=1;i<=n;i++){
        if(!vis[i])ans.push_back(i);
    }
    int last=-1;
    for(int i=1;i<=n;i++){
        if(vis[i]&&ops[i]=='-'){
            if(last==-1||pos[i]>pos[last]){
                last=i;
            }
        }
    }

    if(last==-1){//没有提前登录的
        for(int i=1;i<=m;i++){
            if(pa[i].first=='+'){
                last=pa[i].second;
                break;
            }
        }
    }

    if(last!=-1){
        bool ok=true;
        set<int>st;
        for(int i=1;i<=n;i++){
            if(vis[i]&&ops[i]=='-')st.insert(i);
        }
        for(int i=1;i<=m;i++){
            auto [op,id]=pa[i];
            if(op=='+'){
                st.insert(id);
            }else{
                st.erase(id);
            }
            if(!st.empty()&&!st.count(last)){
                ok=false;
                break;
            }
        }
        if(ok)ans.push_back(last);
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<'\n';
    for(auto v:ans)cout<<v<<" ";
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
