#include <iostream>
#include <vector>
#include "Stack.h"
#include <cstdlib>
#include <ctime>

using namespace std;

template <typename T>
T numberValidation(T &);

// Horizontal, vertical, and diagonal directions
vector<pair<int, int>> DIRECTIONS = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

class Grid
{
public:
    vector<vector<int>> grid;
    int rows, cols;
    Grid(int r, int c)
    {
        rows = r;
        cols = c;
        grid.resize(rows, vector<int>(cols, 0));
        generateObstacles();
    }

    void generateObstacles()
    {
        srand(time(0));
        int obstacles = 60;
        while (obstacles > 0)
        {
            int r = rand() % rows;
            int c = rand() % cols;
            if (grid[r][c] == 0)
            {
                grid[r][c] = 1;
                obstacles--;
            }
        }
    }

    bool validCell(int x, int y)
    {
        return (x >= 0 && x < rows && y >= 0 && y < cols && grid[x][y] == 0);
    }


    bool pathExists(int startX, int startY, int endX, int endY)
    {
        if (!validCell(startX, startY) || !validCell(endX, endY))
            return false;

        Stack<pair<int, int>> st;
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        st.push({startX, startY});
        visited[startX][startY] = true;

        while (!st.empty())
        {
            int x = st.top().first, y = st.top().second;
            st.pop();

            // Destination Found
            if (x == endX && y == endY)
                return true;

            // Check all 8 directions
            for (auto &d : DIRECTIONS)
            {
                int newX = x + d.first, newY = y + d.second;
                if (validCell(newX, newY) && !visited[newX][newY])
                {
                    st.push({newX, newY});
                    visited[newX][newY] = true;
                }
            }
        }

        return false;
    }

    void displayGrid()
    {
        for (auto &row : grid)
        {
            for (int cell : row)
                cout << cell << " ";
            cout << endl;
        }
    }
};

int main()
{
    system("CLS");
    cout << "--> Pathfinding in a Grid with Obstacles <--" << endl;
    cout << endl;
    int rows = 10, cols = 10;
    Grid grid(rows, cols);

    grid.displayGrid();

    int startX, startY, endX, endY;
    cout << "\nEnter starting point (x y) [1 - Based Indexing] : ";
    numberValidation(startX);
    numberValidation(startY);
    cout << "Enter ending point (x y) [1 - Based Indexing] : ";
    numberValidation(endX);
    numberValidation(endY);

    cout << endl;
    if(!grid.validCell(startX - 1, startY - 1) || !grid.validCell(endX - 1, endY - 1))
        cout << "Invalid Starting or Ending Points!" << endl;
    
    if (grid.pathExists(startX - 1, startY - 1, endX - 1, endY - 1))
        cout << "Path exists!" << endl;
    else
        cout << "No path exists!" << endl;
    cout << endl;
    system("PAUSE");
    cout << endl;
    return 0;
}

template <typename T>
T numberValidation(T &number)
{
    bool validInput = false;
    while (!validInput)
    {
        if (cin >> number)
        {
            if (number < 0)
                cout << "Enter positive number: " << endl;
            else
                validInput = true;
        }
        else
        {
            cin.clear();
            while (cin.get() != '\n')
                ;
            cout << "Invalid input. Please enter a valid number." << endl;
        }
    }
    return number;
}
