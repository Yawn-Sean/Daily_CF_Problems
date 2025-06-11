# Submission link: https://codeforces.com/contest/1278/submission/278451463
def main():
    t = II()
    outs = []

    for _ in range(t):
        n = II()
        nums1 = LII()
        pref = [-n] * (2 * n + 1)
        
        cur = 0
        pref[0] = 0
        for i in range(n):
            cur += 1 if nums1[i] == 1 else -1
            pref[cur] = i + 1
        
        cur = 0
        ma = pref[0]
        for i in range(2 * n - 1, n - 1, -1):
            cur += 1 if nums1[i] == 1 else -1
            ma = fmax(ma, pref[-cur] + 2 * n - i)
        
        outs.append(2 * n - ma)

    print('\n'.join(map(str, outs)))