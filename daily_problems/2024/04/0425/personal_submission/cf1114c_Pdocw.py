def main():
    n, b = MII()
    # n! 在 b 进制下的末尾0位数
    prime_factorization = []

    for i in range(2, b + 1):
        if i * i > b:
            break
        if b % i == 0:
            cnt = 0
            while b % i == 0:
                cnt += 1
                b //= i
            prime_factorization.append((i, cnt))

    if b > 1:
        prime_factorization.append((b, 1))
    # print(prime_factorization)
    ans = inf
    for p, c in prime_factorization:
        cur = n
        cnt = 0  # # 计算 n! 中 p 的个数
        while cur:
            cur //= p
            cnt += cur
        ans = min(ans, cnt // c)

    print(ans)
    return
