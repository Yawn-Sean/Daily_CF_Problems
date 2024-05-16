#include<bits/stdc++.h>
using namespace std;
 
#define d(i)abs(a[i]-a[i-1])
int a[200010];
int main(){
int n,y=1;
cin>>n>>a[0];
for(int i=1;i<n;i++)scanf("%d",&a[i]),y=max(y,d(i));
for(int i=1;i<n;i++)if(d(i)+min(a[i],a[i-1])%y==1*(y!=1)||(d(i)-1)*(d(i)-y))return cout<<"NO"&&0;
cout<<"YES\n1000000000"<<" "<<y;
}
