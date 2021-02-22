using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SeleznevLR6
{
    [Serializable]
    public class Seleznev_Product
    {
        public string Name;
        public int Price;
        public int Guarantee;

        public string name { get => Name; set => Name = value; }
        public int price { get => Price; set => Price = value; }
        public int guarantee { get => Guarantee; set => Guarantee = value; }


    }


}
