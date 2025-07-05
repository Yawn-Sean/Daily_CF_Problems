#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/908/C

//   计算几何 + 模拟 
//   

//日期： 2024-3-23
//格式化： ctrl+shift+ a

const int MAX=1e3+10;
typedef long double ld;

int n;
ld r;

ld x[MAX];
ld ans_y[MAX];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    cin>>n>>r;
    for(int i=0;i<n;i++){
    	cin>>x[i];
	}
	
	for(int i=0;i<n;i++){
		ans_y[i]=r;
		for(int j=0;j<i;j++){
			ld dis_x=abs(x[i]-x[j]);
			if(dis_x>2*r) continue;
			
			ld tmp=sqrt(4*r*r-dis_x*dis_x)+ans_y[j];  //   + ans_y[j]  !!!!!!!!!
			ans_y[i]=max(ans_y[i],tmp);
		}
	}
    
    for(int i=0;i<n;i++){
    	cout<<fixed<<setprecision(10)<<ans_y[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}
/*


*/

