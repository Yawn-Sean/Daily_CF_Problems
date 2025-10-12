#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define endl "\n"

void solve(){
    int n;
    cin>>n;
    vector<int>a(n);
    vector<int>vis(n+5,0);
    deque<int>dq;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    while(!a.empty()){
        auto it=a.end();
        it--;
        while(it!=a.begin()&&distance(a.begin(),it)+1!=(*it)){
            it--;
        }
        if((*it)!=distance(a.begin(),it)+1){
            cout<<"NO"<<endl;
            return;
        }
        dq.push_front((*it));
        a.erase(it);
    }
    cout<<"YES"<<endl;
    while(!dq.empty()){
        cout<<dq.front()<<" ";
        dq.pop_front();
    }

}
 
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t=1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
