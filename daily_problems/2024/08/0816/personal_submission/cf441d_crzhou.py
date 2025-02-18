def build(n, a):
    in_arr = [0] * (n + 1)
    siz = [0] * (n + 1)
    tot = 0
    for i in range(1, n + 1):
        if in_arr[i] == 0:
            tot += 1
            siz[tot] = 1
            in_arr[i] = tot
            j = a[i]
            while j != i:
                in_arr[j] = tot
                siz[tot] += 1
                j = a[j]
    return tot, in_arr, siz

def main():
    data = input().split()
    idx = 0
    
    n = int(data[idx])
    idx += 1
    
    a = [0] * (n + 1)
    for i in range(1, n + 1):
        a[i] = int(data[idx])
        idx += 1
    
    tot, in_arr, siz = build(n, a)
    
    m = int(data[idx])
    idx += 1
    
    print(abs(n - tot - m))
    
    if n - tot > m:
        while n - tot > m:
            for i in range(1, n + 1):
                if siz[in_arr[i]] >= 2:
                    lag = 0
                    for j in range(i + 1, n + 1):
                        if in_arr[j] == in_arr[i]:
                            lag = j
                            break
                    a[i], a[lag] = a[lag], a[i]
                    print(i, lag, end=' ')
                    break
            tot, in_arr, siz = build(n, a)
    else:
        while n - tot < m:
            for i in range(2, n + 1):
                if in_arr[i] != in_arr[1]:
                    a[1], a[i] = a[i], a[1]
                    print(1, i, end=' ')
                    break
            tot, in_arr, siz = build(n, a)
