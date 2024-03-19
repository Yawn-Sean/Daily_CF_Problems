standard_input, packages, output_together = 1, 1, 0
dfs, hashing, read_from_file = 1, 0, 0
de = 1

if 1:

    if standard_input:
        import io, os, sys
        input = lambda: sys.stdin.readline().strip()

        import math
        inf = math.inf

        def I():
            return input()
        
        def II():
            return int(input())

        def MII():
            return map(int, input().split())

        def LI():
            return list(input().split())

        def LII():
            return list(map(int, input().split()))

        def LFI():
            return list(map(float, input().split()))

        def GMI():
            return map(lambda x: int(x) - 1, input().split())

        def LGMI():
            return list(map(lambda x: int(x) - 1, input().split()))

    if packages:
        from io import BytesIO, IOBase

        import random
        import os

        import bisect
        import typing
        from collections import Counter, defaultdict, deque
        from copy import deepcopy
        from functools import cmp_to_key, lru_cache, reduce
        from heapq import merge, heapify, heappop, heappush, heappushpop, nlargest, nsmallest
        from itertools import accumulate, combinations, permutations, count, product
        from operator import add, iand, ior, itemgetter, mul, xor
        from string import ascii_lowercase, ascii_uppercase, ascii_letters
        from typing import *
        BUFSIZE = 4096

    if output_together:
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

        sys.stdout = IOWrapper(sys.stdout)

    if dfs:
        from types import GeneratorType

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

    if hashing:
        RANDOM = random.getrandbits(20)
        class Wrapper(int):
            def __init__(self, x):
                int.__init__(x)

            def __hash__(self):
                return super(Wrapper, self).__hash__() ^ RANDOM

    if read_from_file:
        file = open("input.txt", "r").readline().strip()[1:-1]
        fin = open(file, 'r')
        input = lambda: fin.readline().strip()
        output_file = open("output.txt", "w")
        def fprint(*args, **kwargs):
            print(*args, **kwargs, file=output_file)

    if de:
        def debug(*args, **kwargs):
            print('\033[92m', end='')
            print(*args, **kwargs)
            print('\033[0m', end='')

class PrimeTable:
    
    def __init__(self, n:int) -> None:
        self.n = n
        self.primes = []
        self.max_div = list(range(n+1))
        self.max_div[1] = 1
        self.phi = list(range(n+1))

        for i in range(2, n + 1):
            if self.max_div[i] == i:
                self.primes.append(i)
                for j in range(i, n+1, i):
                    self.max_div[j] = i
                    self.phi[j] = self.phi[j] // i * (i-1)

    def is_prime(self, x:int):
        if x < 2: return False
        if x <= self.n: return self.max_div[x] == x
        for p in self.primes:
            if p * p > x: break
            if x % p == 0: return False
        return True

    def prime_factorization(self, x:int):
        if x > self.n:
            for p in self.primes:
                if p * p > x: break
                if x <= self.n: break
                if x % p == 0:
                    cnt = 0
                    while x % p == 0: cnt += 1; x //= p
                    yield p, cnt
        while (1 < x and x <= self.n):
            p, cnt = self.max_div[x], 0
            while x % p == 0: cnt += 1; x //= p
            yield p, cnt
        if x >= self.n and x > 1:
            yield x, 1

    def get_factors(self, x:int):
        factors = [1]
        for p, b in self.prime_factorization(x):
            n = len(factors)
            for j in range(1, b+1):
                for d in factors[:n]:
                    factors.append(d * (p ** j))
        return factors

pt = PrimeTable(10 ** 6)

t = II()
ans = []
for _ in range(t):
    n, q = MII()
    
    cnt = Counter()
    for p, c in pt.prime_factorization(n):
        cnt[p] = c
    d_cnt = Counter()
    for x in cnt.values():
        for p, c in pt.prime_factorization(x + 1):
            d_cnt[p] += c
    
    tmp_cnt = deepcopy(cnt)
    tmp_d_cnt = deepcopy(d_cnt)
    
    def check():
        for x in tmp_d_cnt:
            if tmp_cnt[x] < tmp_d_cnt[x]: return False
        return True
    
    for _ in range(q):
        query = LII()
        if query[0] == 1:
            for p, c in pt.prime_factorization(query[1]):
                if tmp_cnt[p]:
                    for p1, c1 in pt.prime_factorization(tmp_cnt[p] + 1):
                        tmp_d_cnt[p1] -= c1
                tmp_cnt[p] += c
                for p1, c1 in pt.prime_factorization(tmp_cnt[p] + 1):
                    tmp_d_cnt[p1] += c1
            ans.append('YES' if check() else 'NO')
        else:
            tmp_cnt = deepcopy(cnt)
            tmp_d_cnt = deepcopy(d_cnt)
print('\n'.join(ans))