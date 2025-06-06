# https://codeforces.com/contest/592/submission/307631916

package main

import (
    "bufio"
    . "fmt"
    "io"
    "math/big"
    "os"
)

func slove(_r io.Reader, _w io.Writer) {
    in := bufio.NewReader(_r)
    out := bufio.NewWriter(_w)
    defer out.Flush()
    var t, w, b int64
    Fscan(in, &t, &w, &b)
    g := gcd(w, b)
    lcm := new(big.Int).Mul(new(big.Int).Div(big.NewInt(w), big.NewInt(g)), big.NewInt(b))
    a := new(big.Int).Mul(new(big.Int).Div(big.NewInt(t), lcm), big.NewInt(min(w, b)))
    remainder := new(big.Int).Mod(new(big.Int).SetInt64(t), lcm)
    a.Add(a, new(big.Int).SetInt64(min(remainder.Int64(), w-1, b-1)))
    g = gcd(a.Int64(), t)
    Fprintf(out, "%d/%d\n", a.Int64()/g, t/g)
}

func main() { slove(os.Stdin, os.Stdout) }

func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}

func gcd(a, b int64) int64 {
    for b != 0 {
        a, b = b, a%b
    }
    return a
}

//func max(a, b int) int {
//  if a > b {
//      return a
//  }
//  return b
//}

//func min(a, b int) int {
//  if a < b {
//      return a
//  }
//  return b
//}