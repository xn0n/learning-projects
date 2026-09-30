using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace Graf
{
    public partial class Graf : Form
    {
        private Graph graph;
        private int startNodeId;
        private int endNodeId;

        public Graf()
        {
            InitializeComponent();
            graph = new Graph();
        }

        class PriorityQueue<T>
        {
            private SortedDictionary<int, Queue<T>> _dictionary = new SortedDictionary<int, Queue<T>>();

            public void Enqueue(int priority, T item)
            {
                if (!_dictionary.ContainsKey(priority))
                {
                    _dictionary.Add(priority, new Queue<T>());
                }
                _dictionary[priority].Enqueue(item);
            }

            public T Dequeue()
            {
                if (_dictionary.Count == 0)
                {
                    throw new InvalidOperationException("The priority queue is empty");
                }

                var firstKey = _dictionary.Keys.Min();
                var queue = _dictionary[firstKey];
                var item = queue.Dequeue();

                if (queue.Count == 0)
                {
                    _dictionary.Remove(firstKey);
                }

                return item;
            }

            public int Count
            {
                get
                {
                    int count = 0;
                    foreach (var queue in _dictionary.Values)
                    {
                        count += queue.Count;
                    }
                    return count;
                }
            }
        }

        class Graph
        {
            private Dictionary<int, Node> nodes;
            private List<Edge> edges;

            public Graph()
            {
                nodes = new Dictionary<int, Node>();
                edges = new List<Edge>();
            }

            public void AddNode(int id)
            {
                if (!nodes.ContainsKey(id))
                {
                    nodes.Add(id, new Node(id));
                }
            }

            public void AddEdge(int sourceId, int destinationId, int weight)
            {
                AddNode(sourceId);
                AddNode(destinationId);

                // Проверка, существует ли уже ребро между этими узлами
                if (!nodes[sourceId].Neighbors.ContainsKey(destinationId))
                {
                    edges.Add(new Edge(sourceId, destinationId, weight));
                    nodes[sourceId].Neighbors.Add(destinationId, weight);
                }
                else
                {
                    // Если ребро существует, можно обновить вес или игнорировать это, в зависимости от требований
                    // nodes[sourceId].Neighbors[destinationId] = weight; // Для обновления веса
                    // Или просто игнорировать
                }
            }


            public Dictionary<int, Node> GetNodes()
            {
                return nodes;
            }

            public List<Edge> GetEdges()
            {
                return edges;
            }
        }

        class Node
        {
            public int Id { get; set; }
            public Dictionary<int, int> Neighbors { get; set; }
            public int Distance { get; set; }
            public int PreviousNode { get; set; }

            public Node(int id)
            {
                Id = id;
                Neighbors = new Dictionary<int, int>();
                Distance = int.MaxValue;
                PreviousNode = -1;
            }
        }

        class Edge
        {
            public int SourceId { get; set; }
            public int DestinationId { get; set; }
            public int Weight { get; set; }

            public Edge(int sourceId, int destinationId, int weight)
            {
                SourceId = sourceId;
                DestinationId = destinationId;
                Weight = weight;
            }
        }

        private void UpdateGraphInfo()
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

            labelPathLength.Text = graphInfo.ToString();
        }

        private void DijkstraAlgorithm(Graph graph, int startNodeId)
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

        private void ShowPath(Graph graph, int startNodeId, int endNodeId)
        {
            List<int> path = new List<int>();
            int currentNode = endNodeId;

            while (currentNode != startNodeId)
            {
                path.Add(currentNode);
                currentNode = graph.GetNodes()[currentNode].PreviousNode;
            }

            path.Add(startNodeId);
            path.Reverse();

            string pathString = "";
            foreach (int node in path)
            {
                pathString += node + " ";
            }

            // Отображение пути на форме
            labelPathLength.Text = "Кратчайший путь: " + pathString;
        }

        private void buttonFindPath_Click(object sender, EventArgs e)
        {
            // Запуск алгоритма Дейкстры
            DijkstraAlgorithm(graph, startNodeId);
        }

        private void panelGraph_Paint(object sender, PaintEventArgs e)
        {

        }

        private void buttonGenerateGraph_Click(object sender, EventArgs e)
        {
            Random random = new Random();
            graph = new Graph();

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

            UpdateGraphInfo();  // Обновление интерфейса после генерации графа
            MessageBox.Show("Граф сгенерирован.");
        }

        private void buttonFindPath_Click_1(object sender, EventArgs e)
        {
            int startNodeId, endNodeId;

            // Получение начального узла
            if (!int.TryParse(textBoxStartNode.Text, out startNodeId))
            {
                MessageBox.Show("Некорректный формат начального узла.");
                return;
            }

            // Получение конечного узла
            if (!int.TryParse(textBoxEndNode.Text, out endNodeId))
            {
                MessageBox.Show("Некорректный формат конечного узла.");
                return;
            }

            if (!graph.GetNodes().ContainsKey(startNodeId) || !graph.GetNodes().ContainsKey(endNodeId))
            {
                MessageBox.Show("Начальный или конечный узел не существует.");
                return;
            }

            DijkstraAlgorithm(graph, startNodeId); // Запуск алгоритма Дейкстры

            if (graph.GetNodes()[endNodeId].Distance == int.MaxValue)
            {
                MessageBox.Show("Невозможно найти путь между выбранными узлами.");
                return;
            }

            // Отображение кратчайшего пути между начальным и конечным узлами
            ShowPath(graph, startNodeId, endNodeId);
        }

        private void buttonShowPath_Click(object sender, EventArgs e)
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

        private void textBoxStartNode_TextChanged(object sender, EventArgs e)
        {
            if (int.TryParse(textBoxStartNode.Text, out int startNode))
            {
                startNodeId = startNode;
            }
            else
            {
                MessageBox.Show("Введите корректное значение для начального узла.");
            }
        }

        private void textBoxEndNode_TextChanged(object sender, EventArgs e)
        {
            if (int.TryParse(textBoxEndNode.Text, out int endNode))
            {
                endNodeId = endNode;
            }
            else
            {
                MessageBox.Show("Введите корректное значение для конечного узла.");
            }
        }

        private void textBoxEdges_TextChanged(object sender, EventArgs e)
        {
            string[] lines = textBoxEdges.Text.Split(new[] { Environment.NewLine }, StringSplitOptions.RemoveEmptyEntries);

            graph = new Graph(); // Очищаем предыдущий граф

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
                        MessageBox.Show("Ошибка в формате ввода ребра. Используйте формат: sourceId destinationId weight");
                    }
                }
                else
                {
                    MessageBox.Show("Ошибка в формате ввода ребра. Используйте формат: sourceId destinationId weight");
                }
            }
        }

    }
}
