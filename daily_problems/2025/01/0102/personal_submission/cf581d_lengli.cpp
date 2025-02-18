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
    std::vector<int> x(3),y(3);
    int sum=0;
    for(int i=0;i<3;i++){
        std::cin>>x[i]>>y[i];
        if(x[i]>y[i]) std::swap(x[i],y[i]);
        sum+=x[i]*y[i];
    }
    int len=std::sqrt(sum);
    if(len*len!=sum){
        std::cout<<"-1"<<"\n";
        return;
    }

    std::vector<std::vector<char>> res(len,std::vector<char> (len));

    auto push=[&](int sx,int sy,int ex,int ey,int v){
        char c=(v==0 ? 'A' : v==1 ? 'B' : 'C');
        for(int i=sx;i<=ex;i++)
            for(int j=sy;j<=ey;j++) res[i][j]=c;
    };

    auto check=[&](int sx,int id){
        std::vector<int> q;
        for(int i=0;i<3;i++){
            if(i==id) continue;
            q.pb(i);
        }
        
        for(int i=0;i<4;i++){
            for(int j=0;j<2;j++)
                if(i>>j&1) std::swap(x[q[j]],y[q[j]]);


            if(x[q[0]]==x[q[1]] and x[q[0]]==len-sx and y[q[0]]+y[q[1]]==len){
                push(sx,0,len-1,y[q[0]]-1,q[0]);
                push(sx,y[q[0]],len-1,len-1,q[1]);
                return 1;
            }

            if(x[q[0]]==x[q[1]] and x[q[0]]==len and y[q[0]]+y[q[1]]==len-sx){
                push(sx,0,sx+y[q[0]]-1,len-1,q[0]);
                push(sx+y[q[0]],0,len-1,len-1,q[1]);
                return 1;
            }

            for(int j=0;j<2;j++)
                if(i>>j&1) std::swap(x[q[j]],y[q[j]]);
            
        }
        return 0;
    };

    for(int i=1;i<len;i++){
        for(int j=0;j<3;j++){
            if(x[j]==i and y[j]==len){
                push(0,0,i-1,len-1,j);
                auto flag=check(i,j);
                if(flag){
                    std::cout<<len<<"\n";
                    for(auto x:res){
                        for(auto y:x) std::cout<<y;
                        std::cout<<"\n";
                    }
                    return;
                }
            }
        }
    }
    std::cout<<"-1"<<"\n";

}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
