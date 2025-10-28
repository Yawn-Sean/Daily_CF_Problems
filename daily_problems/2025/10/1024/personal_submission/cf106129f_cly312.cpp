#include<bits/stdc++.h>
using namespace std;
int main(){
    int h,w;
    cin>>h>>w;
    int n=0;
    vector<string> grid(h);
    for(auto &s:grid) cin>>s;
    for(auto i:grid) for(auto j:i) if(j=='#') n++;
    for(int k=min(h,w);k>=2;k--){
        if(n%(k*k)) continue;
        bool flag=true;
        vector<vector<bool>> v(h,vector<bool>(w,false));
        for(int i=0;i<h;i++) for(int j=0;j<w;j++) if(grid[i][j]=='#') v[i][j]=true;
        for(int i=0;i<h&&flag;i++){
            for(int j=0;j<w&&flag;j++){
                if(!v[i][j]) continue;;
                for(int i2=0;i2<k&&flag;i2++){
                    for(int j2=0;j2<k&&flag;j2++){
                        if(i+i2<h&&j+j2<w&&v[i+i2][j+j2]) v[i+i2][j+j2]=false;
                        else flag=false;
                    }
                }
            }
        }
        if(flag) return cout<<k,0;
    }
    cout<<1;
}