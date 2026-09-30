using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace deixtra.Classes
{
    class Algorithm
    {
        public static void DijkstraAlgorithm(GraphDefine graph, int startNodeId)
        {
            // Инициализация
            PriorityQueue<Node> priorityQueue = new PriorityQueue<Node>();
            foreach (Node node in graph.GetNodes().Values)
            {
                node.Distance = int.MaxValue;
                node.PreviousNode = -1;
            }

            graph.GetNodes()[startNodeId].Distance = 0;
            priorityQueue.Enqueue(0, graph.GetNodes()[startNodeId]);

            // Алгоритм Дейкстры
            while (priorityQueue.Count > 0)
            {
                Node currentNode = priorityQueue.Dequeue();

                if (currentNode.Distance == int.MaxValue)
                {
                    break;
                }

                foreach (KeyValuePair<int, int> neighborPair in currentNode.Neighbors)
                {
                    int neighborId = neighborPair.Key;
                    int weight = neighborPair.Value;

                    int newDistance = currentNode.Distance + weight;
                    if (newDistance < graph.GetNodes()[neighborId].Distance)
                    {
                        graph.GetNodes()[neighborId].Distance = newDistance;
                        graph.GetNodes()[neighborId].PreviousNode = currentNode.Id;
                        priorityQueue.Enqueue(newDistance, graph.GetNodes()[neighborId]);
                    }
                }
            }
        }
    }
}
