#include<bits/stdc++.h>
using namespace std;
const int N =1e5+10;

void solve(){
    int n,k;cin>>n>>k;
    std::vector<vector<int>>v(n+2);
    int t=1,i;
    for(i=1;;i++){
        if(v[t].size()==4)t++;
        if(t>n)break;
        if(v[t].empty()){
            if(i%2==0)i++;
            v[t].push_back(i);
            continue;
        }
        int ok=1;
        for(int c:v[t]){
            if(__gcd(i,c)!=1){
                ok=0;
                break;
            }   
        }
        if(ok)
        v[t].push_back(i);
        //cout<<i<<" "<<t<<"\n";
    }    
    cout<<(i-1)*k<<"\n";
    for(int i=1;i<=n;i++){
        for(auto c:v[i]){
            cout<<c*k<<" ";
        }
        cout<<"\n";
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
