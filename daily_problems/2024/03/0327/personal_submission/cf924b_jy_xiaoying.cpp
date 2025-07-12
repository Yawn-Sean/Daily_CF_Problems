#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/924/B

//  贪心 + 滑窗  
//

//日期： 2024-3-27
//格式化： ctrl+shift+ a

const int MAX=1e5+10;
typedef long double ld;

ld power[MAX];
int n;
ld u;

void f(){
	ld ans=-1;
	for(int i=0,j=0;i<n;i++){     //左闭右开区间：[i,j)
		while(j<n && power[j]-power[i]<=u){
			j++;
		}
		ld a=0;
		if(i+1<n) a=power[j-1]-power[i+1];
		ld b=power[j-1]-power[i];
		
		if(b!=0){
			ans=max(ans,a/b);
		}
	}
	if(ans==0) ans=-1;  //特判 
	cout<<fixed<<setprecision(9)<<ans<<endl;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    
    cin>>n>>u;
    for(int i=0;i<n;i++) cin>>power[i];
    
    f();

	return 0;
}
/*


*/

