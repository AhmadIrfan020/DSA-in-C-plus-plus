#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to print the board
void print_board(const vector<char> &board)
{
    for (int i = 0; i < 3; i++)
    {
        cout << "\t\t|";
        for (int j = i * 3; j < (i + 1) * 3; j++)
        {
            cout << " " << board[j] << " |";
        }
        cout << endl;
        if (i < 2)
        {
            cout << "\t\t-------------" << endl;
        }
    }
}

// Create an empty board
vector<char> create_board()
{
    return vector<char>(9, ' ');
}

// Function to take player input and place it on the board
void take_input(char player, vector<char> &board)
{
    while (true)
    {
        try
        {
            int move;

            cout << endl;
            cout << "Player " << player << ", enter your move (1-9): ";
            cin >> move;
            cout << endl;
            move--;
            if (move >= 0 && move < 9 && board[move] == ' ')
            {
                board[move] = player;
                break;
            }
            else
            {
                cout << "That position is already taken or invalid. Try again." << endl;
            }
        }
        catch (exception &e)
        {
            cout << "Invalid input. Enter a number between 1 and 9." << endl;
        }
    }
}

// Function to check for a win
bool check_win(const vector<char> &board, char player)
{
    vector<vector<int>> win_conditions = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, // rows
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8}, // columns
        {0, 4, 8},
        {2, 4, 6} // diagonals
    };
    for (const auto &condition : win_conditions)
    {
        if (board[condition[0]] == player && board[condition[1]] == player && board[condition[2]] == player)
        {
            return true;
        }
    }
    return false;
}

// Function to check for a tie
bool check_tie(const vector<char> &board)
{
    for (char cell : board)
    {
        if (cell == ' ')
        {
            return false;
        }
    }
    return true;
}

// Game loop function
void game_loop()
{
    vector<char> board = create_board();
    char current_player = 'X';
    while (true)
    {
        print_board(board);
        take_input(current_player, board);
        if (check_win(board, current_player))
        {
            print_board(board);
            cout << "Player " << current_player << " wins!" << endl;
            break;
        }
        else if (check_tie(board))
        {
            print_board(board);
            cout << "It's a tie!" << endl;
            break;
        }
        current_player = (current_player == 'X') ? 'O' : 'X';
    }
}

// Main function to start the game and ask to play again
int main()
{
    cout << endl
         << "Welcome to Tic Tac Toe!" << endl
         << endl;
    cout << "Player X goes first." << endl
         << endl;
    while (true)
    {
        game_loop();
        string play_again;
        cout << "Do you want to play again? (y/n): ";
        cin >> play_again;
        if (play_again == "N" || play_again == "n")
        {
            cout << "Thanks for playing!" << endl;
            cout << "Goodbye!" << endl;
            break;
        }
    }
    return 0;
}
