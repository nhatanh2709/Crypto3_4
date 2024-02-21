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

namespace UI
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
        [DllImport("Encryption.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "Encryption")]
        private static extern double Encryption(string datafile, string PublicFile, string EncryptionFile, int choosen,int Form);

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
        private void button7_Click(object sender, EventArgs e)
        {
            textBox9.Text = "BASE64";          
        }
        private void button8_Click(object sender, EventArgs e)
        {
            textBox9.Text = "HEX";
            
        }
        private void TimeEncrypt_Click(object sender, EventArgs e)
        {
            int form = 0;
            if (textBox9.Text == "BASE64")
                form = 1;
            else form = 2;
            int type = 0;
            if (FileButton1.Checked)
                type = 1;
            else if (TextButton1.Checked)
                type = 2;
            else
                MessageBox.Show("Please choose input format!!");
            string datafile;
            if (type == 1) datafile = textBox1.Text;
            else datafile = textBox7.Text;
            string PublicFile = textBox2.Text;
            string EncryptionFile = textBox3.Text;
            double Time = Encryption(datafile, PublicFile, EncryptionFile, type,form);
            if (Time < (double)0)
            {
                MessageBox.Show("False to Encrytioon");
            }
            else
            {
                String CurentTime = Time.ToString();
                MessageBox.Show( CurentTime );
            }
        }

        private void Encrytion_Click(object sender, EventArgs e)
        {
            int form = 0;
            if (textBox9.Text == "BASE64")
                form = 1;
            else form = 2;
            int type = 0;
            if (FileButton1.Checked)
                type = 1;
            else if (TextButton1.Checked)
                type = 2;
            else
                MessageBox.Show("Please choose input format!!");
            string datafile;
            if (type == 1) datafile = textBox1.Text;
            else datafile = textBox7.Text;
            string PublicFile = textBox2.Text;
            string EncryptionFile = textBox3.Text;
            double Time = Encryption(datafile, PublicFile, EncryptionFile, type,form);
            if (Time < (double)0)
            {
                MessageBox.Show("False to Encrytioon");
            }
            else
            {
                MessageBox.Show("Successfully Encryption");
            }
        }


        private void button4_Click(object sender, EventArgs e)
        {
            using (var dialog = new OpenFileDialog())
            {
                if (dialog.ShowDialog() == DialogResult.OK)
                {
                    textBox4.Text = dialog.FileName;

                }
            }
        }

        private void button5_Click(object sender, EventArgs e)
        {
            using (var dialog = new OpenFileDialog())
            {
                if (dialog.ShowDialog() == DialogResult.OK)
                {
                    textBox5.Text = dialog.FileName;
                }
            }
        }

        private void button6_Click(object sender, EventArgs e)
        {
            using (var dialog = new OpenFileDialog())
            {
                if (dialog.ShowDialog() == DialogResult.OK)
                {
                    textBox6.Text = dialog.FileName;

                }
            }
        }
        private void button9_Click(object sender, EventArgs e)
        {
            textBox10.Text = "BASE64";
        }
        private void button10_Click(object sender, EventArgs e)
        {
            textBox10.Text = "HEX";
        }
        [DllImport("Decrypt.dll", CallingConvention = CallingConvention.Cdecl, CharSet = CharSet.Ansi, EntryPoint = "Decrypt")]
        private static extern double Decrypt(string CipherFile, string PublicFile, string DecryptionFile, int choosen,int form);
        private void Decryption_Click(object sender, EventArgs e)
        {
            int form = 0;
            if (textBox10.Text == "BASE64")
                form = 1;
            else form = 2;
            int choice = 0;
            MessageBox.Show(textBox10.Text);
            if (FileButton2.Checked)
                choice = 1;
            else if (TextButton2.Checked)
                choice = 2;
            else
                MessageBox.Show("Please choose key format!!");
            if (FileButton2.Checked) MessageBox.Show("1");
            string Cipherfile;
            if (choice == 1) Cipherfile = textBox4.Text;
            else Cipherfile = textBox8.Text;
            string PrivateFile = textBox5.Text;
            string DecryptionFile = textBox6.Text;
            double Time = Decrypt(Cipherfile, PrivateFile, DecryptionFile, choice,form);
            if (Time== -1 )
            {
                MessageBox.Show("False to Decrypt");
            }
            else 
            {
                MessageBox.Show("Successfully Encryption");
            }
        
        }

        private void TimeDecrypt_Click(object sender, EventArgs e)
        {
            int form = 0;
            if (textBox10.Text == "BASE64")
                form = 1;
            else form = 2;
            int choice = 0;
            if (FileButton2.Checked)
                choice = 1;
            else if (TextButton2.Checked)
                choice = 2;
            else
                MessageBox.Show("Please choose key format!!");
            string Cipherfile;
            if (choice == 1) Cipherfile = textBox4.Text;
            else Cipherfile = textBox8.Text;
            string PrivateFile = textBox5.Text;
            string DecryptionFile = textBox6.Text;
            double Time = Decrypt(Cipherfile, PrivateFile, DecryptionFile, choice,form);
            if (Time == -1)
            {
                MessageBox.Show("False to Decrypt");
            }
            else
            {
                String CurentTime = Time.ToString();
                MessageBox.Show(CurentTime);
            }
        }

        
    }


}
