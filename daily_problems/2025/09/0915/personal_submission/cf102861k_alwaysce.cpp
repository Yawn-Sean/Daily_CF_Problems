#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 MOD = 1000000007;

/*
例如
4 4
4 2
1 3
2 3
1 4
输出YES
可以划分成[1,4] 和[2,3] 这样每个组内每个人都有奇数个朋友
*/
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int P, F;
  cin >> P >> F;

  __int128_t one = 1;
  vector<int> cnt(P + 1);
  vector<__int128_t> friends(P + 1);
  for (int i = 0; i < F; i++) {
    int a, b;
    cin >> a >> b;
    friends[a] |= (one << b);
    friends[b] |= (one << a);
    
    cnt[a] ^= 1;
    cnt[b] ^= 1;
  }


  // 分组有两种可能 一种是0/ 一种是1
  // x[i]=0表示第i个人被分在了第一组 x[i]=1表示第i个人被分在了第二组
  for (int i = 1; i <= P; i++) {
    if (cnt[i]) {
      friends[i] |= (one << i); // xi +x_t1+...+x_tk = 0
    } else {
      friends[i] |= 1; // x_t1+...+x_tk = 1
    }
  }

  // 系数 | 常数项
  // P <= 100 所以可以用128位整数来存储
  vector<__int128_t> basis(P + 1);
  for (auto& x : friends) {
    for (int i = P; i >= 0; i--) {
      // basis[i] 存“最高位在 i 的一行”。
      // 按 i 从大到小插入，每行最终要么被已有主元消成 0，要么以其最高 1 成为新的主元行
      if (x >> i & 1) {
        if (basis[i]) {
          x ^= basis[i];
        } else {
          basis[i] = x;
          break;
        }
      }
    }
  }
  cout << (basis[0] ? "N" : "Y") << endl;
  
  return 0;
}
