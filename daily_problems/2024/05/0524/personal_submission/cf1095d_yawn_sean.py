# Submission link: https://codeforces.com/contest/1095/submission/262321477
def main():
    n = II()
    v = [[], []]
    
    for _ in range(n):
        x, y = GMI()
        v[0].append(x)
        v[1].append(y)
    
    for i in range(2):
        ans = [0, v[i][0]]
        for _ in range(n):
            u = ans[-2]
            f = False
            next_u = -1
            for j in range(2):
                if v[j][u] == ans[-1]: f = True
                else: next_u = v[j][u]
            if not f: break
            else: ans.append(next_u)
        
        if len(ans) == n + 2 and check(ans):
            print(' '.join(str(x + 1) for x in ans[:n]))
            break