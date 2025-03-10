import numpy as np
import pygame


ROW_COUNT = 6
COLUMN_COUNT = 7

def create_board():
    board = np.zeros((ROW_COUNT, COLUMN_COUNT))
    return board

def drop_piece(board, row, column, piece):
    board[row][column] = piece


def is_valid_position(board, column):
    return board[ROW_COUNT-1][column] == 0

def print_board(borad):
    print(np.flip(board, 0))

def get_next_open_row(board, column):
    for row in range(ROW_COUNT):
        if board[row][column] == 0:
            return row

def winning_move(board, piece):
    for c in range(COLUMN_COUNT-3):
        for r in range(ROW_COUNT):
            if board[r][c] == piece and board[r][c+1] == piece and board[r][c+2] == piece and board[r][c+3] == piece:
                return True

    for c in range(COLUMN_COUNT):
        for r in range(ROW_COUNT-3):
            if board[r][c] == piece and board[r+1][c] == piece and board[r+2][c] == piece and board[r+3][c] == piece:
                return True

    for c in range(COLUMN_COUNT-3):
        for r in range(ROW_COUNT-3):
            if board[r][c] == piece and board[r+1][c+1] == piece and board[r+2][c+2] == piece and board[r+3][c+3] == piece:
                return True

    for c in range(COLUMN_COUNT-3):
        for r in range(3, ROW_COUNT):
            if board[r][c] == piece and board[r-1][c+1] == piece and board[r-2][c+2] == piece and board[r-3][c+3] == piece:
                return True


board = create_board()

turn = 0
game_over = False

while not game_over:

    print_board(board)

    if turn == 0:
        column = int(input("Player A make your selection(0-6):"))

        if is_valid_position(board, column):
            row = get_next_open_row(board, column)
            drop_piece(board, row, column, 1)
            if winning_move(board, 1):
                print("Player A winning !!!")
                game_over = True

    else:
        column = int(input("Player B make your selection(0-6):"))

        if is_valid_position(board, column):
            row = get_next_open_row(board, column)
            drop_piece(board, row, column, 2)
            if winning_move(board, 2):
                print("Player B winning !!!")
                game_over = True

    turn = turn + 1
    turn = turn % 2

print(board)