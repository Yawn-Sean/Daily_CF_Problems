def main():
    n, k = map(int, sys.stdin.readline().split())
    a = list(map(int, sys.stdin.readline().split()))
    total = sum(a)
    
    if k > total:
        print(-1)
        return
    
    def check(x):
        s = 0
        for num in a:
            s += min(num, x)
            if s > k:
                return False
        return True
    
    left, right = 0, total
    while left <= right:
        mid = (left + right) // 2
        if check(mid):
            left = mid + 1
        else:
            right = mid - 1
    
    sum_r = sum(min(num, right) for num in a)
    leftover = k - sum_r
    
    st = 0
    flag = True
    for i in range(n):
        a[i] -= min(a[i], right)
        if a[i] > 0:
            if leftover == 0 and flag:
                flag = False
                st = i
            elif leftover > 0:
                leftover -= 1
                a[i] -= 1
    
    output = []
    for i in range(st, n):
        if a[i] > 0:
            output.append(str(i + 1))
    for i in range(st):
        if a[i] > 0:
            output.append(str(i + 1))
    
    print(' '.join(output))
