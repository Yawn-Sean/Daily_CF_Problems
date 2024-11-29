# Submission link: https://codeforces.com/contest/163/submission/291510669
def main():
    n, l, v1, v2 = MII()
    nums = LII()
    rnd = random.getrandbits(20)

    l *= v1 + v2
    for i in range(n):
        nums[i] *= v1 + v2
        nums[i] += rnd
        nums[i] %= 2 * l

    tmp = l // (v1 + v2) * v2

    diff = Counter()
    for x in nums:
        if x + tmp <= 2 * l:
            diff[x] += 1
            diff[x + tmp] -= 1
        else:
            diff[x] += 1
            diff[2 * l] -= 1
            diff[0] += 1
            diff[x + tmp - 2 * l] -= 1

    diff[2 * l] += 0

    ans = [0] * (n + 1)
    last, cur = 0, 0

    for x in sorted(diff):
        ans[cur] += x - last
        cur += diff[x]
        last = x

    print('\n'.join(str(x / (2 * l)) for x in ans))