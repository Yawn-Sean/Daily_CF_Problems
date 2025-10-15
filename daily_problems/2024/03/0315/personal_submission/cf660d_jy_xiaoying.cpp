#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/660/D

//   计算平行四边形的数量

//日期： 2024-3-15
//格式化： ctrl+shift+ a

const int MAX=2e3+10;
typedef unsigned long long ll;

const ll tag1=13331;
const ll tag2=1e9+7;

ll nums[MAX][2];
int n;
ll x1,y1;
ll x2,y2;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>n;
	unordered_map<ll,ll> mp;
	ll ans=0;

	for(int i=0; i<n; i++) {
		cin>>nums[i][0]>>nums[i][1];
	}

	for(int i=0; i<n; i++) {
		x1=nums[i][0],y1=nums[i][1];
		for(int j=i+1; j<n; j++) {
			x2=nums[j][0],y2=nums[j][1];
			
			ll tmp=(x1+x2)*tag1+(y1+y2)*tag2;
			ans+=mp[tmp];
			mp[tmp]+=1;
		}

	}

	cout<<ans<<endl;

	return 0;
}
/*


*/

