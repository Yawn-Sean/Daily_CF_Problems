def main():
    n = int(input())
    nums = list(map(int, input().split()))
    res = [1] * n
    cur = nums[-1]
    for i in range(n - 2, -1, -1):
        if abs(cur + nums[i]) < abs(cur - nums[i]):
            cur += nums[i]
        else:
            cur -= nums[i]
            res[i] = 0
    if cur < 0:
        for i in range(n):
            res[i] = 1 - res[i]
    print(''.join('+' if x == 1 else '-' for x in res))

main()