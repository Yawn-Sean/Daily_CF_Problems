# Submission link: https://codeforces.com/gym/102201/submission/389716289
def main():
    a, b = MII()
    
    ops = []
    
    while a != b:
        if a % 2 == 0:
            ops.append('B+=B')
            a //= 2
        elif b % 2 == 0:
            ops.append('A+=A')
            b //= 2
        elif a > b:
            ops.append('A+=B')
            ops.append('B+=B')
            a += b
            a //= 2
        else:
            ops.append('B+=A')
            ops.append('A+=A')
            b += a
            b //= 2
    
    print(len(ops))
    print('\n'.join(ops))