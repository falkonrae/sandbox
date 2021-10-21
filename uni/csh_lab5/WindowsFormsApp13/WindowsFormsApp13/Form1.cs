using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace csh_lab5
{
	public partial class Form1 : Form
	{
        Timer таймерЗапуска;
        public int rad = 200;
		public int a = 250, b = 100;
		Graphics pen;
		public Form1()
		{
			InitializeComponent();
            таймерЗапуска = new Timer();
            таймерЗапуска.Interval = 200;
            таймерЗапуска.Tick += ТаймерЗапуска_Tick;
		}

        private void ТаймерЗапуска_Tick(object sender, EventArgs e)
        {
            Invalidate();
            if (a + rad*2 < this.Width )
            {
                a += 10;
            }
            else
                таймерЗапуска.Stop();

        }

        private void label1_Click(object sender, EventArgs e)
		{

		}

		private void button1_Click(object sender, EventArgs e)
		{
			try
			{
                таймерЗапуска.Start();
			}
			catch
			{ 
				MessageBox.Show("Warning!"); 
			}
		}
		
		private void Form1_Paint(object sender, PaintEventArgs e)
		{
			pen = CreateGraphics();
            pen.Clear(this.BackColor);

            pen.DrawEllipse(Pens.Green, a, b, rad*2, rad*2);
		}

		private void textBox1_TextChanged(object sender, EventArgs e) //текст "радиус"
		{

		}


        private void button4_Click(object sender, EventArgs e)
		{
			try
			{
				rad = Convert.ToInt32(radius.Text);
            }
			catch
			{
				MessageBox.Show("Проверьте правильность ввода чисел!");
			}
		}
	}
}