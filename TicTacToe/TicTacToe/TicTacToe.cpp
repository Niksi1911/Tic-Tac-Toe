#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void drawBoard(char[3][3]);
void playmove(char, char, char[3][3],int&);
void changeTurn(int& turn);
void checkIfWin(char[3][3],int&,int);
int checkAlreadyUsed(int,int,char[3][3]);
void player1CordinatesInput(int&, int&);
void player2CordinatesInput(int&, int&);
void InputInBoard(int, int, char[3][3],int, char, char);

int main()
{   
    //IGRA !
    char player1 = 'x';
    char player2 = 'o';
    int turn = 1;
    int duration = 9;
    int draw = 0;

    char board[3][3] = {
       {' ', ' ', ' '},
       {' ', ' ', ' '},
       {' ', ' ', ' '}
    };

    drawBoard(board);
    int iterator = 0;
    while (iterator<duration)
    {
        playmove(player1, player2, board, turn);
        checkIfWin(board,duration,turn);
        
        if (iterator == 8) 
        {
            cout << "DRAW ! ! !";
            exit(1);
        }
        iterator++;
    }
    return 0; 
}


void drawBoard(char board[3][3])
{   
    cout << "  -------------------\n";
    for (int i = 0; i < 3; i++) {
        cout << "  |  ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << "  |  ";
        }
        cout << "\n  -------------------\n";
    }
}

void playmove(char p1, char p2, char board[3][3],int& turn) {

    int x = 0;
    int y = 0;

    //PLAYER 1 UNOS !
    if (turn==1)
    {    
        player1CordinatesInput(x, y);
        int checkFlag = checkAlreadyUsed(x, y, board);

        if (checkFlag==1)
        {
            player1CordinatesInput(x, y);
        }
        InputInBoard(x, y, board, turn, p1, p2);
    }
    //PLAYER 2 UNOS !
    if(turn==0)
    {
        player2CordinatesInput(x, y);
        int checkFlag = checkAlreadyUsed(x, y, board);
        if (checkFlag==1)
        {
            player2CordinatesInput(x, y);
        }
        InputInBoard(x, y, board, turn, p1, p2);
    }

    changeTurn(turn);
    system("cls");
    drawBoard(board);
}
void changeTurn(int& turn) {
    if (turn==1)
    {
        turn = 0;
    }
    else
    {
        turn = 1;
    }
}
void checkIfWin(char board[3][3],int& dur,int turn) {
    cout << endl;
    //provjera po RED-u za WIN
   
    for (int i = 0; i < 3; i++)
    {
        if (board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][2] !=' ')
        {
            if (turn ==1)
            {
                cout << "PLAYER 2 WON THE GAME\n";
            }
            if (turn ==0)
            {
                cout << "PLAYER 1 WON THE GAME\n";
            }
            dur = 0;
        }
    }

    //provjera po STUPCU za WIN

    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] != ' ')
        {
            if (turn == 1)
            {
                cout << "PLAYER 2 WON THE GAME\n";
            }
            if (turn == 0)
            {
                cout << "PLAYER 1 WON THE GAME\n";
            }
            dur = 0;
        }
    }
    //provjera po dijagonali za WIN
    
    //¸Main dijagonala
    int i = 0;

    if (board[i][i] == board[i + 1][i + 1] && board[i][i] == board[i + 2][i+2] && board[i][i]!=' ')
    {
        if (turn == 1)
        {
            cout << "PLAYER 2 WON THE GAME\n";
        }
        if (turn == 0)
        {
            cout << "PLAYER 1 WON THE GAME\n";
        }
            dur = 0;
    }
    
    // druga dijagonala
    
    if (board[2][0]==board[0][2] && board[1][1]==board[2][0]&& board[1][1]!=' ')
    {
        if (turn == 1)
        {
            cout << "PLAYER 2 WON THE GAME\n";
        }
        if (turn == 0)
        {
            cout << "PLAYER 1 WON THE GAME\n";
        }
        dur = 0; 
    }
}
int checkAlreadyUsed(int x,int y,char board[3][3]) {
    if (board[x][y]=='x' || board[x][y] == 'o')
    {
        cout << "THIS POSITION IS TAKEN...\nPLACE ON NEW POSITION\n";
        return 1;
    }
    else
    {
        return 0;
    }
}
void player1CordinatesInput(int& x, int& y) {
    cout << "Player 1 unesite kordinate \n\n";
    cout << "X kordinata :";
    cin >> x;
    while (x > 2 || cin.fail())
    {
        cout << "POGRESAN UNOS KORDINATE ...\nPOKUSAJTE PONOVO\n";
        cout << "Player 1 unesite kordinate \n\n";
        cout << "X kordinata :";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> x;
    }
    cout << "Y kordinata :";
    cin >> y;
    while (y > 2 || cin.fail())
    {
        cout << "POGRESAN UNOS KORDINATE ...\nPOKUSAJTE PONOVO\n";
        cout << "Player 1 unesite kordinate \n\n";
        cout << "Y kordinata :";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> y;
    }
}
void player2CordinatesInput(int& x,int& y) {
    cout << "Player 2 unesite kordinate \n\n";
    cout << "X kordinata :";
    cin >> x;
    while (x > 2 || cin.fail())
    {
        cout << "POGRESAN UNOS KORDINATE ...\nPOKUSAJTE PONOVO\n";
        cout << "Player 2 unesite kordinate \n\n";
        cout << "X kordinata :";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> x;
    }
    cout << "Y kordinata :";
    cin >> y;
    while (y > 2 || cin.fail())
    {
        cout << "POGRESAN UNOS KORDINATE ...\nPOKUSAJTE PONOVO\n";
        cout << "Player 2 unesite kordinate \n\n";
        cout << "Y kordinata :";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> y;
    }
}
void InputInBoard(int x, int y, char board[3][3], int turn, char p1, char p2) {
    if (turn == 1){
        for (int i = 0; i < 3; i++){
            for (int j = 0;j < 3; j++){
                if (i == x && j == y)
                {
                    board[i][j] = p1;
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < 3; i++){
            for (int j = 0;j < 3; j++){
                if (i == x && j == y)
                {
                    board[i][j] = p2;
                }
            }
        }
    }
}