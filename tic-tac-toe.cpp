#include <bits/stdc++.h>
using namespace std;
#define int long long
#define boost                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)
#define testcases \
    int t;        \
    cin >> t;     \
    while (t--)
#define repi(i, a, b) for (int i = a; i < b; i++)
#define repj(j, a, b) for (int j = a; j < b; j++)

//tic tac toe

char ttt[4][4]; //global variables
int chances = 0;

void initialize()
{
    std::fill(*ttt, *ttt + 4 * 4, '-');
}

string play(char player, int x, int y)
{
    static int chk = -1;
    if (chk == -1 && player == 'X' && ttt[x][y] == '-')
    {
        chk *= -1;
        ttt[x][y] = 'X';
        return "OK\n";
    }
    if (chk == 1 && player == 'O' && ttt[x][y] == '-')
    {
        chk *= -1;
        ttt[x][y] = 'O';
        return "OK\n";
    }
    return "BAD\n";
}

bool verticheck()
{
    bool track;
    int col = 0, row = 0;
    int times = 0;
    int i, j;
    for (j = 1; j < 4; j++)
    {
        char ele = ttt[1][j];
        times = 0;
        for (i = 1; i < 4; i++)
        {
            if (ttt[i][j] != ele)
            {
                break;
            }
            else
            {
                col = j;
                times += 1;
                row = i;
            }
        }
        if (times == 3)
            break;
    }
    if (times == 3 && ttt[row][col] != '-')
    {
        track = true;
        cout << ttt[row][col] << " WON"
             << "\n";
    }
    else
    {
        track = false;
    }
    return track;
}

bool horicheck()
{
    bool track;
    int col = 0, row = 0;
    int times = 0;
    int i, j;
    for (i = 1; i < 4; i++)
    {
        char ele = ttt[i][1];
        times = 0;
        for (j = 1; j < 4; j++)
        {
            if (ttt[i][j] != ele)
            {
                break;
            }
            else
            {
                col = j;
                times += 1;
                row = i;
            }
        }
        if (times == 3)
            break;
    }
    if (times == 3 && ttt[row][col] != '-')
    {
        track = true;
        cout << ttt[row][col] << " WON"
             << "\n";
    }
    else
    {
        track = false;
    }
    return track;
}

bool diagcheck()
{
    bool track, track1 = false, track2 = false;
    if (ttt[1][1] == ttt[2][2] && ttt[2][2] == ttt[3][3] && ttt[1][1] == ttt[3][3])
    {
        if (ttt[2][2] != '-')
            track1 = true;
    }
    if (ttt[1][3] == ttt[2][2] && ttt[2][2] == ttt[3][1] && ttt[1][3] == ttt[3][1])
    {
        if (ttt[2][2] != '-')
            track2 = true;
    }
    if (track1 || track2)
    {
        track = true;
        cout << ttt[2][2] << " WON"
             << "\n";
    }
    else
    {
        track = false;
    }
    return track;
}

string checkWin()
{
    string verdict;
    bool t1 = verticheck();
    bool t2 = horicheck();
    bool t3 = diagcheck();

    if (!t1 && !t2 && !t3)
    {
        if (chances < 9)
            verdict = "INPROGRESS\n";
        else
            verdict = "DRAW\n";
    }
    return verdict;
}

int32_t main()
{
    initialize();

    repi(i, 1, 4)
    {
        repj(j, 1, 4)
        {
            cout << ttt[i][j] << " ";
        }
        cout << "\n";
    }

    while (chances < 9)
    {
        cout << "enter player name ('X' or 'O') and row and column ";
        char player;
        int x, y;
        cin >> player >> x >> y;
        if ((player == 'X' || player == 'O') && x >= 1 && x < 4 && y >= 1 && y < 4)
        {
            string status1 = play(player, x, y);
            cout << status1;

            repi(i, 1, 4)
            {
                repj(j, 1, 4)
                {
                    cout << ttt[i][j] << " ";
                }
                cout << "\n";
            }

            if (status1 == "OK\n")
            {
                chances++;
                string status2 = checkWin();
                if (status2 == "INPROGRESS\n" || status2 == "DRAW\n")
                {
                    cout << status2;
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            cout << "INPUTERROR\n";
        }
    }
}
