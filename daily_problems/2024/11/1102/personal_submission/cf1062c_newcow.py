# https://codeforces.com/problemset/problem/1062/C

def solve():
    n,q = map(int,input().split())
    mod = 10 ** 9 + 7
    s = input()
    pre = [0]

    for c in s:
        if c == '1':
            pre.append(pre[-1] + 1)
        else:
            pre.append(pre[-1])

    for _ in range(q):
        l,r = map(int,input().split())

        sum_ = pre[r] - pre[l - 1]

        if sum_ == r - l + 1:
            print(pow(2,sum_,mod) - 1)
        else:
            print( (pow(2,r-l+1,mod) - pow(2,r-l+1-sum_,mod)) % mod)

solve()
