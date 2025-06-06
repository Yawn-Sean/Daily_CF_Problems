#include<bits/stdc++.h>

using namespace std;
#define int long long
void solve()
{
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    int n;
    fin>>n;
    std::vector<int> a(n);
    for(int i=0;i<n;i++){
        fin>>a[i];
    }
    int x1=0,x2=0;
    int m;
    fin>>m;
    std::vector<int> b(m);
    for(int i=0;i<m;i++){
        fin>>b[i];
    }
    for(int i=1;i<n;i++){
        if(a[i]!=a[i-1]){
            x1++;
        }
    }
    for(int i=1;i<m;i++){
        if(b[i]!=b[i-1]){
            x2++;
        }
    }
    std::vector<int> c;
    if(x1>x2||(x1==x2&&a[0]==0)){
        int j=0;
        for(int i=0;i<n;i++){
            c.push_back(i+1);
            while(j<m&&b[j]==a[i]){
                c.push_back(j+1+n);
                j++;
            }
        }
        while(j<m){
            c.push_back(j+1+n);
            j++;
        }
    }
    else{
        int i=0;
        for(int j=0;j<m;j++){
            c.push_back(j+n+1);
            while(i<n&&a[i]==b[j]){
                c.push_back(i+1);
                i++;
            }
        }
        while(i<n){
            c.push_back(i+1);
            i++;
        }
    }
    std::vector<int> ans;
    int last=-1;
    int sum=0;
    auto get=[&](int i)->int{
        if(i>n){
            return b[i-n-1];
        }
        else{
            return a[i-1];
        }
    };
    for(int i=0;i<n+m;i++){
        if(last!=get(c[i])){
            if(sum!=0){
                ans.push_back(sum);
            }
            sum++;
            last=get(c[i]);
        }
        else{
            sum++;
        }
    }
    if(get(c[n+m-1])!=0){
        ans.push_back(n+m);
    }
    for(int i=0;i<n+m;i++){
        fout<<c[i]<<" \n"[i==n+m-1];
    }
    fout<<ans.size()<<endl;
    for(auto x:ans){
        fout<<x<<" ";
    }
    fout<<endl;
}
signed main()
{
    
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    int t=1;
    while(t--)
    solve();
    return 0;
}
