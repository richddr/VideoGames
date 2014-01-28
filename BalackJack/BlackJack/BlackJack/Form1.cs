using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using BlackJack.Entidades;
using System.Media;

namespace BlackJack
{
    public partial class Form1 : Form
    {
        Player Jugador = new Player();
        Player Banca = new Player("Banca");
        Mazo Deck = new Mazo();
        List<PictureBox> Lista_de_Cartas = new List<PictureBox>();

        public Form1()
        {  
            InitializeComponent();
            GameInit();
            InterfazInit();
        }

        private void BOTON_Hit_Click(object sender, EventArgs e)
        {
            Hit_Card(Jugador);

            Check_Winner();

            if (Banca.Suma <= 16)
                Hit_Card(Banca);
            else
                Banca.Hold = true;
        }

        /// <summary>
        /// Se encarga de inicializar todos los Labels y textbox.
        /// </summary>
        public void InterfazInit()
        {
            TEX_WinJ.Text = Convert.ToString(Jugador.Wins);
            TEX_LossJ.Text = Convert.ToString(Jugador.Loss);
            TEX_Suma.Text = Convert.ToString(Jugador.Suma);
            TEX_Money.Text = Convert.ToString(Jugador.Cash);
            TEX_Bet.Text = Convert.ToString(Jugador.Bet);
            LABEL_WinJ.BringToFront();
            LABEL_LoseJ.BringToFront();
            LABEL_Suma.BringToFront();
            LABEL_Bet.BringToFront();
            LABEL_Money.BringToFront();
        }

        void Hit_Card(Player Actual)
        {
            if (Deck.CardsLeft > 5)
                Deck.CardsLeft--;
            else
                Barajar();

            PictureBox Pic = new PictureBox();
            Lista_de_Cartas.Add(Pic);
            Lista_de_Cartas[Lista_de_Cartas.Count - 1].Size = new Size(75, 100);

            Random random = new Random();
            Lista_de_Cartas[Lista_de_Cartas.Count - 1].Location = new Point(510 + (Actual.Cards_In_Hand.Count * 15), Actual.Y);
            int Card;
            int tipo;

            while (Deck._iD[tipo = Convert.ToInt16(random.Next(4))].CardNumber[Card = Convert.ToInt16(random.Next(13))].Un_used);

            Deck._iD[tipo].CardNumber[Card].Un_used = true;

            string ruta;

            if(Actual.Y < 200 && Banca.Cards_In_Hand.Count == 0)
                ruta = "C:\\Cards\\Down.jpg";
            else
                ruta = Convert.ToString("C:\\Cards\\" + (tipo+1) + "\\" + (Card+1) + ".jpg");

            Lista_de_Cartas[Lista_de_Cartas.Count - 1].Image = Image.FromFile(ruta);
            
            if (Card > 10)  // Estas son las condiciones para las cartas mayores que 10.
                Card = 9;
            
            Actual.Cards_In_Hand.Add(Card+1);

            int tmp = 0;

            Actual.Suma = 0;

            for (int i = 0; i < Actual.Cards_In_Hand.Count; i++)
            {
                if (Actual.Cards_In_Hand[i] == 1)
                    tmp++;
                else
                    Actual.Suma += Actual.Cards_In_Hand[i]; 
            }

            if(tmp != 0)
                for (int i = tmp; i > 0; i--)
                {
                    if ((Actual.Suma + (tmp * 11)) <= 21)
                    {
                        Actual.Suma += (tmp * 11);
                        break;
                    }

                    else
                    {
                        Actual.Suma++;
                        tmp--;
                    }
                }
            
            this.Controls.Add(Lista_de_Cartas[Lista_de_Cartas.Count - 1]);
            Lista_de_Cartas[Lista_de_Cartas.Count - 1].BringToFront();
            Lista_de_Cartas[Lista_de_Cartas.Count - 1].SizeMode = PictureBoxSizeMode.StretchImage;

            TEX_Suma.Text = Convert.ToString(Jugador.Suma);
            TEX_CantRestante.Text = Convert.ToString(Deck.CardsLeft);
        }

        private bool Compare(string p, string p_2)
        {
            throw new NotImplementedException();
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        public void GameInit()
        {
            Banca.Y = 175;
            Deck.DeckInit();
            for (int i = 0; i < 2; i++)
            {
                Hit_Card(Banca);

                Hit_Card(Jugador);
            }

            Apostar();
        }

        private void BOTON_Hold_Click(object sender, EventArgs e)
        {
            Jugador.Hold = true;
            BOTON_Hit.Enabled = false;

            if (Banca.Suma <= 16)
                Hit_Card(Banca);
            else
                Banca.Hold = true;
            Check_Winner();
        }

        void Check_Winner()
        {
            if (Jugador.Suma == 21 && Banca.Hold == true)
                Win(Jugador, Banca);

            else if (Jugador.Suma > 21)
                Win(Banca, Jugador);
           
            else if (Banca.Suma == 21 && Jugador.Hold == true)
                Win(Banca, Jugador);

            else if(Banca.Suma > 21)
                Win(Jugador, Banca);
            
            else if (Jugador.Hold == true && Banca.Hold == true)
            {
                if (Jugador.Suma > Banca.Suma)
                    Win(Jugador, Banca);

                else if (Jugador.Suma < Banca.Suma)
                {
                    Win(Banca, Jugador);   
                }
                else if (Jugador.Suma == Banca.Suma)
                {
                    if (Jugador.Cards_In_Hand.Count > Banca.Cards_In_Hand.Count)
                        Win(Banca, Jugador);
                    else if (Jugador.Cards_In_Hand.Count < Banca.Cards_In_Hand.Count)
                        Win(Jugador, Banca);
                }

            }
            
        }

        /// <summary>
        /// Se encarga de Barajar la mano nuevamente.
        /// </summary>
        void Barajar()
        {
            Lista_de_Cartas.Clear();

            for(int i = 0; i < 4;i++)
                for (int j = 0; j < 13; j++)
                {
                    Deck._iD[i].CardNumber[j].Un_used = false;
                }
            Deck.CardsLeft = 52;

        }

        /// <summary>
        /// Se Encarga de reiniciar la jugada.
        /// </summary>
        void Reset()
        {
            BOTON_Hit.Enabled = true;
            BOTON_Apuesta.Enabled = true;
            Banca.Hold = false;
            Jugador.Hold = false;

            for(int i = 0; i < Lista_de_Cartas.Count; i++)
            {
                Lista_de_Cartas[i].Dispose(); // Las cartas que estan en juego actualmente en la mesa.
            }

            Lista_de_Cartas.Clear();
            Jugador.Suma = 0;
            Jugador.Cards_In_Hand.Clear();

            Banca.Suma = 0;
            Banca.Cards_In_Hand.Clear();

            if (Jugador.Cash > 0)
            {
                for (int i = 0; i < 2; i++)
                {
                    Hit_Card(Banca);
                    Hit_Card(Jugador);
                }

                Jugador.Bet = 0;
                Apostar();
            }

            else
            {
                MessageBox.Show("No tienes suficiente dinero para seguir jugando!\n Presiones OK para Salir.");
                this.Close();
            }

        }

        void Apostar()
        {
            if (Jugador.Cash >= 25)
            {
                Jugador.Bet += 25;
                Jugador.Cash -= 25;
            }

            if(Jugador.Cash < 25)
               BOTON_Apuesta.Enabled = false;

            TEX_Money.Text = Convert.ToString(Jugador.Cash);
            TEX_Bet.Text = Convert.ToString(Jugador.Bet);
        }

        void Win(Player Ganador, Player Perdedor)
        {
            MessageBox.Show("GANADOR: "+ Ganador.Nombre + "!!\nPresione Aceptar para volver a jugar.");

            Ganador.Wins++;
            Perdedor.Loss++;

            Ganador.Cash += (Ganador.Bet * 2);

            InterfazInit();
            Reset();
        }
       
        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void LABEL_CantRestante_Click(object sender, EventArgs e)
        {
            
        }

        private void BOTON_Apuesta_Click(object sender, EventArgs e)
        {
            Apostar();
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }

        private void button2_Click(object sender, EventArgs e)
        {
            Jugador.Bet += Jugador.Cash;
            Jugador.Cash = 0;

            TEX_Bet.Text = Convert.ToString(Jugador.Bet);
            TEX_Money.Text = Convert.ToString(Jugador.Cash);
        }
    }
}
