using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO;
using System.Net;
using System.Net.Sockets;
using System.Windows.Forms;

namespace WindowsFormsApplication367
{
    public partial class Form1 : Form
    {
        private Image mask;
        private Image wall;
        private PointF playerPosition;
        private Maze maze;

        public Form1()
        {
            InitializeComponent();

            SetStyle(ControlStyles.AllPaintingInWmPaint | ControlStyles.OptimizedDoubleBuffer | ControlStyles.UserPaint | ControlStyles.ResizeRedraw, true);
            BackColor = Color.Black;
            SetClientSizeCore(500, 500);

            mask = Properties.Resources.shadow;
            wall = Properties.Resources.brick;

            maze = new Maze();
            playerPosition = new PointF(10.5f, 10.5f);

            new Timer { Interval = 50, Enabled = true }.Tick += delegate { playerPosition.X += 0.03f; Invalidate(); };
        }

        protected override void OnPaint(PaintEventArgs e)
        {
            var tileCount = 5;
            var tileSize = ClientSize.Width / tileCount;
            var d = tileSize * tileCount / 2;

            e.Graphics.SetClip(new Rectangle(0, 0, tileCount * tileSize, tileCount * tileSize));
            e.Graphics.TranslateTransform(-playerPosition.X * tileSize + d, -playerPosition.Y * tileSize + d);

            //рисуем тайлы (вокруг игрока)
            e.Graphics.PixelOffsetMode = System.Drawing.Drawing2D.PixelOffsetMode.HighQuality;
            var fromI = Math.Max(0, (int)playerPosition.X - tileCount / 2);
            var fromJ = Math.Max(0, (int)playerPosition.Y - tileCount / 2);
            for (int i = fromI; i < fromI + tileCount + 1; i++)
                for (int j = fromJ; j < fromJ + tileCount + 1; j++)
                    if (maze[i, j] == 1)
                        e.Graphics.DrawImage(wall, new Rectangle(i * tileSize, j * tileSize, tileSize + 1, tileSize + 1));

            //рисуем игрока
            e.Graphics.FillRectangle(Brushes.Lime, new RectangleF(playerPosition.X * tileSize - 3, playerPosition.Y * tileSize - 3, 6, 6));

            //рисуем маску
            e.Graphics.ResetTransform();
            e.Graphics.DrawImage(mask, e.Graphics.ClipBounds);
        }

        class Maze
        {
            private static Random rnd = new Random();
            private int[,] items;

            public Maze()
            {
                items = new int[100, 100];
                for (int i = 0; i < 100; i++)
                    for (int j = 0; j < 100; j++)
                        items[i, j] = rnd.Next(2);
            }

            public int this[int x, int y]
            {
                get { return items[x % items.GetLength(0), y % items.GetLength(1)]; }
            }
        }
    }
}