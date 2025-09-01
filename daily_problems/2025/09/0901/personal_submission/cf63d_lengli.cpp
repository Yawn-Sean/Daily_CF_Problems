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
    int a,b,c,d,n;
    std::cin>>a>>b>>c>>d>>n;
    int row,col;
    if(a%2==0) row=0,col=1;
    else row=b+1,col=1;
    std::vector<std::vector<char>> g(110,std::vector<char> (110,'*'));

    i64 sum=0;
    char y='a';
    for(int i=0;i<n;i++){
        int x;
        std::cin>>x;
        sum+=x;
        if(sum>(a*b)+(c*d)) break;
        for(int j=0;j<x;j++){
            if(a%2==0) col%2==1 ? row++ : row--;
            else col%2==1 ? row-- : row++;

            if(!row) row=1,col++;
            else if(col<=a and row>b) row=b,col++;
            else if(col>a and row>d) row=d,col++;
            g[row][col]=y;
        }
        y++;
    }

    if(sum>(a*b)+(c*d)) std::cout<<"NO"<<"\n";
    else{
        std::cout<<"YES"<<"\n";
        for(int i=1;i<=std::max(b,d);i++){
            for(int j=1;j<=a+c;j++){
                if(g[i][j]!='*'){
                    std::cout<<g[i][j];
                }else std::cout<<".";
            }
            std::cout<<"\n";
        }
    }

}

signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
