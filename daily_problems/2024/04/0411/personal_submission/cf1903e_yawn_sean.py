# Submission link: https://codeforces.com/contest/1903/submission/256060475

def main():
    def delete():
        while v0 and used[v0[-1]]: v0.pop()
        while v1 and used[v1[-1]]: v1.pop()

    n = II()
    msk = sum(MII()) & 1
    used = [0] * (n + 1)
    
    v0 = []
    v1 = []
    for i in range(1, n + 1):
        if (sum(MII()) & 1) ^ msk: v1.append(i)
        else: v0.append(i)
    
    used = [0] * (n + 1)
    
    if len(v0) >= len(v1):
        print('First')
        for i in range(n):
            delete()
            if i % 2 == 0: print(v1.pop() if v1 else v0.pop(), flush=True)
            else: used[II()] = 1
    
    else:
        print('Second', flush=True)
        for i in range(n):
            delete()
            if i % 2: print(v0.pop() if v0 else v1.pop(), flush=True)
            else: used[II()] = 1