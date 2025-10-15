# Submission link: https://codeforces.com/contest/633/submission/320704049
def main():
    n = II()
    nums = LII()

    rnd = random.getrandbits(30)

    cnt = Counter()
    for x in nums:
        cnt[x ^ rnd] += 1

    ans = 0
    if rnd in cnt:
        ans = cnt[rnd]

    for i in range(n):
        for j in range(n):
            if i == j or (nums[i] == 0 and nums[j] == 0): continue
            
            cur = [nums[i], nums[j]]
            cnt[cur[0] ^ rnd] -= 1
            cnt[cur[1] ^ rnd] -= 1
            
            while True:
                cur.append(cur[-1] + cur[-2])
                if cur[-1] ^ rnd not in cnt or cnt[cur[-1] ^ rnd] == 0:
                    cur.pop()
                    break
                cnt[cur[-1] ^ rnd] -= 1
            
            ans = fmax(ans, len(cur))
            
            for v in cur:
                cnt[v ^ rnd] += 1

    print(ans)