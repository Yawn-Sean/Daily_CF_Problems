#python 代码：
n, k = map(int, input().split())
if n > k * (k - 1):
    print('NO')
else:
    print('YES')
    cnt = 0
    for i in range(1, k + 1):
        for j in range(1, i):
            print(j, i)
            cnt += 1
            if cnt == n:
                break
            print(i, j)
            cnt += 1
            if cnt == n:
                break
        if cnt == n:
            break
