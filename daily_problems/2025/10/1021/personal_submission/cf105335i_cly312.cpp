#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> p(n);
    for(int &x:p)cin>>x;
    int h=n/2,c0=p[0]-1,c1=(p[1]-1)-(p[0]<p[1]?1:0);
    int c0n,c1n;
    if(n%2==0){
        c0n=(c0+h)%n;
        c1n=c1;
    }else{
        int t=c1+h;
        c1n=t%(n-1);
        int ca=t/(n-1);
        c0n=(c0+h+ca)%n;
    }
    int q0=c0n+1,k=c1n+1,q1=(k<q0)?k:k+1;
    vector<int>ans(n);
    ans[0]=q0;
    if(n>=2) ans[1]=q1;
    if(n>2){
        int s=n-2;
        vector<int> sf(s);
        for(int i=0;i<s;++i) sf[i]=p[i+2];
        vector<char> pr(n+1,0);
        for(int x:sf) pr[x]=1;
        vector<int> rk(n+1,-1);
        int cu=0;
        for(int v=1;v<=n;++v) if(pr[v]) rk[v]=cu++;
        vector<int> rl(s);
        for(int i=0;i<s;++i) rl[i]=rk[sf[i]];
        vector<int> rm;
        for(int v=1;v<=n;++v) if(v!=q0&&v!=q1)rm.push_back(v);
        for(int i=0;i<s;++i) ans[i+2]=rm[rl[i]];
    }
    for(int i:ans) cout<<i<<' ';
    cout<<'\n';
    return 0;
}
