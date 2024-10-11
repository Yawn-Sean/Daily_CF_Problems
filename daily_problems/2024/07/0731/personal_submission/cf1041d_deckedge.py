def solve():
    n, h = MII()
    a, b = [], []
    sum_b = [0] * n  
    for i in range(n):
        l, r = MII()
        dis = r - l
        a.append((r - l, l, r))
    for i in range(1, n):  
        b.append((a[i][1] - a[i-1][2], a[i-1][2], a[i][1]))  
        sum_b[i] = sum_b[i-1] + b[i-1][0]  
  
    pre_up = [0] * (n + 1)  
    for i in range(1, n + 1):  
        pre_up[i] = pre_up[i - 1] + a[i - 1][0]  
  
    res = 0  
    for i in range(n):  
        low, high = 0, n - 1  
        while low < high:  
            mid = (low + high + 1) // 2  
            if sum_b[mid] - sum_b[i] < h:  
                low = mid  
            else:  
                high = mid - 1  
        if sum_b[low] - sum_b[i] >= h:  
            low -= 1  
        dis = pre_up[low + 1] - pre_up[i] + sum_b[low] - sum_b[i]  
        dis += h - (sum_b[low] - sum_b[i])  
        res = max(res, dis)  
  
    print(res) 

def main():
    t = 1
    while t:
        solve()
        t -= 1
main()