#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/743/E

//   二分答案 + 状压dp
//

//日期： 2024-3-29
//格式化： ctrl+shift+ a

const int MAX=1e3+10;
typedef long long ll;
typedef vector<int> vv;

const int MAX_M=260;
const int fu_inf=INT_MIN/100;
const int is_ok=(1<<8)-1;
int dp[MAX][MAX_M];

int n;
int k;   //数字最大出现次数至少为 k 最多为 k+1
int nums[MAX];
vector<vv> id;

void init() {
	for(int i=0; i<n+5; i++) {
		for(int j=0; j<MAX_M; j++) {
			dp[i][j]=-1;
		}
	}
}

int bs(vector<int> &v,int i) {
	int l=0,r=v.size()-1;
	while(l<=r) {
		int mid=(l+r)/2;
		if(v[mid]==i)
			return mid;
		else if(v[mid]>i) {
			r=mid-1;
		} else {
			l=mid+1;
		}
	}
	return -1;
}

int dfs(int i,int j) { // 来到 i 位置，数字出现至少 k 次的状态为 j 时， 数字出现 k+1 次的数字个数
	if(j==is_ok) {
		return 0;
	}

	if(i>=n) return fu_inf;  //表示负无穷

	int x=nums[i];
	if(dp[i][j]!=-1) return dp[i][j];

	if((j & (1<<x) )!=0) {  //数字 x 满足状态 ，直接去下一个位置
		return dfs(i+1,j);
	}

	int ans=fu_inf;

	int x_id=bs(id[x],i);  //查询 x 在 id【x】 中的下标
	int len=id[x].size();
	//int limits=id[len-1];

	int p1=x_id+k;  //假设数字 x 可以出现 k+1 次
	if(p1<len) {
		int status_1= (j | (1<<x));
		int next_i_1=id[x][p1]+1;
		ans=max(ans,1+dfs(next_i_1,status_1));
	}

	int p2=x_id+k-1; //假设数字 x 可以出现 k 次
	if(p2<len) {
		int status_2= (j | (1<<x));
		int next_i_2=id[x][p2]+1;
		ans=max(ans,dfs(next_i_2,status_2));
	}

	ans=max(ans,dfs(i+1,j)); //暂时让数字 x 出现的次数不满足

	dp[i][j]=ans;
	return ans;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>n;
	id=vector<vv>(10,vv());
	int tmp;
	for(int i=0; i<n; i++) {
		cin>>tmp;
		tmp--;           //  出现数字只要 0~7 啦
		nums[i]=tmp;
		id[tmp].push_back(i);
	}

	int r=MAX;
	int l=1;
	for(int i=0; i<8; i++) {
		r=min(r,(int)id[i].size());
		//cout<<i<<" "<<id[i].size()<<endl;
	}
	
//	for(int tmp:id[7]) cout<<tmp<<" ";
//	cout<<endl;
//	cout<<bs(id[7],23)<<endl;

	int ans=0;
	if(r==0) {          //特判有数字没有出现的情况 ， 其他数字最多出现 1 次

		for(int i=0; i<8; i++) {
			if(id[i].size()>0) ans++;
		}
		cout<<ans<<endl;
		return 0;
	}

  // cout<<r<<endl;
   
	while(l<=r) {
		int mid=(l+r)/2;
		init();
		k=mid;
		int cnt=dfs(0,0);

		//cout<<mid<<" "<<cnt<<endl;

		if(cnt>=0) {
			ans=cnt*(k+1)+(8-cnt)*k;
			l=mid+1;
		} else {
			r=mid-1;
		}
	}

	cout<<ans<<endl;

	return 0;
}
/*
10
1 1 2 3 4 5 6 7 8 8


*/

