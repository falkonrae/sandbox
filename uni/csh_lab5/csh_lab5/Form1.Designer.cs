
namespace csh_lab5
{
	partial class Form1
	{
		/// <summary>
		///  Required designer variable.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		///  Clean up any resources being used.
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
		///  Required method for Designer support - do not modify
		///  the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
			this.components = new System.ComponentModel.Container();
			this.radius = new System.Windows.Forms.TextBox();
			this.Радиус = new System.Windows.Forms.Label();
			this.button4 = new System.Windows.Forms.Button();
			this.backgroundWorker1 = new System.ComponentModel.BackgroundWorker();
			this.button1 = new System.Windows.Forms.Button();
			this.timer1 = new System.Windows.Forms.Timer(this.components);
			this.timer2 = new System.Windows.Forms.Timer(this.components);
			this.SuspendLayout();
			// 
			// radius
			// 
			this.radius.Location = new System.Drawing.Point(12, 32);
			this.radius.Name = "radius";
			this.radius.Size = new System.Drawing.Size(125, 27);
			this.radius.TabIndex = 0;
			this.radius.TextChanged += new System.EventHandler(this.textBox1_TextChanged);
			// 
			// Радиус
			// 
			this.Радиус.AutoSize = true;
			this.Радиус.Location = new System.Drawing.Point(12, 9);
			this.Радиус.Name = "Радиус";
			this.Радиус.Size = new System.Drawing.Size(56, 20);
			this.Радиус.TabIndex = 1;
			this.Радиус.Text = "Радиус";
			this.Радиус.Click += new System.EventHandler(this.label1_Click);
			// 
			// button4
			// 
			this.button4.Location = new System.Drawing.Point(12, 65);
			this.button4.Name = "button4";
			this.button4.Size = new System.Drawing.Size(125, 48);
			this.button4.TabIndex = 5;
			this.button4.Text = "Изменить радиус";
			this.button4.UseVisualStyleBackColor = true;
			this.button4.Click += new System.EventHandler(this.button4_Click);
			// 
			// button1
			// 
			this.button1.Location = new System.Drawing.Point(12, 119);
			this.button1.Name = "button1";
			this.button1.Size = new System.Drawing.Size(125, 48);
			this.button1.TabIndex = 6;
			this.button1.Text = "Привести в движение";
			this.button1.UseVisualStyleBackColor = true;
			this.button1.Click += new System.EventHandler(this.button1_Click);
			// 
			// Form1
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 20F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(916, 569);
			this.Controls.Add(this.button1);
			this.Controls.Add(this.button4);
			this.Controls.Add(this.Радиус);
			this.Controls.Add(this.radius);
			this.Name = "Form1";
			this.Text = "Form1";
			this.Paint += new System.Windows.Forms.PaintEventHandler(this.Form1_Paint);
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.TextBox radius;
		private System.Windows.Forms.Label Радиус;
		private System.Windows.Forms.Button button4;
		private System.ComponentModel.BackgroundWorker backgroundWorker1;
		private System.Windows.Forms.Button button1;
		private System.Windows.Forms.Timer timer1;
		private System.Windows.Forms.Timer timer2;
	}
}

