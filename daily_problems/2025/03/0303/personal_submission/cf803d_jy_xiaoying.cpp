#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/803/D
//格式化： ctrl+shift+ a

int k;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>k;
	cin.ignore();
	getline(cin, s);

	vector<int> nums;
	int cnt=0;
	int l=1,r=s.size()+10;

	for(char ss:s) {
		cnt+=1;
		if(ss==' ' || ss=='-') {
			nums.emplace_back(cnt);
			l=max(l,cnt);
			cnt=0;
		}
	}

	if(cnt!=0) {
		nums.emplace_back(cnt);
		l=max(l,cnt);
	}


	int ans;

	auto is_ok=[&](int len)->bool {
		int sum=0;
		int counts=1;
		for(int y:nums) {
			if(sum+y>len) {
				counts+=1;
				sum=y;
			} else
				sum+=y;
		}
		return counts<=k;
	};

	while(l<=r) {
		int mid=(l+r)>>1;
		if(is_ok(mid)) {
			ans=mid;
			r=mid-1;
		} else {
			l=mid+1;
		}
	}

	cout<<ans<<endl;

//    for(int x:nums){
//    	cout<<x<<" ";
//	}

	return 0;
}
