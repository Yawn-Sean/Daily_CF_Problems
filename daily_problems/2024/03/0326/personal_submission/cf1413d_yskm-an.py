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


n = int(input())
q = []
for _ in range(2 * n):
    s = list(input().strip().split())
    q.append(s)
pq = []
res = []
for s in q[::-1]:
    if s[0] == '-':
        x = int(s[1])
        if not pq or x <= pq[-1]:
            pq.append(x)
        else:
            print('NO')
            exit(0)
    else:
        if pq:
            res.append(pq.pop())
        else:
            print('NO')
            exit(0)
print('YES')
print(*res[::-1])
