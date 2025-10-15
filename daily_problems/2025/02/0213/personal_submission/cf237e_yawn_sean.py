# Submission link: https://codeforces.com/contest/237/submission/305877543
def main():
    s = I()
    target = len(s)
    cnt = [0] * 26

    for c in s:
        cnt[ord(c) - ord('a')] += 1

    n = II()

    mcf = MCFGraph(n + 28)
    src = n + 26
    dst = n + 27

    for i in range(26):
        if cnt[i] > 0:
            mcf.add_edge(n + i, dst, cnt[i], 0)

    for i in range(n):
        si, ai = LI()
        ai = int(ai)
        
        mcf.add_edge(src, i, ai, i + 1)
        
        for j in range(26):
            cnt[j] = 0
        
        for c in si:
            cnt[ord(c) - ord('a')] += 1
        
        for j in range(26):
            mcf.add_edge(i, n + j, cnt[j], 0)

    f, c = mcf.flow(src, dst)
    print(c if f == target else -1)