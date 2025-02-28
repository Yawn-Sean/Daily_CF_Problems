'''
https://codeforces.com/problemset/submission/621/288859143
621C
2024/10/30 Y1
1700
probability
'''
# ref
n, p = map(int, input().split())

probs = []

for _ in range(n):
    l, r = map(int, input().split())
    probs.append((r // p - (l - 1) // p) / (r - l + 1))

ans = 0
for i in range(n):
    ans += probs[i] + probs[i - 1] - probs[i] * probs[i - 1]

print(ans * 2000)