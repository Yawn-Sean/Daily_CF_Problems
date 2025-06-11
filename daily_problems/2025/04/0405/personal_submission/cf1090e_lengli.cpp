/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back
#define i64 long long


void solve() {
    int n;
    std::cin>>n;
    std::vector<std::vector<int>> a(8,std::vector<int> (8,0));
    for(int i=0;i<n;i++){
        char r,f;
        std::cin>>r>>f;
        a[r-'a'][f-'1']=1;
    }
    std::vector<int> dx={-2,-2,-1,-1,1,1,2,2};
    std::vector<int> dy={1,-1,2,-2,2,-2,1,-1};
    std::vector<std::string> res;
    for(int i=0;i<n;i++){
        int r=i%8,f=i/8;
        if(a[r][f]) continue;
        std::vector<std::vector<std::array<int,2>>> p(8,std::vector<std::array<int,2>> (8));
        p[r][f]={-1,-1};
        std::vector<std::vector<int>> st(8,std::vector<int> (8,0));
        st[r][f]=1;
        std::queue<std::array<int,2>> q;
        q.push({r,f});
        std::vector<std::string> tmp;
        while(q.size()){
            auto [x,y]=q.front();
            q.pop();
            int j=x+8*y;
            if(a[x][y] and j>i){
                std::vector<std::array<int,2>> path;
                {
                    int cx=x,cy=y;
                    while(cx!=-1 and cy!=-1){
                        path.pb({cx,cy});
                        auto [ll,rr]=p[cx][cy];
                        cx=ll,cy=rr;
                    
                    }
                }
                reverse(all(path));
                for(int k=0;k<path.size()-1;k++){
                    auto [cx,cy]=path[k];
                    auto [nx,ny]=path[k+1];
                    std::string cur,ne;
                    cur+=(char)(cx+'a');cur+=(char)(cy+'1');
                    ne+=(char)(nx+'a');ne+=(char)(ny+'1');
                    if(a[nx][ny] and (nx!=x or ny!=y)) tmp.pb(ne+"-"+cur);
                
                }
                for(int k=path.size()-2;k>=0;k--){
                    auto [cx,cy]=path[k];
                    auto [nx,ny]=path[k+1];
                    std::string cur,ne;
                    cur+=(char)(cx+'a');cur+=(char)(cy+'1');
                    ne+=(char)(nx+'a');ne+=(char)(ny+'1');
                    if(a[nx][ny] and (nx!=x or ny!=y));
                    else tmp.pb(ne+"-"+cur);
                }
                a[x][y]=0;
                a[r][f]=1;
                break;
            }
            for(int k=0;k<8;k++){
                int nx=x+dx[k],ny=y+dy[k];
                if(nx<0 or nx>=8 or ny<0 or ny>=8 or st[nx][ny]) continue;
                st[nx][ny]=1;
                q.push({nx,ny});
                p[nx][ny]={x,y};
            }
        }
        for(auto t:tmp) res.pb(t);
    }
    std::cout<<res.size()<<"\n";
    for(auto x:res) std::cout<<x<<"\n";
}


signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
