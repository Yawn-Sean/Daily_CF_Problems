#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/613/B

//       最大化的二元线性函数，固定其中一个数值+ 二分另一个
//思路：

//日期：  2024-4-9
//格式化： ctrl+shift+ a


const int MAX=1e5+10;
typedef long long ll;
typedef pair<ll,int> pp;  // 数值 - 原数组下标

pp nums[MAX];
ll ans[MAX];
ll sum[MAX];
ll n,A,cf,cm,m;

void solve() {
	
	if(m>=n*A-sum[n]){
		cout<<n*cf+A*cm<<endl;
		for(int i=0;i<n;i++){
			cout<<A<<" ";
		}
		cout<<endl;
		return ;
	}
	
	int cnt;
	ll big;
	int id;
	ll res=-1000000;
	for(int i=0; i<n; i++) {
		ll coins=sum[n]-sum[n-i];
		coins=i*A-coins;       //升满 i 个技能所需要的钱币 
		if(coins>m) break;
		
		coins=m-coins;         // 升满 i 个技能后剩下的钱币

		//cout<<"000"<<endl;

		ll l=nums[0].first,r=A-1;
		while(l<=r) {
			ll mid=(l+r)/2;

			int LL=0,RR=n-i-1;
			int ANS=-1;
			while(LL<=RR) {
				int MM=(LL+RR)/2;
				if(nums[MM].first<=mid) {
					LL=MM+1;
					ANS=MM;
				} else {
					RR=MM-1;
				}
			}
            //cout<<ANS<<endl;
			ll tmp_cost=(ANS+1)*mid-sum[ANS+1]; 
			
			if(tmp_cost>coins) {
				r=mid-1;
				//cout<<"666"<<endl;
				
			} else {
				l=mid+1;
				ll tmp_res=i*cf+mid*cm;
				
				//cout<<tmp_res<<" "<<i<<" "<<mid<<" "<<endl;
				
				if(tmp_res>res) {
					res=tmp_res;
					cnt=i;
					big=mid;
					id=ANS;
				}
			}

		}
	}

	for(int i=n-cnt; i<n; i++) {
		nums[i].first=A;
	}
	for(int i=0; i<=id; i++) {
		nums[i].first=big;
	}

	for(int i=0; i<n; i++) {
		int id=nums[i].second;
		ans[id]=nums[i].first;
	}

	cout<<res<<endl;
	for(int i=0; i<n; i++) {
		cout<<ans[i]<<" ";
	}
	cout<<endl;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>n>>A>>cf>>cm>>m;

	ll tmp;
	for(int i=0; i<n; i++) {
		cin>>tmp;
		nums[i]=pp(tmp,i);
	}

	sort(nums,nums+n,[&](const pp &a,const pp &b) {
		return a.first<b.first;
	});

	sum[0]=0;
	for(int i=0; i<n; i++) {
		sum[i+1]=sum[i]+nums[i].first;
	}

	solve();

	return 0;
}
/*

2 6 0 1 4
5 1


*/

