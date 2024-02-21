namespace UI
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.tabPage1 = new System.Windows.Forms.TabPage();
            this.BerButton = new System.Windows.Forms.RadioButton();
            this.PemButton = new System.Windows.Forms.RadioButton();
            this.Generate = new System.Windows.Forms.Button();
            this.PublicFileBox = new System.Windows.Forms.TextBox();
            this.PrivateFileBox = new System.Windows.Forms.TextBox();
            this.PublicFileLabel = new System.Windows.Forms.Label();
            this.PrivateKeyLabel = new System.Windows.Forms.Label();
            this.Form = new System.Windows.Forms.TabControl();
            this.tabPage2 = new System.Windows.Forms.TabPage();
            this.Encrytion = new System.Windows.Forms.Button();
            this.TextButton1 = new System.Windows.Forms.RadioButton();
            this.FileButton1 = new System.Windows.Forms.RadioButton();
            this.textBox7 = new System.Windows.Forms.TextBox();
            this.button3 = new System.Windows.Forms.Button();
            this.TimeEncry = new System.Windows.Forms.Button();
            this.textBox3 = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.button2 = new System.Windows.Forms.Button();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.p = new System.Windows.Forms.Label();
            this.button1 = new System.Windows.Forms.Button();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.tabPage3 = new System.Windows.Forms.TabPage();
            this.TimeDecrypt = new System.Windows.Forms.Button();
            this.textBox8 = new System.Windows.Forms.TextBox();
            this.TextButton2 = new System.Windows.Forms.RadioButton();
            this.FileButton2 = new System.Windows.Forms.RadioButton();
            this.Decryption = new System.Windows.Forms.Button();
            this.button6 = new System.Windows.Forms.Button();
            this.textBox6 = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.button5 = new System.Windows.Forms.Button();
            this.textBox5 = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.button4 = new System.Windows.Forms.Button();
            this.textBox4 = new System.Windows.Forms.TextBox();
            this.button7 = new System.Windows.Forms.Button();
            this.button8 = new System.Windows.Forms.Button();
            this.textBox9 = new System.Windows.Forms.TextBox();
            this.button9 = new System.Windows.Forms.Button();
            this.button10 = new System.Windows.Forms.Button();
            this.textBox10 = new System.Windows.Forms.TextBox();
            this.tabPage1.SuspendLayout();
            this.Form.SuspendLayout();
            this.tabPage2.SuspendLayout();
            this.tabPage3.SuspendLayout();
            this.SuspendLayout();
            // 
            // tabPage1
            // 
            this.tabPage1.Controls.Add(this.BerButton);
            this.tabPage1.Controls.Add(this.PemButton);
            this.tabPage1.Controls.Add(this.Generate);
            this.tabPage1.Controls.Add(this.PublicFileBox);
            this.tabPage1.Controls.Add(this.PrivateFileBox);
            this.tabPage1.Controls.Add(this.PublicFileLabel);
            this.tabPage1.Controls.Add(this.PrivateKeyLabel);
            this.tabPage1.Location = new System.Drawing.Point(4, 25);
            this.tabPage1.Name = "tabPage1";
            this.tabPage1.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage1.Size = new System.Drawing.Size(1108, 529);
            this.tabPage1.TabIndex = 0;
            this.tabPage1.Text = "GenKey";
            this.tabPage1.UseVisualStyleBackColor = true;
            // 
            // BerButton
            // 
            this.BerButton.AutoSize = true;
            this.BerButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.BerButton.Location = new System.Drawing.Point(649, 182);
            this.BerButton.Name = "BerButton";
            this.BerButton.Size = new System.Drawing.Size(72, 29);
            this.BerButton.TabIndex = 15;
            this.BerButton.TabStop = true;
            this.BerButton.Text = "BER\r\n";
            this.BerButton.UseVisualStyleBackColor = true;
            // 
            // PemButton
            // 
            this.PemButton.AutoSize = true;
            this.PemButton.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.PemButton.Location = new System.Drawing.Point(633, 78);
            this.PemButton.Name = "PemButton";
            this.PemButton.Size = new System.Drawing.Size(76, 29);
            this.PemButton.TabIndex = 14;
            this.PemButton.TabStop = true;
            this.PemButton.Text = "PEM\r\n";
            this.PemButton.UseVisualStyleBackColor = true;
            // 
            // Generate
            // 
            this.Generate.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Generate.Location = new System.Drawing.Point(39, 291);
            this.Generate.Name = "Generate";
            this.Generate.Size = new System.Drawing.Size(725, 80);
            this.Generate.TabIndex = 13;
            this.Generate.Text = "Generate\r\n";
            this.Generate.UseVisualStyleBackColor = true;
            this.Generate.Click += new System.EventHandler(this.Generate_Click);
            // 
            // PublicFileBox
            // 
            this.PublicFileBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.PublicFileBox.Location = new System.Drawing.Point(218, 185);
            this.PublicFileBox.Name = "PublicFileBox";
            this.PublicFileBox.Size = new System.Drawing.Size(298, 27);
            this.PublicFileBox.TabIndex = 12;
            // 
            // PrivateFileBox
            // 
            this.PrivateFileBox.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.PrivateFileBox.Location = new System.Drawing.Point(218, 78);
            this.PrivateFileBox.Name = "PrivateFileBox";
            this.PrivateFileBox.Size = new System.Drawing.Size(298, 27);
            this.PrivateFileBox.TabIndex = 10;
            // 
            // PublicFileLabel
            // 
            this.PublicFileLabel.AutoSize = true;
            this.PublicFileLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.PublicFileLabel.Location = new System.Drawing.Point(49, 185);
            this.PublicFileLabel.Name = "PublicFileLabel";
            this.PublicFileLabel.Size = new System.Drawing.Size(101, 75);
            this.PublicFileLabel.TabIndex = 11;
            this.PublicFileLabel.Text = "File Public\r\n\r\n\r\n";
            this.PublicFileLabel.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // PrivateKeyLabel
            // 
            this.PrivateKeyLabel.AutoSize = true;
            this.PrivateKeyLabel.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.PrivateKeyLabel.Location = new System.Drawing.Point(49, 78);
            this.PrivateKeyLabel.Name = "PrivateKeyLabel";
            this.PrivateKeyLabel.Size = new System.Drawing.Size(108, 50);
            this.PrivateKeyLabel.TabIndex = 9;
            this.PrivateKeyLabel.Text = "File Private\r\n\r\n";
            this.PrivateKeyLabel.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // Form
            // 
            this.Form.Controls.Add(this.tabPage1);
            this.Form.Controls.Add(this.tabPage2);
            this.Form.Controls.Add(this.tabPage3);
            this.Form.Location = new System.Drawing.Point(-7, 12);
            this.Form.Name = "Form";
            this.Form.SelectedIndex = 0;
            this.Form.Size = new System.Drawing.Size(1116, 558);
            this.Form.TabIndex = 9;
            // 
            // tabPage2
            // 
            this.tabPage2.Controls.Add(this.textBox9);
            this.tabPage2.Controls.Add(this.button8);
            this.tabPage2.Controls.Add(this.button7);
            this.tabPage2.Controls.Add(this.Encrytion);
            this.tabPage2.Controls.Add(this.TextButton1);
            this.tabPage2.Controls.Add(this.FileButton1);
            this.tabPage2.Controls.Add(this.textBox7);
            this.tabPage2.Controls.Add(this.button3);
            this.tabPage2.Controls.Add(this.TimeEncry);
            this.tabPage2.Controls.Add(this.textBox3);
            this.tabPage2.Controls.Add(this.label1);
            this.tabPage2.Controls.Add(this.button2);
            this.tabPage2.Controls.Add(this.textBox2);
            this.tabPage2.Controls.Add(this.p);
            this.tabPage2.Controls.Add(this.button1);
            this.tabPage2.Controls.Add(this.textBox1);
            this.tabPage2.Location = new System.Drawing.Point(4, 25);
            this.tabPage2.Name = "tabPage2";
            this.tabPage2.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage2.Size = new System.Drawing.Size(1108, 529);
            this.tabPage2.TabIndex = 1;
            this.tabPage2.Text = "Encrytion";
            this.tabPage2.UseVisualStyleBackColor = true;
            // 
            // Encrytion
            // 
            this.Encrytion.Location = new System.Drawing.Point(61, 441);
            this.Encrytion.Name = "Encrytion";
            this.Encrytion.Size = new System.Drawing.Size(235, 73);
            this.Encrytion.TabIndex = 15;
            this.Encrytion.Text = "Encrytion";
            this.Encrytion.UseVisualStyleBackColor = true;
            this.Encrytion.Click += new System.EventHandler(this.Encrytion_Click);
            // 
            // TextButton1
            // 
            this.TextButton1.AutoSize = true;
            this.TextButton1.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.TextButton1.Location = new System.Drawing.Point(61, 74);
            this.TextButton1.Name = "TextButton1";
            this.TextButton1.Size = new System.Drawing.Size(126, 30);
            this.TextButton1.TabIndex = 14;
            this.TextButton1.TabStop = true;
            this.TextButton1.Text = "Text Data";
            this.TextButton1.UseVisualStyleBackColor = true;
            // 
            // FileButton1
            // 
            this.FileButton1.AutoSize = true;
            this.FileButton1.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.FileButton1.Location = new System.Drawing.Point(61, 20);
            this.FileButton1.Name = "FileButton1";
            this.FileButton1.Size = new System.Drawing.Size(120, 30);
            this.FileButton1.TabIndex = 13;
            this.FileButton1.TabStop = true;
            this.FileButton1.Text = "File Data";
            this.FileButton1.UseVisualStyleBackColor = true;
            // 
            // textBox7
            // 
            this.textBox7.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBox7.Location = new System.Drawing.Point(220, 74);
            this.textBox7.Name = "textBox7";
            this.textBox7.Size = new System.Drawing.Size(318, 27);
            this.textBox7.TabIndex = 12;
            // 
            // button3
            // 
            this.button3.Location = new System.Drawing.Point(662, 372);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(148, 41);
            this.button3.TabIndex = 11;
            this.button3.Text = "Browse";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // TimeEncry
            // 
            this.TimeEncry.Location = new System.Drawing.Point(690, 450);
            this.TimeEncry.Name = "TimeEncry";
            this.TimeEncry.Size = new System.Drawing.Size(235, 73);
            this.TimeEncry.TabIndex = 10;
            this.TimeEncry.Text = "TimeEncrypt";
            this.TimeEncry.UseVisualStyleBackColor = true;
            this.TimeEncry.Click += new System.EventHandler(this.TimeEncrypt_Click);
            // 
            // textBox3
            // 
            this.textBox3.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBox3.Location = new System.Drawing.Point(235, 378);
            this.textBox3.Name = "textBox3";
            this.textBox3.Size = new System.Drawing.Size(318, 27);
            this.textBox3.TabIndex = 9;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label1.Location = new System.Drawing.Point(52, 380);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(129, 25);
            this.label1.TabIndex = 8;
            this.label1.Text = "Encrytion File";
            // 
            // button2
            // 
            this.button2.Location = new System.Drawing.Point(662, 284);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(148, 41);
            this.button2.TabIndex = 7;
            this.button2.Text = "Browse";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // textBox2
            // 
            this.textBox2.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBox2.Location = new System.Drawing.Point(235, 289);
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(318, 27);
            this.textBox2.TabIndex = 6;
            // 
            // p
            // 
            this.p.AutoSize = true;
            this.p.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.p.Location = new System.Drawing.Point(66, 289);
            this.p.Name = "p";
            this.p.Size = new System.Drawing.Size(101, 25);
            this.p.TabIndex = 5;
            this.p.Text = "Public File";
            // 
            // button1
            // 
            this.button1.Location = new System.Drawing.Point(577, 14);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(148, 41);
            this.button1.TabIndex = 2;
            this.button1.Text = "Browse";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // textBox1
            // 
            this.textBox1.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBox1.Location = new System.Drawing.Point(220, 20);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(318, 27);
            this.textBox1.TabIndex = 1;
            // 
            // tabPage3
            // 
            this.tabPage3.Controls.Add(this.textBox10);
            this.tabPage3.Controls.Add(this.button10);
            this.tabPage3.Controls.Add(this.button9);
            this.tabPage3.Controls.Add(this.TimeDecrypt);
            this.tabPage3.Controls.Add(this.textBox8);
            this.tabPage3.Controls.Add(this.TextButton2);
            this.tabPage3.Controls.Add(this.FileButton2);
            this.tabPage3.Controls.Add(this.Decryption);
            this.tabPage3.Controls.Add(this.button6);
            this.tabPage3.Controls.Add(this.textBox6);
            this.tabPage3.Controls.Add(this.label4);
            this.tabPage3.Controls.Add(this.button5);
            this.tabPage3.Controls.Add(this.textBox5);
            this.tabPage3.Controls.Add(this.label3);
            this.tabPage3.Controls.Add(this.button4);
            this.tabPage3.Controls.Add(this.textBox4);
            this.tabPage3.Location = new System.Drawing.Point(4, 25);
            this.tabPage3.Name = "tabPage3";
            this.tabPage3.Padding = new System.Windows.Forms.Padding(3);
            this.tabPage3.Size = new System.Drawing.Size(1108, 529);
            this.tabPage3.TabIndex = 2;
            this.tabPage3.Text = "Decryption";
            this.tabPage3.UseVisualStyleBackColor = true;
            // 
            // TimeDecrypt
            // 
            this.TimeDecrypt.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.TimeDecrypt.Location = new System.Drawing.Point(719, 443);
            this.TimeDecrypt.Name = "TimeDecrypt";
            this.TimeDecrypt.Size = new System.Drawing.Size(175, 67);
            this.TimeDecrypt.TabIndex = 15;
            this.TimeDecrypt.Text = "Time Decrypt";
            this.TimeDecrypt.UseVisualStyleBackColor = true;
            this.TimeDecrypt.Click += new System.EventHandler(this.TimeDecrypt_Click);
            // 
            // textBox8
            // 
            this.textBox8.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBox8.Location = new System.Drawing.Point(289, 229);
            this.textBox8.Name = "textBox8";
            this.textBox8.Size = new System.Drawing.Size(328, 30);
            this.textBox8.TabIndex = 14;
            // 
            // TextButton2
            // 
            this.TextButton2.AutoSize = true;
            this.TextButton2.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.TextButton2.Location = new System.Drawing.Point(102, 229);
            this.TextButton2.Name = "TextButton2";
            this.TextButton2.Size = new System.Drawing.Size(144, 30);
            this.TextButton2.TabIndex = 13;
            this.TextButton2.TabStop = true;
            this.TextButton2.Text = "Cipher Text";
            this.TextButton2.UseVisualStyleBackColor = true;
            // 
            // FileButton2
            // 
            this.FileButton2.AutoSize = true;
            this.FileButton2.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.FileButton2.Location = new System.Drawing.Point(102, 150);
            this.FileButton2.Name = "FileButton2";
            this.FileButton2.Size = new System.Drawing.Size(138, 30);
            this.FileButton2.TabIndex = 12;
            this.FileButton2.TabStop = true;
            this.FileButton2.Text = "Cipher File";
            this.FileButton2.UseVisualStyleBackColor = true;
            // 
            // Decryption
            // 
            this.Decryption.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Decryption.Location = new System.Drawing.Point(90, 443);
            this.Decryption.Name = "Decryption";
            this.Decryption.Size = new System.Drawing.Size(175, 67);
            this.Decryption.TabIndex = 11;
            this.Decryption.Text = "Decrytion";
            this.Decryption.UseVisualStyleBackColor = true;
            this.Decryption.Click += new System.EventHandler(this.Decryption_Click);
            // 
            // button6
            // 
            this.button6.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button6.Location = new System.Drawing.Point(689, 387);
            this.button6.Name = "button6";
            this.button6.Size = new System.Drawing.Size(130, 39);
            this.button6.TabIndex = 10;
            this.button6.Text = "Browse";
            this.button6.UseVisualStyleBackColor = true;
            this.button6.Click += new System.EventHandler(this.button6_Click);
            // 
            // textBox6
            // 
            this.textBox6.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBox6.Location = new System.Drawing.Point(289, 391);
            this.textBox6.Name = "textBox6";
            this.textBox6.Size = new System.Drawing.Size(328, 30);
            this.textBox6.TabIndex = 9;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label4.Location = new System.Drawing.Point(105, 391);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(141, 25);
            this.label4.TabIndex = 8;
            this.label4.Text = "Decryption File";
            // 
            // button5
            // 
            this.button5.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button5.Location = new System.Drawing.Point(689, 304);
            this.button5.Name = "button5";
            this.button5.Size = new System.Drawing.Size(130, 39);
            this.button5.TabIndex = 7;
            this.button5.Text = "Browse";
            this.button5.UseVisualStyleBackColor = true;
            this.button5.Click += new System.EventHandler(this.button5_Click);
            // 
            // textBox5
            // 
            this.textBox5.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBox5.Location = new System.Drawing.Point(289, 308);
            this.textBox5.Name = "textBox5";
            this.textBox5.Size = new System.Drawing.Size(328, 30);
            this.textBox5.TabIndex = 6;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Microsoft Sans Serif", 13.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.label3.Location = new System.Drawing.Point(105, 312);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(121, 26);
            this.label3.TabIndex = 5;
            this.label3.Text = "Private File";
            // 
            // button4
            // 
            this.button4.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button4.Location = new System.Drawing.Point(663, 150);
            this.button4.Name = "button4";
            this.button4.Size = new System.Drawing.Size(130, 39);
            this.button4.TabIndex = 2;
            this.button4.Text = "Browse";
            this.button4.UseVisualStyleBackColor = true;
            this.button4.Click += new System.EventHandler(this.button4_Click);
            // 
            // textBox4
            // 
            this.textBox4.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBox4.Location = new System.Drawing.Point(289, 150);
            this.textBox4.Name = "textBox4";
            this.textBox4.Size = new System.Drawing.Size(328, 30);
            this.textBox4.TabIndex = 1;
            // 
            // button7
            // 
            this.button7.Location = new System.Drawing.Point(61, 124);
            this.button7.Name = "button7";
            this.button7.Size = new System.Drawing.Size(148, 41);
            this.button7.TabIndex = 16;
            this.button7.Text = "BASE64";
            this.button7.UseVisualStyleBackColor = true;
            this.button7.Click += new System.EventHandler(this.button7_Click);
            // 
            // button8
            // 
            this.button8.Location = new System.Drawing.Point(61, 205);
            this.button8.Name = "button8";
            this.button8.Size = new System.Drawing.Size(148, 41);
            this.button8.TabIndex = 17;
            this.button8.Text = "HEX";
            this.button8.UseVisualStyleBackColor = true;
            this.button8.Click += new System.EventHandler(this.button8_Click);
            // 
            // textBox9
            // 
            this.textBox9.Font = new System.Drawing.Font("Microsoft Sans Serif", 10.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBox9.Location = new System.Drawing.Point(252, 171);
            this.textBox9.Name = "textBox9";
            this.textBox9.Size = new System.Drawing.Size(318, 27);
            this.textBox9.TabIndex = 18;
            // 
            // button9
            // 
            this.button9.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button9.Location = new System.Drawing.Point(102, 6);
            this.button9.Name = "button9";
            this.button9.Size = new System.Drawing.Size(130, 39);
            this.button9.TabIndex = 16;
            this.button9.Text = "BASE64";
            this.button9.UseVisualStyleBackColor = true;
            this.button9.Click += new System.EventHandler(this.button9_Click);
            // 
            // button10
            // 
            this.button10.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.button10.Location = new System.Drawing.Point(102, 66);
            this.button10.Name = "button10";
            this.button10.Size = new System.Drawing.Size(130, 39);
            this.button10.TabIndex = 17;
            this.button10.Text = "HEX";
            this.button10.UseVisualStyleBackColor = true;
            this.button10.Click += new System.EventHandler(this.button10_Click);
            // 
            // textBox10
            // 
            this.textBox10.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.textBox10.Location = new System.Drawing.Point(289, 45);
            this.textBox10.Name = "textBox10";
            this.textBox10.Size = new System.Drawing.Size(328, 30);
            this.textBox10.TabIndex = 18;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1121, 602);
            this.Controls.Add(this.Form);
            this.Name = "Form1";
            this.Text = "Form1";
            this.tabPage1.ResumeLayout(false);
            this.tabPage1.PerformLayout();
            this.Form.ResumeLayout(false);
            this.tabPage2.ResumeLayout(false);
            this.tabPage2.PerformLayout();
            this.tabPage3.ResumeLayout(false);
            this.tabPage3.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.TabPage tabPage1;
        private System.Windows.Forms.RadioButton BerButton;
        private System.Windows.Forms.RadioButton PemButton;
        private System.Windows.Forms.Button Generate;
        private System.Windows.Forms.TextBox PublicFileBox;
        private System.Windows.Forms.TextBox PrivateFileBox;
        private System.Windows.Forms.Label PublicFileLabel;
        private System.Windows.Forms.Label PrivateKeyLabel;
        private System.Windows.Forms.TabControl Form;
        private System.Windows.Forms.TabPage tabPage2;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Label p;
        private System.Windows.Forms.TextBox textBox2;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.TextBox textBox3;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button TimeEncry;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.TabPage tabPage3;
        private System.Windows.Forms.Button button4;
        private System.Windows.Forms.TextBox textBox4;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Button Decryption;
        private System.Windows.Forms.Button button6;
        private System.Windows.Forms.TextBox textBox6;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Button button5;
        private System.Windows.Forms.TextBox textBox5;
        private System.Windows.Forms.RadioButton FileButton1;
        private System.Windows.Forms.TextBox textBox7;
        private System.Windows.Forms.RadioButton TextButton1;
        private System.Windows.Forms.RadioButton FileButton2;
        private System.Windows.Forms.TextBox textBox8;
        private System.Windows.Forms.RadioButton TextButton2;
        private System.Windows.Forms.Button Encrytion;
        private System.Windows.Forms.Button TimeDecrypt;
        private System.Windows.Forms.Button button7;
        private System.Windows.Forms.TextBox textBox9;
        private System.Windows.Forms.Button button8;
        private System.Windows.Forms.TextBox textBox10;
        private System.Windows.Forms.Button button10;
        private System.Windows.Forms.Button button9;
    }
}

