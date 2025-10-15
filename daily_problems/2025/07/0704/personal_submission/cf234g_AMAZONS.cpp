#include<bits/stdc++.h>
using namespace std;
const int N =2e5 + 10;
const int mod=1e9+7;
#define int long long
void solve(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");
	int n;fin>>n;
    int l=(ceil(log2(n)));
    vector<int> v[l+1];
    fout<<l<<endl;

    for(int i=1;i<=n;i++){
        for(int j=0;j<l;j++){
            if((i>>j)&1){
                v[j].push_back(i);
            }
        }
    }
    for(int i=0;i<l;i++){
        fout<<v[i].size()<<" ";
        for(auto x:v[i]){
            fout<<x<<" ";
        }
        fout<<endl;
    }
    fout<<endl;
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
