# Submission link: https://codeforces.com/gym/102331/submission/393478402
def main():
    n, x = MII()
    nums = LII()
    nums.sort()
    
    mod = 998244353
    
    if x == 0:
        print(pow(2, n, mod) - 1)
    else:
        k = x.bit_length()
        bit = 1 << k
    
        def solve(l, r):
            trie = Trie01(r - l, x)
            res = r - l + 1
            cnt = 0
            
            for i in range(l, r):
                res += cnt - trie.countLowXor(nums[i], x)
                res %= mod
                
                cnt += 1
                trie.insert(nums[i])
            
            return res
    
        ans = 1
        l = 0
    
        for i in range(n):
            if nums[i] // bit != nums[l] // bit:
                ans = ans * solve(l, i) % mod
                l = i
    
        ans = ans * solve(l, n) % mod
        print((ans - 1) % mod)