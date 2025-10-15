#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int a,b;cin>>a>>b;
    string s;cin>>s;
    int x=0,y=0;
    vector<pair<int,int>>p{{0,0}};
    for(auto&c:s){
        if(c=='L')x--;
        else if(c=='R')x++;
        else if(c=='U')y++;
        else y--;
        p.push_back({x,y});
    }
    for(int i=0;i<(int)p.size();i++){
        int tx=a-p[i].first,ty=b-p[i].second;
        if(x==0&&tx==0){
            if((y==0&&ty==0)||(y!=0&&ty%y==0&&(ty/y)>=0)){
                cout<<"Yes\n";
                return;
            }
        }
        if(y==0&&ty==0){
            if((x==0&&tx==0)||(x!=0&&tx%x==0&&(tx/x)>=0)){
                cout<<"Yes\n";
                return;
            }
        }
        if(x&&(tx%x)==0&&y&&(ty%y)==0&&(tx/x==ty/y)&&(tx/x)>=0){
            cout<<"Yes\n";
            return;
        }
    }
    cout<<"No\n";
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
}