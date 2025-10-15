#include<bits/stdc++.h>
using namespace std;
const int N =2e5 + 10;
const int mod=1e9+7;
typedef long long ll;
void solve(){
	int n,k;cin>>n>>k;
    int b[n+1];
    for(int i=1;i<=n;i++)cin>>b[i];
    vector<int> ans;
    for(int i=n;i>=1;i--){
        vector<int> tmp;int cnt=0;
        for(auto& it:ans){
            if(cnt==b[i])
            {tmp.push_back(i);cnt++;}
            tmp.push_back(it);
            if(it>=i+k)cnt++;
        }
        if(cnt==b[i])tmp.push_back(i);
        swap(ans,tmp);
    }
    for(auto& it:ans){
        cout<<it<<" ";
    }
}
int main(){
    int t=1;
    // cin>>t;
    while(t--)
    {solve();}
    return 0;
}
