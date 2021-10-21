using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WinFormsApp1
{
	public partial class Окно : Form
	{

		Timer таймерПерерисовки;
		Timer таймерРасчета;
		int x = 0;
		int x2 = 0;
		public Окно()
		{
			InitializeComponent();
			x = this.Height;
			Button кнопка = new Button();
			Point точкаКнопки = new Point(100, 100);
			кнопка.Location = точкаКнопки; //не повится, потому что не добавили в управление окном. далее добавление
			кнопка.Text = "Наша кнопка";
			Size размер = new Size(300, 30); //гаечный ключ - свойство, молния - событие, кубики - функции
			кнопка.Size = размер;
			кнопка.Click += Кнопка_Click;
			this.Controls.Add(кнопка);
			this.Paint += Окно_Paint;
			таймерПерерисовки = new Timer();
			таймерПерерисовки.Interval =1000; //миллисекунды
			таймерРасчета = new Timer();
			таймерРасчета.Interval = 1000; //миллисекунды
			таймерПерерисовки.Tick += Таймер_Tick;
			таймерРасчета.Tick += ТаймерРасчета_Tick;
			таймерПерерисовки.Start(); таймерПерерисовки.Start();


		}

		private void ТаймерРасчета_Tick(object sender, EventArgs e)
		{
			throw new NotImplementedException();
		}

		private void Таймер_Tick(object sender, EventArgs e)
		{
			Invalidate();
			x += 5;
			x2 -= 5;
		}

		private void Окно_Paint(object sender, EventArgs e)
		{
			Graphics gr = this.CreateGraphics();
			Rectangle пр_ник = new Rectangle(x, 0, 200, 200);
			Color цвет = Color.FromArgb(255, 0, 0);
			Brush кисть = new SolidBrush(Color.Gold);
			//gr.FillRectangle(кисть, пр_ник);
			//gr.FillEllipse(кисть, пр_ник);
			//gr.DrawLine(new Pen(Color.Indigo), 0, 0, this.Width, this.Height-30);
			Font шрифт = new Font("Arial", 20);
			gr.DrawString("Привет!", шрифт, Brushes.Orange, 10, 200);
			gr.FillRectangle(кисть, x2, 0, 200, 100);

		}


		private void Кнопка_Click(object sender, EventArgs e)
		{
			Invalidate();
			x += 5;
		}
	}
}
