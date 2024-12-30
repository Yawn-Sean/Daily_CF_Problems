import sys
import random
from functools import reduce
from operator import xor

input = lambda: sys.stdin.readline().rstrip()
I = lambda: input()
II = lambda: int(input())
MII = lambda: map(int, input().split())
LMII = lambda: list(map(int, input().split()))
GMI = lambda: map(lambda x: int(x) - 1, input().split())
LGMI = lambda: list(map(lambda x: int(x) - 1, input().split()))

# 要知道，任何target，只要一个数字即可以异或调整过来
n, x = MII()
if n == 1:
    print("YES")
    print(x)
elif n == 2:
    if x:
        print("YES")
        print(0, x)
    else:
        print("NO")
else:
    # 前n - 2个数随便选
    while True: # 防止出0，则最后两个数重复
        # 设置范围小了会re
        rnd = random.sample(range(1 << 17), k = n - 2)
        v = reduce(xor, rnd) ^ x
        if v: break # 找到了
    rnd.extend([1 << 17, (1 << 17) ^ v])
    print("YES")
    print(*rnd)