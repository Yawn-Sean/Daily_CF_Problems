# Submission link: https://codeforces.com/contest/1082/submission/305383053
def main():
    n = II()
    nums = LII()

    chain = [i for i in range(n) if nums[i] > 1]
    nodes = [i for i in range(n) if nums[i] == 1]

    l = len(chain)

    if l == 0: print('NO')
    else:
        edges = []
        if l > 1:
            nums[chain[0]] -= 1
            nums[chain[-1]] -= 1
            for i in range(1, l - 1):
                nums[chain[i]] -= 2
        
        ans = l - 1
        for i in range(1, l):
            edges.append(f'{chain[i - 1] + 1} {chain[i] + 1}')
        
        f1 = False
        f2 = False
        
        for u in nodes:
            if not f1:
                f1 = True
                nums[chain[0]] -= 1
                edges.append(f'{u + 1} {chain[0] + 1}')
            
            elif nums[chain[-1]]:
                f2 = True
                nums[chain[-1]] -= 1
                edges.append(f'{u + 1} {chain[-1] + 1}')
            
            else:
                for v in chain:
                    if nums[v]:
                        nums[v] -= 1
                        edges.append(f'{u + 1} {v + 1}')
                        break
                else:
                    exit(print('NO'))
        
        print('YES', ans + f1 + f2)
        print(n - 1)
        print('\n'.join(edges))