# Submission link: https://codeforces.com/gym/102465/submission/365604860
def main(): 
    n = II()
    names = []
    scores = []
    others = []
    
    for _ in range(n):
        x, y = LI()
        names.append(x)
        y = int(y)
        
        if y == 0:
            scores.append(0)
            others.append(49)
        elif y == 100:
            scores.append(9950)
            others.append(50)
        else:
            scores.append(y * 100 - 50)
            others.append(99)
    
    total = sum(scores)
    total_other = sum(others)
    
    if total > 10000 or total + total_other < 10000:
        print('IMPOSSIBLE')
    else:
        resid = 10000 - total
        
        for i in range(n):
            mi = scores[i] + fmax(0, resid - (total_other - others[i]))
            ma = scores[i] + fmin(others[i], resid)
    
            print(f'{names[i]} {mi // 100}.{mi % 100:02d} {ma // 100}.{ma % 100:02d}')