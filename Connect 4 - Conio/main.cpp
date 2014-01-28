#include <iostream>
#include <conio2.h>
#include <windows.h>
#define LEFT 0x4b
#define RIGHT 0x4d
#define ENTER 0x0D
#define F 6
#define C 7
#define N 11

using namespace std;

bool check_win = false;
int primera_jugada, cont = 0, check_win_P1 = 0, check_win_P2 = 0;
int connect_4[F][C] = { };

int animation(int,int);
bool check_win_h(int, int);
bool check_win_v(int, int);
bool check_win_d(int, int, int);
void feed_board();
void hide_cursor();
void locate(int,int);
int GAME_UPDATE(int, int);
void print_board();
int save(int,int,int);
void SetWindow(int, int);
bool win(int);


int main()
{
    int choice = 1, chk;
    SetWindow(50,40);
    hide_cursor();

    RESTART:
    print_board();
    while(1)
    {
        for(int i = 1;i < 3;i++)
        {
            if(chk == 2)
                i = primera_jugada;
            chk = GAME_UPDATE(choice,i);
            if(chk == 2)//si chk es 2 ya hubo un ganador y se quiere jugar otra vez., por ende se
                break;
        }
        if(chk == 2)
            break;
    }
    if(chk == 2)// como fue 2, el juego se reinicia y se vuelve al principio.
    {
        system("cls");
        goto RESTART;
    }
    return 0;
}

/* Esta funcion es la que se encarga de mostrar la animacion de el movimiento de la monedas mientras van bajando y con su respectivo color.
 *PARAMETROS QUE RECIBE
    choice: es la eleccion del usuario.
    player: el jugador actual.
 *VALOR QUE RETORNA
    2: si ya hubo un ganador y se quiere volver a jugar otra vez.
    1: si el primero (de arriba para abajo esta lleno) se retorna para que el ciclo se repita.
    0: si es una seleccion jugada normal y no hubo un ganador.
*/
int animation(int choice,int player)
{
    int i, chk;

    if(connect_4[0][choice] != 0)   // Si el primero esta lleno la columna
        return 1;                   // completa esta llena. Si la columna
                                    // esta llena debe retornar 1 para que
    for(i = 0;i < F;i++)            // el while se cumpla y el ciclo se repita.
    {
        if(connect_4[i][choice] == 0)
        {
            gotoxy((((choice)*4) + N), (((i)*4) + N));

            if(player == 1)
                textcolor(LIGHTRED);

            else if(player == 2)
                textcolor(YELLOW);

            cout << "O";
            Sleep(250);

            gotoxy(wherex()-1,wherey());
            cout << " ";
        }
        if(connect_4[i+1][choice] != 0)
            break;
    }
    gotoxy(wherex()-1,wherey());
    cout << "O";

    chk = save(i,choice,player);
    if(chk == 2)//si chk es 1 ya hubo un ganador y se quiere jugar otra vez., por ende se retorna 1 a seleccion.
        return 2;

    return 0;
}

/* Esta funcion es la que se encarga de chequear quien horizontalmente.
 *PARAMETROS QUE RECIBE
    fila: de la jugada.
    column: de jugada.
 *VALOR QUE RETORNA
    false: si no gano nadie
    true: si hubo un ganador.
*/
bool check_win_h(int fila, int columna)
{
    int same = 1;
    int j;

    for(j = 1;j < 4;j++)
    {
        if(((connect_4[fila][columna] != 0) && (connect_4[fila][columna + j] != 0)))
                if(connect_4[fila][columna] == connect_4[fila][columna + j])
                    same++;
            if(same == 4)
                return true;//retorna verdadero si se encontro una solucion valida. osea si se gano.
    }
    return false;//si no hubo un ganador, se retorna false para indicarlo.
}

/* Esta funcion es la que se encarga de chequear quien verticalmente.
 *PARAMETROS QUE RECIBE
    fila: de la jugada.
    column: de jugada.
 *VALOR QUE RETORNA
    false: si no gano nadie
    true: si hubo un ganador.
*/
bool check_win_v(int fila, int columna)
{
    int same = 1;
    int j;

    for(j = 1;j < 4;j++)
    {
        if(((connect_4[fila][columna] != 0) && (connect_4[fila - j][columna] != 0)))
                if(connect_4[fila][columna] == connect_4[fila - j][columna])
                    same++;
            if(same == 4)
                return true;//retorna verdadero si se encontro una solucion valida. osea si se gano.
    }
    return false;//si no hubo un ganador, se retorna false para indicarlo.
}

/* Esta funcion es la que se encarga de chequear quien diagonalmente.
 *PARAMETROS QUE RECIBE
    fila: de la jugada.
    column: de jugada.
    tipo: si es diagonalmente hacia arriba o hacia abajo
 *VALOR QUE RETORNA
    false: si no gano nadie
    true: si hubo un ganador.
*/
bool check_win_d(int fila, int columna, int tipo)
{
    int same = 1;
    int j;

    if(tipo == 1)//HACIA ARRIBA
    {
        for(j = 1;j < 4;j++)
        {
            if(((connect_4[fila][columna] != 0) && (connect_4[fila - j][columna + j] != 0)))
                    if(connect_4[fila][columna] == connect_4[fila - j][columna + j])
                        same++;
                if(same == 4)
                    return true;//retorna verdadero si se encontro una solucion valida. osea si se gano.
        }
    }
    else if(tipo == 2)//HACIA ABAJO
    {
        for(j = 1;j < 4;j++)
        {
            if(((connect_4[fila][columna] != 0) && (connect_4[fila - j][columna - j] != 0)))
                    if(connect_4[fila][columna] == connect_4[fila - j][columna - j])
                        same++;
                if(same == 4)
                    return true;//retorna verdadero si se encontro una solucion valida. osea si se gano.
        }
    }
    return false;//si no hubo un ganador, se retorna false para indicarlo.
}

/* Esta funcion es la que se encarga de resetear la matriz y ponerle todos sus valores a cero de nuevo para jugar un juego nuevo.
 *VALOR QUE RETORNA
    tipo void.
*/
void feed_board()
{
    for(int i = 0;i < F;i++)//Se resetean los valores de la matriz.
        for(int j = 0;j < C;j++)
        {
            connect_4[i][j] = 0;
            gotoxy((((j)*4) + N), (((i)*4) + N));
            cout << " ";
        }
}

void hide_cursor()
{
    HANDLE hOut;
    CONSOLE_CURSOR_INFO ConCurInf;

    hOut = GetStdHandle(STD_OUTPUT_HANDLE);

    ConCurInf.dwSize = 100;
    ConCurInf.bVisible = FALSE;

    SetConsoleCursorInfo(hOut,
             &ConCurInf);
}

/* Esta funcion es la que se encarga de imprimir correctamente el selector (la flechita) de la columna.
 *PARAMETROS QUE RECIBE
    pos: es la eleccion del usuario. (choice)
    player: el jugador actual.
 *VALOR QUE RETORNA
    esta funcion es void, por lo tanto no retorna ningun valor.
*/
void locate(int pos,int player)
{
    switch(pos)
    {
        case 1:
            gotoxy(10,7);
            break;
        case 2:
            gotoxy(14,7);
            break;
        case 3:
            gotoxy(18,7);
            break;
        case 4:
            gotoxy(22,7);
            break;
        case 5:
            gotoxy(26,7);
            break;
        case 6:
            gotoxy(30,7);
            break;
        case 7:
            gotoxy(34,7);
            break;
    }

    if(player == 1)
        textcolor(LIGHTRED);
    else if(player == 2)
        textcolor(YELLOW);
    cout << " ||";
    gotoxy(wherex()-2,wherey()+1);
    cout << "\\/";
}

/* Esta funcion es la que se encarga de imprimir la tabla y el titulo y toda la interfaz.
 *VALOR QUE RETORNA
    tipo void.
*/
void print_board()
{
    textbackground(DARKGRAY);
    system("CLS");
    textcolor(LIGHTBLUE);

    textcolor(LIGHTRED);
    gotoxy(1,3);
    cout << "P1: ";//Aqui estara el score del jugador 1.
    gotoxy(5,3);
    cout<<check_win_P1;
    gotoxy(17,3);
    cout << "   O O O O \t<-   ->   Enter";
    gotoxy(17,4);
    textcolor(LIGHTBLUE);
    cout << "CONNECT FOUR!";
    textcolor(YELLOW);
    gotoxy(1,5);
    cout << "P2: ";//Aqui estara el score del jugador 2.
    gotoxy(5,5);
    cout<<check_win_P2;
    gotoxy(17,5);
    cout << "   O O O O \ta     d   e";
    textcolor(LIGHTBLUE);
    gotoxy(1,1);

    int i = 0, j = 0;

    for(;j < 8;j++)
        cout << endl;

    cout << "\t" << char(201);

    for(; i < F;i++)
        cout << char(205) << char(205) << char(205) << char(203);

    cout << char(205) << char(205) << char(205) << char(187) << endl;

    for(j = 0;j < 3;j++)
    {
        cout << "\t";
        for(i = 0;i <= 7;i++)
        {
            cout << char(186) << "   ";
        }
        cout << endl;
    }
    cout << "\t";
    for(j = 0;j < 5;j++)
    {
        cout << char(204);
        for(i = 0;i < F;i++)
            cout << char(205) << char(205) << char(205) << char(206);

        cout << char(205) << char(205) << char(205) << char(185) << endl;
        cout << "\t";
        for(i = 0;i < 3;i++)
        {
            for(int k = 0;k <= 7;k++)
            {
                cout << char(186) << "   ";
            }
            cout << endl;
            cout << "\t";
        }
    }

    cout << char(200);

    for(i = 0; i < F;i++)
        cout << char(205) << char(205) << char(205) << char(202);

    cout << char(205) << char(205) << char(205) << char(188) << endl;
}

/* Esta funcion es la que se encarga de guardar la jugada en la matriz connect_4.
 *PARAMETROS QUE RECIBE
    fila: de la jugada.
    column: de jugada.
    player: el jugador actual.
 *VALOR QUE RETORNA
    2: si hubo un ganador y se quiere volver a jugar otra vez.
*/
int save(int fila,int column,int player)
{
    char preg;
    if(fila == F)//Si fila es igual a 6, la igualamos a 5, por que en nuestra matriz es de 0-5.
        fila--;

    connect_4[fila][column] = player;
    cont++;
    if(cont == 43)
    {
        cout<<"EMPATE.";
        exit(0);
    }
    check_win = win(player);//despues que se guarda la posicion se chequea a ver si se gano.
    if(check_win == true)
    {
        if(player == 1)//Esto es para imprimir en pantalla el ganador y se le suma uno al contador de ganadas de ese jugador.
        {
            check_win_P1++;// Aqui se suma.
            gotoxy(5,3);
            cout<<check_win_P1;// se imprima la nueva cantidad de ganes del jugador.
            textcolor(LIGHTRED);
        }


        if(player == 2)
        {
            check_win_P2++;
            gotoxy(5,5);
            cout<<check_win_P2;
            textcolor(YELLOW);
        }

        gotoxy((((0)*4) + N), (((6)*4) + N));//usando nuestra formula ratata, imprimimos debajo de la tabla el ganador.
        cout << "JUGADOR " << player << ". USTED HA GANADO"<<endl;
        textcolor(LIGHTGRAY);
        cout << "Desea jugar de nuevo? S/N: ";
        preg = getch();
        if(preg == 's')
        {
            //se llama a feedboard, se resetea la matriz, y se pone check_win a false.
            feed_board();
            check_win = false;
            gotoxy((((0)*4) + N), (((6)*4) + N));
            clreol();
            gotoxy(0,wherey()+1);
            clreol();
            primera_jugada = player;
            return 2;//se retorna 2 a animation. para que indique que se quiere jugar otra vez.
        }
        else//Si preg es diferente de s, se acaba el juego y se sale.
            exit(0);
    }
    return 0;
}

/* Esta funcion es la que se encarga de mostrar la animacion de la seleccion de la columna donde se desea jugar.
 *PARAMETROS QUE RECIBE
    choice: es la eleccion del usuario (siempre sera un numero cualquiera en el primer caso).
    player: el jugador actual.
 *VALOR QUE RETORNA
    2: si ya hubo un ganador y se quiere volver a jugar otra vez.
    0: si es una seleccion jugada normal y no hubo un ganador.
*/
int GAME_UPDATE(int choice, int player)
{
    int chk;
    char opc;
    IFLLENO:
    do//Esto es el menu de la animacion del juego.
    {
        do
        {
            if(choice > 7)
                choice = 1;

            else if(choice < 1)
                choice = 7;

            locate(choice,player);

            opc = getch();

            if(player == 1)
            {
                if(opc == RIGHT)
                choice++;

                else if (opc == LEFT)
                choice--;

                if(opc == ENTER)
                {
                    gotoxy(1,wherey()-1);
                    clreol();
                    gotoxy(1,wherey()+1);
                    clreol();
                    break;
                }
            }
            else if(player == 2)
            {
                if(opc == 'd')
                choice++;

                else if(opc == 'a')
                choice--;

                if(opc == 'e')
                {
                    gotoxy(1,wherey()-1);
                    clreol();
                    gotoxy(1,wherey()+1);
                    clreol();
                    break;
                }
            }

            gotoxy(1,wherey()-1);
            clreol();
            gotoxy(1,wherey()+1);
            clreol();

        }while(opc != ENTER);
        chk = animation(choice-1,player);
        if(chk == 2)//si chk es 1 ya hubo un ganador y se quiere jugar otra vez., por ende se retorna 1 al main.
            return 2;
        if(chk == 1)
            goto IFLLENO;
    }while(0);
    return 0;
}

void SetWindow(int Width, int Height)
{
    _COORD coord;
    coord.X = Width;
    coord.Y = Height;

    _SMALL_RECT Rect;
    Rect.Top = 0;
    Rect.Left = 0;
    Rect.Bottom = Height - 1;
    Rect.Right = Width - 1;

    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);      // Get Handle
    SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size
    SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size
}

/* Esta funcion es la que se encarga de chequear quien gano.
 *PARAMETROS QUE RECIBE
    fila: de la jugada.
    column: de jugada.
    player: el jugador actual.
 *VALOR QUE RETORNA
    false: si no gano nadie
    true: si hubo un ganador.
*/
bool win(int player)
{
    int i,j;
    bool h = false;//horizontal
    bool v = false;//vertical
    bool d = false;//diagonal

    for(i=5; i>0; i--)//CHEQUEO HORIZONTAL
        for(j=0; j<4;j++)
        {
            h = check_win_h(i, j);
            if(h == true)
                return true;
        }

    for(i=5; i>=0; i--)//CHEQUEO VERTICAL
        for(j=0; j<7;j++)
        {
            v = check_win_v(i, j);
            if(v == true)
                return true;
        }

    for(i=5; i>0; i--)//CHEQUEO DIAGONAL HACIA ARRIBA
        for(j=0; j<4;j++)
        {
            d = check_win_d(i, j, 1);
            if(d == true)
                return true;
        }

    for(i=5; i>0; i--)//CHEQUEO DIAGONAL HACIA ABAJO
        for(j=6; j>2;j--)
        {
            d = check_win_d(i, j, 2);
            if(d == true)
                return true;
        }

    return false;
}
