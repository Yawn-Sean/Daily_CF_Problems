# Submission link: https://codeforces.com/contest/1255/submission/326211625
def main():
    n = II()

    cnt = [0] * (n + 1)
    path = defaultdict(list)

    for i in range(n - 2):
        tmp = LII()
        tmp.sort()
        
        u, v, w = tmp
        cnt[u] += 1
        cnt[v] += 1
        cnt[w] += 1
        
        path[(u, v)].append(w)
        path[(u, w)].append(v)
        path[(v, w)].append(u)

    for i in range(n + 1):
        if cnt[i] == 1:
            ans = [i]
            
            for u, v in path:
                if u == i and cnt[v] == 2:
                    ans.append(v)
                    break
                if v == i and cnt[u] == 2:
                    ans.append(u)
                    break
            
            for i in range(n - 2):
                u, v = ans[-2], ans[-1]
                if u > v: u, v = v, u
                
                for w in path[(u, v)]:
                    if len(ans) == 2 or ans[-3] != w:
                        ans.append(w)
                        break
            
            print(' '.join(map(str, ans)))
            
            break