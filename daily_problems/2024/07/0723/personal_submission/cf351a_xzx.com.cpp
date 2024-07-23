#include<bits/stdc++.h>
using namespace std;
const int N=4e3+10;
double a[N],b,ans1,sum,sum1,ans=1e9;
int cnt;
int main()
{
    int n;cin>>n;
    for(int i=1;i<=2*n;i++){
	cin>>a[i],b=a[i]-(int)a[i],sum+=b,sum1+=a[i];
	if(b==0)cnt++;
	}
   	for(int i=0;i<=min(cnt,n);i++){
   			ans=min(ans,abs(n-i-sum));//向下：x-b,向上：x+1-b//x =>> 假设让i个整数向上取整得 sum1-(sum1+n-i-sum) 
	   }
    printf("%.3lf",ans);
    return 0;
}
