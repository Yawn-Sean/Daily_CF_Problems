# https://codeforces.com/contest/263/submission/306983893

package main

import (
    "bufio"
    . "fmt"
    "io"
    "math/bits"
    "os"
    "slices"
)

const inf int = 0x3f3f3f3f
const mod int = 1e9 + 7

func slove(_r io.Reader, _w io.Writer) {
    in := bufio.NewReader(_r)
    out := bufio.NewWriter(_w)
    defer out.Flush()
    var n, u, v int
    Fscan(in, &n)
    g := make([][]int, n)
    for i := 0; i < n<<1; i++ {
        Fscan(in, &u, &v)
        u--
        v--
        g[u] = append(g[u], v)
        g[v] = append(g[v], u)
    }
    for _, vs := range g {
        if len(vs) != 4 {
            Fprintln(out, -1)
            return
        }
    }

    paths := make([]int, 3, n)

    vis := make([]bool, n)
    has := make(map[int]bool, 4)
    check := func() bool {
        clear(vis)
        for _, v := range paths[:3] {
            vis[v] = true
        }
    o:
        for i := 3; i < n; i++ {
            clear(has)
            for _, w := range g[paths[i-2]] {
                has[w] = true
            }
            for _, w := range g[paths[i-1]] {
                if has[w] && !vis[w] {
                    vis[w] = true
                    paths = append(paths, w)
                    continue o
                }
            }
            return false
        }
        return true
    }
    for i := (1 << 4) - 1; i >= 0; i-- {
        if bits.OnesCount(uint(i)) != 2 {
            continue
        }
        tmp := make([]int, 0, 2)
        for j, v := range g[0] {
            if i>>j&1 == 1 {
                tmp = append(tmp, v)
            }
        }
        copy(paths[1:3], tmp)
        paths = paths[:3]
        if check() {
            break
        }
        paths = paths[:3]
        slices.Reverse(paths[1:3])
        if check() {
            break
        }
    }

    if len(paths) < n {
        Fprintln(out, -1)
        return
    }
    for _, path := range paths {
        Fprintf(out, "%d ", path+1)
    }
}

func main() { slove(os.Stdin, os.Stdout) }

func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}

