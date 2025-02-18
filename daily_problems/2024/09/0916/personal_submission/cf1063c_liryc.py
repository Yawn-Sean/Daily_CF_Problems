'''
https://codeforces.com/contest/1063/submission/281482900
1063C
2024/9/16 Y2
1900
interative
'''

def query(x, y):
    print(x, y, flush=True)
    s = input()
    return s == 'white'

if __name__ == '__main__':
    n = int(input())
    l, r = 0, 1000000000

    flg = query(r, r)

    for _ in range(n - 1):
        m = l + r >> 1
        if query(m, m) == flg: 
            r = m
        else: 
            l = m

    print(l, r, r, l)