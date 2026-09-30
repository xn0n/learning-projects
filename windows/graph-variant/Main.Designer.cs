namespace Graf
{
    partial class Graf
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.textBoxStartNode = new System.Windows.Forms.TextBox();
            this.textBoxEndNode = new System.Windows.Forms.TextBox();
            this.textBoxEdges = new System.Windows.Forms.TextBox();
            this.buttonGenerateGraph = new System.Windows.Forms.Button();
            this.buttonFindPath = new System.Windows.Forms.Button();
            this.buttonShowPath = new System.Windows.Forms.Button();
            this.panelGraph = new System.Windows.Forms.Panel();
            this.labelPathLength = new System.Windows.Forms.Label();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.panelGraph.SuspendLayout();
            this.SuspendLayout();
            // 
            // textBoxStartNode
            // 
            this.textBoxStartNode.Location = new System.Drawing.Point(12, 80);
            this.textBoxStartNode.Name = "textBoxStartNode";
            this.textBoxStartNode.Size = new System.Drawing.Size(136, 22);
            this.textBoxStartNode.TabIndex = 0;
            this.textBoxStartNode.TextChanged += new System.EventHandler(this.textBoxStartNode_TextChanged);
            // 
            // textBoxEndNode
            // 
            this.textBoxEndNode.Location = new System.Drawing.Point(12, 227);
            this.textBoxEndNode.Name = "textBoxEndNode";
            this.textBoxEndNode.Size = new System.Drawing.Size(136, 22);
            this.textBoxEndNode.TabIndex = 1;
            this.textBoxEndNode.TextChanged += new System.EventHandler(this.textBoxEndNode_TextChanged);
            // 
            // textBoxEdges
            // 
            this.textBoxEdges.Location = new System.Drawing.Point(12, 401);
            this.textBoxEdges.Multiline = true;
            this.textBoxEdges.Name = "textBoxEdges";
            this.textBoxEdges.Size = new System.Drawing.Size(164, 82);
            this.textBoxEdges.TabIndex = 2;
            this.textBoxEdges.TextChanged += new System.EventHandler(this.textBoxEdges_TextChanged);
            // 
            // buttonGenerateGraph
            // 
            this.buttonGenerateGraph.Location = new System.Drawing.Point(254, 489);
            this.buttonGenerateGraph.Name = "buttonGenerateGraph";
            this.buttonGenerateGraph.Size = new System.Drawing.Size(75, 52);
            this.buttonGenerateGraph.TabIndex = 3;
            this.buttonGenerateGraph.Text = "Generate";
            this.buttonGenerateGraph.UseVisualStyleBackColor = true;
            this.buttonGenerateGraph.Click += new System.EventHandler(this.buttonGenerateGraph_Click);
            // 
            // buttonFindPath
            // 
            this.buttonFindPath.Location = new System.Drawing.Point(673, 489);
            this.buttonFindPath.Name = "buttonFindPath";
            this.buttonFindPath.Size = new System.Drawing.Size(75, 52);
            this.buttonFindPath.TabIndex = 4;
            this.buttonFindPath.Text = "Find";
            this.buttonFindPath.UseVisualStyleBackColor = true;
            this.buttonFindPath.Click += new System.EventHandler(this.buttonFindPath_Click_1);
            // 
            // buttonShowPath
            // 
            this.buttonShowPath.Location = new System.Drawing.Point(1066, 489);
            this.buttonShowPath.Name = "buttonShowPath";
            this.buttonShowPath.Size = new System.Drawing.Size(75, 52);
            this.buttonShowPath.TabIndex = 5;
            this.buttonShowPath.Text = "Show";
            this.buttonShowPath.UseVisualStyleBackColor = true;
            this.buttonShowPath.Click += new System.EventHandler(this.buttonShowPath_Click);
            // 
            // panelGraph
            // 
            this.panelGraph.AutoScroll = true;
            this.panelGraph.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(255)))), ((int)(((byte)(192)))));
            this.panelGraph.Controls.Add(this.labelPathLength);
            this.panelGraph.Location = new System.Drawing.Point(225, 12);
            this.panelGraph.Name = "panelGraph";
            this.panelGraph.Size = new System.Drawing.Size(945, 471);
            this.panelGraph.TabIndex = 6;
            this.panelGraph.Paint += new System.Windows.Forms.PaintEventHandler(this.panelGraph_Paint);
            // 
            // labelPathLength
            // 
            this.labelPathLength.Dock = System.Windows.Forms.DockStyle.Fill;
            this.labelPathLength.Location = new System.Drawing.Point(0, 0);
            this.labelPathLength.Name = "labelPathLength";
            this.labelPathLength.Size = new System.Drawing.Size(945, 471);
            this.labelPathLength.TabIndex = 0;
            // 
            // textBox1
            // 
            this.textBox1.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(224)))), ((int)(((byte)(224)))), ((int)(((byte)(224)))));
            this.textBox1.Location = new System.Drawing.Point(12, 12);
            this.textBox1.Multiline = true;
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(191, 62);
            this.textBox1.TabIndex = 7;
            this.textBox1.Text = "Введите корректное значение для начального узла";
            // 
            // textBox2
            // 
            this.textBox2.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(224)))), ((int)(((byte)(224)))), ((int)(((byte)(224)))));
            this.textBox2.Location = new System.Drawing.Point(12, 150);
            this.textBox2.Multiline = true;
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(191, 71);
            this.textBox2.TabIndex = 8;
            this.textBox2.Text = "Введите корректное значение для конечного узла.";
            // 
            // Graf
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1182, 553);
            this.Controls.Add(this.textBox2);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.panelGraph);
            this.Controls.Add(this.buttonShowPath);
            this.Controls.Add(this.buttonFindPath);
            this.Controls.Add(this.buttonGenerateGraph);
            this.Controls.Add(this.textBoxEdges);
            this.Controls.Add(this.textBoxEndNode);
            this.Controls.Add(this.textBoxStartNode);
            this.Name = "Graf";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Form1";
            this.Click += new System.EventHandler(this.buttonFindPath_Click);
            this.panelGraph.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.TextBox textBoxStartNode;
        private System.Windows.Forms.TextBox textBoxEndNode;
        private System.Windows.Forms.TextBox textBoxEdges;
        private System.Windows.Forms.Button buttonGenerateGraph;
        private System.Windows.Forms.Button buttonFindPath;
        private System.Windows.Forms.Button buttonShowPath;
        private System.Windows.Forms.Panel panelGraph;
        private System.Windows.Forms.Label labelPathLength;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.TextBox textBox2;
    }
}

