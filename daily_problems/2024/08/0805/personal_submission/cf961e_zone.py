"""
https://codeforces.com/contest/961/submission/274464980

This is equivalent to find the number of j that satisfy 1) 0 <= j <= min(i - 1, a[i]) and 2) a[j] >= i.
"""
def main():
    n = II() 
    a = LGMI() 
    b = [min(i - 1, x) for i, x in enumerate(a)]
    
    ans = 0
    loc = sorted(list(range(n)), key=lambda x: b[x])
    t   = SortedList() 
    lst = 0 
    
    for i in loc: 
        while lst <= b[i]: 
            t.add(a[lst])
            lst += 1 
        ans += len(t) - bisect.bisect_left(t, i)
    print(ans)
