#include<bits/stdc++.h>

using namespace std;
using i64 = long long;
using u64 =long long;
using d64= double;
using ld64= long double;
#define endl '\n'

void solve(){
    int n;
    std::cin>>n;
    std::vector<std::pair<int,int>> a(2*n);
    std::vector<std::deque<int>> b(100);
    std::vector<int> c(2*n,0);
    for(int i=0;i<2*n;i++){
        std::cin>>a[i].first;
        b[a[i].first].push_back(i);
        a[i].second=i;
    }
    int flag=0;
    int sum1=0;
    int sum2=0;
    int x1=0;
    int x2=0;
    int last=0;
    std::set<int> s1,s2;
    for(auto &x:b){
        if(x.size()>=2){
            int t=x.front();
            c[t]=1;
            sum1++;
            s1.insert(a[t].first);
            x.pop_front();
            t=x.front();
            c[t]=2;
            sum2++;
            s2.insert(a[t].first);
            x.pop_front();
        }
        else if(x.size()>=1){
            int t=x.front();
            if(sum1>sum2){
                sum2++;
                c[t]=2;
                s2.insert(a[t].first);
                x.pop_front();
            }
            else{
                sum1++;
                c[t]=1;
                s1.insert(a[t].first);
                x.pop_front();
            }
        }
    }
    for(int i=0;i<2*n;i++){
        if(c[i]==0){
            if(sum1>sum2){
                c[i]=2;
                sum2++;
            }
            else{
                c[i]=1;
                sum1++;
            }
        }
    }
    std::cout<<s1.size()*s2.size()<<endl;
    for(int i=0;i<2*n;i++){
        std::cout<<c[i]<<" ";
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
