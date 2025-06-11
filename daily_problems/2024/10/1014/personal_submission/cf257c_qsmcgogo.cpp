#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<vector<int>>q;

vector<pair<double,double>>p;
// (x,y) cos：x/sqrt(x*x+y*y);
double f(pair<int,int>a){
    double x=a.first,y=a.second;
    if(abs(y)<=0.0000001){
        if(x>0)return 0;
        return acos(-1);
    }
    if(y>0){
        double z=sqrt(x*x+y*y);
        double t=acos(x/z);
        return t;
    }
    x*=-1,y*=-1;
    double z=sqrt(x*x+y*y);
    double t=acos(x/z);
    t+=acos(-1);
    return t;
}
bool cmp(pair<double,double>a,pair<double,double>b){
    double t=f(a),tt=f(b);
    return t<tt;
}

signed main(){
    ios::sync_with_stdio(false);cin.tie(0);
    int m,t,s,n,i,j,k,x;
    cin>>n;
    for(i=0;i<n;i++){
        double x,y;
        cin>>x>>y;
        if(abs(x)>0.5||abs(y)>0.5)p.push_back({x,y});
    }
    sort(p.begin(),p.end(),cmp);
    double mi=0;
    n=p.size();
    double pi=acos(-1);
    for(i=0;i<n;i++){
        double t1=f(p[i]),t2=f(p[(i-1+n)%n]);
        if(t1<t2)t1+=2*acos(-1);
        mi=max(mi,t1-t2);
    }
    //需要特判共线
    if(abs(f(p[0])-f(p.back()))<0.000000001)return cout<<0,0;
    mi=(2*acos(-1)-mi)/(2*acos(-1))*360;
    printf("%.9f\n",mi);
    
    
}
