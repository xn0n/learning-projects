using MazeSolver.Classes;
using System.Linq;
using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;
using System;
using System.IO;  // Добавлено для работы с файлами

namespace MazeSolver
{
    public partial class Form1 : Form
    {
        private TextBox startTextBox;
        private Button searchButton;
        private Button loadButton;  // Добавлено для загрузки файла
        private Panel mazePanel;

        private int[,] maze;
        private int n;

        public Form1()
        {
            InitializeComponent();

            startTextBox = new TextBox();
            startTextBox.Location = new Point(10, 10);  // Изменено местоположение
            startTextBox.Size = new Size(200, 20);

            searchButton = new Button();
            searchButton.Location = new Point(10, 80);  // Изменено местоположение
            searchButton.Size = new Size(200, 20);
            searchButton.Text = "Найти путь";

            loadButton = new Button();  // Добавлено
            loadButton.Location = new Point(10, 150);  // Изменено местоположение
            loadButton.Size = new Size(200, 20);
            loadButton.Text = "Загрузить файл";

            mazePanel = new Panel();
            mazePanel.Location = new Point(220, 10);
            mazePanel.Size = new Size(400, 400);
            mazePanel.BorderStyle = BorderStyle.FixedSingle;

            this.Controls.Add(startTextBox);
            this.Controls.Add(searchButton);
            this.Controls.Add(loadButton);
            this.Controls.Add(mazePanel);

            searchButton.Click += SearchButton_Click;
            loadButton.Click += LoadButton_Click;
        }

        private void LoadButton_Click(object sender, EventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();
            openFileDialog.Filter = "Текстовые файлы (*.txt)|*.txt";
            if (openFileDialog.ShowDialog() == DialogResult.OK)
            {
                string filePath = openFileDialog.FileName;
                string[] lines = File.ReadAllLines(filePath);
                n = lines.Length;
                maze = new int[n, n];

                for (int i = 0; i < n; i++)
                {
                    string[] cells = lines[i].Split(' ');
                    for (int j = 0; j < n; j++)
                    {
                        maze[i, j] = int.Parse(cells[j]);
                    }
                }

                MessageBox.Show("Файл загружен успешно!");
            }
        }

        private void SearchButton_Click(object sender, EventArgs e)
        {
            if (maze == null)
            {
                MessageBox.Show("Пожалуйста, загрузите файл с лабиринтом.");
                return;
            }

            string[] startPosition = startTextBox.Text.Split(' ');
            int startI = int.Parse(startPosition[0]);
            int startJ = int.Parse(startPosition[1]);

            // Проверка начальной позиции
            if (!IsValidStart(startI, startJ))
            {
                MessageBox.Show("Начальная позиция не является проходимой.");
                return;
            }

            functions func = new functions(maze, n);

            List<Point> path = func.FindNearestExitPath(startI, startJ);

            if (path != null && path.Count > 0)
            {
                VisualizePath(path);
            }
            else
            {
                MessageBox.Show("Путь не найден.");
            }
        }

        private bool IsValidStart(int i, int j)
        {
            return i >= 0 && i < n && j >= 0 && j < n && maze[i, j] == 0;
        }

        private void VisualizePath(List<Point> path)
        {
            mazePanel.Controls.Clear();

            int cellSize = 20;

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    Panel cell = new Panel();
                    cell.Size = new Size(cellSize, cellSize);
                    cell.Location = new Point(j * cellSize, i * cellSize);

                    if (maze[i, j] == 1)
                    {
                        cell.BackColor = Color.Black;
                    }
                    else
                    {
                        cell.BackColor = Color.White;
                    }

                    if (path.Contains(new Point(i, j)))
                    {
                        cell.BackColor = Color.Green;
                    }

                    if (path.Last() == new Point(i, j))
                    {
                        cell.BackColor = Color.Yellow;
                    }

                    mazePanel.Controls.Add(cell);
                }
            }
        }
    }
}
