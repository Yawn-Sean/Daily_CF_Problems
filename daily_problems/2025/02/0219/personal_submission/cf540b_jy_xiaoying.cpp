#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/540/B
//格式化： ctrl+shift+ a

const int MAX=1010;
//int nums[MAX];
int n,k,p,x,y;    //总分数不能超过x，中位数必须>=y 
int sum;
int cnts;         // >=y 的元素个数 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	sum=0;
	cnts=0;
	int tmp;
	cin>>n>>k>>p>>x>>y;
	for(int i=0;i<k;i++){
		cin>>tmp;
		sum+=tmp;
		if(tmp>=y) cnts++;
	}
	
	if(x-sum<n-k){
		cout<<"-1"<<endl;
		return 0;
	}
	
	tmp=max(0,(n+1)/2-cnts);
	if(tmp>n-k ||  x-sum-tmp*y<n-k-tmp){
		cout<<"-1"<<endl;
		return 0;
	}
	
	for(int i=0;i<tmp;i++){
		cout<<y<<" ";
	}
	for(int i=0;i<n-k-tmp;i++){
		cout<<1<<" ";
	}
	cout<<endl;
	
	return 0; 
}	

/*

5 3 5 25 4
3 3 3

*/
	
