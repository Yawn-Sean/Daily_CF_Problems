# Submission link: https://codeforces.com/contest/215/submission/292695199
def main():
    def f(x):
        k = x.bit_length()
        ans = [0] * (k + 1)
        for l in range(1, k):
            for divisor in range(1, l):
                if l % divisor == 0:
                    ans[l // divisor] += 1 << divisor - 1
        
        for divisor in range(1, k):
            if k % divisor == 0:
                msk = 0
                for j in range(0, k, divisor):
                    msk |= 1 << j
                ans[k // divisor] += fmax(0, x // msk - (1 << divisor - 1) + 1)
        
        res = 0
        for i in range(k, 1, -1):
            for j in range(i * 2, k + 1, i):
                ans[i] -= ans[j]
            res += ans[i]
        
        return res

    l, r = MII()
    print(f(r) - f(l - 1))