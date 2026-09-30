using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using static Main.GrafForm;


namespace deixtra.Classes
{
    class ListenTextChange
    {
        public static void StartNode_TextChanged()
        {
            if (int.TryParse(TextBoxStartNode.Text, out int startNode))
            {
                StartNodeId = startNode;
            }
            else
            {
                MessageBox.Show("Введите корректное значение для начального узла.");
            }
        }

        public static void EndNode_TextChanged()
        {
            if (int.TryParse(TextBoxEndNode.Text, out int endNode))
            {
                EndNodeId = endNode;
            }
            else
            {
                MessageBox.Show("Введите корректное значение для конечного узла.");
            }
        }

        public static void Edges_TextChanged(GraphDefine graph)
        {
            string[] lines = TextBoxEdges.Text.Split(new[] { Environment.NewLine }, StringSplitOptions.RemoveEmptyEntries);

            graph = new GraphDefine(); // Очищаем предыдущий граф

            foreach (string line in lines)
            {
                string[] parts = line.Split(new[] { ' ', ',' }, StringSplitOptions.RemoveEmptyEntries);
                if (parts.Length == 3)
                {
                    if (int.TryParse(parts[0], out int sourceId) && int.TryParse(parts[1], out int destinationId) && int.TryParse(parts[2], out int weight))
                    {
                        graph.AddEdge(sourceId, destinationId, weight); // Добавляем ребро в граф
                    }
                    else
                    {
                        MessageBox.Show("Ошибка в формате ввода ребра."/* Используйте формат: sourceId destinationId weight*/);
                    }
                }
                else
                {
                    MessageBox.Show("Ошибка в формате ввода ребра." /*Используйте формат: sourceId destinationId weight"*/);
                }
            }
        }

    }
}
