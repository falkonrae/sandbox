using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

/*Создать приложение, в котором в момент создания формы появляются два прямоугольника 
 * равных размеров и координат, затем прямоугольники начинают разъезжаться 
 * по разным углам окна (по диагонали).*/

namespace WindowsFormsApp14
{
    public partial class Form1 : Form
    {
        int x = 300, y = 200;
        int x1 = 320, y1 = 240;
        Timer таймерДвижения;
        public Form1()
        {
            InitializeComponent();
            this.Paint += Form1_Paint;
            таймерДвижения = new Timer();
            таймерДвижения.Interval = 100;
            таймерДвижения.Tick += ТаймерДвижения_Tick;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Invalidate();
            таймерДвижения.Start();
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
           // Invalidate();
            Graphics граф = this.CreateGraphics();
            Rectangle пр_ник1 = new Rectangle(x, y, 140, 200);
            Rectangle пр_ник2 = new Rectangle(x1, y1, 100, 100);
            Brush кисть1 = new SolidBrush(Color.Black);
            Brush кисть2 = new SolidBrush(Color.Gold);
            граф.Clear(this.BackColor);
            граф.FillRectangle(кисть1, пр_ник1);
            граф.FillRectangle(кисть2, пр_ник2);

        }

        private void ТаймерДвижения_Tick(object sender, EventArgs e)
        {
            Invalidate();

            if (x < this.Width || x1 > 0 || y < this.Height || y1 > 0)
            {
                x += 5;
                y -= 5;
                x1 -= 5;
                y1 += 5;
            }
            else
                таймерДвижения.Stop();
        }
    }
}
