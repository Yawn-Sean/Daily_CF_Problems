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
    int d,n,m;
    std::cin>>d>>n>>m;

    std::vector<int> x_1(d+2),y_1(d+2),x_2(d+2),y_2(d+2);
    for(int i=1;i<=d;i++){
        std::cin>>x_1[i]>>y_1[i]>>x_2[i]>>y_2[i];
        if(x_1[i]>x_2[i]) std::swap(x_1[i],x_2[i]);
        if(y_1[i]>y_2[i]) std::swap(y_1[i],y_2[i]);
    }

    int cl,cr,ct,cb;
    std::cin>>cl>>cr>>ct>>cb;

    std::vector<int> mxl(100010),mxr(100010),myl(100010),myr(100010);

    for(int i=1;i<=d;i++){
        mxl[x_1[i]]++;
        mxr[x_2[i]]++;
        myl[y_1[i]]++;
        myr[y_2[i]]++;
    }

    for(int i=1;i<=100001;i++){
        mxl[i]+=mxl[i-1];
        myl[i]+=myl[i-1];
    }
    for(int i=100000;i>=0;i--){
        mxr[i]+=mxr[i+1];
        myr[i]+=myr[i+1];
    }

    for(int i=1;i<=d;i++){
        int zxl=mxl[x_2[i]-1];
        int zxr=mxr[x_1[i]+1];
        int zyl=myl[y_2[i]-1];
        int zyr=myr[y_1[i]+1];

        if(x_2[i]!=x_1[i]){
            zxl--;
            zxr--;
        }
        if(y_2[i]!=y_1[i]){
            zyl--;
            zyr--;
        }
        if(zxl==cl and zxr ==cr and zyl==ct and zyr==cb){
            std::cout<<i<<"\n";
            return;
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
