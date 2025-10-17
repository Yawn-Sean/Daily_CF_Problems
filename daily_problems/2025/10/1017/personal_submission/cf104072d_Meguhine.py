# -*- coding: UTF-8 -*-
# TLE on #11, 纯当 Python 语法学习了
# 设置功能开关
standard_input, packages, output_together = 1, 1, 0
dfs, hashing, read_from_file = 1, 0, 0
de = 1  # 调试输出开关

if 1:
    # 标准输入处理模块
    if standard_input:
        import io, os, sys
        input = lambda: sys.stdin.readline().strip()  # 快速输入函数
        
        import math
        inf = math.inf  # 无穷大常量
        
        # 输入函数集合
        def I():  # 读取一行字符串
            return input()
        
        def II():  # 读取一个整数
            return int(input())
        
        def MII():  # 读取多个整数(map对象)
            return map(int, input().split())
        
        def LI():  # 读取一行字符串列表
            return input().split()
        
        def LII():  # 读取一行整数列表
            return list(map(int, input().split()))
        
        def LFI():  # 读取一行浮点数列表
            return list(map(float, input().split()))
        
        def GMI():  # 读取并转换为0-indexed索引(map)
            return map(lambda x: int(x) - 1, input().split())
        
        def LGMI():  # 读取并转换为0-indexed索引(list)
            return list(map(lambda x: int(x) - 1, input().split()))
    
    # 常用算法包导入
    if packages:
        from io import BytesIO, IOBase
        import random
        import os
        
        # 二分查找
        import bisect
        
        # 常用集合类
        from collections import Counter, defaultdict, deque
        
        # 深拷贝
        from copy import deepcopy
        
        # 函数工具
        from functools import cmp_to_key, lru_cache, reduce
        
        # 堆操作
        from heapq import merge, heapify, heappop, heappush, heappushpop, nlargest, nsmallest, heapreplace
        
        # 迭代工具
        from itertools import accumulate, combinations, permutations, count, product
        
        # 运算符
        from operator import add, iand, ior, itemgetter, mul, xor
        
        # 字符串常量
        from string import ascii_lowercase, ascii_uppercase, ascii_letters
        
        # 类型提示
        import typing
        from typing import *
        
        # 缓冲区大小
        BUFSIZE = 4096
    
    # 输出加速模块
    if output_together:
        class FastIO(IOBase):
            # 快速IO实现
            newlines = 0
            
            def __init__(self, file):
                self._fd = file.fileno()
                self.buffer = BytesIO()
                self.writable = "x" in file.mode or "r" not in file.mode
                self.write = self.buffer.write if self.writable else None
                
            def read(self):
                # 读取实现
                while True:
                    b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
                    if not b:
                        break
                    ptr = self.buffer.tell()
                    self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
                self.newlines = 0
                return self.buffer.read()
            
            def readline(self):
                # 读取一行
                while self.newlines == 0:
                    b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
                    self.newlines = b.count(b"\n") + (not b)
                    ptr = self.buffer.tell()
                    self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
                self.newlines -= 1
                return self.buffer.readline()
            
            def flush(self):
                # 刷新缓冲区
                if self.writable:
                    os.write(self._fd, self.buffer.getvalue())
                    self.buffer.truncate(0), self.buffer.seek(0)
                    
        class IOWrapper(IOBase):
            # IO包装器
            def __init__(self, file):
                self.buffer = FastIO(file)
                self.flush = self.buffer.flush
                self.writable = self.buffer.writable
                self.write = lambda s: self.buffer.write(s.encode("ascii"))
                self.read = lambda: self.buffer.read().decode("ascii")
                self.readline = lambda: self.buffer.readline().decode("ascii")
                
        sys.stdout = IOWrapper(sys.stdout)  # 重定向标准输出
    
    # DFS递归优化（避免递归深度限制）
    if dfs:
        from types import GeneratorType
        
        def bootstrap(f, stk=[]):
            # 递归优化装饰器
            def wrappedfunc(*args, **kwargs):
                if stk:
                    return f(*args, **kwargs)
                else:
                    to = f(*args, **kwargs)
                    while True:
                        if type(to) is GeneratorType:
                            stk.append(to)
                            to = next(to)
                        else:
                            stk.pop()
                            if not stk:
                                break
                            to = stk[-1].send(to)
                    return to
            return wrappedfunc
    
    # 哈希优化（防止哈希碰撞攻击）
    if hashing:
        RANDOM = random.getrandbits(20)  # 随机种子
        class Wrapper(int):
            # 哈希包装器
            def __init__(self, x):
                int.__init__(x)
                
            def __hash__(self):
                return super(Wrapper, self).__hash__() ^ RANDOM
    
    # 文件输入输出
    if read_from_file:
        file = open("input.txt", "r").readline().strip()[1:-1]
        fin = open(file, 'r')
        input = lambda: fin.readline().strip()  # 从文件读取
        output_file = open("output.txt", "w")
        def fprint(*args, **kwargs):
            # 文件输出函数
            print(*args, **kwargs, file=output_file)
    
    # 调试输出
    if de:
        def dbg(*args, **kwargs):
            # 绿色调试输出
            print('\033[92m', end='')
            print(*args, **kwargs)
            print('\033[0m', end='')
    else :
        def dbg(*args, **kwargs):
            return
    
    # 高效邻接表实现（链式前向星）
    class lst_lst:
        def __init__(self, n) -> None:
            self.n = n
            self.pre = []   # 前向指针列表
            self.cur = []   # 值列表
            self.notest = [-1] * (n + 1)  # 头指针数组
        
        # 添加元素
        def append(self, i, j):
            self.pre.append(self.notest[i])
            self.notest[i] = len(self.cur)
            self.cur.append(j)
        
        # 迭代访问
        def iterate(self, i):
            tmp = self.notest[i]
            while tmp != -1:
                yield self.cur[tmp]
                tmp = self.pre[tmp]

import typing


class FenwickTree:
    '''Reference: https://en.wikipedia.org/wiki/Fenwick_tree'''

    def __init__(self, n: int = 0) -> None:
        self._n = n
        self.data = [0] * n

    def add(self, p: int, x: typing.Any) -> None:
        assert 0 <= p < self._n

        p += 1
        while p <= self._n:
            self.data[p - 1] += x
            p += p & -p

    def sum(self, left: int, right: int) -> typing.Any:
        assert 0 <= left <= right <= self._n

        return self._sum(right) - self._sum(left)

    def _sum(self, r: int) -> typing.Any:
        s = 0
        while r > 0:
            s += self.data[r - 1]
            r -= r & -r

        return s

def main():
    n=II()
    a=[LII() for _ in range(n)]
    U,D,L,R,ul,dr=[
        [[0]*n for _ in range(n)]
        for _ in range(6)
    ]
    ans=0
    for i in range(n):
        for j in range(n):
            if a[i][j]==0:
                continue
            U[i][j]=U[i-1][j]+1 if i else 1
            L[i][j]=L[i][j-1]+1 if j else 1
            ans+=1
    for i in range(n-1,-1,-1):
        for j in range(n-1,-1,-1):
            if a[i][j]==0:
                continue
            D[i][j]=D[i+1][j]+1 if i!=n-1 else 1
            R[i][j]=R[i][j+1]+1 if j!=n-1 else 1
    for i in range(n):
        for j in range(n):
            ul[i][j]=min(U[i][j],L[i][j])
            dr[i][j]=min(D[i][j],R[i][j])
    dbg(ul)
    dbg(dr)
    """
    j>i
    i+di>j
    or
    j<i+di
    j-uj<i
    consider as points
    type 0: (j,j-uj)
    type 1: (i+di,i)
    sort all type together
    touch type 0, fen.add(j-uj,1)
    touch type 1, fen._sum(i)
    note when i>j, it is always true,
    so we sub these
    """
    def work(sx,sy):
        nonlocal ans
        dbg(f"sx={sx}, sy={sy}")
        i,j,k=sx,sy,0
        data=[]
        while i<n and j<n:
            if a[i][j]:
                dbg(f"i={i} j={j} k={k} ul={ul[i][j]} dr={dr[i][j]} ({k},{k-ul[i][j]+1},0) ({k+dr[i][j]},{k+1},1)")
                data.append((k,k-ul[i][j]+1,0))
                data.append((k+dr[i][j],k+1,1))
            i+=1
            j+=1
            k+=1
        data.sort(key=lambda x: x[0])
        fen=FenwickTree(n+1)
        cc=len(data)//2
        res=-cc*(cc+1)//2
        for _,x in enumerate(data):
            if x[2]: # type: 1
                res+=fen._sum(x[1]);
            else: # type: 0
                fen.add(x[1],1);
        dbg(f"res={res}")
        ans+=res;
        return
    work(0,0)
    for i in range(1,n):
        work(i,0)
        work(0,i)
    print(ans)
    return

multi_test = 0
if __name__ == "__main__":
    T = II() if multi_test else 1
    for _ in range(T):
        main()
