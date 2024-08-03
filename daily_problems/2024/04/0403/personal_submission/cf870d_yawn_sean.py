# Submission link: https://codeforces.com/contest/870/submission/254778689
def main():
    def query(i, j):
        print('?', i, j, flush=True)
        return II()

    n = II()
    v1 = [0] * n
    v2 = [0] * n

    for i in range(n):
        v1[i] = query(i, 0)

    v2[0] = v1[0]
    for i in range(1, n):
        v2[i] = query(0, i)

    ans = None
    cnt = 0
    for i in range(n):
        p = [-1] * n
        b = [-1] * n
        
        p[0] = i
        for j in range(n):
            b[j] = v2[j] ^ p[0]
        
        for j in range(n):
            p[j] = v1[j] ^ b[0]
        
        for j in range(n):
            if b[j] >= n or p[b[j]] != j: break
        else:
            ans = p
            cnt += 1

    print('!')
    print(cnt)
    print(*ans)