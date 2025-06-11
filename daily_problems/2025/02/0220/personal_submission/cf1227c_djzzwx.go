# https://codeforces.com/contest/1227/submission/306961339

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
    var n, m, T int
    var s []byte
    for Fscan(in, &T); T > 0; T-- {
        Fscan(in, &n, &m)
        Fscan(in, &s)
        target := make([]byte, n)
        for i := 1; i < m*2-1; i += 2 {
            target[i-1] = '('
            target[i] = ')'
        }
        for i, j := m*2-2, n-1; i < j; i, j = i+1, j-1 {
            target[i], target[j] = '(', ')'
        }
        type pair struct{ l, r int }
        ops := []pair{}
        for i := range target {
            if target[i] != s[i] {
                j := i + 1
                for ; target[i] != s[j]; j++ {
                }
                ops = append(ops, pair{i, j})
                for ; i < j; i, j = i+1, j-1 {
                    s[i], s[j] = s[j], s[i]
                }
            }
        }
        Fprintln(out, len(ops))
        for _, op := range ops {
            Fprintln(out, op.l+1, op.r+1)
        }
    }

}

func main() { slove(os.Stdin, os.Stdout) }

func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}
