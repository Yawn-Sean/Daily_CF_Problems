//链接：https://codeforces.com/problemset/problem/1119/D  

#include<bits/stdc++.h>
using namespace std;

const int MAX=1e5+10;
typedef unsigned long long  ll;

const ll inf=1e18+100;
ll arr[MAX];
ll len[MAX];
ll sum[MAX];
int q,n;
ll ans[MAX];
ll l,r;

void build(){
	sort(arr,arr+n);
	for(int i=0;i<n-1;i++){
		len[i]=arr[i+1]-arr[i];
	}
	len[n-1]=inf;
	sort(len,len+n);
	sum[0]=len[0];
	for(int i=1;i<n;i++){
		sum[i]=sum[i-1]+len[i];
	}
}

ll f(){
	ll res=0;
	ll tar=r-l+1;
	int a=0,b=n-1;
	int id=0;
	while(a<=b){
		int mid=(a+b)>>1;
		if(len[mid]<=tar){
			a=mid+1;
			id=a;
		}
		else{
			b=mid-1;
		}
	}
	//cout<<id<<endl;
	if(id-1>=0){
		res=sum[id-1];
	}
	res+=(n-id)*tar;
	return res;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	build();
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>l>>r;
		ans[i]=f();
	}
	
	for(int i=0;i<q;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 

/*

6
3 1 4 1 5 9
3
7 7
0 2
8 17

2
1 500000000000000000
2
1000000000000000000 1000000000000000000
0 1000000000000000000


*/ 
