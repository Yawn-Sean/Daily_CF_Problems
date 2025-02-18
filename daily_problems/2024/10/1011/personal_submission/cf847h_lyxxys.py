import bisect
import collections
import heapq
import sys
import typing
input = lambda: sys.stdin.readline().strip()

def main():
    n = int(input())
    A = list(map(int, input().split()))
    if n == 1:
        print(0)
        return
    
    pr, pr_num, sf, sf_num = [0]*n, [0]*n, [0]*n, [0]*n
    pr_num[0], sf_num[n-1] = A[0], A[n-1]
    # 分别求前缀pr 和 后缀sf 的 递增\递减 的 最小值
    for i in range(1, n):
        pr_num[i] = max(pr_num[i-1]+1, A[i])
        pr[i] = pr[i-1] + pr_num[i]-A[i]
    
    for i in range(n-2, -1, -1):
        sf_num[i] = max(sf_num[i+1]+1, A[i])
        sf[i] = sf[i+1] + sf_num[i]-A[i]
    
    res = 1e18
    for i in range(n):
        if i == 0:
            res = min(res, sf[i])
        elif i == n-1:
            res = min(res, pr[i])
        else:
            x = max(sf_num[i], pr_num[i])
            res = min(res, x-A[i] + pr[i-1]+sf[i+1])
    
    print(res)
    
