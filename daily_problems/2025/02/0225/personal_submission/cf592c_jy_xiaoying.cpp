#include<bits/stdc++.h>
using namespace std;

//链接：https://codeforces.com/problemset/problem/592/C
//格式化： ctrl+shift+ a

using i128 = __int128;

// 重载输入运算符以支持__int128类型

std::istream &operator>>(std::istream &is, __int128 &val) {

	std::string s;

	bool flag = true;

	is >> s, val = 0;

	if (s[0] == '-') flag = false, val = std::stoi(s.substr(0, 2)), s = s.substr(2);

	for (char &c: s) val = val * 10 + (c - '0') * (!flag ? -1 : 1);

	return is;

}

//重载输出运算符以支持__int128类型

std::ostream &operator<<(std::ostream &os, __int128 val) {

	if (val < 0) os << "-", val = -val;

	if (val > 9) os << val / 10;

	os << static_cast<char>(val % 10 + '0');

	return os;

}

i128 gcd(i128 x,i128 y) {
	return y==0?x:gcd(y,x%y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	i128 t,x,y;
	cin>>t>>x>>y;



	auto lcm=[&](i128 x,i128 y)->i128 {
		return x/gcd(x,y)*y;
	};

	i128 k=min(x,y);
	i128 zi=t/lcm(x,y)*k+min(k-1,t%lcm(x,y));
	i128 mu=t;
	i128 tmp=gcd(zi,mu);

	cout<<zi/tmp<<"/"<<mu/tmp;

	return 0;
}
