#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<long long> a(n),b(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++) cin>>b[i];
    auto f=[](vector<long long>v){
        sort(v.begin(),v.end());
        long long s=0,p=0;
        for(int i=0;i<v.size();i++){
            s+=i*v[i]-p;
            p+=v[i];
        }
        return s;
    };
    long long x=f(a),y=f(b),u=0,v=0;
    for(int i=0;i<n;i++){
        u=a[i]+b[i];
        v=a[i]-b[i];
    }
    vector<long long> c(n),d(n);
    for(int i=0;i<n;i++){
        c[i]=a[i]+b[i];
        d[i]=a[i]-b[i];
    }
    long long s1=f(c),s2=f(d);
    cout<<2*(x+y)-(s1+s2)<<'\n';
    return 0;
}
