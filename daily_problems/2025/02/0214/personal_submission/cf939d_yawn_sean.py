# Submission link: https://codeforces.com/contest/939/submission/306017736
def main():
    n = II()
    s1 = I()
    s2 = I()

    dsu = UnionFind(26)
    ans = []

    for i in range(n):
        if dsu.merge(ord(s1[i]) - ord('a'), ord(s2[i]) - ord('a')):
            ans.append(f'{s1[i]} {s2[i]}')

    print(len(ans))
    print('\n'.join(ans))