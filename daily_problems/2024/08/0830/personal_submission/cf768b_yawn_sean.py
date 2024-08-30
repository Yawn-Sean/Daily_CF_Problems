# Submission link: https://codeforces.com/contest/768/submission/278702962
def main():
    def solve(n, l, r):
        if n == 0: return 0
        if n == 1: return 1
        k = n.bit_length() - 1
        length = (1 << k) - 1
        ans = 0
        if l < length: ans += solve(n // 2, l, fmin(r, length - 1))
        if l <= length and r >= length: ans += n % 2
        if r > length: ans += solve(n // 2, fmax(0, l - length - 1), r - length - 1)
        return ans

    n, l, r = MII()
    l -= 1
    r -= 1
    print(solve(n, l, r))