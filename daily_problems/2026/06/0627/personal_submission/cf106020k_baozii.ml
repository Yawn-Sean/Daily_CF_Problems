let ri () = Scanf.scanf " %d " (fun x -> x)
let rl () = Scanf.scanf " %Ld " (fun x -> x)

let popcount x = 
  let rec f acc x = 
    match x with
    | 0 -> acc
    | _ -> f (acc + (x land 1)) (x lsr 1)
  in f 0 x 

let memos = Array.init 20 (fun m -> Array.make (1 lsl m) (-1L))

let rec dfs m u = 
  if u = (1 lsl m) - 1 then 
    1L
  else if memos.(m).(u) <> -1L then 
    memos.(m).(u)
  else
    let c = popcount u in 
    let ans = ref 0L in 
    for i = 0 to m - 1 do 
      if (u lsr i) land 1 = 0 && i <> c then 
        ans := Int64.add !ans (dfs m (u lor (1 lsl i)))
    done;
    memos.(m).(u) <- !ans;
    !ans 

let init () =
  for m = 1 to 19 do
    ignore (dfs m 0)
  done

let solve () =
  let n = ri () in 
  let k = rl () in 
  
  let m = if n <= 19 then n else if (n - 19) mod 2 = 0 then 19 else 18 in
  let o = n - m in
  let ans = Array.make (n + 1) 0 in  
  for i = 1 to o / 2 do
    ans.(2 * i - 1) <- 2 * i;
    ans.(2 * i) <- 2 * i - 1
  done;

  let cur = ref k in
  let u = ref 0 in 
  
  for pos = 0 to m - 1 do
    let fd = ref false in
    for i = 0 to m - 1 do
      if not !fd && (!u lsr i) land 1 = 0 && i <> pos then begin
        let v = !u lor (1 lsl i) in
        let w = dfs m v in
        
        if !cur <= w then begin
          ans.(o + pos + 1) <- o + i + 1;
          u := v;
          fd := true
        end else begin
          cur := Int64.sub !cur w
        end
      end
    done
  done;  
  for i = 1 to n do Printf.printf "%d " ans.(i) done;
  Printf.printf "\n"

let () = 
  init ();
  for i = 1 to ri () do solve () done 
