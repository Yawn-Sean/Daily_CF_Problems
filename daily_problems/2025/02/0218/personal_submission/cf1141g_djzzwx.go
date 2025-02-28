# link: https://codeforces.com/contest/1141/submission/306640816
package main

import (
    "bufio"
    . "fmt"
    "io"
    "os"
    "slices"
)

const inf int = 0x3f3f3f3f
const mod int = 1e9 + 7

func slove(_r io.Reader, _w io.Writer) {
    in := bufio.NewReader(_r)
    out := bufio.NewWriter(_w)
    defer out.Flush()
    var n, k, u, v int
    Fscan(in, &n, &k)
    edges := make([][]int, n)
    g := make([][]int, n)
    deg := make([]int, n)
    paths := make([]int, n-1)
    for i := 0; i < n-1; i++ {
        Fscan(in, &u, &v)
        u--
        v--
        edges[u] = append(edges[u], i)
        edges[v] = append(edges[v], i)
        g[u] = append(g[u], v)
        g[v] = append(g[v], u)
        deg[u]++
        deg[v]++
    }
    ids := make([]int, n)
    for i := range ids {
        ids[i] = i
    }
    slices.SortFunc(ids, func(a, b int) int {
        return deg[b] - deg[a]
    })
    ans := deg[ids[k]]
    var dfs func(i, j, fa int)
    dfs = func(i, j, fa int) {
        c := 1
        if c == j && c < ans {
            c++
        }
        for x, to := range g[i] {
            if to == fa {
                continue
            }
            if c == j && c < ans {
                c++
            }
            if len(edges[i]) > ans {
                c = 1
            }
            paths[edges[i][x]] = c
            dfs(to, c, i)
            if c < ans {
                c++
            }
        }
    }
    dfs(0, 0, -1)
    Fprintln(out, ans)
    for _, e := range paths {
        Fprintf(out, "%d ", e)
    }
}

func main() { slove(os.Stdin, os.Stdout) }
