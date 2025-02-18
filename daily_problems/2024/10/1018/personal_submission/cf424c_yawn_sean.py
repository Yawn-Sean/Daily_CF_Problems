# Submission link: https://codeforces.com/contest/424/submission/286456777
def main():
    def pref_xor(x):
        if x % 4 == 0: return x
        if x % 4 == 1: return 1
        if x % 4 == 2: return x + 1
        return 0

    n = II()
    nums = LII()

    ans = reduce(xor, nums)

    for i in range(1, n + 1):
        x = n % (2 * i)
        if x >= i: ans ^= pref_xor(i - 1) ^ pref_xor(x - i)
        else: ans ^= pref_xor(x)

    print(ans)