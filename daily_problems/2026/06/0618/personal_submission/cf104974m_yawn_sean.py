# Submission link: https://codeforces.com/gym/104974/submission/379199612
def main():
    n, k = MII()
    nums = LII()
    
    M = 10 ** 6 + 5
    
    notes = [0] * M
    
    for _ in range(n - 1):
        u, v = GMI()
        notes[nums[u]] += 1
        notes[nums[v]] += 1
        notes[math.gcd(nums[u], nums[v])] -= 1
    
    for x in nums:
        notes[x] -= 1
    
    notes[nums[0]] += 1
    
    ans = []
    
    for i in range(1, k + 1):
        res = 0
        for j in range(i, M, i):
            res += notes[j]
        if nums[0] % i:
            res += 1
        ans.append(res)
    
    print(' '.join(map(str, ans)))