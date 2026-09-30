using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using deixtra.Classes;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace Main
{
    public partial class GrafForm : Form
    {
        private GraphDefine graph;
        private static int startNodeId;
        private static int endNodeId;

        public static int StartNodeId { get => startNodeId; set => startNodeId = value; }
        public static int EndNodeId { get => endNodeId; set => endNodeId = value; }

        private static Label _labelPathLength;
        private static System.Windows.Forms.TextBox _textBoxStartNode;
        private static System.Windows.Forms.TextBox _textBoxEndNode;
        private static System.Windows.Forms.TextBox _textBoxEdges;
        public static Label LabelPathLength { get => _labelPathLength; set => _labelPathLength = value; }
        public static System.Windows.Forms.TextBox TextBoxStartNode { get => _textBoxStartNode; set => _textBoxStartNode = value; }
        public static System.Windows.Forms.TextBox TextBoxEndNode { get => _textBoxEndNode; set => _textBoxEndNode = value; }
        public static System.Windows.Forms.TextBox TextBoxEdges { get => _textBoxEdges; set => _textBoxEdges = value; }

        public GrafForm()
        {
            InitializeComponent();
            InitVariables();
            panelGraph.AutoScroll = true;
            graph = new GraphDefine();
            panelGraph.MouseWheel += new MouseEventHandler(panelGraph_MouseWheel);
        }

        private void InitVariables()
        {
            _labelPathLength = labelPathLength;
            _textBoxStartNode = textBoxStartNode;
            _textBoxEndNode = textBoxEndNode;
            _textBoxEdges = textBoxEdges;
        }

        private void buttonFindPath_Click(object sender, EventArgs e)
        {
            // Запуск алгоритма Дейкстры
            Algorithm.DijkstraAlgorithm(graph, startNodeId);
        }


        private void buttonGenerateGraph_Click(object sender, EventArgs e)
        {
            graph = Buttons.GenerateGraph();
        }

        private void buttonFindPath_Click_1(object sender, EventArgs e)
        {
            Buttons.FindPath(graph);
        }

        private void buttonShowPath_Click(object sender, EventArgs e)
        {
            Buttons.ShowPath(graph);
        }

        private void textBoxStartNode_TextChanged(object sender, EventArgs e)
        {
            ListenTextChange.StartNode_TextChanged();
        }

        private void textBoxEndNode_TextChanged(object sender, EventArgs e)
        {
            ListenTextChange.EndNode_TextChanged();
        }

        private void textBoxEdges_TextChanged(object sender, EventArgs e)
        {
            ListenTextChange.Edges_TextChanged(graph);
        }
        private void panelGraph_MouseWheel(object sender, MouseEventArgs e)
        {
            // Изменяем вертикальную позицию прокрутки панели в зависимости от направления прокрутки колеса мыши
            panelGraph.VerticalScroll.Value -= e.Delta * SystemInformation.MouseWheelScrollLines / 120;
        }

        private void InitializeComponent()
        {
            this.SuspendLayout();
            // 
            // GrafForm
            // 
            this.ClientSize = new System.Drawing.Size(282, 253);
            this.Name = "GrafForm";
            this.Load += new System.EventHandler(this.GrafForm_Load);
            this.ResumeLayout(false);

        }

        private void GrafForm_Load(object sender, EventArgs e)
        {

        }
    }
}
