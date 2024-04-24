/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define endl '\n'
#define all(x) x.begin(),x.end()
#define pb push_back

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) "lengli"
#endif

const int N=100010,inf=1e9;

int tr[N][27],idx,cnt[N];
int ne[N];

void insert(string s,int k){
    int p=0;
    for(auto x:s){
        int t=x-'a';
        if(!tr[p][t]) tr[p][t]=++idx;
        p=tr[p][t];
    }
    cnt[p]+=k;
}

void get_fail(){
    queue<int> q;
    for(int i=0;i<26;i++){
        if(tr[0][i]) q.push(tr[0][i]);
    }
    while(q.size()){
        auto t=q.front();
        q.pop();
        for(int i=0;i<27;i++){
            int j=tr[t][i];
            if(!j) tr[t][i]=tr[ne[t]][i];
            else{
                ne[j]=tr[ne[t]][i];
                q.push(j);
            }
        }
        cnt[t]+=cnt[ne[t]];
    }
}

void solve(){
    string s,a,b;
    cin>>s>>a>>b;
    insert(a,1),insert(b,-1);
    get_fail();

    vector<vector<int>> f(s.size()+2,vector<int> (idx+2,-inf));
    f[0][0]=0;
    for(int i=0;i<s.size();i++){
        for(int j=0;j<=idx;j++){
            if(f[i][j]==-inf) continue;
            for(int l=0;l<26;l++){
                if(s[i]=='*' or s[i]==l+'a'){
                    int t=tr[j][l];
                    f[i+1][t]=max(f[i+1][t],f[i][j]+cnt[t]);
                }
            }
        }
    }
    int res=-inf;
    for(int j=0;j<=idx;j++) res=max(res,f[s.size()][j]);
    cout<<res;
}

signed main(){
    fastio;
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
