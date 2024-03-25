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

'''
手写栈防止recursion limit
注意要用yield 不要用return
'''
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

'''
max(***), mp可能为空 -> error
'''

mod = 10 ** 9 + 9

def solve():
    n, a, b, k = MI()
    s = I()
    inva = pow(a, mod - 2, mod)
    
    #k-sum是等比数列#
    cura = pow(a, n, mod)
    curb = 1
    routinue_sum = 0
    for i in range(k):
        if s[i] == '+':
            routinue_sum += cura * curb % mod
        else:
            routinue_sum += -cura * curb % mod
        routinue_sum %= mod
        cura = cura * inva % mod
        curb = curb * b % mod
    #print(routinue_sum)
    
    q = pow(pow(a, k, mod), mod - 2, mod) * pow(b, k, mod) % mod
    #从0到n, n+1个数#
    quotient, residue = divmod(n + 1, k)
    #print(quotient, residue)
    #余数部分#
    cura = pow(a, n + 1 - quotient * k, mod)
    curb = pow(b, k * quotient, mod)
    residue_sum = 0
    for i in range(residue):
        if s[i] == '+':
            residue_sum += cura * curb % mod
        else:
            residue_sum += -cura * curb % mod
        cura = cura * inva % mod
        curb = curb * b % mod
        residue_sum %= mod
    #print(residue_sum)
    if not quotient:
        quotient_sum = 0
    else:
        #特殊讨论n=1的情况#
        if q == 1:
            print((quotient * routinue_sum % mod + residue_sum) % mod)
            return
        quotient_sum = routinue_sum * (pow(q, quotient, mod) - 1) % mod
        #print(quotient_sum)
        quotient_sum = quotient_sum * pow(q - 1, mod - 2, mod) % mod

    print((quotient_sum + residue_sum) % mod)


for _ in range(1):solve()