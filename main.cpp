#include <array>
#include <fstream>
#include <iostream>

using namespace std;

using Board = array<array<int, 9>, 9>;

bool valid(const Board &board, int y, int x, int n) {
  for (int i = 0; i < 9; i++) {
    if (board[y][i] == n || board[i][x] == n) {
      return false;
    }
  }
  for (int i = y / 3 * 3; i < y / 3 * 3 + 3; i++) {
    for (int j = x / 3 * 3; j < x / 3 * 3 + 3; j++) {
      if (board[i][j] == n) {
        return false;
      }
    }
  }
  return true;
}

bool solve(Board &board) {
  for (int y = 0; y < 9; y++) {
    for (int x = 0; x < 9; x++) {
      if (board[y][x] != 0) {
        continue;
      }
      for (int n = 1; n <= 9; n++) {
        if (!valid(board, y, x, n)) {
          continue;
        }
        board[y][x] = n;
        if (solve(board)) {
          return true;
        }
        board[y][x] = 0;
      }
      return false;
    }
  }
  return true;
}

int main() {
  ifstream fin("input.txt");
  ofstream fout("output.txt");
  Board board{};
  for (int y = 0; y < 9; y++) {
    for (int x = 0; x < 9; x++) {
      char c;
      fin >> c;
      board[y][x] = c - '0';
    }
  }
  if (solve(board)) {
    for (const auto &row : board) {
      for (int n : row) {
        fout << n;
      }
      fout << '\n';
    }
  } else {
    fout << "No solution\n";
  }
  return 0;
}
