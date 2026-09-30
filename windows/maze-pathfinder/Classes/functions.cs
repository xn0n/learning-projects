using System;
using System.Collections.Generic;
using System.Drawing;

namespace MazeSolver.Classes
{
    internal class functions
    {
        private int[,] maze;
        private int n;

        public functions(int[,] maze, int n)
        {
            this.maze = maze;
            this.n = n;
        }

        public bool IsValidMove(int i, int j)
        {
            return i >= 0 && i < n && j >= 0 && j < n && maze[i, j] == 0;
        }

        public List<Point> ReconstructPath(Dictionary<Point, Point> pathMap, Point endPoint)
        {
            List<Point> path = new List<Point>();
            Point current = endPoint;

            while (pathMap.ContainsKey(current))
            {
                path.Insert(0, current);
                current = pathMap[current];
            }

            path.Insert(0, current);
            return path;
        }

        public bool IsOnBorder(int i, int j)
        {
            return i == 0 || i == n - 1 || j == 0 || j == n - 1;
        }

        public List<Point> FindNearestExitPath(int startI, int startJ)
        {
            int[][] directions = new int[][]
            {
                new[] { -1, 0 },
                new[] { 1, 0 },
                new[] { 0, -1 },
                new[] { 0, 1 }
            };

            Queue<Point> queue = new Queue<Point>();
            queue.Enqueue(new Point(startI, startJ));

            bool[,] visited = new bool[n, n];
            visited[startI, startJ] = true;

            Dictionary<Point, Point> pathMap = new Dictionary<Point, Point>();

            while (queue.Count > 0)
            {
                Point current = queue.Dequeue();

                if (IsOnBorder(current.X, current.Y))
                {
                    return ReconstructPath(pathMap, current);
                }

                foreach (int[] direction in directions)
                {
                    int newI = current.X + direction[0];
                    int newJ = current.Y + direction[1];

                    if (IsValidMove(newI, newJ) && !visited[newI, newJ])
                    {
                        queue.Enqueue(new Point(newI, newJ));
                        visited[newI, newJ] = true;
                        pathMap[new Point(newI, newJ)] = current;
                    }
                }
            }

            return null;
        }
    }
}
