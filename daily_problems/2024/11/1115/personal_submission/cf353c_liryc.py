'''
https://codeforces.com/problemset/submission/353/291532350
CF353 C
20241115 Y1
1600
'''
# ref
n = int(input())
a = list(map(int, input().split()))
s = input()

cur = sum(a)
ans = 0

for i in range(n - 1, -1, -1):
    cur -= a[i]
    if s[i] == '1':
        ans = max(ans, cur)
        cur += a[i]

print(max(ans, cur))