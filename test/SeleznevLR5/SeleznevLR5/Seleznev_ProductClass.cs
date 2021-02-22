using System;


namespace SeleznevLR5
{
    [Serializable]
    class Seleznev_ProductClass
    {
        private string Name;
        private int Price;
        private int Guarantee;

        public virtual void WriteConsole()
        {
            Console.WriteLine("Название товара: " + Name);
            Console.WriteLine("Стоимость товара: " + Price + "руб.");
            Console.WriteLine("Срок гарантии: " + Guarantee + "лет");
        }
        public virtual void ReadConsole()
        {
            Console.WriteLine("Введите название товара: ");
            Name = Console.ReadLine();
            Console.WriteLine("Введите стоимость товара");
            Price = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("Введите срок гарантии: ");
            Guarantee = Convert.ToInt32(Console.ReadLine());
        }


    }


}
