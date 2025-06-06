#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/923/C
//格式化： ctrl+shift+ a


const int MAX=3e5+10;

int tree[MAX*32][2];
int pass[MAX*32];
int cnt;

int a[MAX];
int b[MAX];
int n;

void insert_num(int x) {
	int id=1;
	pass[id]++;
	for(int i=31; i>=0; i--) {
		int j=(x>>i) & 1;        // 获得x的第i位比特 
		if(tree[id][j]==0) {
			tree[id][j]=(++cnt);
		}
		id=tree[id][j];
		pass[id]++;
	}
}

int find_ans(int x) {
	int ans=0;
	int id=1;
	pass[id]--;
	for(int i=31; i>=0; i--) {
		int tar=(x>>i) & 1;        // 获得x的第i位比特
		if(pass[tree[id][tar]]==0) {
			tree[id][tar]=0;
			tar= tar==1?0:1;
		}
		id=tree[id][tar];
		pass[id]--;
		if(tar==1)
			ans=ans|(1<<i);
	}
	return ans;
}

void build() {
	cnt=1;
	for(int i=0; i<MAX*32; i++) {
		pass[i]=0;
		tree[i][0]=tree[i][1]=0;
	}
	for(int i=0; i<n; i++)
		insert_num(b[i]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin>>n;
	for(int i=0; i<n; i++) cin>>a[i];
	for(int i=0; i<n; i++) cin>>b[i];

	build();
	
	vector<int> res;
	for(int i=0;i<n;i++){
		int tmp=a[i] ^ (find_ans(a[i]));
		res.push_back(tmp);
	}
	
	for(int x:res) cout<<x<<" ";
	cout<<endl;

	return 0;
}
