// To design a tic tac toe game in c++
#include <iostream>
using namespace std;
#include <vector>

#define length 3
int moves = 0;
char board [length][length];
vector<int> pos(int resp);

void display(int resp, int p);
bool checkwin();

int main()
{
    display(-1, 0);
    int player = 0, resp = -1;
    bool gamewin = false;

    while (!gamewin && (moves != length*length))
    {
        player = (player == 1) ? 2:1;
        cout << "Player"<<player<<"'s turn: ";
        cin >> resp;
        display(resp, player);
        gamewin = checkwin();
        moves ++;
    }
    if (moves != length*length)
    {
        cout<<"Player "<<player<<" wins the game.\n";
    }
    else
    {
        cout<<"It was a draw.\n";
    }
}

void display(int resp, int p)
{
    if (resp == -1)
    {
        cout<< " Welcome! Let's play tic tac toe. Here are the numbers assigned for each position.\n";
           cout<<"\n";
            cout<<" ___  ___  ___ \n";
        for (int i = 0; i < length; i++)
        {
            for (int j = 0; j < length; j++)
            {
                cout<<"| "<<++resp<<" |";
                board[i][j] = ' ';
            }
            cout<<"\n";
            cout<<" ___  ___  ___ \n"; // length == 3
        }
    }
    else
    {
        int x,y, posf = 0;
        do{
            x = pos(resp)[0];
            y = pos(resp)[1];
            if ( (x==y && y == -1)|| board[x][y] != ' ')
            {
                posf = 1; // Validity of position
                cout<< " Invalid move. Enter position again: ";
                cin >> resp;
            }
            else
            {
                posf = 0;
            }
        }while(posf == 1);
        if (p == 1)
        {
            board[x][y] = 'X';
        }
        else
        {
            board[x][y] = 'O';
        }
        cout << "Move number: "<<moves;
        cout<<"\n";
        cout<<" ___  ___  ___ \n";
        for (int i = 0; i < length; i++)
        {
            cout<<"\n";
            for (int j = 0; j < length; j++)
            {
                cout<<"| "<<board[i][j]<<" |";
            }
            cout<<"\n";
            cout<<" ___  ___  ___ \n"; // length == 3
        }


    }
}

bool checkwin()
{
    // Check for row win
    for (int j = 0; j < length; j++)
    {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[0][j] != ' ')
        {
            return true;
        }
    }

    // Check for column win
    for (int i = 0; i < length; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
        {
            return true;
        }
    }

    // Check for diagonal win
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
    {
        return true;
    }

    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ')
    {
        return true;
    }
    return false;
}

vector<int> pos(int resp)
{
    vector<int> ans;
    if (resp >= 0 && resp < 3)
    {
        ans.push_back(0);
        ans.push_back(resp);
    }
    else if (resp >= 0 && resp < 6)
    {
        ans.push_back(1);
        ans.push_back(resp - 3);
    }
    else if (resp >= 0 && resp < 9)
    {
        ans.push_back(2);
        ans.push_back(resp - 6);
    }
    else
    {
        ans.push_back(-1); // Invalid entry
        ans.push_back(-1);
    }
    return ans;
}