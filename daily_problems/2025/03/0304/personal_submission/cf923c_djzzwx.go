# https://codeforces.com/contest/923/submission/308910194

package main

import (
    "bufio"
    . "fmt"
    "io"
    "math"
    "os"
)

const inf = math.MaxInt / 2

func slove(_r io.Reader, _w io.Writer) {
    in := bufio.NewReader(_r)
    out := bufio.NewWriter(_w)
    defer out.Flush()
    var n, x int
    Fscan(in, &n)
    a := make([]int, n)
    for i := range a {
        Fscan(in, &a[i])
    }
    root := new(trie)
    for range n {
        Fscan(in, &x)
        root.insert(x)
    }
    for _, v := range a {
        Fprintf(out, "%d ", root.search(v)^v)
    }
}

func main() { slove(os.Stdin, os.Stdout) }

type trie struct {
    c, v int
    l, r *trie
}

func (t *trie) insert(num int) {
    tr := t
    for i := 30; i >= 0; i-- {
        if num>>i&1 == 1 {
            if tr.r == nil {
                tr.r = new(trie)
            }
            tr = tr.r
        } else {
            if tr.l == nil {
                tr.l = new(trie)
            }
            tr = tr.l
        }
        tr.c++
    }
    tr.v = num
}

func (t *trie) search(num int) int {
    tr := t
    for i := 30; i >= 0; i-- {
        if num>>i&1 == 1 {
            if tr.r != nil && tr.r.c > 0 {
                tr = tr.r
                tr.c--
            } else {
                tr = tr.l
                tr.c--
            }
        } else {
            if tr.l != nil && tr.l.c > 0 {
                tr = tr.l
                tr.c--
            } else {
                tr = tr.r
                tr.c--
            }
        }
    }
    return tr.v
}
