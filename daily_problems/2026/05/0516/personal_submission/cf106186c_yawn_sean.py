# Submission link: https://codeforces.com/gym/106186/submission/374606779
def main():  
    n, m = MII()
    prs = LII()
    nums = LII()
    
    cnt = [0] * (1 << m)
    
    for i in range(n):
        msk = 0
        for j in range(m):
            if nums[i] % prs[j] == 0:
                msk |= 1 << j
    
        cnt[msk] += 1
    
    for i in range(m):
        for j in range(1 << m):
            if j >> i & 1:
                cnt[j ^ (1 << i)] += cnt[j]
    
    mod = 10 ** 9 + 7
    
    for i in range(1 << m):
        cnt[i] = pow(2, cnt[i], mod) - 1
    
    for i in range(m):
        for j in range(1 << m):
            if j >> i & 1:
                nj = j ^ (1 << i)
                cnt[nj] = (cnt[nj] - cnt[j]) % mod
    
    val = [1] * (1 << m)
    
    for i in range(1, 1 << m):
        x = i & -i
        val[i] = val[i - x] * prs[x.bit_length() - 1] % mod
    
    print(sum(val[i] * cnt[i] % mod for i in range(1 << m)) % mod)