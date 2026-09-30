using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace Calculator
{
    public partial class FormMain : Form
    {
        internal class buttons
        {

        }
        private void button14_Click(object sender, EventArgs e)
        {
            equation.Text = "";

            switch (operation)
            {
                case "+":
                    result.Text = (value + Double.Parse(result.Text)).ToString();
                    break;

                case "-":
                    result.Text = (value - Double.Parse(result.Text)).ToString();
                    break;

                case "*":
                    result.Text = (value * Double.Parse(result.Text)).ToString();
                    break;

                case "/":
                    result.Text = (value / Double.Parse(result.Text)).ToString();
                    break;

                case "√": // Извлечение квадратного корня
                    result.Text = Math.Sqrt(Double.Parse(result.Text)).ToString();
                    break;

                case "pow": // Возведение в степень
                    double exponent = Double.Parse(result.Text);
                    result.Text = Math.Pow(value, exponent).ToString();
                    break;

                case "sin": // Синус
                    result.Text = Math.Sin(Double.Parse(result.Text)).ToString();
                    break;

                case "cos":
                    result.Text = Math.Cos(Double.Parse(result.Text)).ToString();
                    break;

                case "tan": // Тангенс
                    result.Text = Math.Tan(Double.Parse(result.Text)).ToString();
                    break;

                case "cot": // Котангенс
                    double angle = double.Parse(result.Text);
                    double cotangent = 1.0 / Math.Tan(angle);
                    result.Text = cotangent.ToString();
                    break;

                case "asin": // Арксинус
                    result.Text = Math.Asin(Double.Parse(result.Text)).ToString();
                    break;

                case "acos": // Арккосинус
                    result.Text = Math.Acos(Double.Parse(result.Text)).ToString();
                    break;

                case "atan": // Арктангенс
                    result.Text = Math.Atan(Double.Parse(result.Text)).ToString();
                    break;

                case "acot": // Арккотангенс
                    double angle1 = double.Parse(result.Text);
                    double arccotangent = Math.Atan(1.0 / angle1);
                    result.Text = arccotangent.ToString();
                    break;

                case "log": // Логарифм
                    double logBase = Double.Parse(result.Text);
                    double logNumber = value;
                    result.Text = Math.Log(logNumber, logBase).ToString();
                    break;

                case "x^2": // Возведение в квадрат
                    double x = Double.Parse(result.Text);
                    double resultValue = x * x;
                    result.Text = resultValue.ToString();
                    break;


                case "x^y": // Возведение в степень
                    double exponent1 = Double.Parse(result.Text);
                    double resultValue1 = Math.Pow(value, exponent1);
                    result.Text = resultValue1.ToString();
                    break;

                case "+/-": // Превратить число в отрицательное или положительное
                    result.Text = (-1 * Double.Parse(result.Text)).ToString();
                    break;

                case "1/x": // Разделить 1 на текущее число
                    result.Text = (1 / Double.Parse(result.Text)).ToString();
                    break;

                default:
                    break;
            }
        }

        private void button_Click(object sender, EventArgs e)
        {
            if ((result.Text == "0") || (operation_pressed))
                result.Clear();

            operation_pressed = false;

            Button bt = (Button)sender;

            if (bt.Text == "е")
            {
                result.Text += bt.Text; // Добавляем символ "е" для числа Эйлера
            }
            else
            {
                result.Text += bt.Text; // Добавляем текст кнопки
            }

        }

        private void button19_Click(object sender, EventArgs e)
        {
            result.Text = "0";
            equation.Text = "0";
        }

        private void FormMain_Click(object sender, EventArgs e)
        {

        }

        private void operation_click(object sender, EventArgs e)
        {
            Button bt = (Button)sender;
            double value = Double.Parse(result.Text);
            equation.Text = $"{value} {bt.Text} = {result.Text}";
            operation_pressed = true; // Если нужно сбросить результат для следующего ввода
        }


        private void button16_Click(object sender, EventArgs e)
        {
            result.Text = Math.PI.ToString();
        }

        private void button20_Click(object sender, EventArgs e)
        {
            result.Text = Math.E.ToString();
        }

        private void button21_click(object sender, EventArgs e)
        {

        }

        private void buttonC_Click(object sender, EventArgs e)
        {
            if (result.Text.Length > 0)
            {
                // Удаляем последний символ
                result.Text = result.Text.Substring(0, result.Text.Length - 1);

                // Если у нас больше нет символов, устанавливаем 0
                if (result.Text.Length == 0)
                    result.Text = "0";
            }
        }
    }
}
