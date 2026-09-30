using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace deixtra.Classes
{
    class GraphDefine
    {
        private Dictionary<int, Node> nodes;
        private List<Edge> edges;

        public GraphDefine()
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
}
