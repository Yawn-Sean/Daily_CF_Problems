# Submission link: https://codeforces.com/gym/106632/submission/385366226
def main():
    class LinkedList:
        def __init__(self, n):
            self.head = 0
            self.tail = 1
            
            self.nxt = [-1] * (n + 5)
            self.prv = [-1] * (n + 5)
            self.tags = [0] * (n + 5)
            
            self.nxt[0] = 1
            self.prv[1] = 0
            
            self.pos = {}
            self.sz = 0
            self.flg = False
            self.pt = 2
        
        def check(self, idx):
            return idx in self.pos
        
        def size(self):
            return self.sz
        
        def insert(self, idx):
            if self.flg:
                self.prv[self.pt] = self.head
                self.nxt[self.pt] = self.nxt[self.head]
            else:
                self.prv[self.pt] = self.prv[self.tail]
                self.nxt[self.pt] = self.tail
    
            self.nxt[self.prv[self.pt]] = self.pt
            self.prv[self.nxt[self.pt]] = self.pt
            
            self.tags[self.pt] = idx
            self.pos[idx] = self.pt
            
            self.pt += 1
            self.sz += 1
        
        def delete(self, idx):
            p = self.pos[idx]
            del self.pos[idx]
            
            self.prv[self.nxt[p]] = self.prv[p]
            self.nxt[self.prv[p]] = self.nxt[p]
            
            self.sz -= 1
        
        def get_head(self):
            return self.tags[self.prv[self.tail] if self.flg else self.nxt[self.head]]
        
        def reverse(self):
            self.flg = not self.flg
        
        def output(self):
            ans = []
            
            if self.flg:
                cur = self.tail
                while self.prv[cur] != self.head:
                    cur = self.prv[cur]
                    ans.append(self.tags[cur])
            else:
                cur = self.head
                while self.nxt[cur] != self.tail:
                    cur = self.nxt[cur]
                    ans.append(self.tags[cur])
            
            return ans
    
    t = II()
    outs = []
    
    rnd = random.getrandbits(30)
    
    for _ in range(t):
        n, m, k = MII()
        
        idxs = [0] * n
        states = [0] * n
        
        for i in range(n):
            idxs[i], states[i] = MII()
            idxs[i] ^= rnd
        
        reverses = [0] * n
        if k:
            for idx in GMI():
                reverses[idx] = 1
        
        total = LinkedList(n)
        broken = LinkedList(n)
        
        for i in range(n):
            if total.check(idxs[i]):
                total.delete(idxs[i])
                if broken.check(idxs[i]):
                    broken.delete(idxs[i])
                
                total.insert(idxs[i])
                if not states[i]:
                    broken.insert(idxs[i])
            
            elif total.size() < m:
                total.insert(idxs[i])
                if not states[i]:
                    broken.insert(idxs[i])
            
            elif broken.size():
                idx = broken.get_head()
                total.delete(idx)
                broken.delete(idx)
                
                total.insert(idxs[i])
                if not states[i]:
                    broken.insert(idxs[i])
            
            elif states[i]:
                idx = total.get_head()
                total.delete(idx)
                
                total.insert(idxs[i])
                if not states[i]:
                    broken.insert(idxs[i])
            
            if reverses[i]:
                total.reverse()
                broken.reverse()
    
        ans = total.output()
        outs.append(str(len(ans)))
        outs.append(' '.join(str(x ^ rnd) for x in ans))
    
    print('\n'.join(outs))