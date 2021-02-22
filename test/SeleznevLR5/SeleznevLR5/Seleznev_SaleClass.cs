using System;

namespace SeleznevLR5
{
    [Serializable]
    class Seleznev_SaleClass : Seleznev_ProductClass
    {
        private string DayOff;
        private int Sale;

        public override void WriteConsole()
        {
            base.WriteConsole();
            Console.WriteLine("Дата окончания скидки:" + DayOff);
            Console.WriteLine("Размер скидки: " + Sale);
        }
        public override void ReadConsole()
        {
            base.ReadConsole();
            Console.WriteLine("Введите дату окончания скидки: ");
            DayOff = Console.ReadLine();
            Console.WriteLine("Введите размер скидки: ");
            Sale = Convert.ToInt32(Console.ReadLine());

        }

    }

}
