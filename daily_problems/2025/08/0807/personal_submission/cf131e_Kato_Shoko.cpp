#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 1e5 + 5, mod = 1e9+7, inf = 2e18;
const double esp=1e-3;
double PI=3.1415926;

vector<int>gx[N];
vector<int>gy[N];

il void solve(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>>pa(m+1);
    int maxx=0,maxy=0;
    map<int,set<int>>diff,add;
    for(int i=1;i<=m;i++){
        auto &[x,y]=pa[i];
        cin>>x>>y;
        gx[x].push_back(y);
        gy[y].push_back(x);
        diff[x-y].insert(x);
        add[x+y].insert(x);
        maxx=max(maxx,x);
        maxy=max(maxy,y);
    }

    vector<int>ans(9);
    for(int i=1;i<=maxx;i++){
        sort(gx[i].begin(),gx[i].end());
    }
    for(int i=1;i<=maxy;i++){
        sort(gy[i].begin(),gy[i].end());
    }

    for(int i=1;i<=m;i++){
        int res=0;
        auto [x,y]=pa[i];
        //上
        {
            auto it=lower_bound(gy[y].begin(),gy[y].end(),x);
            if(it!=gy[y].begin())res++;
        }
        //下
        {
            auto it=upper_bound(gy[y].begin(),gy[y].end(),x);
            if(it!=gy[y].end())res++;
        }
        //左
        {
            auto it=lower_bound(gx[x].begin(),gx[x].end(),y);
            if(it!=gx[x].begin())res++;
        }
        //右
        {
            auto it=upper_bound(gx[x].begin(),gx[x].end(),y);
            if(it!=gx[x].end())res++;
        }
        //右上
        {
            auto it=add[x+y].lower_bound(x);
            if(it!=add[x+y].begin())res++;
        }
        //左下
        {
            auto it=add[x+y].upper_bound(x);
            if(it!=add[x+y].end())res++;
        }
        //左上
        {
            auto it=diff[x-y].lower_bound(x);
            if(it!=diff[x-y].begin())res++;
        }
        //右下
        {
            auto it=diff[x-y].upper_bound(x);
            if(it!=diff[x-y].end())res++;   
        }
        ans[res]++;
    }
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
