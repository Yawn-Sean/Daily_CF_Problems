'''
https://codeforces.com/contest/622/submission/271111854
622C
2024/7/18 Y1
1700
array: d[x] denotes the first previous pos that not equals to a[x]
'''
n, m = map(int, input().split())
a = list(map(int, input().split()))
d = [-1] * n
for i in range(1, n):
    if a[i] == a[i - 1]:
        d[i] = d[i - 1]
    else:
        d[i] = i - 1
for _ in range(m):
    l, r, x = map(int, input().split())
    l -= 1
    r -= 1
    if a[r] != x:
        print(r + 1)
    elif d[r] >= l:
        print(d[r] + 1)
    else:
        print(-1)