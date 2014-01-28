using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace BlackJack.Entidades
{
    class Player
    {

        #region Propiedades

        public string Nombre { get; set; }
        public List<int> Cards_In_Hand { get; set; }
        public int Y { get; set; }
        public int Wins { get; set; }
        public int Loss { get; set; }
        public int Suma { get; set; }
        public int Bet { get; set; }
        public int Cash { get; set; }
        public bool Hold { get; set; }

        #endregion

        #region Constructores
        public Player()
        {
            this.Nombre = "Player";
            this.Suma = 0;
            this.Loss = 0;
            this.Wins = 0;
            this.Bet = 0;
            this.Cash = 300;
            this.Hold = false;
            this.Cards_In_Hand = new List<int>();
            this.Y = 480;
        }

        public Player(string Nombre)
        {
            this.Nombre = Nombre;
            this.Wins = 0;
            this.Loss = 0;
            this.Suma = 0;
            this.Bet = 0;
            this.Cash = 300;
            this.Cards_In_Hand = new List<int>();
            this.Y = 480;
        }
        #endregion

        #region Metodos/Funciones
       
        #endregion
    }
}
