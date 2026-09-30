using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static Main.GrafForm;

namespace deixtra.Classes
{
    class Buttons
    {
        public static GraphDefine GenerateGraph()
        {
            Random random = new Random();
            GraphDefine graph = new GraphDefine();

            int numNodes = random.Next(5, 10);
            for (int i = 1; i <= numNodes; i++)
            {
                graph.AddNode(i);
            }

            int numEdges = random.Next(10, 20);
            for (int i = 0; i < numEdges; i++)
            {
                int sourceId = random.Next(1, numNodes + 1);
                int destinationId = random.Next(1, numNodes + 1);
                int weight = random.Next(1, 10);
                graph.AddEdge(sourceId, destinationId, weight);
            }

            GraphOperations.UpdateGraphInfo(graph);  // Обновление интерфейса после генерации графа
            //MessageBox.Show("Граф сгенерирован.");
            return graph;
        }

        public static void FindPath(GraphDefine graph)
        {
            int startNodeId, endNodeId;

            // Получение начального узла
            if (!int.TryParse(TextBoxStartNode.Text, out startNodeId))
            {
                MessageBox.Show("Некорректный формат начального узла.");
                return;
            }

            // Получение конечного узла
            if (!int.TryParse(TextBoxEndNode.Text, out endNodeId))
            {
                MessageBox.Show("Некорректный формат конечного узла.");
                return;
            }

            if (!graph.GetNodes().ContainsKey(startNodeId) || !graph.GetNodes().ContainsKey(endNodeId))
            {
                MessageBox.Show("Начальный или конечный узел не существует.");
                return;
            }

            Algorithm.DijkstraAlgorithm(graph, startNodeId); // Запуск алгоритма Дейкстры

            if (graph.GetNodes()[endNodeId].Distance == int.MaxValue)
            {
                MessageBox.Show("Невозможно найти путь между выбранными узлами.");
                return;
            }

            // Отображение кратчайшего пути между начальным и конечным узлами
            GraphOperations.ShowPath(graph, startNodeId, endNodeId);
        }

        public static void ShowPath(GraphDefine graph)
        {
            StringBuilder graphInfo = new StringBuilder();

            // Получение информации о каждом узле и его соседях
            foreach (var node in graph.GetNodes())
            {
                graphInfo.AppendLine($"Узел {node.Key}:");
                graphInfo.AppendLine("Соседи:");
                foreach (var neighbor in node.Value.Neighbors)
                {
                    graphInfo.AppendLine($"  Узел {neighbor.Key}, Вес: {neighbor.Value}");
                }
                graphInfo.AppendLine();
            }
        }
    }
}
