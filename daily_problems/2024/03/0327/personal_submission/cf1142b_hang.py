# https://codeforces.com/contest/1142/submission/253481243
def main():
    n,m,q = map(int,input().split())
    p = list(map(int,input().split()))
    pos = [0] * n
    for i in range( n):
        pos[p[i] - 1] = i
    a = list(map(int,input().split()))
    b = [pos[x-1] for x in a]
    pos = [m] * n
    n_pos = [m] * m
    for i in range(m-1, -1, -1):
        n_pos[i] = pos[(b[i] + 1) % n]
        pos[b[i]] = i
    search = list(range(m))
    n -= 1
    for i in range(n.bit_length()):
        if n >> i & 1:
            search = [n_pos[x] if x < m else m for x in search]
        n_pos = [n_pos[x] if x < m else m for x in n_pos]
    for  i in range(m-1, 0, -1):
        if search[i-1] > search[i]:
            search[i-1] = search[i]
        
    ans = []
    for i in range(q):
        l,r = map(int,input().split())
        l-=1
        r-=1
        ans.append(1 if search[l] <= r else 0)
    print(''.join(map(str,ans)))

main()