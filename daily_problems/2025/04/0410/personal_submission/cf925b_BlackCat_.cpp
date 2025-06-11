#include<bits/stdc++.h>
using namespace std;
using i64 = long long;
using u64 =long long;
using d64= double;
using ld64= long double;
#define endl '\n'

void solve(){
    int n,x,y;
    std::cin>>n>>x>>y;
    std::vector<std::pair<int,int>> a(n);
    for(int i=0;i<n;i++){
        std::cin>>a[i].first;
        a[i].second=i+1;
    }
    sort(a.begin(),a.end(),[&](std::pair<int,int> &a1,std::pair<int,int> &a2){
        return a1.first<a2.first;
    });
    std::vector<int> a1,a2;
    int flag=0;
        int j=-1;
        for(int i=n-1;i>=0;i--){
            a1.push_back(a[i].second);
            if(a[i].first*(n-i)>=x){
                j=i;
                break;
            }
        }
        if(j==-1){
            flag=1;
        }
        else{
            int h=-1;
            int t=0;
            int w=a[0].first;
            for(int i=j-1;i>=0;i--){
                a2.push_back(a[i].second);
                if(a[i].first*(j-i)>=y){
                    h=i;
                    break;
                }
            }
            if(h==-1){
                flag=1;
            }
        }
    if(flag==1){
        int j=-1;
        flag=0;
        a1.clear();
        a2.clear();
        for(int i=n-1;i>=0;i--){
            a2.push_back(a[i].second);
            if(a[i].first*(n-i)>=y){
                j=i;
                break;
            }
        }
        if(j==-1){
            flag=1;
        }
        else{
            int h=-1;
            for(int i=j-1;i>=0;i--){
                a1.push_back(a[i].second);
                if(a[i].first*(j-i)>=x){
                    h=i;
                    break;
                }
            }
            if(h==-1){
                flag=1;
            }
        }
    }
    if(flag){
        std::cout<<"No"<<endl;
    }
    else{
        std::cout<<"Yes"<<endl;
        std::cout<<a1.size()<<" "<<a2.size()<<endl;
        for(int i=0;i<a1.size();i++){
            std::cout<<a1[i]<<" \n"[i==a1.size()-1];
        }
        for(int i=0;i<a2.size();i++){
            std::cout<<a2[i]<<" \n"[i==a2.size()-1];
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    //std::cin>>t;
    while(t--){
        solve();
    }
}
