from datetime import *
from functools import *
from sys import *
from itertools import accumulate, combinations, permutations
from bisect import *
from heapq import *
from collections import *
from math import *
from types import *
import random
RANDOM = random.randint(0, 10**9 + 7)
Mod = random.randint(10 ** 14, 10 ** 15)
del pow
# math.ceil(x)向上取整,math.comb(n, k) 组合数C(n,k),从n个里面挑k个出来,math.isqrt(),整数开根号
# from sortedcontainers import *
input = stdin.readline
# print = stdout.write #如果输出多的话记得用快写
# setrecursionlimit (10000)
 
# 对浮点数进行四舍五入, 小数位不足自动补零


def rounding_num(num, x):
    num = round(num, x)
    num = "{{:.{}f}}".format(x).format(num)
    return num


 
# 模拟栈，使用时要@bootstrap, 并且一定要写返回值，内部调用时也要用yield返回迭代器，返回值也要用yield返回迭代器


def bootstrap(f, stack=[]):
    def wrappedfunc(*args, **kwargs):
        if stack:
            return f(*args, **kwargs)
        else:
            to = f(*args, **kwargs)
            while True:
                if type(to) is GeneratorType:
                    stack.append(to)
                    to = next(to)
                else:
                    stack.pop()
                    if not stack:
                        break
                    to = stack[-1].send(to)
            return to
    return wrappedfunc


 
# 遇到没有确定行数的输入时可以用这个来读取输入
# while True:
#     try:
#         #这里写你的输入
#         pass
#     except:
#         break

n, m = map(int, input().split())
arr = list(map(int, input().split()))
brr = list(map(int, input().split()))
ans1 = 0
ans2 = 0
for i in range(n):
    ans1 ^= arr[i]
for j in range(m):
    ans2 ^= brr[j]
if ans1 != ans2:
    print('NO')
    exit(0)
res = [[0] * m for _ in range(n)]
for i in range(n - 1):
    res[i][m - 1] = arr[i]
for j in range(m - 1):
    res[n - 1][j] = brr[j]
for i in range(n - 1):
    res[-1][-1] ^= arr[i]
res[-1][-1] ^= brr[-1]
print('YES')
for arr in res:
    print(*arr)
