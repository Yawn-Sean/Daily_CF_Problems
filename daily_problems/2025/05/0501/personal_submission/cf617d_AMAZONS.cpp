#include<bits/stdc++.h>
using namespace std;
const int N =2e5 + 10;
const int mod=1e9+7;
typedef long long ll;
vector<pair<int,int>> vp(4);
void solve(){
    int ans=0,cnt=0,flag=0;
    map<int,int> mp1,mp2;
	for(int i=1;i<=3;i++){
        cin>>vp[i].first>>vp[i].second;
        int x=vp[i].first,y=vp[i].second;
    }
    // sort(vp.begin()+1,vp.end());
    if((vp[1].first==vp[2].first&&vp[1].first==vp[3].first)||(vp[1].second==vp[2].second&&vp[1].second==vp[3].second)){cout<<1<<endl;return ;}
    for(int i=1;i<=3;i++)
    {
        int j=(i)%3+1,k=(i+1)%3+1;
        if(vp[i].first==vp[j].first&&(vp[k].second<=min(vp[i].second,vp[j].second)||vp[k].second>=max(vp[i].second,vp[j].second)))
        {cout<<2<<endl ;return ;}
        if(vp[i].second==vp[j].second&&(vp[k].first<=min(vp[i].first,vp[j].first)||vp[k].first>=max(vp[i].first,vp[j].first)))
        {cout<<2<<endl;return ;}
    }
    // if(ans==0)ans=3;
    cout<<3<<endl;
}
int main(){
    int t=1;
    // cin>>t;
    while(t--)
    {solve();}
    return 0;
}
