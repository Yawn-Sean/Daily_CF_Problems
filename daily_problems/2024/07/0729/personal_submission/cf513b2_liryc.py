'''
513 B2
2024/7/29 Y1
1800
排列组合
'''
if __name__ == '__main__':
    n, m = map(int, input().split())
    m -= 1
    a = [0] * n
    i, j = 0, -1
    for x in range(1, n):
        if m & 1 << (n - x - 1):
            a[j] = x
            j -= 1
        else:
            a[i] = x
            i += 1
    a[i] = n
    print(*a)