#include <bits/stdc++.h>
using namespace std;
char r[9], p[9];
int ar[100002];
int toint(){
	int i,ret=0;
	for(i=0;i<strlen(r);++i)
		ret= ret*10 + p[i];
	return ret;
}
int main(){
	int k,j,n,i;cin>>n;
	for(i=1;i<=n;++i){
		scanf("%s",r);
		for(j=0;j<strlen(r);++j)
			if(r[j]=='?')
				p[j]= 9;
			else
				p[j]= r[j]-'0';
		ar[i]= toint();
		if(ar[i]<=ar[i-1]){
			printf("NO\n");
			return 0;
		}
		for(j=0;j<strlen(r);++j){
			if(r[j]=='?'){
				for(k=8;k>=0;--k){
					if(j==0 &&k==0)continue;
					p[j]=k;
					if(toint()<=ar[i-1]){
						++p[j];
						break;
					}
					else
						ar[i]=toint();
				}
			}
		}
	}
	puts("YES");
	for(i=1;i<=n;++i)
		printf("%d\n",ar[i]);
}
