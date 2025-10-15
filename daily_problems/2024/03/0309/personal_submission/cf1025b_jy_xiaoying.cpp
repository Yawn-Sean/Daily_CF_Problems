#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/1025/B
//日期： 2024-3-9
//格式化： ctrl+shift+ a

const int MAX=150010;
int a[MAX];
int b[MAX];
int n;

bool f(int x){
	vector<int> pri;
	for(int i=2;i*i<=x;i++){
		if(x%i!=0) continue;
		while(x%i==0){
			x/=i;
		}
		pri.push_back(i);
	}
	if(x>1) pri.push_back(x);
	
//	for(int x:pri) cout<<x<<" ";
//	cout<<endl;
	
	for(int x:pri){
		bool is_ok=1;
		for(int i=1;i<n;i++){
			bool flag=(a[i]%x==0) || (b[i]%x==0);
			if(flag==0) {
				is_ok=0;
				break;
			}
		}
		if(is_ok){
			cout<<x<<endl;
			return 1;
		}
	}
	return 0;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}
	
	if(n==1){
		cout<<a[0]<<endl;
		return 0;
	}
	
	if(f(a[0])){
		return 0;
	}
	if(!f(b[0])){
		cout<<"-1"<<endl;
	}

	return 0;
}


