# Submission link: https://codeforces.com/gym/100488/submission/340994578
def main():
    n, l, r = MII()
    s = I()
    
    stk_left = list(s[:l-1])
    que_mid = deque(s[l-1:r])
    stk_right = list(s[r:])
    stk_right.reverse()
    
    q = II()
    flg = 1
    outs = []
    
    for _ in range(q):
        query = LI()
        
        if query[0] == 'Q':
            outs.append(que_mid[0] if (query[1] == 'L') == flg else que_mid[-1])
        elif query[0] == 'R':
            flg ^= 1
        else:
            if query[1] == 'L':
                if query[2] == 'L':
                    if flg:
                        que_mid.appendleft(stk_left.pop())
                    else:
                        que_mid.append(stk_left.pop())
                else:
                    if flg:
                        stk_left.append(que_mid.popleft())
                    else:
                        stk_left.append(que_mid.pop())
            else:
                if query[2] == 'L':
                    if flg:
                        stk_right.append(que_mid.pop())
                    else:
                        stk_right.append(que_mid.popleft())
                else:
                    if flg:
                        que_mid.append(stk_right.pop())
                    else:
                        que_mid.appendleft(stk_right.pop())
    
    print(''.join(outs))