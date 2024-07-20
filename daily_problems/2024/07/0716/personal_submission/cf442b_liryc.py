'''
https://codeforces.com/contest/442/submission/270906123
442B
2024/7/16 Y1
1800
probability
'''
n = int(input())
a = list(map(float, input().split()))
a.sort(reverse=True)
p1, fp = 0.0, 1.0
for p in a:
    p2 = p1 * (1 - p) + p * fp
    if p2 > p1:
        p1 = p2
        fp *= (1 - p)
print(p1)
