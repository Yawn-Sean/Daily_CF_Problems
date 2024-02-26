standard_input, packages, output_together = 1, 1, 1
dfs, hashing, read_from_file = 0, 0, 0
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

def main():
    n, q = MII()
    s = I()
    
    next_pos = [[n] * (n + 2) for _ in range(26)]
    for i in range(n - 1, - 1, -1):
        for j in range(26):
            next_pos[j][i] = next_pos[j][i+1]
        next_pos[ord(s[i]) - ord('a')][i] = i
    
    m = 255
    def f(x, y, z):
        return (x * m + y) * m + z
    
    def revf(msk):
        msk, z = divmod(msk, m)
        return *divmod(msk, m), z

    
    dp = [n] * (m ** 3)
    dp[0] = -1
    
    cur0 = cur1 = cur2 = 0
    s0, s1, s2 = [], [], []
    
    for _ in range(q):
        query = LI()
        
        if query[0] == '-':
            
            if query[1] == '1':
                s0.pop()
                cur0 -= 1
            
            elif query[1] == '2':
                s1.pop()
                cur1 -= 1
            
            else:
                s2.pop()
                cur2 -= 1
        
        else:
            c = ord(query[2]) - ord('a')
            
            if query[1] == '1':
                for i in range(cur1 + 1):
                    for j in range(cur2 + 1):
                        dp[f(cur0 + 1, i, j)] = next_pos[c][dp[f(cur0, i, j)] + 1]
                        
                        if i and next_pos[s1[i-1]][dp[f(cur0 + 1, i - 1, j)] + 1] < dp[f(cur0 + 1, i, j)]:
                            dp[f(cur0 + 1, i, j)] = next_pos[s1[i-1]][dp[f(cur0 + 1, i - 1, j)] + 1]
                        
                        if j and next_pos[s2[j-1]][dp[f(cur0 + 1, i, j - 1)] + 1] < dp[f(cur0 + 1, i, j)]:
                            dp[f(cur0 + 1, i, j)] = next_pos[s2[j-1]][dp[f(cur0 + 1, i, j - 1)] + 1]
                s0.append(c)
                cur0 += 1
            
            elif query[1] == '2':
                for i in range(cur0 + 1):
                    for j in range(cur2 + 1):
                        dp[f(i, cur1 + 1, j)] = next_pos[c][dp[f(i, cur1, j)] + 1]
                        
                        if i and next_pos[s0[i-1]][dp[f(i - 1, cur1 + 1, j)] + 1] < dp[f(i, cur1 + 1, j)]:
                            dp[f(i, cur1 + 1, j)] = next_pos[s0[i-1]][dp[f(i - 1, cur1 + 1, j)] + 1]
                        
                        if j and next_pos[s2[j-1]][dp[f(i, cur1 + 1, j - 1)] + 1] < dp[f(i, cur1 + 1, j)]:
                            dp[f(i, cur1 + 1, j)] = next_pos[s2[j-1]][dp[f(i, cur1 + 1, j - 1)] + 1]
                        
                s1.append(c)
                cur1 += 1
            
            else:
                for i in range(cur0 + 1):
                    for j in range(cur1 + 1):
                        dp[f(i, j, cur2 + 1)] = next_pos[c][dp[f(i, j, cur2)] + 1]
                        
                        if i and next_pos[s0[i-1]][dp[f(i - 1, j, cur2 + 1)] + 1] < dp[f(i, j, cur2 + 1)]:
                            dp[f(i, j, cur2 + 1)] = next_pos[s0[i-1]][dp[f(i - 1, j, cur2 + 1)] + 1]
                        
                        if j and next_pos[s1[j-1]][dp[f(i, j - 1, cur2 + 1)] + 1] < dp[f(i, j, cur2 + 1)]:
                            dp[f(i, j, cur2 + 1)] = next_pos[s1[j-1]][dp[f(i, j - 1, cur2 + 1)] + 1]
                        
                s2.append(c)
                cur2 += 1
        
        print('YES' if dp[f(cur0, cur1, cur2)] < n else 'NO')
    return

t = 1
for _ in range(t):
    main()
