#include <iostream>
#include <vector>
#include "Queue.h"

using namespace std;

bool checkWin(vector<vector<char>> &board, char ch)
{
    for (int i = 0; i < 3; i++)
    {
        if ((board[i][0] == ch && board[i][1] == ch && board[i][2] == ch)     // Row
            || (board[0][i] == ch && board[1][i] == ch && board[2][i] == ch)) // Column
            return true;
    }
    if ((board[0][0] == ch && board[1][1] == ch && board[2][2] == ch)     // Diagonal
        || (board[0][2] == ch && board[1][1] == ch && board[2][0] == ch)) // Anti-Diagonal
        return true;
    return false;
}

vector<pair<int, int>> winForGeorge(vector<pair<int, int>> &preferences)
{
    vector<vector<char>> board(3, vector<char>(3, '*'));
    Queue<vector<pair<int, int>>> queue;
    queue.enqueue({});

    while (!queue.is_empty())
    {
        vector<pair<int, int>> currentMoves = queue.peek_front();
        queue.dequeue();

        // Reset the board
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
                board[i][j] = '*';

        // Apply all previous moves
        for (int i = 0; i < currentMoves.size(); i++)
        {
            int x = currentMoves[i].first - 1, y = currentMoves[i].second - 1; // Conversion to 0 - Based Indexing
            board[x][y] = (i % 2 == 0) ? 'G' : 'P';
        }

        // If George wins, return the moves
        if (checkWin(board, 'G'))
            return currentMoves;

        // George's move
        for (auto move : preferences)
        {
            int x = move.first - 1, y = move.second - 1; // Conversion to 0 - Based Indexing
            // Mark only if the cell is empty, otherwise continue
            if (board[x][y] == '*')
            {
                board[x][y] = 'G';
                currentMoves.push_back(move); // George's move

                // After marking George's move, check all other possible moves for our Player
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        // If the cell is empty, mark it as Player's move and push it to the queue
                        if (board[i][j] == '*')
                        {
                            vector<pair<int, int>> newMoves = currentMoves;
                            newMoves.push_back({i + 1, j + 1}); // Conversion to 1 - Based Indexing
                            queue.enqueue(newMoves);
                        }
                    }
                }
                break;
            }
        }
    }
    return {};
}

int main()
{
    system("cls");
    cout << "----------> George's Tic Tac Toe <----------" << endl;
    vector<pair<int, int>> preferences(9);
    cout << "Enter the preferences of George (x, y) _ [1 - Based Indexing] : " << endl;
    for (int i = 0; i < 9; i++)
    {
        cout << i + 1 << ": ";
        int x, y;
        cin >> x >> y;
        preferences[i] = {x, y};
    }

    vector<pair<int, int>> finalMoves = winForGeorge(preferences);

    cout << "\nWinning Moves: " << endl;
    // Double increment to only get our Player moves and size - 1 to exclude the last move
    for (int i = 1; i < finalMoves.size() - 1; i += 2)
        cout << finalMoves[i].first << " " << finalMoves[i].second << endl;
    cout << endl;
    system("pause");
    return 0;
}