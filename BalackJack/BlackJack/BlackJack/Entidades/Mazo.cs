using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace BlackJack.Entidades
{
    class Mazo:ID
    {

        #region Propiedades

        public ID[] _iD { get; set; }
        public int CardsLeft { get; set; }

        #endregion

        #region Constructores
        public Mazo()
        {
            this._iD = new ID[4];
            this.CardsLeft = 52;
        }
        #endregion

        #region Metodos/Funciones
        /// <summary>
        /// Funcion que inicializa un tipo de la carta(Rombo,Trebol,Corazon,Hoja)
        /// </summary>
        /// <param name="Tipo"></param>Tipo de Carta
        public void DeckInit()
        {
            for (int i = 0; i < 4; i++)
            {
                this._iD[i] = new ID();

                for (int j = 1; j < 14; j++)
                {
                    this._iD[i].CardNumber[j - 1] = new CardN();
                    this._iD[i].CardNumber[j - 1].Number = j;
                    this._iD[i].CardNumber[j - 1].Un_used = false;
                }
            }
        }
        #endregion
    }
}
