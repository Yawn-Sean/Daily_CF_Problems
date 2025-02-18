# Submission link: https://codeforces.com/contest/865/submission/284708977
def main():
    n, tot = MII()

    v1 = []
    c1 = []
    v2 = []
    c2 = []

    cnt1 = cnt2 = 0

    ans = 0

    for _ in range(n):
        s, a, b = MII()
        if a >= b:
            ans += s * a
            v1.append(a - b)
            c1.append(s)
            cnt1 += s
        else:
            ans += s * b
            v2.append(b - a)
            c2.append(s)
            cnt2 += s

    if (cnt1 + tot - 1) // tot + (cnt2 + tot - 1) // tot == (cnt1 + cnt2 + tot - 1) // tot:
        print(ans)
    else:
        res = 10 ** 10
        
        to_remove1 = cnt1 % tot
        st_range1 = sorted(range(len(v1)), key=lambda x: v1[x])
        
        val1 = 0
        for i in st_range1:
            c = fmin(to_remove1, c1[i])
            val1 += c * v1[i]
            to_remove1 -= c
        
        res = fmin(res, val1)
        
        to_remove2 = cnt2 % tot
        st_range2 = sorted(range(len(v2)), key=lambda x: v2[x])
        
        val2 = 0
        for i in st_range2:
            c = fmin(to_remove2, c2[i])
            val2 += c * v2[i]
            to_remove2 -= c
        
        res = fmin(res, val2)
        print(ans - res)