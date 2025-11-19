# Submission link: https://codeforces.com/gym/104936/submission/349723295
def main(): 
    n, k = MII()
    nums = LII()
    
    def solve(val):
        ans = 0
        
        trie = Trie01(n, (1 << 30) - 1)
        l = r = 0
        while l < n:
            while r < n:
                if l == r:
                    trie.insert(nums[l])
                else:
                    if trie.findMinXor(nums[r]) >= val:
                        trie.insert(nums[r])
                    else: break
                r += 1
            
            ans += r - l
            
            trie.delete(nums[l])
            l += 1
        
        return ans
    
    print(solve(k) - solve(k + 1))