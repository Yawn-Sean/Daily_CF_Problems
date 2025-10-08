#include <bits/stdc++.h>
#define il inline

using namespace std;
using ll = long long;
using ull = unsigned long long;
using int128=__int128_t;

const ll N = 1e7 + 5, mod =1e9+7, inf = 2e18;
const double esp=1e-9;
double PI=3.1415926;

il void solve(){
    ll a,b;
    cin>>a>>b;
    for(int mask=0;mask<=30;mask++){
        if((((a>>mask)&1)==0)&&(b>>mask)&1){
            cout<<-1<<'\n';
            return ;
        }
    }

    if(a==0&&b==0){
        cout<<"1\n0\n";
        return ;
    }
    vector<int>bit;
    for(int mask=0;mask<=30;mask++){
        if((a>>mask)&1){
            bit.push_back(1<<mask);
        }
    }
    int k=bit.size();
    if(k==1){
        if(b!=a){
            cout<<-1<<'\n';
        }else{
            cout<<"2\n0 "<<a<<'\n';
        }
        return ;
    }
    vector<int>ans;
    for(int mask=0;mask<1<<k;mask++){
        int val=0;
        for(int i=0;i<k;i++){
            if(mask&(1<<i))val|=bit[i];
        }
        if(val==b&&b)continue;
        ans.push_back(val);
    }
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<'\n';
    for(auto v:ans)cout<<v<<" ";
    cout<<'\n';
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int t = 1;

    cin >> t;

    while (t--) {

        solve();

    }

    return 0;
}
