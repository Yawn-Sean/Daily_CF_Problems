# Submission link: https://codeforces.com/gym/104785/submission/346421863
def main(): 
    n, m = MII()
    
    idxs1 = []
    idxs2 = []
    
    for i in range(1, m + 1):
        x, y = MII()
        if x < y: idxs1.append(i)
        else: idxs2.append(i)
    
    print('YES')
    
    if len(idxs1) > len(idxs2):
        print(len(idxs1))
        print(' '.join(map(str, idxs1)))
    else:
        print(len(idxs2))
        print(' '.join(map(str, idxs2)))