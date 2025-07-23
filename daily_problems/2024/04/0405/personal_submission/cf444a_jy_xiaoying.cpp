#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/444/A

//
//     贪心 + 思维 

//日期： 2024-4-5 
//格式化： ctrl+shift+ a

const int MAX=520;
typedef long double ld;
ld nums[MAX];
int n,m;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>nums[i];
	}
	ld ans=0;
	int a,b;   ld len; 
	for(int i=0;i<m;i++){
		cin>>a>>b>>len;
		ans=max(ans,(nums[a]+nums[b])/len);
	}
	
	cout<<fixed<<setprecision(15)<<ans<<endl;

	return 0;
}
/*


*/

