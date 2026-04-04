'''
https://codeforces.com/gym/102911/submission/369526726
'''
board = [[]]
tile = 'A'

def chessBoard(r: int, c: int, size: int, dr: int, dc: int):
    global board, tile
    if size < 2: return
    if size > 4:
        tile = 'A'
    t = tile 
    tile = chr(ord(tile) + 1)
    s = size // 2 
    

    # 处理左上角子棋盘
    if dr < r + s and dc < c + s:
        chessBoard(r, c, s, dr, dc) # 特殊方格在该子棋盘
    else:
        # 将子棋盘右下角用骨牌 t 所覆盖
        board[r + s - 1][c + s - 1] = t
        # 递归求解左上角子棋盘的覆盖问题
        chessBoard(r, c, s, r + s - 1, c + s - 1)

    #处理右上角子棋盘
    if dr < r + s and dc >= c + s: 
        chessBoard(r, c + s, s, dr, dc) # 特殊方格在该子棋盘
    else:
        # 将子棋盘左下角用骨牌 t 所覆盖
        board[r + s - 1][c + s] = t
        # 递归求解右上角子棋盘的覆盖问题
        chessBoard(r, c + s, s, r + s - 1, c + s)

    # 处理左下角子棋盘
    if (dr >= r + s and dc < c + s):
        chessBoard(r + s, c, s, dr, dc) # 特殊方格在该子棋盘
    else:
        # 将子棋盘右上角用骨牌 t 所覆盖
        board[r + s][c + s - 1] = t
        # 递归求解左下角子棋盘的覆盖问题
        chessBoard(r + s, c, s, r + s, c + s - 1)

    # 处理右下角子棋盘
    if (dr >= r + s and dc >= c + s):
        chessBoard(r + s, c + s, s, dr, dc) # 特殊方格在该子棋盘
    else:
        # 将子棋盘右下角用骨牌 t 所覆盖
        board[r + s][c + s] = t
        # 递归求解左上角子棋盘的覆盖问题
        chessBoard(r + s, c + s, s, r + s, c + s)
