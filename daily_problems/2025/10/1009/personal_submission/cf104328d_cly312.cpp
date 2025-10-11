#include <bits/stdc++.h>
using namespace std;
const int M=1e7;
int main(){
    vector<int> spf(M+1);
    for(int i=0;i<=M;i++) spf[i]=i;
    for(int i=2;i*i<=M;i++){
        if(spf[i]==i){
            for(int j=i*i;j<=M;j+=i){
                if(spf[j]==j) spf[j]=i;
            }
        }
    }
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> p(n);
    for(int &x:p) cin>>x;
    vector<vector<int>> g(n);
    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        u--;v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    unordered_map<int,vector<int>> mp;
    for(int i=0;i<n;i++){
        if(p[i]==1) continue;
        int x=p[i];
        while(x>1){
            int f=spf[x];
            mp[f].push_back(i);
            while(x%f==0) x/=f;
        }
    }
    for(auto &x:mp){
        auto &v=x.second;
        if(v.size()<=n/2) continue;
        unordered_set<int> S(v.begin(),v.end()),vis;
        for(int node:v){
            if(vis.count(node)) continue;
            vector<int> comp;
            queue<int> q;
            q.push(node);
            vis.insert(node);
            while(q.size()){
                int u=q.front();
                q.pop();
                comp.push_back(u);
                for(int v:g[u]){
                    if(S.count(v)&&!vis.count(v)){
                        vis.insert(v);
                        q.push(v);
                    }
                }
            }
            unordered_map<int,int> d1,d2;
            queue<int> q1,q2;
            d1[comp[0]]=0;
            q1.push(comp[0]);
            while(q1.size()){
                int u=q1.front();
                q1.pop();
                for(int v:g[u]){
                    if(S.count(v)&&!d1.count(v)){
                        d1[v]=d1[u]+1;
                        q1.push(v);
                    }
                }
            }
            int f1=comp[0];
            for(int u:comp){
                if(d1.count(u)&&d1[u]>d1[f1]) f1=u;
            }
            d2[f1]=0;
            q2.push(f1);
            while(q2.size()){
                int u=q2.front();
                q2.pop();
                for(int v:g[u]){
                    if(S.count(v)&&!d2.count(v)){
                        d2[v]=d2[u]+1;
                        q2.push(v);
                    }
                }
            }
            int f2=f1;
            for(int u:comp){
                if(d2.count(u)&&d2[u]>d2[f2]) f2=u;
            }
            if(d2[f2]+1>n/2){
                cout<<"YES\n";
                return 0;
            }
        }
    }
    cout<<"NO\n";
}
