#include<bits/stdc++.h>
using namespace std;
int st[10][10];
int dir[4][2]={1,0,-1,0,0,1,0,-1};
void solve(){
    int n;cin>>n;
    if(n==2){
        cout<<"a1 h1 h8";
        return;
    }
    vector<pair<char,int>>v;
    v.push_back({'a',1});
    st[1][1]=1;
    int flag=1;
    auto check=[&](int x,int y)->void{
        if(st[x][y])return;
        int vn=(int)v.size();
        if(vn==(n+1))return;
        st[x][y]=1;
        v.push_back({x+'a'-1,y});
        int sub=n-vn-1;
        if(sub==1){
            for(int i=1;i<=7;i++){
                if(st[i][8]==0&&x==i){
                    v.push_back({i+'a'-1,8});
                    v.push_back({'h',8});
                    return;
                }
                if(st[8][i]==0&&y==i){
                    v.push_back({'h',i});
                    v.push_back({'h',8});
                    return;
                }
            }
            for(int i=0;i<4;i++){
                int dx=x+dir[i][0],dy=y+dir[i][1];
                if(dx>=1&&dx<=8&&dy>=1&&dy<=8&&st[dx][dy]==0&&(dx==8||dy==8)&&!(dx==8&&dy==8)){
                    v.push_back({dx+'a'-1,dy});
                    v.push_back({'h',8});
                    return;
                }
            }
        }
        if(sub==2){
            if(st[x][1]==0&&st[8][1]==0){
                v.push_back({x+'a'-1,1});
                v.push_back({'h',1});
                v.push_back({'h',8});
                return;
            }
        }
    };
    for(int i=1,dir=1,j=2;i<=7&&flag;i++,dir^=1){
        int fx=dir*2-1;
        for(;j>=2&&j<=8;){
            check(i,j);
            if((j+fx)<2||(j+fx)>8)break;
            j+=fx;
        }
    }
    check(7,1);
    for(int i=2;i<=6;i++)check(i,1);
    for(int i=1;i<=7;i++)check(8,i);
    for(auto[x,y]:v)cout<<x<<y<<' ';
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
}
