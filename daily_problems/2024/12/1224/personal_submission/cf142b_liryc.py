'''
https://codeforces.com/problemset/submission/142/298142170
142B
2024/12/24 Y1
1800
constructive
'''
# ref
n, m = map(int, input().split())
if min(n, m) == 1: 
    print(n * m)
elif min(n, m) == 2:
    v = max(n, m)
    print((v >> 2 << 2) + (min(v & 3, 2) << 1))
else:
    print(n * m + 1 >> 1)
