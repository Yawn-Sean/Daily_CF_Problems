# Submission link: https://codeforces.com/contest/1281/submission/303723963
def main():
    t = II()
    outs = []

    for _ in range(t):
        s1, s2 = LI()
        
        s1 = list(s1)
        k = len(s1)
        
        a, b = 0, 0
        pos = k - 1
        for i in range(k - 2, -1, -1):
            if s1[i] < s1[pos]:
                pos = i
            elif s1[i] > s1[pos]:
                a, b = i, pos
        
        s1[a], s1[b] = s1[b], s1[a]
        s1 = ''.join(s1)
        
        outs.append(s1 if s1 < s2 else '---')

    print('\n'.join(outs))