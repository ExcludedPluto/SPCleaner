using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

namespace eliminator_5
{
    public partial class 잉여지우개: Form
    {
        bool blnBtnClosing = false;
        public 잉여지우개()
        {
            InitializeComponent();
        }

        private void richTextBox1_TextChanged(object sender, EventArgs e)
        {

        }
         
        private void Form1_Load(object sender, EventArgs e)
        { 
            using (System.IO.StreamReader objReadFile = new System.IO.StreamReader(@"deinstall.txt", System.Text.Encoding.Default))
            { 
                richTextBox1.Text = objReadFile.ReadToEnd();
                objReadFile.Close();
                objReadFile.Dispose();
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            if (MessageBox.Show("제대로 입력하셨습니까?", "입력 확인", MessageBoxButtons.YesNo) == DialogResult.Yes)
            {
                blnBtnClosing = true;
                this.DialogResult = DialogResult.Abort;
                System.Diagnostics.ProcessStartInfo process =
                new System.Diagnostics.ProcessStartInfo(System.Windows.Forms.Application.StartupPath + @"\\SPcleaner_deinst.exe");
                System.Diagnostics.Process.Start(process);
                Application.Exit();

            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (MessageBox.Show("삭제하면 안 될 은행을 다시 선택하시겠습니까?", "확인", MessageBoxButtons.YesNo) == DialogResult.Yes)
            {
                blnBtnClosing = true;
                this.DialogResult = DialogResult.Abort;
                System.Diagnostics.ProcessStartInfo process =
                new System.Diagnostics.ProcessStartInfo(System.Windows.Forms.Application.StartupPath + @"\\SPcleaner_search.exe");
                System.Diagnostics.Process.Start(process);
                Application.Exit();
            }
        }

        private void label2_Click(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        { 
            System.IO.StreamWriter objSaveFile = new System.IO.StreamWriter(@"choose_2.txt");
            objSaveFile.Write(textBox1.Text);
            objSaveFile.Close();
            objSaveFile.Dispose();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }
    }
}
