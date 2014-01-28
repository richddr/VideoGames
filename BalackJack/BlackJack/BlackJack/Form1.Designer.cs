namespace BlackJack
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.BOTON_Hit = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.BOTON_Hold = new System.Windows.Forms.Button();
            this.BOTON_Apuesta = new System.Windows.Forms.Button();
            this.LABEL_WinJ = new System.Windows.Forms.Label();
            this.LABEL_LoseJ = new System.Windows.Forms.Label();
            this.TEX_WinJ = new System.Windows.Forms.TextBox();
            this.TEX_LossJ = new System.Windows.Forms.TextBox();
            this.LABEL_Suma = new System.Windows.Forms.Label();
            this.TEX_Suma = new System.Windows.Forms.TextBox();
            this.LABEL_CantRestante = new System.Windows.Forms.Label();
            this.TEX_CantRestante = new System.Windows.Forms.TextBox();
            this.LABEL_Bet = new System.Windows.Forms.Label();
            this.TEX_Bet = new System.Windows.Forms.TextBox();
            this.LABEL_Money = new System.Windows.Forms.Label();
            this.TEX_Money = new System.Windows.Forms.TextBox();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // pictureBox1
            // 
            this.pictureBox1.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox1.Image")));
            this.pictureBox1.Location = new System.Drawing.Point(0, 0);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(1300, 1267);
            this.pictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.AutoSize;
            this.pictureBox1.TabIndex = 0;
            this.pictureBox1.TabStop = false;
            this.pictureBox1.Click += new System.EventHandler(this.pictureBox1_Click);
            // 
            // BOTON_Hit
            // 
            this.BOTON_Hit.AccessibleName = "";
            this.BOTON_Hit.BackColor = System.Drawing.Color.Red;
            this.BOTON_Hit.Location = new System.Drawing.Point(839, 578);
            this.BOTON_Hit.Name = "BOTON_Hit";
            this.BOTON_Hit.Size = new System.Drawing.Size(82, 23);
            this.BOTON_Hit.TabIndex = 2;
            this.BOTON_Hit.Text = "Pedir Carta";
            this.BOTON_Hit.UseVisualStyleBackColor = false;
            this.BOTON_Hit.Click += new System.EventHandler(this.BOTON_Hit_Click);
            // 
            // button2
            // 
            this.button2.ImageAlign = System.Drawing.ContentAlignment.BottomCenter;
            this.button2.Location = new System.Drawing.Point(1089, 578);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(75, 23);
            this.button2.TabIndex = 3;
            this.button2.Text = "All In";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // BOTON_Hold
            // 
            this.BOTON_Hold.Location = new System.Drawing.Point(927, 578);
            this.BOTON_Hold.Name = "BOTON_Hold";
            this.BOTON_Hold.Size = new System.Drawing.Size(75, 23);
            this.BOTON_Hold.TabIndex = 4;
            this.BOTON_Hold.Text = "Hold";
            this.BOTON_Hold.UseVisualStyleBackColor = true;
            this.BOTON_Hold.Click += new System.EventHandler(this.BOTON_Hold_Click);
            // 
            // BOTON_Apuesta
            // 
            this.BOTON_Apuesta.Location = new System.Drawing.Point(1008, 578);
            this.BOTON_Apuesta.Name = "BOTON_Apuesta";
            this.BOTON_Apuesta.Size = new System.Drawing.Size(75, 23);
            this.BOTON_Apuesta.TabIndex = 5;
            this.BOTON_Apuesta.Text = "Apostar";
            this.BOTON_Apuesta.UseVisualStyleBackColor = true;
            this.BOTON_Apuesta.Click += new System.EventHandler(this.BOTON_Apuesta_Click);
            // 
            // LABEL_WinJ
            // 
            this.LABEL_WinJ.BackColor = System.Drawing.Color.Red;
            this.LABEL_WinJ.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.LABEL_WinJ.ForeColor = System.Drawing.Color.WhiteSmoke;
            this.LABEL_WinJ.Location = new System.Drawing.Point(12, 372);
            this.LABEL_WinJ.Name = "LABEL_WinJ";
            this.LABEL_WinJ.Size = new System.Drawing.Size(78, 23);
            this.LABEL_WinJ.TabIndex = 6;
            this.LABEL_WinJ.Text = "Wins";
            this.LABEL_WinJ.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            this.LABEL_WinJ.Click += new System.EventHandler(this.label1_Click);
            // 
            // LABEL_LoseJ
            // 
            this.LABEL_LoseJ.BackColor = System.Drawing.Color.Blue;
            this.LABEL_LoseJ.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.LABEL_LoseJ.ForeColor = System.Drawing.Color.White;
            this.LABEL_LoseJ.Location = new System.Drawing.Point(1084, 321);
            this.LABEL_LoseJ.Name = "LABEL_LoseJ";
            this.LABEL_LoseJ.Size = new System.Drawing.Size(78, 23);
            this.LABEL_LoseJ.TabIndex = 7;
            this.LABEL_LoseJ.Text = "Loss";
            this.LABEL_LoseJ.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // TEX_WinJ
            // 
            this.TEX_WinJ.BackColor = System.Drawing.SystemColors.MenuText;
            this.TEX_WinJ.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.TEX_WinJ.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.TEX_WinJ.ForeColor = System.Drawing.Color.White;
            this.TEX_WinJ.Location = new System.Drawing.Point(0, 398);
            this.TEX_WinJ.Name = "TEX_WinJ";
            this.TEX_WinJ.Size = new System.Drawing.Size(100, 22);
            this.TEX_WinJ.TabIndex = 8;
            this.TEX_WinJ.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // TEX_LossJ
            // 
            this.TEX_LossJ.BackColor = System.Drawing.SystemColors.MenuText;
            this.TEX_LossJ.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.TEX_LossJ.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.TEX_LossJ.ForeColor = System.Drawing.Color.White;
            this.TEX_LossJ.Location = new System.Drawing.Point(1078, 347);
            this.TEX_LossJ.Name = "TEX_LossJ";
            this.TEX_LossJ.Size = new System.Drawing.Size(100, 22);
            this.TEX_LossJ.TabIndex = 9;
            this.TEX_LossJ.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // LABEL_Suma
            // 
            this.LABEL_Suma.BackColor = System.Drawing.Color.Transparent;
            this.LABEL_Suma.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.LABEL_Suma.ForeColor = System.Drawing.Color.DarkOrange;
            this.LABEL_Suma.Location = new System.Drawing.Point(1085, 397);
            this.LABEL_Suma.Name = "LABEL_Suma";
            this.LABEL_Suma.Size = new System.Drawing.Size(82, 23);
            this.LABEL_Suma.TabIndex = 10;
            this.LABEL_Suma.Text = "Suma";
            this.LABEL_Suma.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // TEX_Suma
            // 
            this.TEX_Suma.BackColor = System.Drawing.SystemColors.MenuText;
            this.TEX_Suma.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.TEX_Suma.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.TEX_Suma.ForeColor = System.Drawing.Color.Yellow;
            this.TEX_Suma.Location = new System.Drawing.Point(1078, 423);
            this.TEX_Suma.Name = "TEX_Suma";
            this.TEX_Suma.Size = new System.Drawing.Size(100, 22);
            this.TEX_Suma.TabIndex = 11;
            this.TEX_Suma.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // LABEL_CantRestante
            // 
            this.LABEL_CantRestante.BackColor = System.Drawing.Color.Transparent;
            this.LABEL_CantRestante.Font = new System.Drawing.Font("Microsoft Sans Serif", 11.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.LABEL_CantRestante.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(128)))), ((int)(((byte)(0)))));
            this.LABEL_CantRestante.Location = new System.Drawing.Point(9, 441);
            this.LABEL_CantRestante.Name = "LABEL_CantRestante";
            this.LABEL_CantRestante.Size = new System.Drawing.Size(156, 23);
            this.LABEL_CantRestante.TabIndex = 12;
            this.LABEL_CantRestante.Text = "# Cartas Restantes";
            this.LABEL_CantRestante.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.LABEL_CantRestante.Click += new System.EventHandler(this.LABEL_CantRestante_Click);
            // 
            // TEX_CantRestante
            // 
            this.TEX_CantRestante.BackColor = System.Drawing.SystemColors.MenuText;
            this.TEX_CantRestante.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.TEX_CantRestante.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.TEX_CantRestante.ForeColor = System.Drawing.Color.White;
            this.TEX_CantRestante.Location = new System.Drawing.Point(0, 467);
            this.TEX_CantRestante.Name = "TEX_CantRestante";
            this.TEX_CantRestante.Size = new System.Drawing.Size(100, 22);
            this.TEX_CantRestante.TabIndex = 13;
            this.TEX_CantRestante.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // LABEL_Bet
            // 
            this.LABEL_Bet.BackColor = System.Drawing.Color.Transparent;
            this.LABEL_Bet.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.LABEL_Bet.ForeColor = System.Drawing.Color.DarkOrange;
            this.LABEL_Bet.Location = new System.Drawing.Point(1085, 466);
            this.LABEL_Bet.Name = "LABEL_Bet";
            this.LABEL_Bet.Size = new System.Drawing.Size(82, 23);
            this.LABEL_Bet.TabIndex = 14;
            this.LABEL_Bet.Text = "BET";
            this.LABEL_Bet.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // TEX_Bet
            // 
            this.TEX_Bet.BackColor = System.Drawing.SystemColors.MenuText;
            this.TEX_Bet.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.TEX_Bet.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.TEX_Bet.ForeColor = System.Drawing.Color.Yellow;
            this.TEX_Bet.Location = new System.Drawing.Point(1078, 492);
            this.TEX_Bet.Name = "TEX_Bet";
            this.TEX_Bet.Size = new System.Drawing.Size(100, 22);
            this.TEX_Bet.TabIndex = 15;
            this.TEX_Bet.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // LABEL_Money
            // 
            this.LABEL_Money.BackColor = System.Drawing.Color.Transparent;
            this.LABEL_Money.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.LABEL_Money.ForeColor = System.Drawing.Color.DarkOrange;
            this.LABEL_Money.Location = new System.Drawing.Point(8, 513);
            this.LABEL_Money.Name = "LABEL_Money";
            this.LABEL_Money.Size = new System.Drawing.Size(82, 23);
            this.LABEL_Money.TabIndex = 16;
            this.LABEL_Money.Text = "$ Money";
            this.LABEL_Money.TextAlign = System.Drawing.ContentAlignment.TopCenter;
            // 
            // TEX_Money
            // 
            this.TEX_Money.BackColor = System.Drawing.SystemColors.MenuText;
            this.TEX_Money.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.TEX_Money.Font = new System.Drawing.Font("Microsoft Sans Serif", 14.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.TEX_Money.ForeColor = System.Drawing.Color.Green;
            this.TEX_Money.Location = new System.Drawing.Point(0, 539);
            this.TEX_Money.Name = "TEX_Money";
            this.TEX_Money.Size = new System.Drawing.Size(100, 22);
            this.TEX_Money.TabIndex = 17;
            this.TEX_Money.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1176, 613);
            this.Controls.Add(this.TEX_Money);
            this.Controls.Add(this.LABEL_Money);
            this.Controls.Add(this.TEX_Bet);
            this.Controls.Add(this.LABEL_Bet);
            this.Controls.Add(this.TEX_CantRestante);
            this.Controls.Add(this.LABEL_CantRestante);
            this.Controls.Add(this.TEX_Suma);
            this.Controls.Add(this.LABEL_Suma);
            this.Controls.Add(this.TEX_LossJ);
            this.Controls.Add(this.TEX_WinJ);
            this.Controls.Add(this.LABEL_LoseJ);
            this.Controls.Add(this.LABEL_WinJ);
            this.Controls.Add(this.BOTON_Apuesta);
            this.Controls.Add(this.BOTON_Hold);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.BOTON_Hit);
            this.Controls.Add(this.pictureBox1);
            this.Name = "Form1";
            this.Text = "BlackJack: Durakuzz Productions";
            this.Load += new System.EventHandler(this.Form1_Load);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox pictureBox1;
        private System.Windows.Forms.Button BOTON_Hit;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button BOTON_Hold;
        private System.Windows.Forms.Button BOTON_Apuesta;
        private System.Windows.Forms.Label LABEL_WinJ;
        private System.Windows.Forms.Label LABEL_LoseJ;
        private System.Windows.Forms.TextBox TEX_WinJ;
        private System.Windows.Forms.TextBox TEX_LossJ;
        private System.Windows.Forms.Label LABEL_Suma;
        private System.Windows.Forms.TextBox TEX_Suma;
        private System.Windows.Forms.Label LABEL_CantRestante;
        private System.Windows.Forms.TextBox TEX_CantRestante;
        private System.Windows.Forms.Label LABEL_Bet;
        private System.Windows.Forms.TextBox TEX_Bet;
        private System.Windows.Forms.Label LABEL_Money;
        private System.Windows.Forms.TextBox TEX_Money;
    }
}

