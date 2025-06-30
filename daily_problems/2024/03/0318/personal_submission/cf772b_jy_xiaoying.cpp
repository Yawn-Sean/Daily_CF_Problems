#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/772/B

//  计算几何 + 求三角形面积 + 凸边形的性质 
//   

//日期： 2024-3-18 
//格式化： ctrl+shift+ a

const int MAX=1e3+10;
typedef long double ld; 

ld x[MAX];
ld y[MAX];
int n;

void f(){
	ld ans=-1;
	for(int i=0;i<n;i++){
		int j=(i-1+n)%n;
		int k=(i+1)%n;
		ld x1=x[i],y1=y[i];
		ld x2=x[j],y2=y[j];
		ld x3=x[k],y3=y[k];
		
		ld tmp=sqrt((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
		ld s=abs((x2-x1)*(y3-y1)-(x3-x1)*(y2-y1));  //2倍面积
		
		if(ans==-1)
		ans=s/tmp;
		else
		ans=min(ans,s/tmp); 
	}
	
	ans/=2;
	cout<<fixed<<setprecision(10)<<ans<<endl;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    cin>>n;
    for(int i=0;i<n;i++){
    	cin>>x[i]>>y[i];
	}
	f();
 
	return 0;
}
/*


*/

