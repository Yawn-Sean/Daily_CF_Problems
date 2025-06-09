#include <bits/stdc++.h>
using namespace std;
int const N = 300000 + 10;
int a1[N],a2[N];
int s1,s2,n,p,k1,k2;
struct Node
{
	int id,c;
	bool operator < (const Node& e) const{
		return c < e.c;
	}
}s[N],tmp[N];
int Move(int l,int r,int k){   //将区间[l,r]移到最后
	for(int i=r+1;i<n;i++)
		s[i-k]= s[i];
	return n - k;   //新的区间长度
}
bool solve(int &k,int &p,int a[N],int ss,int n){
	for(k=1;k<=n;k++){  //枚举k，服务器最低要求为ss/k
		p = lower_bound(s,s+n,(Node){0,(int)ceil(1.0*ss/k)}) -s ;
		if(p+k-1 < n){
			int cnt = 0;
			for(int i=p;i<=p+k-1;i++)	a[++cnt] = s[i].id;
				return true;
		}
	}	
	return false;
}
void Print(){
	printf("Yes\n");
	printf("%d %d\n",k1,k2);
	for(int i=1;i<=k1;i++)	printf("%d ",a1[i]);	printf("\n");
	for(int i=1;i<=k2;i++)	printf("%d ",a2[i]);	printf("\n");
}
int main(){
	scanf("%d%d%d",&n,&s1,&s2);
	for(int i=0;i<n;i++)
		scanf("%d",&s[i].c),	s[i].id = i+1;
	sort(s,s+n);
	bool flag = true;
	memcpy(tmp,s,sizeof(s));   //复制一份
	bool flag1 = solve(k1,p,a1,s1,n);    //先枚举k1
	int nn = Move(p,p+k1-1,k1);
	bool flag2 = solve(k2,p,a2,s2,nn);
	if(!flag1 || !flag2){
		memcpy(s,tmp,sizeof(tmp));     //复制回来，在枚举k2
		bool flag3 = solve(k2,p,a2,s2,n);
		int nn = Move(p,p+k2-1,k2);
		bool flag4 = solve(k1,p,a1,s1,nn);
		if(!flag3 || !flag4)	printf("No\n"),flag = false;
	}
	if(flag)	Print();
	return 0;
}
