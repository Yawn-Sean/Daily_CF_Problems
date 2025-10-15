import sys
RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())
mx = lambda x, y: x if x > y else y
mn = lambda x, y: y if x > y else x

'''
https://codeforces.com/problemset/problem/1227/C

可以构造成k - 1个() + ((((...))))，每个位置上去后面找需要的字符交换
'''

for _ in range(RI()):
    n, k = RII()
    s = list(RS())
    left = (n - 2 * k + 2) // 2
    t = '()' * (k - 1) + '(' * left + ')' * left
    ans = []
    for i in range(n):
        if s[i] != t[i]:
            for j in range(i + 1, n):
                if s[j] == t[i]:
                    s[i:j + 1] = s[i:j + 1][::-1]
                    ans.append((i + 1, j + 1))
                    break
    print(len(ans))
    for x, y in ans:
        print(x, y)