def main():
    s = I().split()
    
    pos_cnt, neg_cnt = 1 + s.count('+'), s.count('-')
    n = int(s[-1])
    
    
    
    for pos_value in range(max(neg_cnt + n, pos_cnt), pos_cnt * n + 1):
        neg_value = pos_value - n
        if neg_cnt == 0 or 1 <= (pos_value + pos_cnt - 1) // pos_cnt <= n and 1 <= (neg_value + neg_cnt - 1) // neg_cnt <= n:
            base, surplus = divmod(pos_value, pos_cnt)
            pos = [base] * (pos_cnt - surplus) + [base + 1] * surplus
            if neg_cnt > 0:
                base, surplus = divmod(neg_value, neg_cnt)
                neg = [base] * (neg_cnt - surplus) + [base + 1] * surplus
            elif neg_value == 0:
                neg = []
            else:
                continue
    
            for i in range(len(s)):
                if s[i] == '?':
                    if i == 0 or s[i - 1] == '+':
                        s[i] = str(pos.pop())
                    else:
                        s[i] = str(neg.pop())
            print("Possible")
            print(' '.join(s))
            break
    else:
        print("Impossible")
