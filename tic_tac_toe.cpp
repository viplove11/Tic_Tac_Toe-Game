#include <iostream>
#include <unistd.h>
using namespace std;
void displayPattern(void)
{
    cout << "  00  |  01  |  02   " << endl;
    cout << "------|------|-------" << endl;
    cout << "  10  |  11  |  12   " << endl;
    cout << "------|------|-------" << endl;
    cout << "  20  |  21  |  22   " << endl;

    cout << "Options : " << endl
         << "For User1 --> 'x' | For User2 --> 'o'" << endl
         << endl;
}
void OX(char arr[][3], int i, int j)
{
    int row, col;
    for (row = 0; row < 3; row++)
    {
        for (col = 0; col < 3; col++)
        {
            if (row == i && col == j)
            {
                // cout << "  |  ";
                cout << arr[i][j];
                cout << "  |  ";
            }
            else
            {
                // cout << "  |  ";
                cout << arr[row][col];
                cout << "  |  ";
            }
        }
        cout << endl;
    }
}
int main()
{
    char game[3][3] = {{'-', '-', '-'}, {'-', '-', '-'}, {'-', '-', '-'}};
    // user1 --> 'o' && user2 --> 'o'
    char user1_choice, user2_choice;
    int i, j;
    int flag = 0;
    displayPattern();
    while (flag == 0)
    {
        cout << endl
             << endl;
        cout << "User 1 turns : ";
        cin >> i >> j;
        if (game[i][j] == '-')
        {
            game[i][j] = 'x';
        }
        else
        {
            cout << "Not allowed" << endl;
            flag = 3;
        }

        // for x
        if ((game[0][0] == 'x' && game[1][1] == 'x' && game[2][2] == 'x') || (game[0][0] == 'x' && game[1][0] == 'x' && game[2][0] == 'x') || (game[0][2] == 'x' && game[1][2] == 'x' && game[2][2] == 'x') || (game[2][0] == 'x' && game[2][1] == 'x' && game[2][2] == 'x') || (game[1][0] == 'x' && game[1][1] == 'x' && game[1][2] == 'x') || (game[0][0] == 'x' && game[1][0] == 'x' && game[2][0] == 'x') || (game[0][1] == 'x' && game[1][1] == 'x' && game[2][1] == 'x') || (game[0][2] == 'x' && game[1][1] == 'x' && game[2][0] == 'x'))
        {
            flag = 1;
            break;
        }
        OX(game, i, j);
        cout << endl
             << endl;
        cout << "User 2 turns : ";
        cin >> i >> j;
        cout << endl;
        if (game[i][j] == '-')
        {
            // game[i][j] = 'x';
            game[i][j] = 'o';
        }
        else
        {
            cout << "Not allowed" << endl;
        }
        // for o
        if ((game[0][0] == 'o' && game[1][1] == 'o' && game[2][2] == 'o') || (game[0][0] == 'o' && game[1][0] == 'o' && game[2][0] == 'o') || (game[0][2] == 'o' && game[1][2] == 'o' && game[2][2] == 'o') || (game[2][0] == 'o' && game[2][1] == 'o' && game[2][2] == 'o') || (game[1][0] == 'o' && game[1][1] == 'o' && game[1][2] == 'o') || (game[0][0] == 'o' && game[1][0] == 'o' && game[2][0] == 'o') || (game[0][1] == 'o' && game[1][1] == 'o' && game[2][1] == 'o') || (game[0][2] == 'o' && game[1][1] == 'o' && game[2][0] == 'o'))
        {
            flag = 2;
            break;
        }
        OX(game, i, j);
        // sleep(5);
        // system("cls");
    }
    OX(game, i, j);
    cout << "---------------------------------------------------------------" << endl;
    if (flag == 1)
    {
        cout << "\t\t\tUSER 1 WINS" << endl;
    }
    if (flag == 2)
    {
        cout << "\t\t\tUSER 2 WINS" << endl;
    }
    cout << "---------------------------------------------------------------" << endl;
    // cout << game[0][0] <,.< endl;
    return 0;
}