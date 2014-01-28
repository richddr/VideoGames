#include <iostream>
#include <conio2.h>
#include <windows.h>
#define UP 0x48
#define DOWN 0x50
#define LEFT 0x4b
#define RIGHT 0x4d
#define ENTER 0x0D
#define SPACE 32
#define N 3

using namespace std;

//Variables Globales
int tic_tac_toe[N][N] = { };
int player[2] = { };
int primera_jugada,after_win = 0;
bool gane = false;

int animation(int,int);
void hide_cursor();
int locate(int,int);
int GAME_UPDATE(int);
int GAME_DEINIT();
void GAME_INIT();
void print_board();
void save(int,int);
void SetWindow(int, int);
bool win(int);

int main()
{
    SetWindow(55,30);
    hide_cursor();
    int x;

    INICIO:
    GAME_INIT();

    while(!gane)
    {
        for(int i = 1; i < 3; i++)
        {
            x = GAME_UPDATE(i);
            if(x == 9)//Si esta lleno
                GAME_DEINIT();
            else if(x == 0)//Si se gano
                break;
        }
    }
    if(GAME_DEINIT() == 1)
        goto INICIO;

    return 0;
}

/* Esta funcion es la que se encarga de mostrar la animacion de los jugadores al desplazarse por las posiciones de la tabla.
 *PARAMETROS QUE RECIBE
    choice: es la eleccion del usuario.
    player: el jugador actual.
 *VALOR QUE RETORNA
    9: si el tablero esta lleno y el juego se tranco.
    0: si es una seleccion jugada normal y no hubo un ganador.
*/
int animation(int choice, int player)
{
    choice = 5;// Es igualado a 5, para que empieze en en medio siempre.
    char opc;
    int lleno = 0;

    for(int i = 0;i < 3;i++)//Este for de aqui es el que determina cuando el tablero esta lleno y el juego se tranca.
        for(int j = 0;j < 3;j++)
        {
            if(tic_tac_toe[i][j] != 0)
                lleno++;
        }
    if(lleno == 9)//si tiene las 9 casillas ocupadas esta lleno y por ende retorna la variable lleno al main.
        return lleno;
    //Esto aqui es el lo que se encarga de mostrar la animacion de los jugadores al desplazarse por las posiciones de la tabla.
    do
    {
        do
        {

            if(choice > 9)
                choice -= 9;

            else if(choice < 1)
                choice += 9;

            locate(choice,player);//primero que todo se localiza la posicion actual del jugador.

            opc = getch();

            if(player == 1)//Cada jugador tiene sus controles diferentes
            {
                if(opc == ENTER)
                    break;

                else if(opc == RIGHT)
                    choice++;

                else if(opc == LEFT)
                    choice--;

                else if(opc == DOWN)
                    choice += 3;

                else if(opc == UP)
                    choice -= 3;
            }

            else if(player == 2)
            {
                if(opc == 'e')
                    break;

                else if(opc == 'd')
                    choice++;

                else if(opc == 'a')
                    choice--;

                else if(opc == 's')
                    choice += 3;

                else if(opc == 'w')
                    choice -= 3;
            }

            print_board(); // Imprimimos el tablero de nuevo.

            for(int i = 1;i < 10;i++) // Imprime en el tablero las jugadas previamente realizadas.
                locate(i,0);

        }while(1);

    }while(locate(choice,player) == 1);//este ciclo se repitara mientras la funcion locate retorne 1, osea que se guardo.

    save(choice,player);//se llama a la funcion save para guardar los nuevos valores en la matriz tic_tac_toe.
    return 0;
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

/* Esta funcion es la que se encarga de imprimir la X o O del jugador actual, mientras este se desplaza en el tablero eligiendo su posicion.
 *PARAMETROS QUE RECIBE
    pos: es la posicion del usuario.
    player: el jugador actual.
 *VALOR QUE RETORNA
    1: si esa posicion ya estava ocupada por otro jugador.
    0: si se guardo en un lugar donde no habia nadie. (una jugada normal)
*/
int locate(int pos, int player)
{
    bool used = false;
    if(player == -1)
        textcolor(LIGHTRED);

    else if(player == 1 || player == 2 || player == 0)
        textcolor(LIGHTGREEN);

    if(pos == 1)
    {
        gotoxy(2,6);// el gotoxy adecuado para caer en la exacta columna.
        if(tic_tac_toe[0][0] == 0)//Si en esa posicion ahi un cero, significa que esta vacia y disponible.
        {
            if(player == 1)
                cout << "X";

            else if(player == 2)
                cout << "O";
        }

        else
        {
            if(player != 0 && player != -1 && player != -2)//si no esta vacia, se le cambia el background color de fondo blanco para indicarle que no se puede jugar ahi.
                textbackground(WHITE);

            if(tic_tac_toe[0][0] == 1)
                cout << "X";
            else
                cout << "O";
            used = true;//se cambia used de false a true para que sepa que esta ocupada ya.
        }
    }
    //las mismas instrucciones se repiten para todas las posiciones.
    if(pos == 2)
    {
        gotoxy(6,6);
        if(tic_tac_toe[0][1] == 0)
        {
            if(player == 1)
                cout << "X";

            else if(player == 2)
                cout << "O";
        }

        else
        {
            if(player != 0 && player != -1 && player != -2)
                textbackground(WHITE);

            if(tic_tac_toe[0][1] == 1)
                cout << "X";
            else
                cout << "O";
            used = true;
        }
    }

    if(pos == 3)
    {
        gotoxy(10,6);
        if(tic_tac_toe[0][2] == 0)
        {
            if(player == 1)
                cout << "X";

            else if(player == 2)
                cout << "O";
        }

        else
        {
            if(player != 0 && player != -1 && player != -2)
                textbackground(WHITE);

            if(tic_tac_toe[0][2] == 1)
                cout << "X";
            else
                cout << "O";
            used = true;
        }
    }

    if(pos == 4)
    {
        gotoxy(2,10);
        if(tic_tac_toe[1][0] == 0)
        {
            if(player == 1)
                cout << "X";

            else if(player == 2)
                cout << "O";
        }

        else
        {
            if(player != 0 && player != -1 && player != -2)
                textbackground(WHITE);

            if(tic_tac_toe[1][0] == 1)
                cout << "X";
            else
                cout << "O";
            used = true;
        }
    }

    if(pos == 5)
    {
        gotoxy(6,10);
        if(tic_tac_toe[1][1] == 0)
        {
            if(player == 1)
                cout << "X";

            else if(player == 2)
                cout << "O";
        }

        else
        {
            if(player != 0 && player != -1 && player != -2)
                textbackground(WHITE);

            if(tic_tac_toe[1][1] == 1)
                cout << "X";
            else
                cout << "O";
            used = true;
        }
    }

    if(pos == 6)
    {
        gotoxy(10,10);
        if(tic_tac_toe[1][2] == 0)
        {
            if(player == 1)
                cout << "X";

            else if(player == 2)
                cout << "O";
        }

        else
        {
            if(player != 0 && player != -1 && player != -2)
                textbackground(WHITE);

            if(tic_tac_toe[1][2] == 1)
                cout << "X";
            else
                cout << "O";
            used = true;
        }
    }

    if(pos == 7)
    {
        gotoxy(2,14);
        if(tic_tac_toe[2][0] == 0)
        {
            if(player == 1)
                cout << "X";

            else if(player == 2)
                cout << "O";
        }

        else
        {
            if(player != 0 && player != -1 && player != -2)
                textbackground(WHITE);

            if(tic_tac_toe[2][0] == 1)
                cout << "X";
            else
                cout << "O";
            used = true;
        }
    }

    if(pos == 8)
    {
        gotoxy(6,14);
        if(tic_tac_toe[2][1] == 0)
        {
            if(player == 1)
                cout << "X";

            else if(player == 2)
                cout << "O";
        }

        else
        {
            if(player != 0 && player != -1 && player != -2)
                textbackground(WHITE);

            if(tic_tac_toe[2][1] == 1)
                cout << "X";
            else
                cout << "O";
            used = true;
        }

    }

    if(pos == 9)
     {
        gotoxy(10,14);
        if(tic_tac_toe[2][2] == 0)
        {
            if(player == 1)
                cout << "X";

            else if(player == 2)
                cout << "O";
        }

        else
        {
            if(player != 0 && player != -1 && player != -2)
                textbackground(WHITE);

            if(tic_tac_toe[2][2] == 1)
                cout << "X";
            else
                cout << "O";
            used = true;
        }
    }

    textcolor(YELLOW);
    textbackground(BLACK);
    return used;// se retorna used, que sera un 1,cuando es  verdadero, 0 cuando false.
}

/* Esta funcion es la que se encarga de imprimir el tablero y todo su interfaz.
*/
void print_board()
{
    gotoxy(1,1);
    cout << "Tic Tac Toe!!!" << endl;
    //Aqui es donde se imprime la interfaz del programa en general.
    gotoxy(1,5);
    for(int k = 0;k < 2;k++)
    {
        for(int x = 0;x < 3;x++)
        {
            for(int i = 0; i < 2;i++)
                cout << "   " << char(186);

            clreol();
            cout << endl;
        }

        for(int i = 0; i < 3;i++)
        {
            if(i != 2)
                cout << char(205) << char(205) << char(205) << char(206);
            else
                cout << char(205) << char(205) << char(205);
        }
        clreol();
        cout << endl;
    }

    for(int x = 0;x < 3;x++)
    {
        for(int i = 0; i < 2;i++)
            cout << "   " << char(186);

        clreol();
        cout << endl;
    }

    textcolor(LIGHTRED);
    gotoxy(17,8);
    cout << "Jugador X: " << player[0];
    textcolor(YELLOW);
    gotoxy(17,10);
    cout << "   ^     enter";
    gotoxy(17,11);
    cout << "<- v ->";


    textcolor(LIGHTRED);
    gotoxy(17,13);
    cout << "Judador O: " << player[1];
    gotoxy(17,15);
    textcolor(YELLOW);
    cout << "  w      e";
    gotoxy(17,16);
    cout << "a s d";
    textcolor(YELLOW);

    return;
}

/* Esta funcion inicia los valores del juego, gane ==  false.
*/
void GAME_INIT()
{
    gane = false;
    textcolor(YELLOW);
    print_board();
}

/* Esta funcion pregunta si se jugara de nuevo o no.
*/
int GAME_DEINIT()
{
    cout << "Desea jugar de nuevo? S/N: ";
    char preg;
    preg = getche();
    tolower(preg);

    if(preg == 's')//Si se quiere volver a jugar otra vez, se reinicia la matriz del tic_tac_toe.
    {
        clrscr();
        for(int i = 0;i < 3;i++)
            for(int j = 0;j < 3;j++)
                tic_tac_toe[i][j] = 0;
        return 1;
    }
    return 0;
}

/* Esta funcion actualiza todo, recibe el jugador (i).
*/
int GAME_UPDATE(int i)
{
    int choice, lleno;
    gotoxy(2,17);

    textcolor(WHITE);
    if(after_win == 1)//el que gano el juego anterior es quien juega primero el proximo juego.
        i = primera_jugada;

    if(i == 1)
        cout << "Jugador X";
    else
        cout << "Jugador O";

    textcolor(YELLOW);
    clreol();
    lleno = animation(choice,i);

    if(lleno == 9)
    {
        textcolor(BLACK);
        print_board();
        for(int j = 1;j <= 9;j++)
        {
            if(j == 2 || j == 5 || j == 8 || j == 4 || j == 6)
            {
                textcolor(BLACK);
                textbackground(WHITE);
            }

            if(j == 1 || j == 9)
            {
                textcolor(BLACK);
                textbackground(LIGHTBLUE);
            }

            if(j == 3 || j == 7)
            {
                textcolor(BLACK);
                textbackground(LIGHTRED);
            }

            locate(j,-2);
            Sleep(150);
        }

        gotoxy(2,16);
        cout << "Empate. Se han agotado todas las jugadas."<<endl;
        clreol();
        return lleno;
    }

    if(win(i))
    {
        gane = true;

        if(i == 1)
        {
            gotoxy(12,20);
            cout << "Felicidades al Jugador X!!!, Usted ha ganado!" << endl;
        }

        else
        {
            gotoxy(12,20);
            cout << "Felicidades al Jugador O!!!, Usted ha ganado!" << endl;
        }
        player[i-1]++;//aqui es donde se le suma la cantida de ganadas al respectivo jugador que gano para luego imprimirlo.
        after_win = 1;
        primera_jugada = i;//el ganador de este juego es el que jugara primero el proximo si desea jugar de nuevo.
        return 0;
    }
    after_win = 0;//nadie gano por ende after no se cambia a uno.
    return -1;
}

/* Esta funcion es la que se encarga de guardar el numero del jugador actual en la posicion selecionada en la matriz tic_tac_toe.
 *PARAMETROS QUE RECIBE
    pos: es la posicion del usuario.
    player: el jugador actual.
*/
void save(int pos,int player)
{
    switch(pos)//En cada posicion se guarda solamente si era igual a cero antes. osea si estava vacia.
    {
        case 1:
            if(tic_tac_toe[0][0] == 0)
                tic_tac_toe[0][0] = player;
            break;

        case 2:
            if(tic_tac_toe[0][1] == 0)
                tic_tac_toe[0][1] = player;
            break;

        case 3:
            if(tic_tac_toe[0][2] == 0)
                tic_tac_toe[0][2] = player;
            break;

        case 4:
            if(tic_tac_toe[1][0] == 0)
                tic_tac_toe[1][0] = player;
            break;

        case 5:
            if(tic_tac_toe[1][1] == 0)
                tic_tac_toe[1][1] = player;
            break;

        case 6:
            if(tic_tac_toe[1][2] == 0)
                tic_tac_toe[1][2] = player;
            break;

        case 7:
            if(tic_tac_toe[2][0] == 0)
                tic_tac_toe[2][0] = player;
            break;

        case 8:
            if(tic_tac_toe[2][1] == 0)
                tic_tac_toe[2][1] = player;
            break;

        case 9:
            if(tic_tac_toe[2][2] == 0)
                tic_tac_toe[2][2] = player;
            break;
    }
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

/* Esta funcion es la que se encarga de chequear si hubo un ganador con cada jugada realizada.
 *PARAMETROS QUE RECIBE
    player: el jugador actual.
 *VALOR QUE RETORNA
    true: si hubo una ganador.
    false: si no se gano.
*/
bool win(int player)
{
    /*  TABLERO
         0 1 2

      0  1 2 3
      1  4 5 6
      2  7 8 9

      A continuacion se muestran todas las posibilidades para poder ganar. a la combinacion ganadora se le cambia el color a rojo,
      esto lo hacemos mandandole player como -1 a la funcion locate para cada uno de los puntos.
      Esto se repite en todad las posibles formas de ganar.
    */
    if((tic_tac_toe[0][0] == player) && (tic_tac_toe[0][1] == player) && (tic_tac_toe[0][2] == player))//123
    {
        locate(1,-1);
        locate(2,-1);
        locate(3,-1);
        return true;
    }

    if((tic_tac_toe[0][0] == player) && (tic_tac_toe[1][0] == player) && (tic_tac_toe[2][0] == player))//147
    {
        locate(1,-1);
        locate(4,-1);
        locate(7,-1);
        return true;
    }

    if((tic_tac_toe[0][0] == player) && (tic_tac_toe[1][1] == player) && (tic_tac_toe[2][2] == player))//159
    {
        locate(1,-1);
        locate(5,-1);
        locate(9,-1);
        return true;
    }

    if((tic_tac_toe[1][0] == player) && (tic_tac_toe[1][1] == player) && (tic_tac_toe[1][2] == player))//456
    {
        locate(4,-1);
        locate(5,-1);
        locate(6,-1);
        return true;
    }

    if((tic_tac_toe[2][0] == player) && (tic_tac_toe[2][1] == player) && (tic_tac_toe[2][2] == player))//789
    {
        locate(7,-1);
        locate(8,-1);
        locate(9,-1);
        return true;
    }

    if((tic_tac_toe[2][0] == player) && (tic_tac_toe[1][1] == player) && (tic_tac_toe[0][2] == player))//753
    {
        locate(7,-1);
        locate(5,-1);
        locate(3,-1);
        return true;
    }

    if((tic_tac_toe[0][1] == player) && (tic_tac_toe[1][1] == player) && (tic_tac_toe[2][1] == player))//258
    {
        locate(2,-1);
        locate(5,-1);
        locate(8,-1);
        return true;
    }

    if((tic_tac_toe[0][2] == player) && (tic_tac_toe[1][2] == player) && (tic_tac_toe[2][2] == player))//369
    {
        locate(3,-1);
        locate(6,-1);
        locate(9,-1);
        return true;
    }

    return false;//si no se gano se retorna false para indicar tal cosa.
}
