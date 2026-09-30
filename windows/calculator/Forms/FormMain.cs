using System;
using System.Windows.Forms;

namespace Calculator
{
    public partial class FormMain : Form
    {
        Double value = 0;
        String operation = "";
        Boolean operation_pressed = false;
        String fast_operation = "";
        public FormMain()
        {
            InitializeComponent();
        }

        private void FormMain_Load(object sender, EventArgs e)
        {
            result.Text = "0";
        }

        private void result_TextChanged(object sender, EventArgs e)
        {
            
        }
    }
}
