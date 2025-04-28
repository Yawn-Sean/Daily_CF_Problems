#include <iostream>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<queue>
#include<vector>
#include<utility>
#include<algorithm>

using namespace std;
#define endl '\n'

void slove(){
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i].first;
        a[i].second=i;
    }
    vector<int> e(n,0);
    sort(a.begin(),a.end(),[&](pair<int,int>&a1,pair<int,int>&a2){
        return a1.first<a2.first;
    });
    vector<pair<int,int>> w;
    vector<pair<int,int>> ans;
    int wei=0;
    if(a[0].first!=0){
        cout<<-1<<endl;
        return ;
    }
    w.push_back(a[0]);
    for(int i=1;i<n;i++){
        if(e[w[wei].second]==k){
            wei++;
        }
        while(wei<i&&(a[i].first>w[wei].first+1||e[w[wei].second]>=k)){
            wei++;
        }
        if(wei==i||a[i].first!=w[wei].first+1){
            cout<<-1<<endl;
            return ;
        }
        else{
            ans.push_back({a[i].second+1,w[wei].second+1});
            w.push_back(a[i]);
            e[w[wei].second]++;
            e[a[i].second]++;
        }
    }
    cout<<ans.size()<<endl;
    for(auto &[x,y]:ans){
        cout<<x<<" "<<y<<endl;
    }
}
int main() {
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios::sync_with_stdio(false);
    int t=1;
    //cin>>t;
    while(t--){
        slove();
    }
    return 0;
}
