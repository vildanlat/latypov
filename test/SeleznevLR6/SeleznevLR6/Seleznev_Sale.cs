using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SeleznevLR6
{
    [Serializable]
    public class Seleznev_Sale : Seleznev_Product
    {
        public string DayOff;
        public int Sale;

        public string dayoff { get => DayOff; set => DayOff = value; }
        public int sale { get => Sale; set => Sale = value; }


    }

}
