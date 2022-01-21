using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyHelper
{
    public class ClassUDO
    {
        //   .Net  4.5.2
        public static double SecondsToMinutes(int seconds)
        {
            double minutes = seconds / 60.0;
            return minutes;
        }
    }
}
