# Submission link: https://codeforces.com/gym/105010/submission/376542987
def main():
    n, k = MII()
    nums = LII()
    
    c = 0
    for x in nums:
        if x % k: c += 1
    
    if c == 0:
        print('Rami')
    elif c == 2:
        print('Oussama')
    else:
        print('Oussama' if n % 2 == 0 else 'Rami')