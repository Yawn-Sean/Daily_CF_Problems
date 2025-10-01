#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 2e5 + 5, mod =1e9+7, inf = 2e18;
const double esp=1e-9;
double PI=3.1415926;

il auto query(int l,int r){
    cout<<"Q "<<l<<" "<<r<<endl;
    set<int>a;
    for(int i=1;i<=r-l+1;i++){
        int x;cin>>x;
        a.insert(x);
    }
    return a;
}

il void print(vector<int>&a){
    cout<<"A ";
    for(auto &i:a)cout<<i<<" ";
}

il void solve(){
    int n;
    cin>>n;
    
    vector<int>ans(n);
    set<int>to_fill;
    for(int i=1;i<=n;i++)to_fill.insert(i);

    int m=n;
    if(n&1){
        auto st=query(n,n);
        ans[n-1]=*st.begin();
        to_fill.erase(ans[n-1]);
        m--;
    }
    if(m==0){
        print(ans);
        return ;
    }

    int half=m>>1;
    auto L=query(1,half);
    set<int>l=L;
    set<int>r;
    for(auto i:to_fill){
        if(l.find(i)==l.end())r.insert(i);
    }

    for(int i=2;i<=half;i++){
        auto mid=query(i,m-i+1);

        int ansl=-1;
        for(auto v:l){
            if(mid.find(v)==mid.end()){
                ansl=v;
                break;
            }
        }
        if(ansl!=-1){
            l.erase(ansl);
            ans[i-2]=ansl;
        }

        int ansr=-1;
        for(auto v:r){
            if(mid.find(v)==mid.end()){
                ansr=v;
                break;
            }
        }
        if(ansr!=-1){
            r.erase(ansr);
            ans[m-i+2-1]=ansr;
        }
    }

    if(!l.empty()){
        ans[half-1]=*l.begin();
    }
    if(!r.empty()){
        ans[half]=*r.begin();
    }
    print(ans);
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
