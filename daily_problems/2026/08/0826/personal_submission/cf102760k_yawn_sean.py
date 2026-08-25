# Submission link: https://codeforces.com/gym/102760/submission/388306457
def main():
    n = II()
    pts = [tuple(MII()) for _ in range(n)]
    
    order = sorted(range(n), key=lambda x: pts[x])
    for i in range(n - 2, -1, -1):
        order.append(order[i])
    
    print(2 * n - 1)
    print(' '.join(str(x + 1) for x in order))