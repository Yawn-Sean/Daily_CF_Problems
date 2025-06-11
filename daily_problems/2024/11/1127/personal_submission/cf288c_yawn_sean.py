# Submission link: https://codeforces.com/contest/288/submission/293424044
def main():
    n = II()
    ans = list(range(n + 1))

    def solve(l, r):
        if l > r: return
        length = r - l + 1
        v = 1 << length.bit_length() - 1
        
        for i in range(l, r - v + 1):
            ans[i] ^= v
        
        for i in range(l + v, r + 1):
            ans[i] ^= v
        
        for i in range(r - v + 1, r + 1):
            ans[i] ^= v - 1
        
        solve(l, r - v)

    solve(0, n)
    print(n * (n + 1))
    print(' '.join(map(str, ans)))