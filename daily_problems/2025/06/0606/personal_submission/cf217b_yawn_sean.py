# Submission link: https://codeforces.com/contest/217/submission/323059045
def main():
    n, r = MII()

    chosen = -1
    cur = 10 ** 7

    for val in range(1, r + 1):
        a, b = r, val
        cnt = 0
        mistake = 0
        
        while b:
            x = a // b
            a, b = b, a % b
            
            cnt += x
            mistake += x - 1
        
        if a == 1 and cnt == n and mistake < cur:
            chosen = val
            cur = mistake

    if chosen == -1: exit(print('IMPOSSIBLE'))

    print(fmax(0, cur - 1))

    ar = []

    a, b = r, chosen

    while b:
        x = a // b
        a, b = b, a % b
        ar.append(x)

    ar[-1] -= 1
    ar.append(1)
    ar.reverse()

    print(''.join(ar[i] * ('B' if i & 1 else 'T') for i in range(len(ar))))