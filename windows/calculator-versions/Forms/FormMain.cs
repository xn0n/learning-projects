using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Calculator.Classes;

namespace Calculator
{
    public partial class FormMain : Form
    {
        static TextBox _textBox;
        public static TextBox TextBox { get => _textBox; set => _textBox = value; }
        static Label _memory;
        public static Label Memory { get => _memory; set => _memory = value; }

        static Double _value = 0;
        public static Double Value { get => _value; set => _value = value; }

        String operation = "";
        Boolean operation_pressed = false;

        public FormMain()
        {
            InitializeComponent();
            InitVariables();
        }

        private void button_Click(object sender, EventArgs e)
        {
            if ((_textBox.Text == "0")||(operation_pressed))
                _textBox.Clear();

            operation_pressed = false;
            Button bt = (Button)sender;
            _textBox.Text += bt.Text;
        }

        private void button19_Click(object sender, EventArgs e) { _textBox.Text = "0"; }

        private void operation_click(object sender, EventArgs e)
        {
            Button bt = (Button)sender;
            operation = bt.Text;
            _value = Double.Parse(result.Text);
            operation_pressed = true;
            memory.Text = $"{_value} {operation}";
        }

        private void button17_Click(object sender, EventArgs e) 

        { Clavisha.OperationClick(operation); }

        private void button18_Click(object sender, EventArgs e)
        {
            _textBox.Clear();
            _value = 0;
        }

        void InitVariables()
        {
            _textBox = result;
            _memory = memory;
        }
    }
}