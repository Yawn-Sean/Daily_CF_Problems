def main():
    a = int(input())
    nums = [int(x) for x in input()]
    n = len(nums)
    c = [0] * (9 * n + 1)
    for i in range(n):
        cur = 0
        for j in range(i,n):
            cur += nums[j]
            c[cur] += 1
    if a == 0:
        t = n * (n + 1) // 2
        print(t * t - (t - c[0]) * (t - c[0]))
    else:
        ans = 0
        for i in range(1, 9 * n + 1):
            if a % i == 0 and a // i <= 9 * n:
                ans += c[i] * c[a // i]
        print(ans)
main()