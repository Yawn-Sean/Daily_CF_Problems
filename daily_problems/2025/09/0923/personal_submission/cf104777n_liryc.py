'''
https://codeforces.com/gym/104777/submission/339953001
'''
def solve(n: int, a: list[int]) -> list[int]:
    trie = Trie01(n, n + 2) # ref template from Yawn_Sean
    
    for i in range(1, n - 1):
        a[i] ^= a[i - 1]
    
    trie.insert(0)
    for x in a:
        trie.insert(x)
    
    for i in range(n):
        if trie.findMaxXor(i) == n - 1:
            return [i] + [i ^ x for x in a]
