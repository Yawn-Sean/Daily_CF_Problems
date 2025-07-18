#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/852/B

//
//     矩阵快速幂优化dp

//日期： 2024-4-4
//格式化： ctrl+shift+ a

const int MAX=1e6+10;
typedef long long ll;
const ll mod=1e9+7;
typedef vector<ll> vv;

int n,m,k;
ll a[MAX];
ll mid[MAX];
ll b[MAX];

vector<vv> multiply(vector<vv> &v1,vector<vv> &v2) {
	int len1=v1.size(),len2=v2[0].size();   // v1:(len1,len)  v2:(len,len2)  (行，列)
	int len=v1[0].size();

	vector<vv> res=vector<vv>(len1,vv(len2,0));

	for(int i=0; i<len1; i++) {
		for(int j=0; j<len2; j++) {
			ll tmp=0;
			for(int ft=0; ft<len; ft++) {
				tmp+=v1[i][ft]*v2[ft][j];
				tmp%=mod;
			}
			res[i][j]=tmp;
		}
	}
	return res;
}

vector<vv> q_pow(vector<vv> &v,int cnt) {
	int len=v.size();
	vector<vv> res=vector<vv>(len,vv(len,0));
	for(int i=0; i<len; i++) {
		res[i][i]=1;
	}
	while(cnt) {
		if(cnt & 1) res=multiply(res,v);
		cnt/=2;
		v=multiply(v,v);
	}
	return res;
}

void f() {
	vector<vv> star(1,vv(k,0));
	for(int i=0; i<n; i++) {
		int tmp=a[i]%k;
		star[0][tmp]++;
		star[0][tmp]%=mod;
	}

	vector<vv> base(k,vv(k,0));

	vector<int> cnt(k,0);
	for(int i=0; i<n; i++) {
		int tmp=mid[i]%k;
		cnt[tmp]+=1;
	}

	for(int i=0; i<k; i++) {

		for(int j=0; j<k; j++) {
			int id=(j+i)%k;
			base[i][id]+=cnt[j];  //前面的状态为 i 加入了 j 的变量 ！! ! 所以 +=cnt[j]
			base[i][id]%=mod;
		}
	}

	vector<vv> tmp_base=q_pow(base,m-2);
	vector<vv> ans=multiply(star,tmp_base);

//	for(int i=0; i<k; i++) cout<<ans[0][i]<<" ";
//	cout<<endl;

	ll res=0;
	for(int i=0; i<n; i++) {
		int tmp=k-(mid[i]+b[i])%k;
		tmp%=k;
		res+=ans[0][tmp];
		res%=mod;
	}
	cout<<res<<endl;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>n>>m>>k;
	for(int i=0; i<n; i++) {
		cin>>a[i];
	}

	for(int i=0; i<n; i++) {
		cin>>mid[i];
	}

	for(int i=0; i<n; i++) {
		cin>>b[i];
	}

	f();

	return 0;
}
/*


*/

