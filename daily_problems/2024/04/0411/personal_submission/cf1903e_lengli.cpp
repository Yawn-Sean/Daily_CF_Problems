/*
lengli_QAQ
Hope there are no bugs!!!
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(),x.end()
#define pb push_back

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) "lengli"
#endif

const int N=100010;

void solve(){
    int n;
    cin>>n;
    int sx,sy;
    cin>>sx>>sy;
    vector<array<int,2>> a(n+1);
    set<int> l,r;
    for(int i=1;i<=n;i++){
        cin>>a[i][0]>>a[i][1];
        int d=(a[i][0]+a[i][1])+(sx+sy);
        if(d%2==0) l.insert(i);
        else r.insert(i);
    }

    if(n&1){
        bool flag=0;
        if(l.size()>n/2) flag=1;
        else flag=0;
        if(flag){
            cout<<"First"<<endl;
            while(l.size() or r.size()){
                if(r.size()){
                    auto it=r.begin();
                    cout<<*it<<endl;
                    r.erase(it);
                }else{
                    auto it=l.begin();
                    cout<<*it<<endl;
                    l.erase(it);
                }
                if(l.empty() and r.empty()) return;
                int x;
                cin>>x;
                if(l.count(x)) l.erase(x);
                else r.erase(x);
            }
        }else{
            cout<<"Second"<<endl;
            while(l.size() or r.size()){
                int x;
                cin>>x;
                if(l.count(x)) l.erase(x);
                else r.erase(x);
                if(l.empty() and r.empty()) return;
                if(l.size()){
                    auto it=l.begin();
                    cout<<*it<<endl;
                    l.erase(it);
                }else{
                    auto it=r.begin();
                    cout<<*it<<endl;
                    r.erase(it);
                }
            }
        }
    }else{
        bool flag=0;
        if(l.size()>=n/2) flag=1;
        else flag=0;
        if(flag){
            cout<<"First"<<endl;
            while(l.size() or r.size()){
                if(r.size()){
                    auto it=r.begin();
                    cout<<*it<<endl;
                    r.erase(it);
                }else{
                    auto it=l.begin();
                    cout<<*it<<endl;
                    l.erase(it);
                }
                if(l.empty() and r.empty()) return;
                int x;
                cin>>x;
                if(l.count(x)) l.erase(x);
                else r.erase(x);
            }
        }else{
            cout<<"Second"<<endl;
            while(l.size() or r.size()){
                int x;
                cin>>x;
                if(l.count(x)) l.erase(x);
                else r.erase(x);
                if(l.empty() and r.empty()) return;
                if(l.size()){
                    auto it=l.begin();
                    cout<<*it<<endl;
                    l.erase(it);
                }else{
                    auto it=r.begin();
                    cout<<*it<<endl;
                    r.erase(it);
                }
            }
        }
    } 

    
}

signed main(){
    fastio;
    int T;
    cin>>T;
    while(T--) solve();
    
    return 0;
}
