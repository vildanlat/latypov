using System;

namespace SeleznevLR5
{
    class Program
    {
        static void Main(string[] args)
        {
            int menu=-1;
            Seleznev_StockClass products = new Seleznev_StockClass();
            do
            {
                Console.WriteLine(
                    "[1] Добавить товар в базу склада \n" +
                    "[2] Просмотр товаров на складе \n" +
                    "[3] Считать список товаров  из файла \n" +
                    "[4] Записать список товаров в файл \n" +
                    "[5] Очистить базу товаров \n" +
                    "[0] Выход из программы \n");
                try
                {
                    menu = Convert.ToInt32(Console.ReadLine());
                }
                catch (FormatException)
                { Console.WriteLine("Введите корректное значение!");}
                if (menu == 1)
                    products.AddProduct();
                else if (menu == 2)
                    products.DisplayProducts();
                else if (menu == 3)
                    products.ReadFile();
                else if (menu == 4)
                    products.WriteFile();
                else if (menu == 5)
                    products.Clear();
            } while (menu != 0);

        }
    }
}
