'''
https://codeforces.com/contest/476/submission/275326153
476C
2024/8/9 Y1
1600
套公式
for k in 1..a
    for m in 1..b-1
        x // b = km
        x = kmb + m = (kb + 1)m
'''
a, b = map(int, input().split())
ans = ((1+a) * a >> 1) * (b * b * (b - 1) >> 1) + a * (b * (b - 1) >> 1)
print(ans % 1000000007)
