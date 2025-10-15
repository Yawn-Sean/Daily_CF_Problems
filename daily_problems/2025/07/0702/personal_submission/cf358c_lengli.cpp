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
    int n;
    std::cin>>n;
    std::vector<int> q(n);
    for(auto &x:q) std::cin>>x;
    std::vector<int> cur;
    for(int i=0;i<n;i++){
        if(!q[i]){
            if(cur.empty()) std::cout<<0<<"\n";
            else if(cur.size()==1) std::cout<<"pushStack"<<"\n"<<"1 popStack"<<"\n";
            else if(cur.size()==2){
                std::cout<<"pushStack"<<"\n"<<"pushQueue"<<"\n"<<"2 popStack popQueue"<<"\n";
            }else{
                int x=-1,y=-1,z=-1;
                for(int i=0;i<cur.size();i++){
                    if(x==-1 or cur[i]>cur[x]) x=i;
                }
                for(int i=0;i<cur.size();i++){
                    if(i!=x and (y==-1 or cur[i]>cur[y])) y=i;
                }
                for(int i=0;i<cur.size();i++){
                    if(i!=x and i!=y and (z==-1 or cur[i]>cur[z])) z=i;
                }
                for(int i=0;i<cur.size();i++){
                    if(i==x) std::cout<<"pushStack"<<"\n";
                    else if(i==y) std::cout<<"pushQueue"<<"\n";
                    else if(i==z) std::cout<<"pushFront"<<"\n";
                    else std::cout<<"pushBack"<<"\n"; 
                }
                std::cout<<"3 popStack popQueue popFront"<<"\n";
            }
            cur.clear();
        }else cur.pb(q[i]);
    }
    for(auto x:cur) std::cout<<"pushBack"<<"\n";
}


signed main(){
    fastio;
    
    int T;
    T=1;
    while(T--) solve();
    
    return 0;
}
