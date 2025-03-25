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
using i64=long long;
using u64=unsigned long long;

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    if(n==0){
        cout<<"YES"<<endl;
        cout<<1<<endl;
        cout<<1<<endl;
        cout<<3<<endl;
        cout<<3<<endl;
    }
    else if(n==1){
        cout<<"YES"<<endl;
        cout<<2*a[0]<<endl;
        cout<<2*a[0]<<endl;
        cout<<3*a[0]<<endl;
    }
    else if(n==2){
        
        for(int i=1;i<=1500;i++){
            for(int j=1;j<=1500;j++){
                vector<int> c=a;
                c.push_back(i);
                c.push_back(j);
                sort(c.begin(),c.end());
                if(4*c[0]==c[1]+c[2]){
                    if(3*c[0]==c[3]){
                        cout<<"YES"<<endl;
                        cout<<i<<endl;
                        cout<<j<<endl;
                        return; 
                    }
                }
            }
        }
        cout<<"NO"<<endl;
    }
    else if(n==3){
        if(a[2]==3*a[0]){
            if(4*a[0]>a[1]&&a[0]<=4*a[0]-a[1]){
                cout<<"YES"<<endl;
                cout<<4*a[0]-a[1]<<endl;
            }
            else{
                cout<<"NO"<<endl;
            }
        }
        else{
            int t=a[2]/3;
            if(3*a[0]>a[2]){
                if(4*a[0]==a[1]+a[2]){
                    cout<<"YES"<<endl;
                    cout<<3*a[0]<<endl;
                }
                else if(t*3==a[2]){
                    if(t*4==a[0]+a[1]){
                        cout<<"YES"<<endl;
                        cout<<t<<endl;
                    }
                    else{
                        cout<<"NO"<<endl;
                    }
                }
                else{
                    cout<<"NO"<<endl;
                }
            }
            else{
                if(t*3==a[2]){
                    if(t*4==a[0]+a[1]){
                        cout<<"YES"<<endl;
                        cout<<t<<endl;
                    }
                    else{
                        cout<<"NO"<<endl;
                    }
                }
                else{
                    cout<<"NO"<<endl;
                }
            }
        }
    }
    else if(n==4){
        
        if(4*a[0]!=a[1]+a[2]){
            cout<<"NO"<<endl;
            return ;
        }
        if(3*a[0]!=a[3]){
            cout<<"NO"<<endl;
            return ;
        }
        cout<<"YES"<<endl;
    }

}
int main() {
    std::cin.tie(0);
    std::cout.tie(0);
    std::ios::sync_with_stdio(false);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
