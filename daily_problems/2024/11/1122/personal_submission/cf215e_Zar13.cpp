#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
LL L, R;
LL sa[65];

int mul[65];
int z[65], idx;
bool is_z[65];

LL f1(int n){
	LL res=0;
	for(int i=2;i<=n;i++){//循环节 个数 
		if(!mul[i]) continue;
		if(n%i==0){
			int j=n/i;//循环节 长度 
			j--;
			res+=(1LL<<j)*mul[i];
		}
	}
	return res;
}
LL f2(LL x){
	if(!x) return 0; 
	int n=log2(x)+1;
	LL res=0;
	for(int i=2;i<=n;i++){
		if(!mul[i]) continue;
		if(n%i==0){
			int j=n/i;
			j--;
			LL l=-1, r=(1LL<<j) +1;
			while(l+1<r){
				LL mid=l+r>>1;
				LL t=(1LL<<j)+mid, tx=0;
				int ii=i;
				while(ii--){
					tx=(tx<<(j+1))+t;
				}
				if(tx<=x) l=mid;
				else r=mid;	
			}
			res+=(l+1)*mul[i];	
		}
	}
	return res;
}
int main(){
	//容斥 
	for(int i=2;i<65;i++){
		if(is_z[i]==0){
			z[++idx]=i;
			mul[i]=1;
			for(int j=1;j<idx&& i*z[j]<65;j++){
				mul[i*z[j]]=-1;
			}
			for(int j=2*i;j<65;j+=i){
				is_z[j]=1;
			}
		}
	}
    mul[2*3*5]=mul[2*3*7]=1;
    
	cin>>L>>R;
	L--;
	for(int i=1;i<64;i++){
		sa[i]=sa[i-1]+f1(i);
	}
	int len1=log2(max(1LL, L)), len2=log2(R);
	LL res=sa[len2]-sa[len1];
	res+=f2(R)-f2(L);
	cout<<res;
	return 0;
} 
