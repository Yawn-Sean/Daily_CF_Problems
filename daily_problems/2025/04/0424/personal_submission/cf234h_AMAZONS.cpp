#include<bits/stdc++.h>
using namespace std;
const int N =2e5 + 10;
const int mod=1e9+7;
typedef long long ll;
void solve(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");
	int n,m;fin>>n;vector<int> v1(n+1);
    for(int i=1;i<=n;i++)fin>>v1[i];
    fin>>m;vector<int> v2(m+1);
    for(int i=1;i<=m;i++)fin>>v2[i];
    v1.push_back(0);v2.push_back(0);//为最后成为全0序列
    int c1=0,c2=0;
    for(int i=1;i<=n;i++){
        if(v1[i]!=v1[i+1])c1++;
    }
    for(int i=1;i<=m;i++)
    if(v2[i]!=v2[i+1])c2++;
    vector<int> s,ans;
    if(c1>c2)
    {
        
        int p=1;
        for(int i=1;i<=n;i++)
        {
            while(p<=m&&v1[i]==v2[p]){
                s.push_back(v2[p]);
                ans.push_back(p+n);
                p++;
            }
            // cout<<v1[i]<<endl;
            ans.push_back(i);
            s.push_back(v1[i]);

        }

        while(p<=m){
            s.push_back(v2[p]);
            ans.push_back(p+n);
            p++;
        }

    }
    else 
    {
        // cout<<9;
        int p=1;
        for(int i=1;i<=m;i++)
        {
            while(p<=n&&v2[i]==v1[p]){
                // cout<<i<<endl;
                s.push_back(v1[p]);
                ans.push_back(p);
                p++;
            }
            ans.push_back(i+n);
            s.push_back(v2[i]);
        }
        while(p<=n){
            s.push_back(v1[p]);
            ans.push_back(p);
            p++;
        }
    }
    for(auto &it:ans)fout<<it<<" ";
    fout<<endl;
    vector<int> idx;
    s.push_back(0);
    for(int i=1;i<=n+m;i++)
    {
        // cout<<s[i];
        if(s[i]!=s[i-1])idx.push_back(i);
    }
    // cout<<endl<<endl;
    fout<<idx.size()<<endl;
    for(auto it: idx)
    {fout<<it<<" ";}
}
int main(){
    int t=1;
    // cin>>t;
    while(t--)
    {solve();}
    return 0;
}
