"""
思路: 本质上是斐波那契数列, 递推判断就好. 
"""
#python代码:
f0, f1 = 1, 2
res = 0
n = int(input())
while f1 <= n:
    f0, f1 = f1, f1 + f0
    res += 1
print(res)
