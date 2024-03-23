'''
Hala Madrid!
https://www.zhihu.com/people/li-dong-hao-78-74
'''

import sys
import os
from io import BytesIO, IOBase
BUFSIZE = 8192
class FastIO(IOBase):
    newlines = 0
    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None
    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()
    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()
    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)
class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")
sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
input = lambda: sys.stdin.readline().rstrip("\r\n")

def I():
    return input()
def II():
    return int(input())
def MI():
    return map(int, input().split())
def LI():
    return list(input().split())
def LII():
    return list(map(int, input().split()))
def GMI():
    return map(lambda x: int(x) - 1, input().split())

#------------------------------FastIO---------------------------------

from bisect import *
from heapq import *
from collections import *
from functools import *
from itertools import *
from time import *
from random import *
from math import log, gcd, sqrt, ceil

# '''
# 手写栈防止recursion limit
# 注意要用yield 不要用return
# 函数结尾要写yield None
# '''
# from types import GeneratorType
# def bootstrap(f, stack=[]):
#     def wrappedfunc(*args, **kwargs):
#         if stack:
#             return f(*args, **kwargs)
#         else:
#             to = f(*args, **kwargs)
#             while True:
#                 if type(to) is GeneratorType:
#                     stack.append(to)
#                     to = next(to)
#                 else:
#                     stack.pop()
#                     if not stack:
#                         break
#                     to = stack[-1].send(to)
#             return to
#     return wrappedfunc

# RANDOM = getrandbits(32)
 
# class Wrapper(int):
#     def __init__(self, x):
#         int.__init__(x)

#     def __hash__(self):
#         return super(Wrapper, self).__hash__() ^ RANDOM

# def TIME(f):

#     def wrap(*args, **kwargs):
#         s = perf_counter()
#         ret = f(*args, **kwargs)
#         e = perf_counter()

#         print(e - s, 'sec')
#         return ret
    
#     return wrap

inf = float('inf')

def ask(x1, y1, x2, y2):
    print('?', x1 + 1, y1 + 1, x2 + 1, y2 + 1, flush = True)
    
def answer(x1, y1, x2, y2):
    print('!', x1 + 1, y1 + 1, x2 + 1, y2 + 1, flush = True)

# @TIME
def solve(testcase):
    n = II()
    
    r = [0 for _ in range(n)]
    c = [0 for _ in range(n)]
    
    yep = []
    tot = 0
    for i in range(n - 1):
        ask(i, 0, i, n - 1)
        r[i] = II()
        if r[i] & 1:
            yep.append(i)
        tot = (tot - r[i]) & 1
    
    if tot & 1:
        yep.append(n - 1)
    
    if len(yep) == 2:
        ans = []
        for row in yep:
            # print('row', row)
            l, r = 0, n - 1
            while l < r:
                mid = l + r >> 1
                ask(row, l, row, mid)
                tmp = II()
                if tmp & 1:
                    r = mid
                else:
                    l = mid + 1
                    
            ans.append(row)
            ans.append(l)
            # print('ans', ans)
        
        answer(ans[0], ans[1], ans[2], ans[3])
    
    else:
        yep = []
        tot = 0
        for i in range(n - 1):
            ask(0, i, n - 1, i)
            c[i] = II()
            if c[i] & 1:
                yep.append(i)
            tot = (tot - c[i]) & 1
        
        if tot & 1:
            yep.append(n - 1)
        
        assert len(yep) == 2
        ans = []
        for col in yep:
            l, r = 0, n - 1
            while l < r:
                mid = l + r >> 1
                ask(l, col, mid, col)
                tmp = II()
                if tmp & 1:
                    r = mid
                else:
                    l = mid + 1
            ans.append(l)
            ans.append(col)
            
        answer(ans[0], ans[1], ans[2], ans[3])
        return
    
for testcase in range(1):
    solve(testcase)