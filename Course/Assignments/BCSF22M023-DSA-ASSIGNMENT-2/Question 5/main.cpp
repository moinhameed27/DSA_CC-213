#include <iostream>
#include <vector>
#include "Queue.h"
using namespace std;

template <typename T>
T numberValidation(T &);

int ROWS, COLS;

// Horizontal and Vertical directions
vector<pair<int, int>> DIRECTIONS = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

// Check whether the given cell is inside the grid or not
bool insideBounds(int x, int y) { return x >= 0 && x < ROWS && y >= 0 && y < COLS; }

// Search for the island starting from the given cell
void search(vector<vector<char>> &grid, int i, int j)
{
    Queue<pair<int, int>> pq;
    pq.enqueue({i, j});

    while (!pq.is_empty())
    {
        int x = pq.peek_front().first, y = pq.peek_front().second;
        pq.dequeue();
        // Check for all neighbours
        for (auto &d : DIRECTIONS)
        {
            int newX = x + d.first, newY = y + d.second;
            if (insideBounds(newX, newY) && grid[newX][newY] == '1')
            {
                grid[newX][newY] = 'm';
                pq.enqueue({newX, newY});
            }
        }
    }
}

// Function to count the number of islands
int numIslands(vector<vector<char>> &grid)
{
    int islands = 0;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (grid[i][j] == '1')
            {
                islands++;
                grid[i][j] = 'm'; // Mark as visited
                search(grid, i, j);
            }
        }
    }
    return islands;
}

void displayGrid(const vector<vector<char>> &grid)
{
    cout << "\nGrid:\n";
    for (const auto &row : grid)
    {
        for (char cell : row)
        {
            cout << cell << ' ';
        }
        cout << endl;
    }
}

int main()
{
    system("CLS");
    cout << "--> Number of Islands <--" << endl;
    cout << "Enter the number of rows: ";
    numberValidation(ROWS);
    cout << "Enter the number of columns: ";
    numberValidation(COLS);

    vector<vector<char>> grid(ROWS, vector<char>(COLS));

    cout << "Enter the grid (row-wise) using '1' for land and '0' for water: " << endl;
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            while (true)
            {
                cout << "[" << i + 1 << "][" << j + 1 << "] : ";
                cin >> grid[i][j];
                if (grid[i][j] == '1' || grid[i][j] == '0')
                    break;
                else
                    cout << "Invalid input. Please enter '1' for land and '0' for water:" << endl;
            }
        }
    }

    vector<vector<char>> duplicate = grid;
    int result = numIslands(grid);
    displayGrid(duplicate);
    cout << "\nNumber of islands: " << result << "\n\n";
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