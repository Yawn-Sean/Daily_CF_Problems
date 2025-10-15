# Submission link: https://codeforces.com/contest/747/submission/321850520
def main():
    s = I().split(',')
    n = len(s)

    ans = []

    cur = [10 ** 7]

    for i in range(0, n, 2):
        x = s[i]
        v = int(s[i + 1])
        
        while cur[-1] == 0:
            cur.pop()
        
        if len(cur) - 1 == len(ans):
            ans.append([])
        ans[len(cur) - 1].append(x)
        
        cur[-1] -= 1
        
        cur.append(v)

    print(len(ans))
    print('\n'.join(' '.join(x) for x in ans))