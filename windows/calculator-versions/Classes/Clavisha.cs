using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Calculator;

namespace Calculator.Classes
{
    public class Clavisha
    {
        static public void OperationClick(string _operation)
        {
            FormMain.Memory.Text = "";

            switch (_operation)
            {
                case "+":
                    FormMain.TextBox.Text = (FormMain.Value + Double.Parse(FormMain.TextBox.Text)).ToString();
                    break;
                case "-":
                    FormMain.TextBox.Text = (FormMain.Value - Double.Parse(FormMain.TextBox.Text)).ToString();
                    break;
                case "*":
                    FormMain.TextBox.Text = (FormMain.Value * Double.Parse(FormMain.TextBox.Text)).ToString();
                    break;
                case "/":
                    FormMain.TextBox.Text = (FormMain.Value / Double.Parse(FormMain.TextBox.Text)).ToString();
                    break;
                default:
                    break;
            }
        }
    }
}