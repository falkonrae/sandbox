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
		public int rad = 200;
		public int a = 250, b = 100;

		Graphics pen;
		public Form1()
		{
			InitializeComponent();
		}

		private void label1_Click(object sender, EventArgs e)
		{

		}

		private void button4_Click(object sender, EventArgs e)
		{
			try
			{
				pen.Clear(BackColor);
				rad = Convert.ToInt32(radius.Text);
			}
			catch
			{ 
				MessageBox.Show("Проверьте правильность ввода чисел!"); 
			}
		}

			private void pictureBox1_Click(object sender, EventArgs e)
		{

		}
		
		private void Form1_Paint(object sender, PaintEventArgs e)
		{
			pen = CreateGraphics();
			pen.DrawEllipse(Pens.Gray, a, b, rad*2, rad*2);
		}

		private void textBox1_TextChanged(object sender, EventArgs e)
		{

		}

		private void button1_Click(object sender, EventArgs e)
		{
			try
			{
				pen.Clear(BackColor);
				
				rad = Convert.ToInt32(radius.Text);
			}
			catch
			{
				MessageBox.Show("Проверьте правильность ввода чисел!");
			}
		}
	}
}
