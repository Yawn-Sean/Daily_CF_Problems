#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> a;
bool ok(int k,int n,int L,int R){
    if(!k) return 1;
    vector<bool> f(R+1);
    f[0]=1;
    for(auto &p:a){
        int m=p.first,c=p.second,t=c/k;
        vector<bool> g(R+1);
        for(int r=0;r<m;r++){
            deque<int> q;
            for(int j=r;j<=R;j+=m){
                while(!q.empty()&&q.front()<j-t*m) q.pop_front();
                if(f[j])q.push_back(j);
                if(!q.empty()) g[j]=1;
            }
        }
        f=g;
    }
    for(int j=L;j<=R;j++) if(f[j]) return 1;
    return 0;
}
int main(){
    int n,L,R;
    cin>>n>>L>>R;
    a.resize(n);
    for(auto &[i,j]:a) cin>>i>>j;
    long long l=0,r=5e7,ans=0;
    while(l<=r){
        long long m=(l+r)/2;
        if(ok(m,n,L,R)){
            ans=m;
            l=m+1;
        }else r=m-1;
    }
    cout<<ans;
}
