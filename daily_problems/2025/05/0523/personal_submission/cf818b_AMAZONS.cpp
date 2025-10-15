#include<bits/stdc++.h>
using namespace std;
const int N =2e5 + 10;
const int mod=1e9+7;
typedef long long ll;
// a记录某一位置的答案，vis记录每一答案的位置
void solve(){
	int n,m;cin>>n>>m;
    int l[m+1];
    for(int i=1;i<=m;i++)cin>>l[i];
    vector<int> a(n+1,-1),cnt(n+1,0),vis(n+1,-1);
    for(int i=2;i<=m;i++){
        int tmp=(l[i]-l[i-1]+(n-1))%n+1;
        if(a[l[i-1]]!=-1&&a[l[i-1]]!=tmp){cout<<-1<<endl;return ;}
        if(vis[tmp]!=-1&&vis[tmp]!=l[i-1]){cout<<-1<<endl;return ;}
        a[l[i-1]]=tmp,vis[tmp]=l[i-1];
        // cout<<l[i-1]<<" "<<tmp<<endl;
    }
    int x=1;
    for(int i=1;i<=n;i++){
        if(a[i]==-1){
            while(vis[x]!=-1)x++;
            a[i]=x;vis[x]=i;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

}
int main(){
    int t=1;
    // cin>>t;
    while(t--)
    {solve();}
    return 0;
}
