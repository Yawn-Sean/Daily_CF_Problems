# Submission link: https://codeforces.com/contest/380/submission/312870022
def main():
    m = II()
    ar_pref = []

    notes = []
    lengths = [0]

    M = 10 ** 5

    for _ in range(m):
        tmp = LII()
        if tmp[0] == 1:
            if len(ar_pref) < M:
                ar_pref.append(tmp[1])
            
            notes.append(-tmp[1])
            lengths.append(lengths[-1] + 1)
        else:
            l = tmp[1]
            c = tmp[2]
            
            for i in range(l * c):
                if len(ar_pref) == M: break
                ar_pref.append(ar_pref[i % l])
            
            notes.append(l)
            lengths.append(lengths[-1] + l * c)

    q = II()
    queries = LII()

    ans = [-1] * q
    for i in range(q):
        x = queries[i] 
        p = bisect.bisect_left(lengths, x) - 1
        if notes[p] < 0: ans[i] = -notes[p]
        else: ans[i] = ar_pref[(x - 1 - lengths[p]) % notes[p]]

    print(' '.join(map(str, ans)))