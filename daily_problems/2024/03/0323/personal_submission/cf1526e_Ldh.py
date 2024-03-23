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

from math import gcd

class Factorial:
    def __init__(self, N, mod) -> None:
        self.mod = mod
        self.f = [1 for _ in range(N)]
        self.g = [1 for _ in range(N)]
        for i in range(1, N):
            self.f[i] = self.f[i - 1] * i % self.mod
        self.g[-1] = pow(self.f[-1], mod - 2, mod)
        for i in range(N - 2, -1, -1):
            self.g[i] = self.g[i + 1] * (i + 1) % self.mod
    
    def comb(self, n, m):
        if n < m or n < 0 or m < 0:
            return 0
        return self.f[n] * self.g[m] % self.mod * self.g[n - m] % self.mod
    
    def perm(self, n, m):
        if n < m or n < 0 or m < 0:
            return 0
        return self.f[n] * self.g[n - m] % self.mod

    def catalan(self, n):
        #TODO: check 2 * n < N#
        return (self.comb(2 * n, n) - self.comb(2 * n, n - 1)) % self.mod
    
class Lucas:
    def __init__(self, p) -> None:
        self.p = p
        self.f = [1 for _ in range(self.p)]
        self.g = [1 for _ in range(self.p)]
        for i in range(1, self.p):
            self.f[i] = self.f[i - 1] * i % self.p
        self.g[self.p - 1] = pow(self.f[self.p - 1], self.p - 2, self.p)
        for i in range(self.p - 2, -1, -1):
            self.g[i] = self.g[i + 1] * (i + 1) % self.p
    
    def comb(self, n, m):
        if n < m:
            return 0
        else:
            return self.f[n] * self.g[m] % self.p * self.g[n - m] % self.p

    def lucas(self, n, m):
        if m == 0:
            return 1 % self.p
        else:
            return self.lucas(n // self.p, m // self.p) * self.comb(n % self.p, m % self.p) % self.p

class Crt:
    # ax + by = gcd(a, b), q是gcd#
    def exgcd(self, a, b):
        if b == 0:
            return 1, 0, a
        else:
            x, y, q = self.exgcd(b, a % b)
            x, y = y, x - (a // b) * y
            return x, y, q

    # 同余方程组，A数组是mod数组，B数组是residue数组，M是所有mod的乘积#
    # TODO: 检查mod数组中的数是否两两互质，如果不是就要用excrt。    
    def crt(self, A, B, M):
        res = 0
        for a, b in zip(A, B):
            Mi = M // a
            x, _, _ = self.exgcd(Mi, a)
            res += b * Mi * x
            res %= M
        return res

    # 同余方程组，A数组是mod数组，B数组是residue数组
    # 可能有无解的情况
    def excrt(self, A, B):
        res, M = 0, 1
        for a, b in zip(A, B):
            rhs = (b - res) % a
            #g, l代表最大公约数，最小公倍数#
            g = gcd(M, a)
            l = M * a // g
            
            if rhs % g:
                return -1, -1
            x, y, q = self.exgcd(M, a)
            res += x * rhs // g * M
            res %= l
            M = l
        return res, M

    def lcm(self, a, b):
        return a * b // gcd(a, b)

    #wx = b(mod a)的同余方程组，记得重写lcm#
    def excrt_with_weight(self, W, A, B):
        res, M = 0, 1
        for w, a, b in zip(W, A, B):
            rhs = (b - w * res) % a
            x, _, g = self.exgcd(w * M % a, a)
            if rhs % g:
                return -1, -1
            res += x * (rhs // g) % (a // g) * M
            M = self.lcm(M, a // gcd(a, w))
            res %= M
        return res, M

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
    
    def dissolve(self, num):
        '''prime factor decomposition of num'''
        lst = []
        idx = -1
        for prime in self.primes:
            if prime > num:
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

class Ex_Lucas:
        
    def __init__(self, p) -> None:
        #TODO: 把CRT, Prime板子也带上
        self.CRT = Crt()
        self.PRIME = Prime(10 ** 5 + 10)

        #分解质因子
        self.p = p
        self.dissolved = self.PRIME.dissolve(p)
        
        self.piset = []
        self.m = []
        self.num = 0
        for pr, pw in self.dissolved:
            self.m.append(pr ** pw)
            self.piset.append(pr)
            self.num += 1
    
    #找循环节#
    def multi(self, n, pi, pk):
        if not n:
            return 1
        ans = 1
        for i in range(2, pk + 1):
            if i % pi:
                ans = ans * i % pk
        ans = pow(ans, n // pk, pk)
        for i in range(2, n % pk + 1):
            if i % pi:
                ans = ans * i % pk
        return ans * self.multi(n // pi, pi, pk) % pk

    def count(self, num, p):
        ret = 0
        while num:
            ret += num // p
            num //= p
        return ret
    
    def inv(self, num, p):
        return self.CRT.exgcd(num, p)[0]
    
    #pi是质因数pr，pk是质因数pr的pw次方#
    def exlucas(self, n, m, pi, pk):
        if m > n:
            return 0
        a = self.multi(n, pi, pk)
        b = self.multi(m, pi, pk)
        c = self.multi(n - m, pi, pk)
        k = self.count(n, pi) - self.count(m, pi) - self.count(n - m, pi)
        return a * self.inv(b, pk) % pk * self.inv(c, pk) % pk * pow(pi, k, pk) % pk
    
    def comb(self, n, m):
        self.r = [-1 for _ in range(self.num)]
        for i in range(self.num):
            self.r[i] = self.exlucas(n, m, self.piset[i], self.m[i])
        return self.CRT.crt(self.m, self.r, self.p)



inf = float('inf')

mod = 998244353
F = Factorial(2000010, mod)

# @TIME
def solve(testcase):
    n, k = MI()
    A = LII()
    
    pos = [0 for _ in range(n + 1)]
    for i, v in enumerate(A):
        pos[v] = i
    pos[n] -= 1

    cnt = 0
    for i in range(n - 1):
        if pos[A[i] + 1] > pos[A[i + 1] + 1]:
            cnt += 1
    
    print(F.comb(k - cnt + n - 1, n))

for testcase in range(1):
    solve(testcase)