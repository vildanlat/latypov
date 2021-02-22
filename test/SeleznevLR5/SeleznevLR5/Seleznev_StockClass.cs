using System;
using System.Collections.Generic;
using System.Runtime.Serialization.Formatters.Binary; 
using System.IO;


namespace SeleznevLR5
{
    [Serializable]
    class Seleznev_StockClass
    {
        private List<Seleznev_ProductClass> products = new List<Seleznev_ProductClass>();
        public void AddProduct()
        {
            Console.WriteLine();
            Console.WriteLine("[0] Добавить товар\n[1] Добавить товар со скидкой");
            int k=0;
            try
            {
                k = Convert.ToInt32(Console.ReadLine()); ;
            }
            catch (FormatException)
            { Console.WriteLine("Введите корректное значение!"); }

            Seleznev_ProductClass product;
            if (k == 1)
            {
                product = new Seleznev_SaleClass();
            }
            else
            {
                product = new Seleznev_ProductClass();
            }
            product.ReadConsole();
            products.Add(product);
        }
        public void DisplayProducts()
        {
            foreach (Seleznev_ProductClass it in products)
            {
                it.WriteConsole();
                Console.WriteLine();
            }
        }

        public void ReadFile()
        {
            Console.WriteLine("\nВведите путь до файла:");
            string fName = Console.ReadLine();
            using (FileStream fin = new FileStream(fName, FileMode.Open))
            {
                BinaryFormatter formatter = new BinaryFormatter();
                products = formatter.Deserialize(fin) as List<Seleznev_ProductClass>;
            }
        }

        public void WriteFile()
        {
            Console.WriteLine("\nВведите путь до файла:");
            string fName = Console.ReadLine();
            using (FileStream fout = new FileStream(fName, FileMode.OpenOrCreate))
            {
                BinaryFormatter formatter = new BinaryFormatter();
                formatter.Serialize(fout, products);
            }
        }

        public void Clear()
        {
            products.Clear();
        }
    }
}
