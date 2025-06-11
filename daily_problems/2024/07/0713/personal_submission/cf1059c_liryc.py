'''
submit link: https://codeforces.com/contest/1059/submission/270263283
1059C 2024/7/13 Y1 
1600
constructive
'''
n = int(input())
a = []
p = 1
while n:
    if n <= 3:
        if n == 1:
            a += [p]
        elif n == 2:
            a += [p, p * 2]
        else:
            a += [p, p, p * 3]
        break
    a += [p] * (n + 1 >> 1)
    n >>= 1
    p <<= 1
print(*a)