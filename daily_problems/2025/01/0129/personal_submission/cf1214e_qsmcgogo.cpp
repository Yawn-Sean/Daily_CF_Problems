#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[1202020],b[1202020],p[202020],r[202020];
char s[202020];
int t[1202020];
int sum[202020];
int dp[602020][20];
map<int,int>mp;
int out[202020];
vector<vector<int>>e;
void add(int x,int p){
    for(int i=x;i<3e5;i+=i&-i)t[i]=max(t[i],p);
}
int ask(int x){
    int res=0;
    for(int i=x;i;i-=i&-i)res=max(res,t[i]);
    return res;
}
signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n,i;
    cin>>n;
    for(i=1;i<=n;i++){
        cin>>a[i];
        e.push_back({a[i],2*i-1,2*i});
    }
    vector<int>v;
    sort(e.begin(),e.end());
    for(i=n-2;i>=0;i--){
        cout<<e[i][1]<<" "<<e[i+1][1]<<'\n';
        v.push_back(e[i+1][1]);
    }
    v.push_back(e[0][1]);
    int jj=0;
    for(i=n-1;i>=0;i--){
        int ed=jj+e[i][0]-1;
        cout<<e[i][2]<<" "<<v[ed]<<'\n';
        if(ed==v.size()-1)v.push_back(e[i][2]);
        jj++;
    }
    return 0;
}
