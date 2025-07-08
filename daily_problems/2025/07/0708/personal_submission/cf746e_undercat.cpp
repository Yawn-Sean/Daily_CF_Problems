#include<bits/stdc++.h>
using namespace std;
#define int long long

void solve(){
    int n,m;cin>>n>>m;
    vector<int>a(n);
    for(auto&i:a)cin>>i;
    if(n%2){
        cout<<-1;return;
    }
    map<int,vector<int>>mp[2];
    int cnt[2]{0,0},mo,me;
    if(m%2)mo=m,me=m-1;
    else mo=m-1,me=m;
    for(int i=0;i<n;i++){
        mp[a[i]%2][a[i]].push_back(i);
    }
    cnt[1]=mp[1].size();
    cnt[0]=mp[0].size();
    vector<vector<vector<int>>>vec(2);
    for(int i=0;i<2;i++){
        for(auto&[_,x]:mp[i]){
            vec[i].push_back(x);
        }
        // sort(vec[i].begin(),vec[i].end(),[&](vector<int>&a,vector<int>&b){
        //     return a.size()>b.size();
        // });
    }
    int res=0;
    if(cnt[0]>cnt[1]){
        for(auto&_:vec[0]){
            while(_.size()>1){
                if(cnt[0]>=n/2){
                    while(mo>0&&mp[1].count(mo))mo-=2;
                    if(mo<=0){
                        cout<<-1;return;
                    }
                    mp[1][mo].push_back(_.back());
                    a[_.back()]=mo;
                    _.pop_back();
                    cnt[1]++;
                }else if(cnt[0]<n/2){
                    while(me>0&&mp[0].count(me))me-=2;
                    if(me<=0){
                        cout<<-1;return;
                    }
                    mp[0][me].push_back(_.back());
                    a[_.back()]=me;
                    _.pop_back();
                    cnt[0]++;
                }
                res++;
            }
        }
        if(cnt[0]>n/2){
            for(auto&_:vec[0]){
                if(cnt[0]==n/2)break;
                while(mo>0&&mp[1].count(mo))mo-=2;
                if(mo<=0){
                    cout<<-1;return;
                }
                mp[1][mo].push_back(_.back());
                a[_.back()]=mo;
                _.pop_back();
                cnt[0]--;
                cnt[1]++;
                res++;
            }
        }
        for(auto&_:vec[1]){
            while(_.size()>1){
                while(mo>0&&mp[1].count(mo))mo-=2;
                if(mo<=0){
                    cout<<-1;return;
                }
                mp[1][mo].push_back(_.back());
                a[_.back()]=mo;
                _.pop_back();
                res++;
            }
        }
    }else{
        for(auto&_:vec[1]){
            while(_.size()>1){
                if(cnt[1]>=n/2){
                    while(me>0&&mp[0].count(me))me-=2;
                    if(me<=0){
                        cout<<-1;return;
                    }
                    mp[0][me].push_back(_.back());
                    a[_.back()]=me;
                    _.pop_back();
                    cnt[0]++;
                }else if(cnt[1]<n/2){
                    while(mo>0&&mp[1].count(mo))mo-=2;
                    if(mo<=0){
                        cout<<-1;return;
                    }
                    mp[1][mo].push_back(_.back());
                    a[_.back()]=mo;
                    _.pop_back();
                    cnt[1]++;
                }
                res++;
            }
        }
        if(cnt[1]>n/2){
            for(auto&_:vec[1]){
                if(cnt[1]==n/2)break;
                while(me>0&&mp[0].count(me))me-=2;
                if(me<=0){
                    cout<<-1;return;
                }
                mp[0][me].push_back(_.back());
                a[_.back()]=me;
                _.pop_back();
                cnt[1]--;
                cnt[0]++;
                res++;
            }
        }
        for(auto&_:vec[0]){
            while(_.size()>1){
                while(me>0&&mp[0].count(me))me-=2;
                if(me<=0){
                    cout<<-1;return;
                }
                mp[0][me].push_back(_.back());
                a[_.back()]=me;
                _.pop_back();
                res++;
            }
        }
    }
    cout<<res<<'\n';
    for(auto&i:a)cout<<i<<' ';
}
signed main(){
    ios::sync_with_stdio(0);cin.tie(0);
    // int t;cin>>t;while(t--)
    solve();
}