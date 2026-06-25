'''
20260625 T1
'''
def main(n: int, a: list[int]) -> int:
    ans = 0
    ia = [i for i in range(n) if a[i]]
    
    for i in range(1, len(ia)):
        x = ia[i - 1]
        y = ia[i]
        if min(a[x], a[y]) == 1 and max(a[x], a[y]) <= 2:
            lx = ia[i - 2] if i - 2 >= 0 else -1
            ry = ia[i + 1] if i + 1 < len(ia) else n
            
            ans += (x - lx) * (ry - y)
            if y - x == 1: ans -= 1
    
    return ans