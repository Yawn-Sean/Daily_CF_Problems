import sys
from collections import defaultdict, deque
from itertools import accumulate
from heapq import *
from bisect import *
from types import GeneratorType
from heapq import *
from typing import List
from math import inf

standard_input = True
if standard_input:
    RI = lambda: int(sys.stdin.readline().strip())
    RF = lambda: float(sys.stdin.readline().strip())
    RS = lambda: sys.stdin.readline().strip()
    RFF = lambda: map(float, sys.stdin.readline().strip().split())
    RII = lambda: map(int, sys.stdin.readline().strip().split())
    RILIST = lambda: list(RII())
    RFLIST = lambda: list(RFF())

else:
    RI = lambda: int(input())
    RF = lambda: float(input())
    RS = lambda: input()
    RFF = lambda: map(float, input())
    RII = lambda: map(int, input().split())
    RILIST = lambda: list(RII())
    RFLIST = lambda: list(RFF())
    fin = open('input.txt', 'r')
    fout = open('output.txt', 'w')
    input = lambda: fin.readline().strip()


    def print(x):
        fout.write(str(x))

mx = lambda x, y: x if x > y else y
mn = lambda x, y: y if x > y else x


def bootstrap(f, stack=[]):
    def wrappedfunc(*args, **kwargs):
        if stack:
            return f(*args, **kwargs)
        else:
            to = f(*args, **kwargs)
            while True:
                if isinstance(to, GeneratorType):
                    stack.append(to)
                    to = next(to)
                else:
                    stack.pop()
                    if not stack:
                        return to
                    to = stack[-1].send(to)

    return wrappedfunc


s = RS()
n = len(s)

@bootstrap
def dfs(i, cnt_4, cnt_7):
    if ''.join(ans) < s:
        yield 1
    else:
        if i == n:
            print(''.join(ans))
            exit()
        if cnt_4 < n // 2:
            ans[i] = '4'
            yield dfs(i + 1, cnt_4 + 1, cnt_7)
        if cnt_7 < n // 2:
            ans[i] = '7'
            yield dfs(i + 1, cnt_4, cnt_7 + 1)
        yield 1


if n & 1:
    print('4'*((n + 1)//2) + '7'*((n + 1)//2))
else:
    mx = '7' * (n // 2) + '4' * (n // 2)
    if s > mx:
        print('4' * ((n + 2) // 2) + '7' * ((n + 2) // 2))
    else:
        ans = ['9'] * n
        dfs(0, 0, 0)
