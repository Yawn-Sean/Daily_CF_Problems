//双端队列 + meet-in-middle，好题！

#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[1202020];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int _=1;
    while(_--){
        int k,n,i,j,m,d;
        cin>>n>>d;
        int su=0;
        for(i=0;i<n;i++)cin>>a[i],su+=a[i];
        sort(a,a+n);
        deque<pair<int,int>>q;
        for(i=0;i<n;i++){
            q.push_back({a[i],1});
        }
        int pl=d,mn=d;
        while(1){
            if(q.size()==1)break;
            if(pl/q.front().second){
                pair<int,int>op=q.front();
                q.pop_front();
                pair<int,int>&temp=q.front();
                if(pl>=(temp.first-op.first)*op.second){
                    pl-=(temp.first-op.first)*op.second;
                    temp.second+=op.second;
                }
                else {
                    int cnt=pl/op.second;
                    q.push_front({op.first+cnt,op.second});
                    pl%=op.second;
                }
            }
            else if(mn/q.back().second){
                pair<int,int>ed=q.back();
                q.pop_back();
                pair<int,int>&temp=q.back();
                if(mn>=abs(temp.first-ed.first)*ed.second){
                    mn-=abs(temp.first-ed.first)*ed.second;
                    temp.second+=ed.second;
                }
                else {
                    int cnt=mn/ed.second;
                    q.push_back({ed.first-cnt,ed.second});
                    mn%=ed.second;
                }
            }
            else break;
        }
        if(q.size()==1)cout<<(su%n==0?0:1)<<'\n';
        else cout<<q.back().first-q.front().first<<'\n';


    }
    
    
}
