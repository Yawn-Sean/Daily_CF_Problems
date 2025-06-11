/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

constexpr int inf=1e9;

void solve(){
    int n;
    std::cin>>n;
    auto query=[&](std::array<int,2> t)->bool{
        auto [x,y]=t;
        std::cout<<x<<" "<<y<<std::endl;
        std::string s;
        std::cin>>s;
        return (s=="white");
    };
    auto print=[&](int x,int y,int x_1,int y_1){
        std::cout<<x<<" "<<y<<" "<<x_1<<" "<<y_1<<std::endl;
    };

    std::map<std::array<int,2>,int> q;
    int len=(1<<29);

    std::array<int,2> la={-1,-1},now={0,0};
    q[now]=query(now);

    int w=0,b=0;
    if(q[now]) w=1;
    else b=1;

    for(int i=1;i<=n-1;i++,len>>=1){
        if(w and b){
            if(now[1]==la[1]){
                int idx=la[0]+len;
                std::array<int,2> t={idx,now[1]};
                q[t]=query(t);
                if(q[t]==q[la]) la=t;
                else now=t;
            }else{
                int idx=la[1]+len;
                std::array<int,2> t={la[0],idx};
                q[t]=query(t);
                if(q[t]==q[la]) la=t;
                else now=t;
            }
        }else if(w){
            if(now[1]==0 and now[0]+len<=inf){
                std::array<int,2> t={now[0]+len,0};
                q[t]=query(t);
                if(!q[t]) b=1;
                la=now,now=t;
            }else{
                std::array<int,2> t={0,now[1]+len};
                q[t]=query(t);
                if(!q[t]) b=1;
                la=now,now=t;
            }
        }else{
            if(now[1]==0 and now[0]+len<=inf){
                std::array<int,2> t={now[0]+len,0};
                q[t]=query(t);
                if(q[t]) w=1;
                la=now,now=t;
            }else{
                la[0]=now[0]=0;
                std::array<int,2> t={0,now[1]+len};
                q[t]=query(t);
                if(q[t]) w=1;
                la=now,now=t;
            }
        }
    }
    if(b and w){
        if(now[1]==la[1]){
            print(la[0]+1,0,la[0]+1,1);
        }else{
            print(0,la[1]+1,1,la[1]+1);
        }
    }else{
        print(0,inf,1,inf);
    }
}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
