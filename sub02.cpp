#include <iostream>
#include <vector>

using namespace std;

bool completion(int grid[16][16], int &row, int &col)
{
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

bool safe(int grid[16][16], int row, int col, int num)
{
    for (int i = 0; i < 16; ++i)
    {
        if (grid[row][i] == num || grid[i][col] == num)
        {
            return 0;
        }
    }
    int br = row - row % 4;
    int bc = col - col % 4;
    for (int r = 0; r < 4; ++r)
    {
        for (int c = 0; c < 4; ++c)
        {
            if (grid[r + br][c + bc] == num)
            {
                return 0;
            }
        }
    }
    return 1;
}

bool Solve(int grid[16][16], int row)
{
    int col;
    if (completion(grid, row, col))
    {
        return 1;
    }
    for (int num = 1; num <= 16; ++num)
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

void nsingle (int grid[16][16],int row , int col,vector<int>vec){
    int count = 0;
    bool found; 
    do{
        found = false;
        for(int row = 0; row < 16; ++row){
            for (int col = 0; col < 16; ++col){
                if (grid[row][col] == 0){
                    count = 0;
                    for(int valuest = 0; valuest < 16; ++valuest){
                        if(safe(grid,row, col,valuest)){
                            vec.push_back(valuest);
                            count++;
                        }
                    }    
                    if (count==1){
                        grid[row][col] = vec.back();
                        found = true;
                    }            
            }
            else{
                continue;
            }
        }
    }

}
while(found);
}


void print(int grid[16][16])
{
    for (int r = 0; r < 16; ++r)
    {  
        if (grid[r][0] > 9)
        {
            char cha = (char)(grid[r][0] + 55);
            cout << cha;
        }
        else
        {
            cout << grid[r][0];
        }
        for (int c = 1; c < 16; ++c)
        {
            if (grid[r][c] > 9)
            {
                char cha = (char)(grid[r][c] + 55);
                cout << ' ' << cha;
            }
            else
            {
                cout << ' ' << grid[r][c];
            }
        }
        cout << endl;
    }
}
int changingLetters(char c){
        int number = c;
        if(number > 64 && number <81){
                return number - 55;
        }
        else{
                return number - 48;
        }
}

int main()
{
    vector<int>vec;

    int grid[16][16] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};

    for (int row = 0; row < 16; ++row)
    {
        for (int col = 0; col < 16; ++col)
        {
            char character;
            cin>>character;
            grid[row][col]=changingLetters(character);
            
        }
    }
    //nsingle(grid,0,0,vec);

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