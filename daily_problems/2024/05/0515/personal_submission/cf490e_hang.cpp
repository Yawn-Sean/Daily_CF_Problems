#include<iostream>
#include<string>
int n;
std::string st[100005];
int put(std::string &x,std::string lst)
{
	if (x.size()<lst.size()) return 0;
	if (x.size()>lst.size()){
		int first=1;
		for (int i=0;i<x.size();i++)
		{
			if (x[i]=='?'){if (!first) x[i]='0';else x[i]='1';}
			if (x[i]!='0'&&x[i]!='?') first=0;
		}
		return 1;
	}
	int first=1,opt=0;
	for (int k=0;k<x.size();k++){
		if (x[k]!='?'){
			if (first&&x[k]=='0') return 0;
			if (x[k]!='0') first=0;
			if (x[k]<lst[k]&&!opt) return 0;
			if (x[k]>lst[k]) opt=1;
			continue;
		}
		if (opt==1){
            x[k]='0';
            continue;
        }
		int can=0;
		for (int i='0';i<='9';i++){
			if (first&&i=='0') continue;
			int flag=0;
			x[k]=i;
			for (int j=k;j<x.size();j++)
				if (x[j]=='?'&&lst[j]!='9'||x[j]!='?'&&x[j]>lst[j]){flag=1;break;}
				else if (x[j]!='?'&&x[j]<lst[j]) break;
			if (flag){can=1;break;}
		}
		if (!can) return 0;
		if (x[k]!='0') first=0;
		if (x[k]>lst[k]) opt=1;
	}
	return opt;
}
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) std::cin>>st[i];
	st[0]="";
	for (int i=1;i<=n;i++) if (!put(st[i],st[i-1])) return puts("NO"),0;
	puts("YES");
	for (int i=1;i<=n;i++) std::cout<<st[i]<<'\n';
	return 0;
}