'''
https://codeforces.com/problemset/submission/1062/289345062
1062C
2024/11/2 Y1
1600
prefix sum
'''
# ref
n, q = map(int, input().split())
s = input()

ps = [0] * (n + 1)
pt2 = [1] * (n + 1)

for i in range(n):
    ps[i + 1] = ps[i] + (s[i] == '1')
    pt2[i + 1] = pt2[i] * 2 % 1000000007

ans = []
for _ in range(q):
    l, r = map(int, input().split())
    l -= 1
    ans.append((pt2[r - l] - pt2[r - l - (ps[r] - ps[l])]) % 1000000007)

print(*ans, sep='\n')