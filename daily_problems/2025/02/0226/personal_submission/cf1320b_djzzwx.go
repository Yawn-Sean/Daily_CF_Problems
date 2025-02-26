# https://codeforces.com/contest/1320/submission/307892040

package main

import (
    "bufio"
    "container/heap"
    . "fmt"
    "io"
    "math"
    "os"
)

func slove(_r io.Reader, _w io.Writer) {
    in := bufio.NewReader(_r)
    out := bufio.NewWriter(_w)
    defer out.Flush()
    var n, m, k, u, v int
    Fscan(in, &n, &m)
    g := make([][]int, n)
    rg := make([][]int, n)
    for range m {
        Fscan(in, &u, &v)
        u--
        v--
        g[u] = append(g[u], v)
        rg[v] = append(rg[v], u)
    }
    Fscan(in, &k)
    ps := make([]int, k)
    for i := range ps {
        Fscan(in, &ps[i])
        ps[i]--
    }

    dis := make([]int, n)
    for i := range dis {
        dis[i] = math.MaxInt
    }
    dis[ps[k-1]] = 0
    cnt := make([]int, n)
    hp := new(PairHeap)
    hp.push(pair{0, ps[k-1]})
    for hp.Len() > 0 {
        p := hp.pop().(pair)
        tmp := p.v + 1
        for _, to := range rg[p.p] {
            if tmp < dis[to] {
                dis[to] = tmp
                hp.push(pair{tmp, to})
                cnt[to] = 1
            } else if tmp == dis[to] {
                cnt[to]++
            }
        }
    }
    var mi, mx int
    for i := 0; i < k-1; i++ {
        cur, nxt := ps[i], ps[i+1]
        if dis[cur]-1 == dis[nxt] {
            if cnt[cur] > 1 {
                mx++
            }
        } else {
            mi++
            mx++
        }
    }
    Fprintln(out, mi, mx)
}

func main() { slove(os.Stdin, os.Stdout) }

type pair struct{ v, p int }
type PairHeap []pair

func (h PairHeap) Len() int            { return len(h) }
func (h PairHeap) Less(i, j int) bool  { return h[i].v < h[j].v || h[i].v == h[j].v && h[i].p < h[j].p }
func (h PairHeap) Swap(i, j int)       { h[i], h[j] = h[j], h[i] }
func (h *PairHeap) Push(x interface{}) { *h = append(*h, x.(pair)) }
func (h *PairHeap) Pop() interface{}   { x := (*h)[len(*h)-1]; *h = (*h)[:len(*h)-1]; return x }
func (h *PairHeap) push(v interface{}) { heap.Push(h, v) }
func (h *PairHeap) pop() interface{}   { return heap.Pop(h) }