import sys
input = lambda: sys.stdin.readline().strip()
MII = lambda: map(int, input().split())
from itertools import groupby
from math import gcd

def solve():
    # 為啥需要考慮特判? 有可能一開始gcd為奇數
    # eg:3,6,9, 這種不需要處理，否則轉換為偶數最快(因為2是最小gcd)
    if gcd(*a) > 1: # *a新用法
        print('YES')
        print(0)
        return 
    
    # 奇偶性分組，只需處理奇數
    ans = 0
    for k, v in groupby(a, key=lambda x: x & 1):
        if k == 0:
            continue
        odds = len(list(v))
        if odds & 1 == 0:
            ans += odds >> 1 # 兩個兩個一組處理
        else:
            ans += (odds >> 1) + 2 # 會剩最後一個奇數，要處理兩次
    
    print('YES')    
    print(ans)
    
               
for _ in range(1):
    n = int(input())
    a = list(MII())
    solve()