# Submission link: https://codeforces.com/contest/1214/submission/303448940
def main():
    n = II()
    nums = LII()
    st_range = sorted(range(n), key=lambda x: -nums[x])

    chain = [2 * x + 1 for x in st_range]

    outs = []
    for i in range(1, n):
        outs.append(f'{chain[i - 1]} {chain[i]}')

    for i in range(n):
        pos = st_range[i]
        dis = nums[pos]
        
        u = 2 * pos + 2
        v = chain[i + dis - 1]
        outs.append(f'{u} {v}')
        
        if chain[-1] == v: chain.append(u)

    print('\n'.join(outs))