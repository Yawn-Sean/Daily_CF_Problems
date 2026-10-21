# Submission link: https://codeforces.com/gym/105122/submission/395417722
def main():
    k = II()
    n = II()
    
    outs = []
    
    for _ in range(n):
        if random.randint(1, k * (k + 1) // 2) <= k:
            x = random.randint(1, k)
            outs.append(f'{x} {x}')
        else:
            while True:
                x = random.randint(1, k)
                y = random.randint(1, k)
                if x != y: break
            if x > y: x, y = y, x
            outs.append(f'{x} {y}')
    
    print('\n'.join(outs))