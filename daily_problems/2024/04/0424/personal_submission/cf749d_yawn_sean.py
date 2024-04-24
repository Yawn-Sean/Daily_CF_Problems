# Submission link: https://codeforces.com/contest/749/submission/257916601
def main():
    n = II()
    bids = [[] for _ in range(n + 1)]
    max_bids = [-1] * (n + 1)

    for _ in range(n):
        person, bid = MII()
        bids[person].append(bid)
        max_bids[person] = max(max_bids[person], bid)

    order = sorted(range(n + 1), key=lambda x: max_bids[x])
    pos = [-1] * (n + 1)
    for i in range(n + 1):
        pos[order[i]] = i

    notes = [0] * (n + 1)

    q = II()
    outs = []

    for _ in range(q):
        k, *persons = MII()
        
        for p in persons:
            notes[pos[p]] = 1
        
        win, price_mi = -1, -1
        for i in range(n, -1, -1):
            if not notes[i]:
                if win == -1: win = order[i]
                else:
                    price_mi = max_bids[order[i]]
                    break
        
        if max_bids[win] == -1: outs.append('0 0')
        else:
            price = bids[win][bisect.bisect(bids[win], price_mi)]
            outs.append(f'{win} {price}')
        
        for p in persons:
            notes[pos[p]] = 0

    print('\n'.join(outs))