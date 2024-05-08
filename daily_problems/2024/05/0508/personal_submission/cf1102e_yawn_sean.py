# Submission link: https://codeforces.com/contest/1102/submission/259934864
def main():
    n = II()
    # 防止卡哈希
    rnd = random.getrandbits(20)
    nums = [x ^ rnd for x in MII()]

    left = {}
    right = {}

    for i in range(n):
        if nums[i] not in left:
            left[nums[i]] = i
        right[nums[i]] = i

    diff = [0] * n

    for x in left:
        diff[left[x]] += 1
        diff[right[x]] -= 1

    ans = 1
    mod = 998244353
    for i in range(n - 1):
        diff[i+1] += diff[i]
        if diff[i] == 0:
            ans = ans * 2 % mod

    print(ans)