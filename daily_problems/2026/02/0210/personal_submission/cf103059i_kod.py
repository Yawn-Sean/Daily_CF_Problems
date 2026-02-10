n = ix()
if n == 1:print(1)
elif n == 4:print('1 3 2 4')
else:
    for i in range(2, n):
        if n % i == 0:
            print(-1)
            break
    else:
        ans = [1]
        for i in range(2, n):
            ans += i * pow(i - 1, -1, n) % n,
        ans += [n]
        print(*ans)
