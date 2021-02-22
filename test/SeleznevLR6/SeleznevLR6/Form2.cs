using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SeleznevLR6
{
    public partial class Form2 : Form
    {
        private Seleznev_Product product = null;
        public Seleznev_Product Product { get => product; }
        public Form2()
        {
            InitializeComponent();
        }

        public Form2(Seleznev_Product product)
        {
            InitializeComponent();
            this.product = product;
            fillFields();
        }

        private void fillFields()
        {
            textBox1.Text = product.Name;
            textBox2.Text = product.Price.ToString();
            textBox3.Text = product.Guarantee.ToString(); ;
            if (product.GetType() == typeof(Seleznev_Sale))
            {
                checkBox1.Checked = true;
                textBox5.Text = (product as Seleznev_Sale).DayOff;
                textBox4.Text = (product as Seleznev_Sale).Sale.ToString();
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (checkBox1.Checked)
            {
                product = new Seleznev_Sale();
                (product as Seleznev_Sale).DayOff = textBox5.Text;
                try
                {
                    (product as Seleznev_Sale).Sale = Convert.ToInt32(textBox4.Text);
                }
                catch (FormatException)
                {
                    MessageBox.Show("Некорректное значение скидки!");
                    (product as Seleznev_Sale).Sale = 0;
                    textBox4.Text = "0";
                }
            }
            else
            {
                product = new Seleznev_Product();
            }
            product.Name = textBox1.Text;

            try
            {
                product.Price = Convert.ToInt32(textBox2.Text);
            }
            catch (FormatException)
            {
                MessageBox.Show("Некорректное значение цены!");
                product.Price = 0;
                textBox2.Text = "0";
            }
            try
            {
                product.Guarantee = Convert.ToInt32(textBox3.Text);
            }
            catch (FormatException)
            {
                MessageBox.Show("Некорректное значение гарантии!");
                product.Guarantee = 0;
                textBox3.Text = "0";
            }

            this.Close();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            textBox5.Enabled = checkBox1.Checked;
            textBox4.Enabled = checkBox1.Checked;
        }
    }
}
