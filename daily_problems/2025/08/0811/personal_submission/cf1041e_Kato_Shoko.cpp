#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 3e5 + 5, mod = 998244353, inf = 2e18;
const double esp=1e-3;
double PI=3.1415926;

vector<int>g[1005];

il void solve(){
    ll n;
    cin>>n;
    vector<int>cont(n+1);
    for(int i=1;i<n;i++){
        int a,b;
        cin>>a>>b;
        if(b!=n){
            cout<<"NO\n";
            return ;
        }
        cont[a]++;
    }

    set<int>st;
    int sum=0;
    for(int i=1;i<=n;i++){
        st.insert(i);
        sum+=cont[i];
        if(sum>i){
            cout<<"NO\n";
            return ;
        } 
    }
    
    vector<pair<int,int>>pa;
    int last=-1;

    for(int i=1;i<n;i++){
        if(cont[i]>0){
            if(st.count(i))st.erase(i);
            if(last!=-1){
                pa.push_back({last,i});
            }
            last=i;
            cont[i]--;
        }

        while(cont[i]){
            if(st.empty()){
                cout<<"NO\n";
                return ;
            }
            int v=*st.begin();
            st.erase(v);
            pa.push_back({last,v});
            last=v;
            cont[i]--;
        }
    }
    pa.push_back({last,n});
    cout<<"YES\n";
    for(auto &[x,y]:pa){
        cout<<x<<" "<<y<<'\n';
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
