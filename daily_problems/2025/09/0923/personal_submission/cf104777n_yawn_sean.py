# Submission link: https://codeforces.com/gym/104777/submission/339839133
def main():
    n = II()
    nums = LII()
    
    trie = Trie01(n, n + 2)
    
    for i in range(1, n - 1):
        nums[i] ^= nums[i - 1]
    
    trie.insert(0)
    for x in nums:
        trie.insert(x)
    
    for i in range(n):
        if trie.findMaxXor(i) == n - 1:
            ans = [i] + [i ^ x for x in nums]
            print(' '.join(map(str, ans)))
            break