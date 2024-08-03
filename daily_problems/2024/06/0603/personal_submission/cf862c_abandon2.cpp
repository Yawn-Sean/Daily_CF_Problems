#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;

void solve(){
    int n,x;cin>>n>>x;
    
    int s=0;
    if(n==1){
        cout<<"Yes\n";
        cout<<x<<"\n";
        return;
    }
    if(n==2){
        if(x==0){
            cout<<"NO\n";return;
        }
        cout<<"Yes\n";
        cout<<4<<" "<<(x^4)<<"\n";
        return;
    }
    std::vector<int> v;
    for(int i=1;i<=n-3;i++){
        s^=i;
        v.push_back(i);
    }

    int t=(1<<18);
    if(s!=x){
        v.push_back(0);
        v.push_back(t);
        v.push_back((s^x^t));
    }
    else{
        v.push_back(t);
        v.push_back(t/2);
        v.push_back((t^(t/2)));
    }
    cout<<"Yes\n";
    for(int x:v){
        cout<<x<<" ";
    }
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    return 0;
}
