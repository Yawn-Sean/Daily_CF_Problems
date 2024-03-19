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

# RANDOM = getrandbits(32, seed = 19981220)
 
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

class Prime:
    def prime_sieve(self, n):
        """returns a sieve of primes >= 5 and < n"""
        flag = n % 6 == 2
        sieve = bytearray((n // 3 + flag >> 3) + 1)
        for i in range(1, int(n**0.5) // 3 + 1):
            if not (sieve[i >> 3] >> (i & 7)) & 1:
                k = (3 * i + 1) | 1
                for j in range(k * k // 3, n // 3 + flag, 2 * k):
                    sieve[j >> 3] |= 1 << (j & 7)
                for j in range(k * (k - 2 * (i & 1) + 4) // 3, n // 3 + flag, 2 * k):
                    sieve[j >> 3] |= 1 << (j & 7)
        return sieve

    def prime_list(self, n):
        """returns a list of primes <= n"""
        res = []
        if n > 1:
            res.append(2)
        if n > 2:
            res.append(3)
        if n > 4:
            sieve = self.prime_sieve(n + 1)
            res.extend(3 * i + 1 | 1 for i in range(1, (n + 1) // 3 + (n % 6 == 1)) if not (sieve[i >> 3] >> (i & 7)) & 1)
        return res
    
    def __init__(self, n) -> None:
        self.primes = self.prime_list(n)
    
    '''
    n = 1会返回空数组
    '''
    @lru_cache(None)
    def dissolve(self, num):
        '''prime factor decomposition of num'''
        lst = []
        idx = -1
        for prime in self.primes:
            if prime * prime > num:
                break

            if num % prime == 0:
                lst.append([prime, 0])
                idx += 1
                
            while num % prime == 0:
                lst[idx][1] += 1
                num //= prime
                
        if num != 1:
            lst.append([num, 1])
            
        return lst

    def GetAllFactors(self, num, SORT = False):
        res = [1]
        if num == 1:
            return res
        else:
            for a, b in self.dissolve(num):
                mul = a
                k = len(res)
                for _ in range(b):
                    for i in range(k):
                        res.append(res[i] * mul)
                    mul *= a
            
            if SORT:
                res.sort()
            
            return res
    
    def primitive_root(self, num):
        '''
        check whether num is prime
        '''
        g = 1
        DIS = self.dissolve(num)

        while True:
            for a, b in DIS:
                if pow(g, (num - 1) // a, num) == 1:
                    break
            else:
                break
            g += 1
        
        return g

        
# class PrimeTable:
#     def __init__(self, n:int) -> None:
#         self.n = n
#         self.primes = []
#         self.max_div = list(range(n+1))
#         self.max_div[1] = 1
#         self.phi = list(range(n+1))

#         for i in range(2, n + 1):
#             if self.max_div[i] == i:
#                 self.primes.append(i)
#                 for j in range(i, n+1, i):
#                     self.max_div[j] = i
#                     self.phi[j] = self.phi[j] // i * (i-1)

#     def is_prime(self, x:int):
#         if x < 2: return False
#         if x <= self.n: return self.max_div[x] == x
#         for p in self.primes:
#             if p * p > x: break
#             if x % p == 0: return False
#         return True

#     def prime_factorization(self, x:int):
#         if x > self.n:
#             for p in self.primes:
#                 if p * p > x: break
#                 if x <= self.n: break
#                 if x % p == 0:
#                     cnt = 0
#                     while x % p == 0: cnt += 1; x //= p
#                     yield p, cnt
#         while (1 < x and x <= self.n):
#             p, cnt = self.max_div[x], 0
#             while x % p == 0: cnt += 1; x //= p
#             yield p, cnt
#         if x >= self.n and x > 1:
#             yield x, 1

#     def get_factors(self, x:int):
#         factors = [1]
#         for p, b in self.prime_factorization(x):
#             n = len(factors)
#             for j in range(1, b+1):
#                 for d in factors[:n]:
#                     factors.append(d * (p ** j))
#         return factors

P = Prime(1000010)

# @TIME
def solve(testcase):
    n, q = MI()
    '''
    mp: n的质因数分解
    cur: 当前质因数的个数（质因数分解形式）
    '''
    mp = defaultdict(int)
    cur = defaultdict(int)
    cur[1] = 1
    mp[1] = 1
    for a, b in P.dissolve(n):
        mp[a] = b
        for c, d in P.dissolve(b + 1):
            cur[c] += d
    # print('mp', mp)
    # print('cur', cur)
    # print('-------------------------')
    
    nope = set()
    for c in cur:
        if cur[c] > mp[c]:
            nope.add(c)
    # print('init_nope', nope)
    # print('mp', mp)

    for _ in range(q):
        ops = LII()
        if ops[0] == 1:
            # print('x', ops[1])
            x = ops[1]
            to_change = []
            changed = []
            for a, b in P.dissolve(x):
                if a == 1:
                    continue
                to_change.append(mp[a])
                mp[a] += b
                if mp[a] >= cur[a]:
                    nope.discard(a)
                changed.append(mp[a])
            # print('mp', mp)
            # print('tc', to_change)
            # print('c', changed)
            
            for v in to_change:
                if v == 0:
                    continue
                for a, b in P.dissolve(v + 1):
                    cur[a] -= b
                    if cur[a] <= mp[a]:
                        nope.discard(a)
            
            for v in changed:
                if v == 0:
                    continue
                for a, b in P.dissolve(v + 1):
                    cur[a] += b
                    if cur[a] > mp[a]:
                        nope.add(a)
            # print('nope', nope)
            print("YES" if not nope else "NO")
            # print('cur', cur)
            # print('------------------------------------------')
        else:
            mp = defaultdict(int)
            cur = defaultdict(int)
            cur[1] = 1
            mp[1] = 1
            for a, b in P.dissolve(n):
                mp[a] = b
                for c, d in P.dissolve(b + 1):
                    cur[c] += d
            nope = set()
            for c in cur:
                if cur[c] > mp[c]:
                    nope.add(c)
    print()


for testcase in range(II()):
    solve(testcase)