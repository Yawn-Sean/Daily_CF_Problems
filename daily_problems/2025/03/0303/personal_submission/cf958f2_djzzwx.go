# https://codeforces.com/contest/958/submission/308769482

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
    var n, m int
    Fscan(in, &n, &m)
    a := make([]int, n)
    b := make([]int, m)
    for i := range a {
        Fscan(in, &a[i])
        a[i]--
    }
    all := 0
    for i := range b {
        Fscan(in, &b[i])
        all += b[i]
    }
    cnt := make([]int, m)
    j := 0
    for i, v := range b {
        for cnt[i] < v {
            if j < n {
                cnt[a[j]]++
                j++
            } else {
                Fprintln(out, -1)
                return
            }
        }
    }
    ans := j - all
    for k := 0; k < n; {
        i := a[k]
        k++
        if cnt[i] > b[i] {
            cnt[i]--
            ans = min(ans, j-k-all)
        } else {
            cnt[i]--
            for ; j < n && cnt[i] < b[i]; j++ {
                cnt[a[j]]++
            }
            if cnt[i] < b[i] {
                break
            }
        }
    }
    Fprintln(out, ans)
}

func main() { slove(os.Stdin, os.Stdout) }

//func abs(x int) int {
//  if x < 0 {
//      return -x
//  }
//  return x
//}

//func gcd(a, b int) int {
//  for b != 0 {
//      a, b = b, a%b
//  }
//  return a
//}

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