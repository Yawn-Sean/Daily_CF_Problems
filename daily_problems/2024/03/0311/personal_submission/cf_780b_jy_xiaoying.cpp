#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/780/B

//     二分时间
 
//日期： 2024-3-11
//格式化： ctrl+shift+ a

const int MAX=6e4+10;
typedef long long ll;
typedef long double ld;

ld nums[MAX];
ld vate[MAX];
int n;


bool bs(ld time) {
	ld max_l=nums[0]-time*vate[0];
	ld min_r=nums[0]+time*vate[0];
	for(int i=1; i<n; i++) {
		ld tmp_l=nums[i]-time*vate[i];
		ld tmp_r=nums[i]+time*vate[i];
		max_l=max(max_l,tmp_l);
		min_r=min(min_r,tmp_r);
	}
	return max_l<=min_r;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>n;
	ld tmp;

	for(int i=0; i<n; i++) {
		cin>>tmp;
		nums[i]=tmp;
	}
	for(int i=0; i<n; i++) {
		cin>>tmp;
		vate[i]=tmp;
	}

	ld l=1e-9,r=1e9;
	int cnt=50;
	while(--cnt) {
		ld mid=(l+r)/2;
		if(bs(mid)){
			r=mid;
		}
		else{
			l=mid;
		}
	}

	ld ans_1=(l+r)/2;
	cout<<fixed<<setprecision(12)<<ans_1<<endl;
	return 0;
}
/*



*/

