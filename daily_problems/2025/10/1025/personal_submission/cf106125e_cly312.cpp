#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int> a(n,0);
    while(1){
        int cm=0,mi=-1,c=0,m=0,L=-1,R=0;
        for(int i=0;i<n;i++){
            c+=(a[i]?-1:1);
            if(c<cm){
                cm=c;
                mi=i;
            }
            if(c-cm>m){
                m=c-cm;
                L=mi;
                R=i;
            }
        }
        cout<<L+2<<' '<<R+1<<endl;
        for(int &x:a) cin>>x;
        int v;
        cin>>v;
        if(v>=70) break;
    }
}
