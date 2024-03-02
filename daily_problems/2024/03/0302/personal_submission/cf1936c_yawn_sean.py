standard_input, packages, output_together = 1, 1, 1
dfs, hashing, read_from_file = 0, 0, 0
de = 1

if 1:

    if standard_input:
        import io, os, sys
        input = lambda: sys.stdin.readline().strip()

        inf = float('inf')

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
        import math

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

def main():
    n, m = MII()
    costs = LII()
    
    def f(i, j):
        return i * m + j
    
    msk = 1 << 20
    def g(d, p):
        return d * msk + p
    
    infos = []
    for _ in range(n):
        infos.extend(MII())
    
    path = [-1] * (n * m + n)
    dist = [0] * (n * m + n)
    revpath = [-1] * (n * m + n)
    for j in range(m):
        nums = [infos[f(i, j)] for i in range(n)]
        sorted_range = sorted(range(n), key=lambda x: nums[x])
        for i in range(n - 1):
            i1, i2 = sorted_range[i], sorted_range[i+1]
            path[f(i2, j)] = f(i1, j)
            dist[f(i2, j)] = nums[i2] - nums[i1]
            revpath[f(i1, j)] = f(i2, j)
    
    base = n * m
    ans = [-1] * (n * m + n)
    
    ans[base] = 0
    hpq = [g(0, base)]
    while hpq:
        d, p = divmod(heappop(hpq), msk)
        if ans[p] == d:
            if p >= base:
                i = p - base
                for j in range(m):
                    if ans[f(i, j)] == -1 or ans[f(i, j)] > d:
                        ans[f(i, j)] = d
                        heappush(hpq, g(d, f(i, j)))
            else:
                i = p // m
                if revpath[p] != -1 and (ans[revpath[p]] == -1 or ans[revpath[p]] > d):
                    ans[revpath[p]] = d
                    heappush(hpq, g(d, revpath[p]))
                if path[p] != -1 and (ans[path[p]] == -1 or ans[path[p]] > d + dist[p]):
                    ans[path[p]] = d + dist[p]
                    heappush(hpq, g(ans[path[p]], path[p]))
                if ans[base + i] == -1 or ans[base + i] > d + costs[i]:
                    ans[base + i] = d + costs[i]
                    heappush(hpq, g(d + costs[i], base + i))
    
    print(ans[-1])
    
    return

t = II()
for _ in range(t):
    main()