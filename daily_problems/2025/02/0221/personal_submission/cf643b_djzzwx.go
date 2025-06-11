# https://codeforces.com/contest/643/submission/307076452

package main

import (
    "bufio"
    . "fmt"
    "io"
    "os"
)

const inf int = 0x3f3f3f3f
const mod int = 1e9 + 7

func slove(_r io.Reader, _w io.Writer) {
    in := bufio.NewReader(_r)
    out := bufio.NewWriter(_w)
    defer out.Flush()
    var n, k, a, b, c, d int
    Fscan(in, &n, &k, &a, &b, &c, &d)
    if n == 4 || k < n+1 {
        Fprintln(out, -1)
        return
    }
    has := map[int]bool{a: true, b: true, c: true, d: true}
    Fprintf(out, "%d %d ", a, c)
    for i := 1; i <= n; i++ {
        if !has[i] {
            Fprintf(out, "%d ", i)
        }
    }
    Fprintf(out, "%d %d ", d, b)
    Fprintln(out)
    Fprintf(out, "%d %d ", c, a)
    for i := 1; i <= n; i++ {
        if !has[i] {
            Fprintf(out, "%d ", i)
        }
    }
    Fprintf(out, "%d %d ", b, d)
}

func main() { slove(os.Stdin, os.Stdout) }
