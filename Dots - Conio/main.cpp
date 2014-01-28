#include <iostream>
#include <conio2.h>
#include <windows.h>
#include <stdlib.h>
#include <stdio.h>
#define UP 0x48
#define DOWN 0x50
#define LEFT 0x4b
#define RIGHT 0x4d
#define ENTER 0x0D
#define ESC 0x1B
#define SYMBOL 254
#define FONDO WHITE

using namespace std;

typedef struct
{
    bool up;
    bool down;
    bool left;
    bool right;
} TPUNTOS;

typedef struct
{
    char nombre[10];
    int color;
    int puntaje;
}JUGADOR;

char ant;//Para la funcion ani_enlace
int f,c,t,x,y,cont = 0;//f,c (fila y columna), cont para el menu del inicio.
int TEXTO = LIGHTRED;
JUGADOR player[2] = { };


void ani_enlace(int, int, char, TPUNTOS**);//Esto es para mostrar la animacion de los enlaces cuando te desplazes.
bool buscar_cuadro(int, int, int, int,TPUNTOS**);
void crear_jugador();
int check_eleccion(int);
void GAME_DEINIT();
int GAME_UPDATE(TPUNTOS**);
void hide_cursor();
TPUNTOS** GAME_INIT(TPUNTOS**);
void locate(int, int);
void locate_player(int, int);
int menu_colores();
void menu_controles();
int menu_juegos();
void print_board();
int selection(TPUNTOS**);
void SetWindow(int, int);


int main()
{
    hide_cursor();
    INICIO_OPCIONES:
    int opcion  = menu_juegos();
    if(check_eleccion(opcion))
        goto INICIO_OPCIONES;

    textbackground(FONDO);
    textcolor(LIGHTRED);
    system("cls");

    TPUNTOS** puntos;
    puntos = GAME_INIT(puntos);

    do
    {
        for(t = 0; t < 2; t++)//Ciclo Mayor, de lo jugadores.
        {
            GAME_UPDATE(puntos);
            if((player[0].puntaje + player[1].puntaje) >= ((f - 1) * (c - 1)))//Condicion de Parada.
                break;
        }
    }while((player[0].puntaje + player[1].puntaje) < ((f - 1) * (c - 1)));

    GAME_DEINIT();
    goto INICIO_OPCIONES;
    return 0;
}

/* Esta funcion es la que se encarga de mostrar la animacion de los jugadores al desplazarse por las direcciones cuando ya seleccionaron un punto.
 *PARAMETROS QUE RECIBE
    fl,cl: La fila y columna donde el usuario hizo la eleccion.
    opc: la tecla actual pulsada por el jugador, (left, right, up, down, esc).
    puntos: la matriz.
*/
void ani_enlace(int fl, int cl,  char opc, TPUNTOS **puntos)
{

    char left_right[] = "---";
    char up_down = char(124);


    if(opc == RIGHT || ant == RIGHT || opc == 'd' || ant == 'd')//IMPRIMIR/BORRAR DERECHA
    {
        if( puntos[fl][cl].right == false)
        {
            if((opc != RIGHT && ant == RIGHT) || (opc != 'd' && ant == 'd') || (opc != RIGHT && ant == 'd') || (opc != 'd' && ant == RIGHT))
            {
                gotoxy((12 + (cl * 4)), (11 + (fl * 4)));
                cout << "   ";
                gotoxy(wherex()-3,wherey());
            }

        }

        if( (((cl + 1) < c) && opc == RIGHT) ||  (((cl + 1) < c) && opc == 'd'))
        {
            gotoxy((12 + (cl * 4)), (11 + (fl * 4)));
            cout << left_right;
            locate(fl,cl+1);
        }
    }

    if(opc == LEFT || ant == LEFT || opc == 'a' || ant == 'a')//IMPRIMIR/BORRAR IZQUIERDA
    {
        if(puntos[fl][cl].left == false)
        {
            if((opc != LEFT && ant == LEFT) || (opc != 'a' && ant == 'a') || (opc != LEFT && ant == 'a') || (opc != 'a' && ant == LEFT))
            {
                gotoxy((8 + (cl * 4)), (11 + (fl * 4)));
                cout << "   ";
                gotoxy(wherex()+2,wherey());
            }
        }

        if(((cl > 0) && opc == LEFT) || ((cl > 0) && opc == 'a'))
        {
            gotoxy((8 + (cl * 4)), (11 + (fl * 4)));
            cout << left_right;
            locate(fl,cl-1);
        }
    }

    if(opc == UP || ant == UP || opc == 'w' || ant == 'w')//IMPRIMIR/BORRAR ARRIBA
    {
        if(puntos[fl][cl].up == false)
        {
            if((opc != UP && ant == UP) || (opc != 'w' && ant == 'w') || (opc != UP && ant == 'w') || (opc != 'w' && ant == UP))
            {
                for(int i = 10; i>7; i--)
                {
                    gotoxy((11 + (cl * 4)), (i + (fl * 4)));
                    cout <<" ";
                }
            }
            gotoxy(wherex(),wherey()+3);
        }

        if( ((fl > 0) && opc == UP) || ((fl > 0) && opc == 'w'))
        {
           for(int i = 10; i>7; i--)
            {
                gotoxy((11 + (cl * 4)), (i + (fl * 4)));
                cout << up_down;
                locate(fl-1,cl);
            }
        }
    }

    if(opc == DOWN || ant == DOWN || opc == 's' || ant == 's')//IMPRIMIR/BORRAR ABAJO
    {
        if(puntos[fl][cl].down == false)
        {
            if((opc != DOWN && ant == DOWN) || (opc != 's' && ant == 's') || (opc != DOWN && ant == 's') || (opc != 's' && ant == DOWN))
            {
                for(int i = 12; i<15; i++)
                {
                    gotoxy((11 + (cl * 4)), (i + (fl * 4)));
                    cout << " ";
                }
            }
            gotoxy(wherex(),wherey()-3);

        }

        if( (((fl + 1) < f) && opc == DOWN) || (((fl + 1) < f) && opc == 's'))
        {
            for(int i = 12; i<15; i++)
            {
                gotoxy((11 + (cl * 4)), (i + (fl * 4)));
                cout << up_down;
                locate(fl+1,cl);
            }
        }
    }

    if(opc ==  ESC)
    {
        if((ant == RIGHT && puntos[fl][cl].right == false) || (ant == 'd' && puntos[fl][cl].right == false))
        {
            gotoxy((12 + (cl * 4)), (11 + (fl * 4)));
            cout << "   ";
        }

        if((ant == LEFT && puntos[fl][cl].left == false) || (ant == 'a' && puntos[fl][cl].left == false))
        {
            gotoxy((8 + (cl * 4)), (11 + (fl * 4)));
            cout << "   ";
        }

        if((ant == UP && puntos[fl][cl].up == false) || (ant == 'w' && puntos[fl][cl].up == false))
        {
            for(int i = 10; i>7; i--)
            {
                gotoxy((11 + (cl * 4)), (i + (fl * 4)));
                cout <<" ";
            }
        }

        if((ant ==  DOWN && puntos[fl][cl].down == false) || (ant ==  's' && puntos[fl][cl].down == false))
        {
            for(int i = 12; i<15; i++)
            {
                gotoxy((11 + (cl * 4)), (i + (fl * 4)));
                cout << " ";
            }
        }
    }

    ant = opc;// se iguala el teclado pulsado actual, al anterior.
}

/* Esta funcion es la que se encarga de buscar los posibles cuadro rellenos desde un determinado punto.(RECURSIVA)
 *PARAMETROS QUE RECIBE
    f,c: La fila y columna donde el usuario hizo la eleccion y se manda chequear si es true.
    k: la combinacion especifica a chequear.
    player: el jugador actual.
    puntos: la matriz.
 *VALOR QUE RETORNA
    true: si se logro completar un cuadro.
    false: Si no se logro completar un cuadro.
*/
bool buscar_cuadro(int f,int c,int k,int player,TPUNTOS **puntos)
{
    if(k == 0)  // Para buscar R,D,L,U al recibir 0.
        if(puntos[f][c].right)
            return buscar_cuadro(f,c+1,k+1,player,puntos);

    if(k == 1)
        if(puntos[f][c].down)
            return buscar_cuadro(f+1,c,k+1,player,puntos);

    if(k == 2)
        if(puntos[f][c].left)
            return buscar_cuadro(f,c-1,k+1,player,puntos);
    if(k == 3)
        if(puntos[f][c].up)
        {
            locate_player(f-1,c);
            return true;
        }
    if(k == 4)  // Para buscar L,D,R,U al recibir 4.
        if(puntos[f][c].left)
            return buscar_cuadro(f,c-1,k+1,player,puntos);

    if(k == 5)
        if(puntos[f][c].down)
            return buscar_cuadro(f+1,c,k+1,player,puntos);

    if(k == 6)
        if(puntos[f][c].right)
            return buscar_cuadro(f,c+1,k+1,player,puntos);

    if(k == 7)
        if(puntos[f][c].up)
        {
            locate_player(f-1,c-1);
            return true;
        }

    if(k == 8) // Para buscar R,U,L,D al recibir 8.
        if(puntos[f][c].right)
            return buscar_cuadro(f,c+1,k+1,player,puntos);

    if(k == 9)
        if(puntos[f][c].up)
            return buscar_cuadro(f-1,c,k+1,player,puntos);

    if(k == 10)
        if(puntos[f][c].left)
            return buscar_cuadro(f,c-1,k+1,player,puntos);
    if(k == 11)
        if(puntos[f][c].down)
        {
            locate_player(f,c);
            return true;
        }

     if(k == 12) // Para buscar L,U,R,D al recibir 12.
        if(puntos[f][c].left)
            return buscar_cuadro(f,c-1,k+1,player,puntos);

    if(k == 13)
        if(puntos[f][c].up)
            return buscar_cuadro(f-1,c,k+1,player,puntos);

    if(k == 14)
        if(puntos[f][c].right)
            return buscar_cuadro(f,c+1,k+1,player,puntos);
    if(k == 15)
        if(puntos[f][c].down)
        {
            locate_player(f,c-1);
            return true;
        }

    return false;

}

/*Cheqea la eleccion seleccionada desde el menu.
   Recibe la seleccion.
*/
int check_eleccion(int opcion)
{
    switch(opcion)
    {
        case 1:
            if(cont == 0)//Esto es si no han personalizado su propio perfil. Cojer Estos valores predeterminados.
            {
                player[0].nombre = {'1'};
                player[0].color = 9;
                player[0].puntaje = 0;

                player[1].nombre = {'2'};
                player[1].color = 12;
                player[1].puntaje = 0;
            }
            else//Cuando se vaya a jugar otra partida despues de una previa se resetean los valores.
            {
                player[0].puntaje = 0;
                player[1].puntaje = 0;
            }
            break;
        case 2:
            crear_jugador();
            cout << "Presione una tecla para elejir el color que desea para los puntos en el tablero." << endl;
            getch();
            TEXTO = menu_colores();
            cont++;
            return 1;
            break;
        case 3:
            menu_controles();
            return 1;
            break;
    }
    return 0;
}
/* Esta funcion es la que se encarga de personalizar/crear los jugadores antes de darle a START GAME en el menu principal.
*/
void crear_jugador()
{
    system("CLS");
    for(int i = 0;i < 2;i++)
    {
        cout << "Digitar nombre del jugador " << i+1 << ": " << endl;
        cin >> player[i].nombre;
        player[i].color = menu_colores();
        player[i].puntaje = 0;
    }
}

/*Representa los resultados finales al final del juego.
*/
void GAME_DEINIT()
{
    gotoxy(1, (11 + (f * 4)));//Se Imprime luego sus ultimos score abajo.
    cout << "Player " << player[0].nombre << ": " << player[0].puntaje << endl;
    cout << "Player " << player[1].nombre << ": " << player[1].puntaje;

    SetWindow(x + 20, y + 10);// Se Reposiciona la pantalla para poder imprimir los resultados adecuadamente.

    gotoxy(1, y+1);

    if(player[0].puntaje == player[1].puntaje)
    {
        cout << "Empate!, han llenado todas las cajas."<< endl <<"Ambos tiene la misma cantidad de cajas."<< endl;
        clreol();
    }
    else
    {
        cout << "\nEl juego ha terminado!" << endl << "El ganador es: ";
        if(player[0].puntaje > player[1].puntaje)
        {
           cout << player[0].nombre << endl;
           cout << "Total de Cajas: " << player[0].puntaje;
        }
        else if(player[0].puntaje < player[1].puntaje)
        {
           cout << player[1].nombre << endl;
           cout << "Total de Cajas: " << player[1].puntaje;
        }
    }
    cout << "\n\nPresione una tecla para volver al menu...";
    getch();
    system("cls");
}

int GAME_UPDATE(TPUNTOS** puntos)
{
    gotoxy(1, (5 + (0 * 4)));
    cout << "Jugador en turno: " << player[t].nombre;
    clreol();
    gotoxy(1, (11 + (f * 4)));
    cout << "Player " << player[0].nombre << ": " << player[0].puntaje << endl;
    cout << "Player " << player[1].nombre << ": " << player[1].puntaje;

    if(!(selection(puntos)))//Si el usuario actual logro completar una caja o si no realizo ninguna jugada valida, sigue jugando el proximo turno.
        t--;
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

/*Se inicia el juego. se digita la dimension de la matriz.
  recibe la matriz puntos.
*/
TPUNTOS** GAME_INIT(TPUNTOS** puntos)
{
     do//El usuario digita el tamaño de su matriz.
    {
        cout << "Digite el numero de filas que desea: "; // Maximo 13
        cin >> f;
        if(f > 13)
            cout << "El maximo de filas permitidas es 13" << endl;
    }while(f > 13);

    do
    {
        cout << "Digite el numero de columnas que desea: "; // Maximo 45
        cin >> c;
        if(c > 45)
            cout << "El maximo de columnas permitidas es 45" << endl;

    }while(c > 45);
    system("cls");//Limpiamos la pantalla.

    x = 13 + (4*c);//Ecuacion para calcular el tamaño adecuado de la pantalla.
    y = 15 + (4*f);
    SetWindow(x,y);

    puntos = new TPUNTOS *[f];//Usamos el constructor new(). :D

    for(int n = 0; n < f; n++)
        puntos[n] = new TPUNTOS[c];

    for(int i = 0;i < f;i++)       //Aqui Igualamos todos los valores de la matriz a false.
        for(int j = 0;j < c;j++)
        {
            puntos[i][j].up = false;
            puntos[i][j].down = false;
            puntos[i][j].left = false;
            puntos[i][j].right = false;
        }

    clrscr();
    cout << "Generando tablero.";
    Sleep(500);
    clrscr();
    print_board();

    return puntos;
}
/* Esta funcion es la que se encarga de imprimir el symbolo sombreado en la posicion que el usuario ha direccionado.
 *PARAMETROS QUE RECIBE
    f,c: La fila y columna donde el usuario hizo la eleccion.
*/
void locate(int f,int c)
{
    gotoxy((11 + (c * 4)), (11 + (f * 4)));
    textbackground(player[t].color);
    cout << char(SYMBOL);
    textbackground(FONDO);
}

/* Esta funcion es la que se encarga de cuando un cuadro ya esta lleno, lo rellena del color elegido por el jugador actual y su inicial.
 *PARAMETROS QUE RECIBE
    f,c: La fila y columna de donde el cuadro logro ser true en la 4 esquinas y pudo completarse.
    p: el jugador actual.
*/
void locate_player(int f, int c)
{
    textbackground(player[t].color);

    if((player[t].color == YELLOW) || (player[t].color == LIGHTGREEN) || (player[t].color == LIGHTCYAN))
        textcolor(BLACK);
    else
        textcolor(WHITE);

    for(int q = 1;q <= 3;q++)
        for(int z = 1;z <= 3;z++)
        {
            gotoxy((11 + q +(c * 4)), (11 + z + (f * 4)));//nos posicionamos en los 9 espacion que ahi dentro de cada cuadro.
            cout << " ";//imprimimos un espacio. que sera del color de background elegido por el usuario.
        }

    gotoxy((13 + (c * 4)), (13 + (f * 4)));//Nos posicionamos en el medio del cuadro e imprimimos la primera letra del nombre.

    cout << player[t].nombre[0];

    textcolor(TEXTO);
    textbackground(FONDO);
}

/* Esta funcion es la que se encarga de mostrar el menu de colores despues que el usuario haya digitado su nombre.
 *VALOR QUE RETORNA
    retorna el numero del color elegido.
*/
int menu_colores()
{
    char* opciones[9];

    char op_uno[] = "CYAN";
    char op_dos[] = "MAGENTA";
    char op_tres[] = "LIGHTBLUE";
    char op_cuatro[] = "LIGHTGREEN";
    char op_cinco[] = "LIGHTCYAN";
    char op_seis[] = "LIGHTRED";
    char op_siete[] = "LIGHTMAGENTA";
    char op_ocho[] = "YELLOW";

    opciones[1] = op_uno;
    opciones[2] = op_dos;
    opciones[3] = op_tres;
    opciones[4] = op_cuatro;
    opciones[5] = op_cinco;
    opciones[6] = op_seis;
    opciones[7] = op_siete;
    opciones[8] = op_ocho;

    char opc;
    int seleccion = 1, i;
    do
    {
        textcolor(WHITE);
        inicio:
        textbackground(BLACK);
        clrscr();
        cout << "\t\t\t\tSeleccione un color:\n\n";
        int color;
        for(i = 1;i < 9;i++)
        {
            if(seleccion == i)
            {
                    switch(seleccion)
                    {
                        case 1:
                            color = 3;
                            break;
                        case 2:
                            color = 5;
                            break;
                        case 3:
                            color = 9;
                            break;
                        case 4:
                            color = 10;
                            break;
                        case 5:
                            color = 11;
                            break;
                        case 6:
                            color = 12;
                            break;
                        case 7:
                            color = 13;
                            break;
                        case 8:
                            color = 14;
                            break;
                    }

                textbackground(color);
                cout << "\t" << opciones[i] << "\t\t\t\t\t\t\t       ";
                textbackground(BLACK);
                cout << endl;
            }
            else
                cout <<"\t" << opciones[i] << endl;
        }

        if (seleccion == 0)
        {
            seleccion = 8;
            goto inicio;
        }
        else if (seleccion == 9)
        {
            seleccion = 1;
            goto inicio;
        }
        opc = getche();

        if(opc == UP)
            seleccion--;

        else if(opc == DOWN)
            seleccion++;

    }while(opc != ENTER);

    textbackground(BLACK);
    clrscr();

    switch(seleccion)
    {
        case 1:
            return 3;
        case 2:
            return 5;
        case 3:
            return 9;
        case 4:
            return 10;
        case 5:
            return 11;
        case 6:
            return 12;
        case 7:
            return 13;
        case 8:
            return 14;
    }
    return 0;
}

/* Esta funcion es la que se encarga de mostrar en INSTRUCCIONES, la instrucciones de como jugar.
*/
void menu_controles()
{
    system("CLS");

    cout << "\n\nJUGADOR 1"<< endl;
    textcolor(YELLOW);
    cout << "\n    ^\t\tENTER"<< endl;
    cout << " <-   ->"<< endl;
    cout << "    v"<< endl;

    textcolor(WHITE);
    cout << " \n\n\nJUGADOR 2"<< endl;
    textcolor(YELLOW);
    cout << "\n   w\t\te"<< endl;
    cout << " a s d"<< endl;

    textcolor(WHITE);
    cout << "\n\n- Darle a START GAME sin personalizar jugadores en AJUSTES\n  utiliza los jugadores predeterminados. (1-RED y 2-BLUE)\n  y usa el color predeterminado de los puntos del tablero, rojo.";
    cout << "\n\n- Se mueve por los puntos, enter/e para seleccionar ese punto luego se\n  selecciona la direccion deseada. Luego el cursor se situa en el primer punto.";
    cout << "\n\n- Presionar ESC cuando ya se presiono enter/e y se desplazo hacia una direccion,\n  reposiciona al jugador al principio.\n  (Para que realize una nueva eleccion el mismo jugador.)";
    cout << "\n\n- Presionar enter/e dos veces repetidas sin haberte desplazado a ninguna,\n  direccion te reposiciona en esa misma posicion para poder realizar una nueva\n  eleccion.";


    cout << "\n\n\nPresione una tecla para volver al menu...";
    getch();

}

/* Esta funcion es la que se encarga de mostrar el menu principal.
 *VALOR QUE RETORNA
    retorna la seleccion elegida al main.
*/
int menu_juegos()
{
    SetWindow(80,35);
    char* opciones[5];

    char op_uno[] = "START GAME";
    char op_dos[] = "AJUSTES";
    char op_tres[] = "INSTRUCCIONES";
    char op_cuatro[] = "SALIDA";

    opciones[1] = op_uno;
    opciones[2] = op_dos;
    opciones[3] = op_tres;
    opciones[4] = op_cuatro;

    char opc;
    int seleccion = 1, i;
    do
    {
        textcolor(WHITE);
        inicio:
        textbackground(BLACK);
        clrscr();
        cout << "\t\t\t\tMAIN MENU\n\n";

        for(i =1;i < 5;i++)
        {
            if(seleccion == i)
            {
                textbackground(LIGHTBLUE);
                cout << "\t" << opciones[i] << "\t\t\t\t\t\t\t       ";
                textbackground(BLACK);
                cout << endl;
            }
            else
                cout <<"\t" << opciones[i] << endl;

        }

        if (seleccion == 0)
        {
            seleccion = 4;
            goto inicio;
        }
        else if (seleccion == 5)
        {
            seleccion = 1;
            goto inicio;
        }
        opc = getche();

        if(opc == UP)
            seleccion--;

        else if(opc == DOWN)
            seleccion++;

    }while(opc!=ENTER);

    textbackground(BLACK);
    clrscr();

    if(seleccion == 4)
        exit(0);

    return seleccion;
}

/* Esta funcion es la que se encarga de mostrar el menu principal.
 *PARAMETROS QUE RECIBE
    f,c: la dimension especificada por el usuario al princio en el main.
*/
void print_board()
{
    textcolor(TEXTO);

    gotoxy(11,11);
    for(int i = 0; i < f; i++)
    {
        for(int j = 0; j < c; j++)
        {
            gotoxy((11 + (j * 4)), (11 + (i * 4)));
            cout << char(SYMBOL);
        }
    }
}

/* Esta funcion es la que se encarga hacer posible desplazarse en la tabla de puntos y seleccionar uno y hacer una jugada.
 *PARAMETROS QUE RECIBE
    f,c: dimension de la matriz digitada en el main.
    p: el jugador actual.
    puntos: la matriz.
 *VALOR QUE RETORNA
    0: si se logro completar un cuadro
    1: Si no se logro completar un cuadro.
*/
int selection(TPUNTOS **puntos)
{
    int fila = 0,columna = 0;
    RE_ENTRY:
    int cont = 0;
    char opc,tmp;
    do
    {
        if(columna == c)
            columna = 0;

        else if(columna < 0)
            columna = c - 1;

        else if(fila == f)
            fila = 0;

        else if(fila < 0)
            fila = f - 1;

        locate(fila,columna);

        opc = getch();

        if(t == 0)//JUGADOR 1
        {
            if(opc == ENTER)
                break;

            else if(opc == RIGHT)
                columna++;

            else if(opc == LEFT)
                columna--;

            else if(opc == DOWN)
                fila++;

            else if(opc == UP)
                fila--;
        }

        else if(t == 1)//JUGADOR 2
        {
            if(opc == ENTER || opc == 'e')
                break;

            else if(opc == RIGHT || opc == 'd')
                columna++;

            else if(opc == LEFT || opc == 'a')
                columna--;

            else if(opc == DOWN || opc == 's')
                fila++;

            else if(opc == UP || opc == 'w')
                fila--;
        }
        gotoxy(wherex()-1,wherey());
        cout << char(SYMBOL);

    }while(1);

    cont = 1;

    do
    {
        opc = getch();

        print_board();

        if((opc == ENTER && cont == 1) || (opc == 'e' && cont == 1))//Si le dio a enter en el primer caso significa que escogio un punto equivocado. por lo tanto vulve a selecionar su punto.
            goto RE_ENTRY;

        if(opc == ESC)
        {
            ani_enlace(fila, columna, opc, puntos);
            goto RE_ENTRY;
        }

        if(t == 0)//JUGADOR 1
        {
            fflush(stdin);
            if(opc == ENTER)
                break;

            if(opc == RIGHT)
                if(puntos[fila][columna].right == false)
                    ani_enlace(fila,columna,opc,puntos);

            if(opc == LEFT)
               if(puntos[fila][columna].left == false)
                   ani_enlace(fila,columna,opc,puntos);

            if(opc == DOWN)
               if(puntos[fila][columna].down == false)
                   ani_enlace(fila,columna,opc,puntos);

            if(opc == UP)
                if(puntos[fila][columna].up == false)
                    ani_enlace(fila,columna,opc,puntos);
        }

        else if(t == 1)//JUGADOR 2
        {
            fflush(stdin);
            if(opc == ENTER || opc == 'e')
                break;

            if(opc == RIGHT || opc == 'd')
                if(puntos[fila][columna].right == false)
                    ani_enlace(fila,columna,opc,puntos);

            if(opc == LEFT || opc == 'a')
               if(puntos[fila][columna].left == false)
                   ani_enlace(fila,columna,opc,puntos);

            if(opc == DOWN || opc == 's')
               if(puntos[fila][columna].down == false)
                   ani_enlace(fila,columna,opc,puntos);

            if(opc == UP || opc == 'w')
                if(puntos[fila][columna].up == false)
                    ani_enlace(fila,columna,opc,puntos);
        }
        tmp = opc;
        cont++;

    }while(1);

    int gane = 0;

    if((tmp == RIGHT || tmp == 'd') && puntos[fila][columna].right == false)
        if(columna + 1 < c)
        {
            gane = 1;
            puntos[fila][columna].right = true;
            puntos[fila][columna+1].left = true;

            if(buscar_cuadro(fila,columna,0,t,puntos))
            {
                gane = 0;
                player[t].puntaje++;

            }
            if(buscar_cuadro(fila,columna,8,t,puntos))
            {
                gane = 0;
                player[t].puntaje++;
            }

        }

    if((tmp == LEFT || tmp == 'a') && puntos[fila][columna].left == false)
        if(columna > 0)
        {
            gane = 1;
            puntos[fila][columna].left = true;
            puntos[fila][columna-1].right = true;

            if(buscar_cuadro(fila,columna,4,t,puntos))
            {
                player[t].puntaje++;
                gane = 0;
            }

            if(buscar_cuadro(fila,columna,12,t,puntos))
            {
                player[t].puntaje++;
                gane = 0;
            }
        }

    if((tmp == DOWN || tmp == 's') && puntos[fila][columna].down == false)
        if(fila + 1 < f)
        {
            gane = 1;
            puntos[fila][columna].down = true;
            puntos[fila+1][columna].up = true;

            if(buscar_cuadro(fila,columna,0,t,puntos))
            {
                player[t].puntaje++;
                gane = 0;
            }
            if(buscar_cuadro(fila,columna,4,t,puntos))
            {
                player[t].puntaje++;
                gane = 0;
            }
        }

    if((tmp == UP || tmp == 'w') && puntos[fila][columna].up == false)
        if(fila > 0)
        {
            gane = 1;
            puntos[fila][columna].up = true;
            puntos[fila-1][columna].down = true;

            if(buscar_cuadro(fila,columna,8,t,puntos))
            {
                player[t].puntaje++;
                gane = 0;
            }
            if(buscar_cuadro(fila,columna,12,t,puntos))
            {
                player[t].puntaje++;
                gane = 0;
            }
        }
    return gane;
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
    //SetConsoleScreenBufferSize(Handle, coord);            // Set Buffer Size
    SetConsoleWindowInfo(Handle, TRUE, &Rect);            // Set Window Size
}
