#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, h;
	cin>>n>>h;
	if(n==2) cout<<"0 \n 1 1";
	else{
		int min1=1e9, min2=1e9, min3=1e9, max1=-1e9, max2=-1e9, p, t;
		for(int i=1;i<=n;i++){
			cin>>t;
			if(t<=min1) min3=min2, min2=min1, min1=t, p=i;
			else if(t<=min2) min3=min2, min2=t;
			else if(t<min3) min3=t;
			if(t>=max1) max2=max1, max1=t;
			else if(t>max2) max2=t;
		}
		bool f;
		int res, res1, res2;
		res1=max1+max2-min1-min2;
		res2=max(max1+max2, min1+max1+h)-min(min1+min2+h, min2+min3);
		if(res1>res2) f=1, res=res2;
		else f=0, res=res1;
		cout<<res<<endl;
		for(int i=1;i<=n;i++){
			if(i!=p) cout<<1<<" ";
			else{
				if(f) cout<<2<<" ";
				else cout<<1<<" ";
			}
		}
	}
}
