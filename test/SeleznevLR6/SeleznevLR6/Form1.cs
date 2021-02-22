using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.InteropServices;

namespace SeleznevLR6
{
    public partial class Form1 : Form
    {
        [DllImport("MFC_DLL.dll", CharSet = CharSet.Ansi)]
        static extern int loadData(StringBuilder fileName);

        [DllImport("MFC_DLL.dll", CharSet = CharSet.Ansi)]
        static extern void saveData(StringBuilder fileName);

        [DllImport("MFC_DLL.dll", CharSet = CharSet.Ansi)]
        static extern void changeClass(int index, int isSale);

        [DllImport("MFC_DLL.dll", CharSet = CharSet.Ansi)]
        static extern void getName(int index, StringBuilder Name);

        [DllImport("MFC_DLL.dll", CharSet = CharSet.Ansi)]
        static extern int getPrice(int index);

        [DllImport("MFC_DLL.dll", CharSet = CharSet.Ansi)]
        static extern int getGuarantee(int index);

        [DllImport("MFC_DLL.dll", CharSet = CharSet.Ansi)]
        static extern int getSale(int index);

        [DllImport("MFC_DLL.dll", CharSet = CharSet.Ansi)]
        static extern void getDayOff(int index, StringBuilder DayOff);

        [DllImport("MFC_DLL.dll", CharSet = CharSet.Ansi)]
        static extern int isSale(int index);

        [DllImport("MFC_DLL.dll", CharSet = CharSet.Ansi)]
        static extern void setName(int index, StringBuilder Name);

        [DllImport("MFC_DLL.dll", CharSet = CharSet.Ansi)]
        static extern void setPrice(int index, int price);

        [DllImport("MFC_DLL.dll", CharSet = CharSet.Ansi)]
        static extern void setGuarantee(int index, int guarantee);

        [DllImport("MFC_DLL.dll", CharSet = CharSet.Ansi)]
        static extern void setSale(int index, int sale);

        [DllImport("MFC_DLL.dll", CharSet = CharSet.Ansi)]
        static extern void setDayOff(int index, StringBuilder DayOff);

        [DllImport("MFC_DLL.dll", CharSet = CharSet.Ansi)]
        static extern void AddProduct(int isSale);

        [DllImport("MFC_DLL.dll", CharSet = CharSet.Ansi)]
        static extern void DeleteProduct(int index);

        Seleznev_Product currentProduct;

        public Form1()
        {
            InitializeComponent();
            loadDataBase();
        }

        private void loadDataBase()
        {
            OpenFileDialog OPF = new OpenFileDialog();
            if (OPF.ShowDialog() == DialogResult.OK)
            {
                var fileName = new StringBuilder(OPF.FileName);

                   int size = loadData(fileName);
                for (int i = 0; i < size; i++)
                {
                    StringBuilder Name = new StringBuilder(256);
                    getName(i, Name);
                    listBox1.Items.Add(Name);
                }
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Form2 addForm = new Form2();
            addForm.ShowDialog();
            Seleznev_Product newProduct = addForm.Product;
            if (newProduct != null)
            {
                int isSale;
                if (newProduct.GetType() == typeof(Seleznev_Sale))
                {
                    isSale = 1;
                }
                else
                {
                    isSale = 0;
                }
                AddProduct(isSale);
                listBox1.Items.Add(newProduct.Name);
                listBox1.SetSelected(listBox1.Items.Count - 1, true);
                int index = listBox1.SelectedIndex;
                setName(index, new StringBuilder(newProduct.Name));
                setPrice(index, newProduct.Price);
                setGuarantee(index, newProduct.Guarantee);

                if (newProduct.GetType() == typeof(Seleznev_Sale))
                {
                    setDayOff(index, new StringBuilder((newProduct as Seleznev_Sale).DayOff));
                    setSale(index, (newProduct as Seleznev_Sale).Sale);
                }

                loadProduct(index);

            }
        }
            private void loadProduct(int index)
            {
                int isSaleProduct = isSale(index);

                if (isSaleProduct == 1)
                {
                    currentProduct = new Seleznev_Sale();
                }
                else if (isSaleProduct == 0)
                {
                    currentProduct = new Seleznev_Product();
                }
                StringBuilder name = new StringBuilder(256);
                getName(index, name);
                currentProduct.Name = name.ToString();
                currentProduct.Price = getPrice(index);
                currentProduct.Guarantee = getGuarantee(index);
                if (currentProduct.GetType() == typeof(Seleznev_Sale))
                {
                    StringBuilder dayoff = new StringBuilder(256);
                    getDayOff(index, dayoff);
                    (currentProduct as Seleznev_Sale).DayOff = dayoff.ToString();

                    (currentProduct as Seleznev_Sale).Sale = getSale(index);
                }
            }

            private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
            {
                int index = listBox1.SelectedIndex;

                if (index > -1)
                {
                    loadProduct(index);
                    textBox1.Text = currentProduct.Name;
                    textBox2.Text = currentProduct.Price.ToString();
                    textBox3.Text = currentProduct.Guarantee.ToString();

                    if (currentProduct.GetType() == typeof(Seleznev_Sale))
                    {
                        textBox4.Text = (currentProduct as Seleznev_Sale).DayOff;
                        textBox5.Text = (currentProduct as Seleznev_Sale).Sale.ToString();
                    }
                    else
                    {
                        textBox4.Clear();
                        textBox5.Clear();
                    }
                }
                else
                {
                    textBox1.Clear();
                    textBox2.Clear();
                    textBox3.Clear();
                    textBox4.Clear();
                    textBox5.Clear();
                }
            }

        private void button3_Click_1(object sender, EventArgs e)
        {
            int index = listBox1.SelectedIndex;
            if (index > -1)
            {
                Form2 addForm = new Form2(currentProduct);
                addForm.ShowDialog();
                Seleznev_Product editProduct = addForm.Product;
                if (editProduct.GetType() == typeof(Seleznev_Sale))
                {
                    changeClass(index, 1);
                    setDayOff(index, new StringBuilder((editProduct as Seleznev_Sale).DayOff));
                    setSale(index, (editProduct as Seleznev_Sale).Sale);
                }
                else
                {
                    changeClass(index, 0);
                }
                setName(index, new StringBuilder(editProduct.Name));
                setPrice(index, editProduct.Price);
                setGuarantee(index, editProduct.Guarantee);
                listBox1.Items.RemoveAt(index);
                listBox1.Items.Insert(index, editProduct.Name);
                listBox1.SetSelected(index, true);
                loadProduct(index);
            }
        }

        private void button4_Click_1(object sender, EventArgs e)
        {
            int index = listBox1.SelectedIndex;

            if (index > -1)
            {
                listBox1.Items.RemoveAt(index);
                DeleteProduct(index);
                currentProduct = new Seleznev_Product();
                if (index >= listBox1.Items.Count)
                {
                    index = listBox1.Items.Count - 1;
                }
                if (index > -1)
                {
                    listBox1.SetSelected(index, true);
                }
            }
        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            OpenFileDialog OPF = new OpenFileDialog();
            var fileName = new StringBuilder(OPF.FileName);
            saveData(fileName);
            this.Close();
        }

        private void listBox1_SelectedIndexChanged_1(object sender, EventArgs e)
        {
            int index = listBox1.SelectedIndex;
            if (index > -1)
            {
                loadProduct(index);
                textBox1.Text = currentProduct.Name;
                textBox2.Text = currentProduct.Price.ToString();
                textBox3.Text = currentProduct.Guarantee.ToString();
                if (currentProduct.GetType() == typeof(Seleznev_Sale))
                {
                   textBox5.Text = (currentProduct as Seleznev_Sale).DayOff;
                   textBox4.Text = (currentProduct as Seleznev_Sale).Sale.ToString();
                }
                else
                {
                    textBox4.Clear();
                    textBox5.Clear();
                }
            }
            else
            {
                textBox1.Clear();
                textBox2.Clear();
                textBox3.Clear();
                textBox4.Clear();
                textBox5.Clear();
            }

        }

    }
    }

