#include <iostream>
#include <conio2.h>
#include <windows.h>
#define N 3

using namespace std;

int tic_tac_toe[N][N] = { };
void print_board(int[N][N]);
void llenado(int,int);
void animation();
bool win( int);

int main()
{
    int player_x = 1, player_o = 2, choice;
    bool gane = false;
    print_board(tic_tac_toe);

    while(!gane)
    {
        //animacion();
        //print_board(tic_tac_toe);
        gotoxy(12,15);
        cout<<"\n\n 1 4 7\n 2 5 8\n 3 6 9\n"<<endl;
        cout<<"Jugador X:\n Digite su jugada: ";
        cin>>choice;
        llenado(choice,player_x);
        if(win(player_x))
        {
            gane = true;
            break;
        }

        //print_board(tic_tac_toe);
        gotoxy(12,15);
        cout<<"\n\n 1 4 7\n 2 5 8\n 3 6 9\n"<<endl;
        cout<<"Jugador O:\n Digite su jugada: ";
        cin>>choice;
        llenado(choice,player_o);
        if(win(player_o))
        {
            gane = true;
            break;
        }
    }
    if(win(player_o))
    {
        gotoxy(12,20);
        cout<<"Felicidades al Jugador O!!!, Usted ha ganado!";
    }
     if(win(player_x))
    {
        gotoxy(12,20);
        cout<<"Felicidades al Jugador X!!!, Usted ha ganado!";
    }

    return 0;
}

void print_board(int board[N][N])
{
    textbackground(WHITE);
    system("CLS");
    textcolor(LIGHTBLUE);
    cout << "Tic Tac Toe!!!" << endl;

    gotoxy(1,5);
    for(int k = 0;k < 2;k++)
    {
        for(int x = 0;x < 3;x++)
        {
            for(int i = 0; i < 2;i++)
                cout << "   " << char(186);

            cout << endl;
        }


        for(int i = 0; i < 3;i++)
        {
            if(i != 2)
                cout << char(205) << char(205) << char(205) << char(206);
            else
                cout << char(205) << char(205) << char(205);
        }

        cout << endl;
    }

    for(int x = 0;x < 3;x++)
    {
        for(int i = 0; i < 2;i++)
            cout << "   " << char(186);

        cout << endl;
    }

    return;
}

void llenado(int pos, int player)
{
    if(pos == 1)
    {
        gotoxy(2,6);

        if(player == 1)
            cout << "X";

        else
            cout << "O";

        tic_tac_toe[0][0] = player;
    }


    if(pos == 2)
    {
        gotoxy(2,10);

        if(player == 1)
            cout << "X";
        else
            cout << "O";
        tic_tac_toe[0][1] = player;
    }

    if(pos == 3)
    {
        gotoxy(2,14);

        if(player == 1)
            cout << "X";
        else
            cout << "O";
        tic_tac_toe[0][2] = player;
    }

    if(pos == 4)
    {
        gotoxy(6,6);

        if(player == 1)
            cout << "X";
        else
            cout << "O";
        tic_tac_toe[1][0] = player;
    }

    if(pos == 5)
    {
        gotoxy(6,10);

        if(player == 1)
            cout << "X";
        else
            cout << "O";
        tic_tac_toe[1][1] = player;
    }

    if(pos == 6)
    {
        gotoxy(6,14);

        if(player == 1)
            cout << "X";
        else
            cout << "O";
        tic_tac_toe[1][2] = player;
    }

    if(pos == 7)
    {
        gotoxy(10,6);

        if(player == 1)
            cout << "X";
        else
            cout << "O";
        tic_tac_toe[2][0] = player;
    }

    if(pos == 8)
    {
        gotoxy(10,10);

        if(player == 1)
            cout << "X";
        else
            cout << "O";
        tic_tac_toe[2][1] = player;
    }

    if(pos == 9)
    {
        gotoxy(10,14);

        if(player == 1)
            cout << "X";
        else
            cout << "O";
        tic_tac_toe[2][2] = player;
    }

    return;
}

bool win(int player)
{
    /*  TABLERO
        1 4 7
        2 5 8
        3 6 9
    */
    bool win = false;
    if((tic_tac_toe[0][0] == player) && (tic_tac_toe[1][0] == player) && (tic_tac_toe[2][0] == player))//147
    {
        //win = true;
        return true;
    }
    if((tic_tac_toe[0][0] == player) && (tic_tac_toe[0][1] == player) && (tic_tac_toe[0][2] == player))//123
    {
        //win = true;
        return true;
    }
    if((tic_tac_toe[0][0] == player) && (tic_tac_toe[1][1] == player) && (tic_tac_toe[2][2] == player))//159
    {
        //win = true;
        return true;
    }
    if((tic_tac_toe[0][1] == player) && (tic_tac_toe[1][1] == player) && (tic_tac_toe[2][1] == player))//258
    {
        //win = true;
        return true;
    }
    if((tic_tac_toe[0][2] == player) && (tic_tac_toe[1][2] == player) && (tic_tac_toe[2][2] == player))//369
    {
        //win = true;
        return true;
    }
    if((tic_tac_toe[0][2] == player) && (tic_tac_toe[1][1] == player) && (tic_tac_toe[2][0] == player))//357
    {
        //win = true;
        return true;
    }
    if((tic_tac_toe[1][0] == player) && (tic_tac_toe[1][1] == player) && (tic_tac_toe[1][2] == player))//456
    {
        //win = true;
        return true;
    }
    if((tic_tac_toe[2][0] == player) && (tic_tac_toe[2][1] == player) && (tic_tac_toe[2][2] == player))//789
    {
        //win = true;
        return true;
    }
    return false;
}
