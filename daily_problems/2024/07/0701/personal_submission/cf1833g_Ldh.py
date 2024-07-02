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

# seed(19981220)
# RANDOM = getrandbits(64)
 
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

# @TIME
def solve(testcase):
    n = II()
    adj = defaultdict(list)
    fa = [-1 for _ in range(n)]
    vis = [False for _ in range(n)]
    mp = defaultdict(lambda : defaultdict(int))
    order = []
    
    for i in range(1, n):
        u, v = MI()
        u -= 1
        v -= 1
        
        adj[u].append(v)
        adj[v].append(u)
        
        mp[u][v] = mp[v][u] = i
    
    q = deque()
    q.append((0, -1))
    while q:
        cur, father = q.popleft()
        order.append(cur)
        for o in adj[cur]:
            if o != father:
                q.append((o, cur))
                fa[o] = cur
    
    res = []
    # print('order', order)
    
    for o in reversed(order):

        if vis[o]:
            pass
        else:
            father = fa[o]
            if father == -1:
                print(-1)
                return
            
            if vis[father]:
                print(-1)
                return
            else:
                grand = fa[father]
                availables = []
                for node in adj[father]:
                    if node != grand:
                        if not vis[node]:
                            availables.append(node)
                
                # print(o, availables)
                
                if len(availables) > 2:
                    print(-1)
                    return
                elif len(availables) == 2:
                    for node in availables:
                        vis[node] = True
                    vis[father] = True
                    if grand != -1:
                        res.append((father, grand))
                else:
                    if grand == -1:
                        print(-1)
                        return
                    else:
                        gf = fa[grand]
                        if vis[grand]:
                            print(-1)
                            return
                        # print(node, father, grand)
                        vis[o] = vis[father] = vis[grand] = True
                        if gf != -1:
                            res.append((grand, gf))
        
        # print('o', o, vis)
    # print(res)
    
    if sum(vis) == n:
        print(len(res))
        print(*[mp[l][r] for l, r in res])
    else:
        print(-1)
            
                    

for testcase in range(II()):
    solve(testcase)