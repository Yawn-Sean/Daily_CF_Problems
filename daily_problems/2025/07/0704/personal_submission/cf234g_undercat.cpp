#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int n;cin>>n;
    int res=1;
    while((1<<res)<n)res++;
    cout<<res<<'\n';
    for(int i=0;i<res;i++){
        vector<int>t;
        for(int j=0;j<n;j++){
            if((j>>i)&1)t.push_back(j);
        }
        cout<<t.size()<<' ';
        for(int i=0;i<t.size();i++)
            cout<<t[i]<<" \n"[i==(int)t.size()-1];
    }
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    // int t;cin>>t;while(t--)
    solve();
}