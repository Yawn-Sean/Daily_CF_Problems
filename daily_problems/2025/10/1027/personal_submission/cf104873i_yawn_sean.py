# Submission link: https://codeforces.com/gym/104873/submission/345849145
def main(): 
    def query(idxs):
        print('?', len(idxs), *idxs, flush=True)
        _, *res = MII()
        return res
    
    def answer(ans):
        print('!', ' '.join(f'{len(v)} {" ".join(map(str, v))}' for v in ans))
    
    n = II()
    ans = [[] for _ in range(n)]
    
    if n == 1: ans[0] = query([1])
    else:
        for i in range(0, n, n // 2):
            idxs = []
            for j in range(i, i + n // 2):
                if j >= n: break
                idxs.append(j + 1)
                idxs.append(j + 1)
            
            k = len(idxs) // 2
            res = query(idxs)
            
            pt = 0
            for j in range(i, i + k):
                npt = pt + 1
                while res[npt] != res[pt]:
                    npt += 1
                ans[j] = res[pt:npt]
                pt = 2 * npt - pt
    
    answer(ans)