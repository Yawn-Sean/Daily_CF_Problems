// https://codeforces.com/problemset/problem/1644/D
#include <bits/stdc++.h>
using namespace std;
const int MOD=998244353;
void solve()
{
    int n,m,k,q;
    cin>>n>>m>>k>>q;
    unordered_map<int,int> mx,my;
    vector<int> xq,yq;
    for(int i=0;i<q;i++){
        int x,y;
        cin>>x>>y;
        xq.push_back(x);
        yq.push_back(y);
    }
    int c1=0,c2=0;
    long long res=1;
    for(int i=q-1;i>=0;i--){
        if((mx.find(xq[i])==mx.end()&&c2<m)||(my.find(yq[i])==my.end()&&c1<n)){
            res=res*k%MOD;
            if(mx.find(xq[i])==mx.end()) {mx[xq[i]]=c1;c1++;}
            if(my.find(yq[i])==my.end()) {my[yq[i]]=c2;c2++;}
        }
    }
        
    cout<<res<<endl;
}

int main()
{
    int t=1;
    cin>>t;
    while(t--)
        solve();
    return 0;
}
