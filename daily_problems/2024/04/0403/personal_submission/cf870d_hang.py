def query(i,j):
    print("?",i,j,flush=True)
    return int(input())

def main():
    n = int(input())
    p_b = [0] * (n)
    b_p = [0] * (n)
    for i in range(n):
        p_b[i] = query(i, 0)
    b_p[0] = p_b[0]
    for i in range(1, n):
        b_p[i] = query(0, i)
    
    ans = []
    res = 0
    for i in range(n):
        p = [-1] * n
        b = [-1] * n
        p[0] = i
        for j in range(n):
            b[j] = b_p[j] ^ p[0]
        for j in range(n):
            p[j] = p_b[j] ^ b[0]
        
        for j in range(n):
            if b[j] >= n or p[b[j]] != j: break
        else:
            ans = p
            res += 1
    print('!')
    print(res)
    print(*ans)
    