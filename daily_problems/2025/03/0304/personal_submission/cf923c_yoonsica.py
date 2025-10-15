import sys

RI = lambda: int(sys.stdin.readline().strip())
RS = lambda: sys.stdin.readline().strip()
RII = lambda: map(int, sys.stdin.readline().strip().split())
RILIST = lambda: list(RII())
mx = lambda x, y: x if x > y else y
mn = lambda x, y: y if x > y else x

def main():
    zero = [0] * (10 ** 7)
    one = [0] * (10 ** 7)
    cnt = [0] * (10 ** 7)
    pt = 0
    
    def insert(x):
        cur = 0
        nonlocal pt
        for i in range(29, -1, -1):
            if x >> i & 1:
                if one[cur] == 0:
                    pt += 1
                    one[cur] = pt
                cur = one[cur]
            else:
                if zero[cur] == 0:
                    pt += 1
                    zero[cur] = pt
                cur = zero[cur]
            cnt[cur] += 1
    
    def delete(x):
        cur = 0
        for i in range(29, -1, -1):
            cur = one[cur] if x >> i & 1 else zero[cur]
            cnt[cur] -= 1
    
    def minXor(x):
        cur = 0
        ans = 0
        for i in range(29, -1, -1):
            if x >> i & 1:
                if one[cur] and cnt[one[cur]]:
                    cur = one[cur]
                else:
                    cur = zero[cur]
                    ans |= 1 << i
            else:
                if zero[cur] and cnt[zero[cur]]:
                    cur = zero[cur]
                else:
                    cur = one[cur]
                    ans |= 1 << i
        return ans
    
    
    '''
    https://codeforces.com/problemset/problem/923/C
    有长度为 n 的数列 a,b，将数列 b 重新排列，使得数列 c 字典序最小
    c[i] = a[i] ^ b[i]
    '''
    n, a, b = RI(), RILIST(), RILIST()
    ans = []
    for x in b:
        insert(x)
        
    for x in a:
        t = minXor(x)
        ans.append(t)
        delete(x ^ t)
    print(' '.join(map(str, ans)))
    
main()