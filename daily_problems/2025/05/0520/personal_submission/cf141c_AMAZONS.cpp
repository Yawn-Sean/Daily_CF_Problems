#include<bits/stdc++.h>
using namespace std;
const int N =2e5 + 10;
const int mod=1e9+7;
typedef long long ll;
void solve(){
	int n;cin>>n;
    vector<pair<int,int>> vp(n+1);
    vector<string> name(n+1);vector<int> height(n+1);
    for(int i=1;i<=n;i++){
        string s;int x;cin>>s>>x;
        name[i]=s;
        vp[i]={x,i};
    }
    int cur=5000;
    sort(vp.begin()+1,vp.end());
    vector<int> v;
    for(int i=1;i<=n;i++){
        // if(vp[i].first>=i){
        //     cout<<-1<<endl;return ;
        // }
        int pos=vp[i].first;
        int idx=vp[i].second;
        int c = (int)v.size();
        if (pos > c) {
            cout << "-1\n";
            return;
        }
        height[idx]=cur--;
        vector<int> nv;
        for(int j=0;j<pos;j++){
            nv.push_back(v[j]);
        }
        nv.push_back(vp[i].second);
        for(int j=pos;j<v.size();j++){
            nv.push_back(v[j]);
        }
        v=nv;
    }
    for(int i=0;i<n;i++){
        int pos=v[i];
        cout<<name[pos]<<" "<<height[pos]<<endl;
    }

}
int main(){
    int t=1;
    // cin>>t;
    while(t--)
    {solve();}
    return 0;
}
