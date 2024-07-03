#include <iostream>
#pragma GCC optimize("O2")

using namespace std;

bool completion(int grid[9][9], int &row, int &col)
{
    for (row; row < 9; ++row)
    {
        for (col = 0; col < 9; ++col)
        {
            if (grid[row][col] == 0)
            {
                return 0;
            }
        }
    }
    return 1;
}

bool safe(int grid[9][9], int row, int col, int num)
{
    for (int i = 0; i < 9; ++i)
    {
        if (grid[row][i] == num || grid[i][col] == num)
        {
            return 0;
        }
    }
    int br = row - row % 3;
    int bc = col - col % 3;
    for (int r = 0; r < 3; ++r)
    {
        for (int c = 0; c < 3; ++c)
        {
            if (grid[r + br][c + bc] == num)
            {
                return 0;
            }
        }
    }
    return 1;
}

bool Solve(int grid[9][9], int row)
{
    int col;
    if (completion(grid, row, col))
    {
        return 1;
    }
    for (int num = 1; num <= 9; ++num)
    {
        if (safe(grid, row, col, num))
        {
            grid[row][col] = num;
            if (Solve(grid, row))
            {
                return 1;
            }
            grid[row][col] = 0;
        }
    }
    return 0;
}

void print(int grid[9][9])
{
    for (int r = 0; r < 9; ++r)
    {
        cout << grid[r][0];
        for (int c = 1; c < 9; ++c)
        {
            cout << ' ' << grid[r][c];
        }
        cout << endl;
    }
}

int main()
{
    int grid[9][9] = {{0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0},
                      {0, 0, 0, 0, 0, 0, 0, 0, 0}};
    for (int row = 0; row < 9; ++row)
    {
        for (int col = 0; col < 9; ++col)
        {
            int n;
            cin >> n;
            grid[row][col] = n;
        }
    }
    if (Solve(grid, 0))
    {
        print(grid);
    }
    else
    {
        cout << "No Solution" << endl;
    }
    return 0;
}
