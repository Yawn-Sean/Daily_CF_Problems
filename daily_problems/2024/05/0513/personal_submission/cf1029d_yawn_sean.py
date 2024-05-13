# Submission link: https://codeforces.com/contest/1029/submission/260722681
def main():
    n, k = MII()
    nums = LII()

    # 防止卡哈希
    rnd = random.getrandbits(20)

    cnts = [Counter() for _ in range(11)]
    for num in nums:
        cnts[len(str(num))][(num % k) ^ rnd] += 1

    ans = 0
    for num in nums:
        cur = num
        d = len(str(num))
        for digit in range(1, 11):
            cur *= 10
            cur %= k
            ans += cnts[digit][((-cur) % k) ^ rnd]
            if digit == d and (cur + num) % k == 0:
                ans -= 1 

    print(ans)