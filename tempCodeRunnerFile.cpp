bool completion(int grid[16][16], int &row, int &col)
{
    row = 0;
    for (row; row < 16; ++row)
    {
        for (col = 0; col < 16; ++col)
        {
            if (grid[row][col] == 0)
            {
                return 0;
            }
        }
    }
    return 1;
}