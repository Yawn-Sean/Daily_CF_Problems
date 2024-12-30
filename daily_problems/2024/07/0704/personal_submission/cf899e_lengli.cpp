/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

struct Node{
    int len,idx;
    Node(){};
    Node(int len,int idx):len(len),idx(idx){};
    bool operator < (const Node &W)const{
        if(len!=W.len) return len>W.len;
        return idx<W.idx;
    };
};

std::set<Node> s;

void solve(){
    int n;
    std::cin>>n;
    std::vector<std::array<int,2>> q;
    int v=-1,cnt=0;
    for(int i=1;i<=n;i++){
        int x;
        std::cin>>x;
        if(v==-1) v=x,cnt=1;
        else if(v==x) cnt++;
        else{
            q.pb({v,cnt});
            v=x,cnt=1;
        }
    }
    if(v!=-1) q.pb({v,cnt});
    int m=q.size();
    std::vector<int> la(m+2,-1),ne(m+2,-1),st(m+2,1);
    for(int i=1;i<m;i++) la[i]=i-1;
    for(int i=0;i<m-1;i++) ne[i]=i+1;
    for(int i=0;i<m;i++){
        s.insert(Node(q[i][1],i));
    }
    int res=0;
    while(s.size()){
        auto it=s.begin();
        auto len=(*it).len,idx=(*it).idx;
        //std::cout<<len<<" "<<idx<<"\n";
        if(la[idx]!=-1 and ne[idx]!=-1){
            int l=la[idx],r=ne[idx];
            while(l!=-1 and r!=-1 and st[l] and st[r] and q[l][0]==q[r][0]){
                s.erase(Node(q[l][1],l));
                s.erase(Node(q[r][1],r));
                s.insert(Node(q[l][1]+q[r][1],l));
                q[l][1]+=q[r][1];
                st[r]=0;
                ne[l]=ne[r];
                r=ne[l];
            }
            if(l!=-1 and r!=-1 and st[l] and st[r]) ne[l]=r,la[r]=l;
        }
        s.erase(it);
        st[idx]=0;
        res++;
    }
    std::cout<<res;
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
