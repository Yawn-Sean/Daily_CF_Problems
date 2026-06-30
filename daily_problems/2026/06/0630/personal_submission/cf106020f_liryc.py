'''
https://codeforces.com/gym/106020/submission/380648596
interactive
'''

def solve(n: int, k: int, a: list[int]):
    si = list(sorted(range(n), key = lambda i: ~a[i]))
    i1, i2 = 0, 0
    while si[i1] & 1:
        i1 += 1
    while not si[i2] & 1:
        i2 += 1
    c2 = i1 # number of evens reserved
    for i in range(k):
        x = int(input())
        j = -1
        if x == 1:
            if i2 < i1 and c2 > k - i - 1: # use even
                j = si[i2] 
                c2 -= 1
                i2 += 1
                while i2 < n and not si[i2] & 1:
                    i2 += 1
            else: # use odd
                j = si[i1]
                i1 += 1
                while i1 < n and si[i1] & 1:
                    if i1 >= i2:
                        c2 += 1
                    i1 += 1
        else: # x == 2
            j = si[i2]
            if i2 < i1: 
                c2 -= 1
            i2 += 1
            while i2 < n and not si[i2] & 1:
                i2 += 1
        print(j + 1, flush=True)
        if input() == '0':
            return
