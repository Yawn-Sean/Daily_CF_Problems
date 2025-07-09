#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/986/B

//   树状数组
//

//日期： 2024-3-25
//格式化： ctrl+shift+ a

const int MAX=1e6+10;
typedef long long ll;

ll n;
ll nums[MAX];

ll tree[MAX];

ll lowbit(int x) {
	return x &(-x);
}

ll query(int i) {
	ll ans=0;
	while(i) {
		ans+=tree[i];
		i-=lowbit(i);
	}
	return ans;
}

void add(int i,ll val) {
	while(i<=n) {
		tree[i]+=val;
		i+=lowbit(i);
	}
}


void f() {
	ll ans=0;
	for(int i=1; i<=n; i++) {
		ans+= query(n)-query(nums[i]);
		add(nums[i],1);
	}

 
 // (ans%2)==((3*n)%2)    (ans&1) == ((3*n)&1)
	if( (ans%2)==((3*n)%2)){
		cout<<"Petr"<<endl;
	} else {
		cout<<"Um_nik"<<endl;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>nums[i];
	}
	f();

	return 0;
}
/*


*/

