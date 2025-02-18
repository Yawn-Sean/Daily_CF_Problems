# Submission link: https://codeforces.com/contest/178/submission/286301862
def main():
    h, m, q = MII()
    rnd = random.getrandbits(30)

    group_ids = [-1] * h
    group_pos = [-1] * h

    groups = []

    tmp = pos = 0
    for i in range(h):
        if group_ids[i] == -1:
            pos = 0
            group = []
            
            while group_ids[i] == -1:
                group.append(i)
                group_ids[i] = tmp
                group_pos[i] = pos
                pos += 1
                i = (i + m) % h
            
            groups.append(group)
            tmp += 1

    fens1 = [FenwickTree([1] * len(groups[0])) for _ in range(len(groups))]

    mp = {}
    ans = 0

    for _ in range(q):
        query = LI()
        if query[0] == '+':
            idx = int(query[1]) ^ rnd
            hsh = int(query[2])
            
            g_id = group_ids[hsh]
            g_pos = group_pos[hsh]
            
            g_npos = fens1[g_id].bisect_min_larger(fens1[g_id].sum(g_pos - 1) + 1)
            ans += g_npos - g_pos
            g_pos = g_npos
            
            if g_pos == len(groups[g_id]):
                g_npos = fens1[g_id].bisect_min_larger(1)
                ans += g_npos
                g_pos = g_npos
            
            fens1[g_id].add(g_pos, -1)
            
            mp[idx] = groups[g_id][g_pos]
        else:
            idx = int(query[1]) ^ rnd
            fens1[group_ids[mp[idx]]].add(group_pos[mp[idx]], 1)
            del mp[idx]
        
    print(ans)