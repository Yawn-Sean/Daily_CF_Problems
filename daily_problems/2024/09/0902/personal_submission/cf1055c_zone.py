from math import gcd 

l0, r0, t0 = map(int, input().split()) 
l1, r1, t1 = map(int, input().split()) 

a, b = r0 - l0 + 1, r1 - l1 + 1

t = gcd(t0, t1)
d = (l0 - l1) % t # 相对位置

# 1在0的左边, i.e., d > 0: min(a + d - t, b)
# 1在0的右边, i.e., d < 0: min(b - d, a) 

print(max(0, min(a + d - t, b), min(b - d, a)))
