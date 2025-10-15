#include<bits/stdc++.h>
using namespace std;
const int N =2e5 + 10;
const int mod=1e9+7;
#define int long long
void solve(){
	int n;cin>>n;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){cin>>v[i];}
    int first=v[1];
    int ans=first;set<int> st;int maxi=0;
    for(int i=1;i<=n;i++){
        while(st.count(v[i])){
            st.erase(v[i]);
            v[i]++;
            
        }
        maxi=max(maxi,v[i]);
        st.insert(v[i]);
    }
    cout<<maxi-st.size()+1<<endl;

}
signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--)
    {solve();}
    return 0;
}
