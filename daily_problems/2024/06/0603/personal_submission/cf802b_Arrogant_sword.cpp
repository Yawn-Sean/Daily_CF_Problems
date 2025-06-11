#include <bits/stdc++.h>
using namespace std;
set<int> s;
int n,cs,k,c[400400],ne[400400],la[400400],cc;

int main(){
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++)scanf("%d",&c[i]);
	for(int i=n-1;i>=0;i--){
		if(!la[c[i]])ne[i]=1e6,la[c[i]]=i;
		else ne[i]=la[c[i]],la[c[i]]=i;
	}
	for(int i=0;i<n;i++){
		if(s.count(i)){s.erase(i),s.insert(ne[i]);continue;}
		if((int)s.size()<k)
			s.insert(ne[i]),cc++;
		else 
			s.erase(--s.end()),s.insert(ne[i]),cc++;
			
		
	}
	printf("%d\n",cc);
}
