def main():
    t = II()
    outs = []
    
    for _ in range(t):
        x, y = MII()
        for i in range(2, max(x, y) + 1):
            if math.gcd(x, i) == 1 and math.gcd(y, i) == 1:
                outs.append(i)
                break
        else: outs.append(-1)

    print('\n'.join(map(str, outs)))