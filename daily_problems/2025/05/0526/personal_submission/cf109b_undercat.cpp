#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int pl,pr,vl,vr,k;cin>>pl>>pr>>vl>>vr>>k;
    vector<int>q,ed{0};
    for(int i=1;i<11;i++){
        auto t=ed;
        vector<int>temp;
        for(auto i:t){
            q.push_back(i*10+4);
            q.push_back(i*10+7);            
            temp.push_back(i*10+4);
            temp.push_back(i*10+7);
        }
        ed.swap(temp);
    }
    int all=(pr-pl+1)*(vr-vl+1),res=0;
    while(pl<=pr){
        int p=lower_bound(q.begin(),q.end(),pl)-q.begin();
        if(q[p]==pl){
            {
                // l
                int nvl=vl,nvr=min(vr,pl);
                if(p-k>=0){
                    nvl=max(nvl,q[p-k]+1);
                }
                if((p-k+1)>=0){
                    nvr=min(nvr,q[p-k+1]);
                }else{
                    nvr=0;
                }
                if(nvl<=nvr){
                    res+=nvr-nvl+1;
                }
            }
            {
                // r
                int nvl=max(vl,pl+1),nvr=vr;
                nvl=max(nvl,q[p+k-1]);
                nvr=min(nvr,q[p+k]-1);
                if(nvl<=nvr){
                    res+=nvr-nvl+1;
                }
            }
            pl++;
        }else{
            int npr=min(pr,q[p]-1);
            int len=npr-pl+1;
            {
                // l
                int nvl=vl,nvr=min(vr,pl);
                if(p-k-1>=0){
                    nvl=max(nvl,q[p-k-1]+1);
                }
                if((p-k)>=0){
                    nvr=min(nvr,q[p-k]);
                }else{
                    nvr=0;
                }
                if(nvl<=nvr){
                    res+=(nvr-nvl+1)*len;
                }
            }
            {
                // r
                int nvl=max(vl,pl+1),nvr=vr;
                nvl=max(nvl,q[p+k-1]);
                nvr=min(nvr,q[p+k]-1);
                if(nvl<=nvr){
                    res+=(nvr-nvl+1)*len;
                }
            }
            pl=q[p];
        }
    }
    cout<<1.0*res/all;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cout<<fixed<<setprecision(12);
    solve();
}