using System;
using System.Collections.Generic;
using System.Collections.Specialized;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Imaging;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;
using static System.Windows.Forms.VisualStyles.VisualStyleElement.Button;

namespace KeyGen
{

    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        [DllImport("genKey.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "genKey")]
        private static extern bool genKey(string PrivateFile, string PublicFile, int type);

        private void Generate_Click(object sender, EventArgs e)
        {
            int choice = 0;
            string filePrivate = PrivateFileBox.Text;
            string filePublic = PublicFileBox.Text;
            if (BerButton.Checked)
                choice = 1;
            else if (PemButton.Checked)
                choice = 2;
            else
                MessageBox.Show("Please choose key format!!");
            bool check = genKey(filePrivate, filePublic, choice);
            if (!check)
            {
                MessageBox.Show("False");
            }
            if (check == true)
            {
                MessageBox.Show("Successfully gen key");
            }
            else
            {
                MessageBox.Show("Fail to gen key");
            }
        }
        [DllImport("Signature.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "Sign")]
        private static extern bool Sign(string datafile, string PrivateFile, string SignatureFile, int choosen);
        private void button1_Click(object sender, EventArgs e)
        {
            using (var dialog = new OpenFileDialog())
            {
                if (dialog.ShowDialog() == DialogResult.OK)
                {
                    textBox1.Text = dialog.FileName;
                }
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            using (var dialog = new OpenFileDialog())
            {
                if (dialog.ShowDialog() == DialogResult.OK)
                {
                    textBox2.Text = dialog.FileName;
                }
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            using (var dialog = new OpenFileDialog())
            {
                if (dialog.ShowDialog() == DialogResult.OK)
                {
                    textBox3.Text = dialog.FileName;
                }
            }
        }

        private void Signature_Click(object sender, EventArgs e)
        {
            int type = 0;
            if (FileButton1.Checked)
                type = 1;
            else if (TextButton1.Checked)
                type = 2;
            else
                MessageBox.Show("Please choose input format!!");
            string datafile;
            if (type == 1) datafile = textBox1.Text;
            else datafile = textBox4.Text;
            string PrivateFile = textBox2.Text;
            string SignatureFile = textBox3.Text;
            bool check = Sign(datafile, PrivateFile, SignatureFile,type);
            if (!check)
            {
                MessageBox.Show("False");
            }
            if (check == true)
            {
                MessageBox.Show("Successfully Signature");
            }
            else
            {
                MessageBox.Show("Fail to Signature");
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            using (var dialog = new OpenFileDialog())
            {
                if (dialog.ShowDialog() == DialogResult.OK)
                {
                    textBox5.Text = dialog.FileName;
                }
            }
        }

        private void button5_Click(object sender, EventArgs e)
        {
            using (var dialog = new OpenFileDialog())
            {
                if (dialog.ShowDialog() == DialogResult.OK)
                {
                    textBox6.Text = dialog.FileName;
                }
            }
        }

        private void button6_Click(object sender, EventArgs e)
        {
            using (var dialog = new OpenFileDialog())
            {
                if (dialog.ShowDialog() == DialogResult.OK)
                {
                    textBox7.Text = dialog.FileName;
                }
            }
        }

        private void button7_Click(object sender, EventArgs e)
        {
            using (var dialog = new OpenFileDialog())
            {
                if (dialog.ShowDialog() == DialogResult.OK)
                {
                    textBox8.Text = dialog.FileName;
                }
            }
        }
        [DllImport("Verify.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "Veri")]
        private static extern bool Veri(string datafile, string PublicFile, string SignatureFile, string VerifyFile);
        private void Verify_Click(object sender, EventArgs e)
        {
            
            string datafile = textBox5.Text;
            string SignatureFile = textBox6.Text;
            string PublicFile = textBox7.Text;
            string VerifyFile = textBox8.Text;
            bool check = Veri(datafile, PublicFile, SignatureFile, VerifyFile);
            if (!check)
            {
                MessageBox.Show("False");
            }
            if (check == true)
            {
                MessageBox.Show("Successfully Verify");
            }
            else
            {
                MessageBox.Show("Fail to Verify");
            }
        }




        /*private void Generate_Click(object sender, EventArgs e)
        {
            
        }
        */


    }


}
