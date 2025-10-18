'''
https://codeforces.com/gym/105408/submission/344420007
'''
# prime factors, gcd

# def prime_elements(n: int): -> enum all prime factors

def solve(n: int, a: list[int]) -> bool:
    ps = set()
    g = gcd(a[0], a[1])
    for x in a:
        y, m = divmod(x, g)
        if m != 0:
            return False
        for p, _ in prime_elements(y):
            if p in ps:
                return False
            ps.add(p)
    return True
