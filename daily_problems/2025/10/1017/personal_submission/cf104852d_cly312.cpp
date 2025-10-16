#include<bits/stdc++.h>
using namespace std;
const int L=1e9;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin>>n;
    vector<int>f;
    for(int d1=0;d1<=9;++d1){
        for(int d2=d1;d2<=9;++d2){
            for(int len=1;len<=10;++len){
                int mx=1<<len;
                for(int m=0;m<mx;++m){
                    long long v=0;
                    bool ok=1;
                    for(int p=len-1;p>=0;--p){
                        int b=(m>>p)&1;
                        int d=b?d2:d1;
                        if(p==len-1&&d==0&&len>1){
                            ok=0;
                            break;
                        }
                        v=v*10+d;
                    }
                    if(!ok) continue;
                    if(v>L) continue;
                    f.push_back((int)v);
                }
            }
        }
    }
    sort(f.begin(),f.end());
    f.erase(unique(f.begin(),f.end()),f.end());
    long long ans=0;
    int h=n/2;
    for(int a:f){
        if(a>h) break;
        if(binary_search(f.begin(),f.end(),(int)(n-a))) ++ans;
    }
    cout<<ans<<'\n';
}
