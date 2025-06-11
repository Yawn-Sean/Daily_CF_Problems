# Submission link: https://codeforces.com/contest/663/submission/299834483
def main():
    equation = LI()

    res = int(equation[-1])
    pos = 1
    neg = 0

    for i in range(1, len(equation) - 2, 2):
        if equation[i] == '+':
            pos += 1
        else:
            neg += 1

    if pos - neg * res <= res <= pos * res - neg:
        print('Possible')
        to_add = res - (pos - neg * res)
        v1 = [1] * pos
        v2 = [res] * neg
        
        for i in range(pos):
            v = fmin(to_add, res - v1[i])
            v1[i] += v
            to_add -= v
        
        for i in range(neg):
            v = fmin(to_add, v2[i] - 1)
            v2[i] -= v
            to_add -= v

        for i in range(0, len(equation) - 1, 2):
            if i == 0 or equation[i - 1] == '+':
                equation[i] = str(v1.pop())
            else:
                equation[i] = str(v2.pop())
        print(' '.join(equation))
    else:
        print('Impossible')