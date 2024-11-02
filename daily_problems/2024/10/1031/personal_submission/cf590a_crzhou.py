def main():
    data = input().split()
    n = int(data[0])
    a = list(map(int, data[1:n + 1]))

    if n <= 2:
        print("0")
        print(" ".join(map(str, a)))
        return

    belong = [0] * (n + 1)
    Whi = [0] * (n + 1)
    cnt = 0
    flag = [0] * (n + 1)
    to = [0] * (n + 1)
    ans = 0

    belong[1] = 1
    Whi[1] = a[0]
    cnt = 1

    for i in range(1, n - 1):
        if a[i] != a[i - 1]:
            cnt += 1
            belong[cnt] += 1
            Whi[cnt] = a[i]
        else:
            belong[cnt] += 1

    if a[n - 1] == a[n - 2]:
        belong[cnt] += 1
    else:
        cnt += 1
        belong[cnt] += 1
        Whi[cnt] = a[n - 1]

    flag[1] = flag[cnt] = 1 
    for i in range(2, cnt):
        flag[i] = 0 if belong[i] == 1 else 1

    lasti = 1
    for i in range(2, cnt + 1):
        if flag[i]:
            to[lasti] = i
            num = i - lasti - 1
            if num % 2 == 1:
                ans = max(ans, num // 2 + 1)
            else:
                ans = max(ans, num // 2)
            lasti = i

    to[cnt] = cnt + 1
    print(ans)

    i = 1
    while i <= cnt:
        To = to[i]
        num = To - i - 1
        for j in range(belong[i]):
            print(Whi[i], end=" ")
        if num % 2 == 1:
            for j in range(num):
                print(Whi[i], end=" ")
        else:
            for j in range(num // 2):
                print(Whi[i], end=" ")
            for j in range(num // 2):
                print(Whi[To], end=" ")
        i = To
