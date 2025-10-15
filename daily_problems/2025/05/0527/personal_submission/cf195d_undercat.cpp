#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
    int n;cin>>n;
    vector<pair<int,int>>p;
    int sumk=0,sumb=0;
    for(int i=0,x,y;i<n;i++){
        cin>>x>>y;
        if(x){
            p.push_back({x,y});
            if(x<0){
                sumk+=x;
                sumb+=y;
            }
        }
    }
    n=p.size();
    sort(p.begin(),p.end(),[](pair<int,int>a,pair<int,int>b){
        // return -a.second*1.0/a.first<-b.second*1.0/b.first;
        // return -a.second*b.first<-b.second*a.first;
        if (a.first < 0) a = {-a.first, -a.second};
        if (b.first < 0) b = {-b.first, -b.second};
        return a.second * b.first > b.second * a.first;
    });
    vector<pair<int,int>>st;
    st.push_back({sumk,sumb});
    for(int i=0;i<n;i++){
        auto [k,b]=p[i];
        // cout<<k<<' '<<b<<'\n';
        if(k<0){
            sumk-=k;
            sumb-=b;
        }else{
            sumk+=k;
            sumb+=b;
        }
        if(i+1<n&&(p[i].second*p[i+1].first==p[i].first*p[i+1].second)){
            continue;
        }
        st.push_back({sumk,sumb});
    }
    int res=0;
    for(int i=1;i<st.size();i++){
        if(st[i]==st[i-1])continue;
        else res++;
    }
    cout<<res;
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
}