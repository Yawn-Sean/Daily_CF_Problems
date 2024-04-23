# Submission link: https://codeforces.com/contest/922/submission/257796777
def main():
    def cmp(i, j):
        if hs[i] * ss[j] > ss[i] * hs[j]: return 1
        if hs[i] * ss[j] < ss[i] * hs[j]: return -1
        return 0

    n = II()
    strs = [I() for _ in range(n)]
    hs = [s.count('h') for s in strs]
    ss = [s.count('s') for s in strs]

    st_range = sorted(range(n), key=cmp_to_key(cmp))
    cnt_s = 0
    ans = 0
    for i in st_range:
        for c in strs[i]:
            if c == 's': cnt_s += 1
            else: ans += cnt_s

    print(ans)