using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using static Main.GrafForm;

namespace deixtra.Classes
{
    class GraphOperations
    {
        public static void UpdateGraphInfo(GraphDefine graph)
        {
            StringBuilder graphInfo = new StringBuilder();

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

            LabelPathLength.Text = graphInfo.ToString();
        }

        public static void ShowPath(GraphDefine graph, int startNodeId, int endNodeId)
        {
            List<int> path = new List<int>();
            int currentNode = endNodeId;
            int weight = 0;

            while (currentNode != startNodeId)
            {
                int previousNode = graph.GetNodes()[currentNode].PreviousNode;
                if (graph.GetNodes()[currentNode].Neighbors.ContainsKey(previousNode))
                {
                    weight += graph.GetNodes()[currentNode].Neighbors[previousNode];
                }
                else
                {
                    // Обработка случая, когда ключ отсутствует
                    // Можно выбрать какое-то значение по умолчанию или обработать эту ситуацию иным способом
                }
                path.Add(currentNode);
                currentNode = previousNode;
            }

            path.Add(startNodeId);
            path.Reverse();

            string pathString = "";
            foreach (int node in path)
            {
                pathString += node + " ";
            }

            // Отображение пути на форме
            LabelPathLength.Text = "Кратчайший путь: " + pathString + "\nДлина пути: " + weight;
        }
    }
}
