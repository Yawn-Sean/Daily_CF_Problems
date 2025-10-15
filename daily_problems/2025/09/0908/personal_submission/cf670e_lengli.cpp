/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long

void solve(){
    int n,m,p;
    std::cin>>n>>m>>p;
    std::vector<char> a(n+2);
    for(int i=1;i<=n;i++) std::cin>>a[i];

    std::vector<int> pre(n+2,-1),ne(n+2,-1);
    for(int i=2;i<=n;i++) pre[i]=i-1;
    for(int i=n-1;i>=1;i--) ne[i]=i+1;

    std::stack<int> q;
    std::vector<int> match(n+2,-1);
    for(int i=1;i<=n;i++){
        if(a[i]=='(') q.push(i);
        else{
            if(q.size()){
                int u=q.top();
                q.pop();
                match[i]=u;
                match[u]=i;
            }
        }
    }

    std::vector<int> st(n+2,1);

    for(int i=1;i<=m;i++){
        char op;
        std::cin>>op;

        if(op=='L'){
            if(pre[p]!=-1) p=pre[p];
        }else if(op=='R'){
            if(ne[p]!=-1) p=ne[p];
        }else if(a[p]=='('){
            int idx=p,to=match[p];
            int l=pre[p],r=ne[to];
            while(1){
                st[idx]=0;
                if(idx==to) break;
                idx=ne[idx];
            }
            if(l!=-1) ne[l]=r;
            if(r!=-1) pre[r]=l;
            if(r!=-1) p=r;
            else p=l;
        }else{
            int idx=p,to=match[p];
            int l=pre[to],r=ne[p];
            while(1){
                st[idx]=0;
                if(idx==to) break;
                idx=pre[idx];
            }
            if(l!=-1) ne[l]=r;
            if(r!=-1) pre[r]=l;
            if(r!=-1) p=r;
            else p=l;
        }
    }
    for(int i=1;i<=n;i++){
        if(st[i]) std::cout<<a[i];
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
