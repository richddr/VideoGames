using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace BlackJack.Entidades
{
    class ID: CardN
    {
        #region Propiedades
        public CardN[] CardNumber { get; set; }
        #endregion

        #region Constructores
        public ID()
        {
            this.CardNumber = new CardN[13];
        }
        #endregion
    }
}
