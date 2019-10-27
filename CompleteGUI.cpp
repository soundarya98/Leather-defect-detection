#pragma once

#include "stdafx.h"
#include <Windows.h>
#include "MyForm3.h"
#include <stdlib.h>

#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>
#include <opencv2/objdetect/objdetect.hpp>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <vcclr.h>
#include <filesystem>
#include <msclr\marshal_cppstd.h>

#define DBOUT( s )            \
{                             \
   std::ostringstream os_;    \
   os_ << s;                   \
   OutputDebugString( os_.str().c_str() );  \
}

using namespace cv;

static std::string filenamestring;
static bool buttonClicked = false;

namespace Project1 
{
	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
		float perc;
		public:
			MyForm(void)
			{
				InitializeComponent();
				//
				//TODO: Add the constructor code here
				//
			}

		protected:
			/// <summary>
			/// Clean up any resources being used.
			/// </summary>
			~MyForm()
			{
				if (components)
				{
					delete components;
				}
			}



	private: System::Windows::Forms::Button^  button1;

	private: System::Windows::Forms::Panel^  panel1;


	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Panel^  panel4;



	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Panel^  panel5;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;

	private: System::ComponentModel::IContainer^  components;






		protected:


		protected:

		protected:

		private:
			/// <summary>
			/// Required designer variable.
			/// </summary>


	#pragma region Windows Form Designer generated code
			/// <summary>
			/// Required method for Designer support - do not modify
			/// the contents of this method with the code editor.
			/// </summary>
			void InitializeComponent(void)
			{
				this->button1 = (gcnew System::Windows::Forms::Button());
				this->panel1 = (gcnew System::Windows::Forms::Panel());
				this->label8 = (gcnew System::Windows::Forms::Label());
				this->button2 = (gcnew System::Windows::Forms::Button());
				this->panel2 = (gcnew System::Windows::Forms::Panel());
				this->textBox5 = (gcnew System::Windows::Forms::TextBox());
				this->textBox4 = (gcnew System::Windows::Forms::TextBox());
				this->textBox3 = (gcnew System::Windows::Forms::TextBox());
				this->textBox1 = (gcnew System::Windows::Forms::TextBox());
				this->label7 = (gcnew System::Windows::Forms::Label());
				this->label6 = (gcnew System::Windows::Forms::Label());
				this->label5 = (gcnew System::Windows::Forms::Label());
				this->label4 = (gcnew System::Windows::Forms::Label());
				this->label3 = (gcnew System::Windows::Forms::Label());
				this->panel3 = (gcnew System::Windows::Forms::Panel());
				this->label1 = (gcnew System::Windows::Forms::Label());
				this->panel4 = (gcnew System::Windows::Forms::Panel());
				this->button3 = (gcnew System::Windows::Forms::Button());
				this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
				this->label2 = (gcnew System::Windows::Forms::Label());
				this->panel5 = (gcnew System::Windows::Forms::Panel());
				this->button4 = (gcnew System::Windows::Forms::Button());
				this->panel1->SuspendLayout();
				this->panel2->SuspendLayout();
				this->panel3->SuspendLayout();
				this->panel4->SuspendLayout();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
				this->SuspendLayout();
				// 
				// button1
				// 
				this->button1->Location = System::Drawing::Point(105, 46);
				this->button1->Name = L"button1";
				this->button1->Size = System::Drawing::Size(75, 23);
				this->button1->TabIndex = 2;
				this->button1->Text = L"Test";
				this->button1->UseVisualStyleBackColor = true;
				this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
				// 
				// panel1
				// 
				this->panel1->BackColor = System::Drawing::Color::Sienna;
				this->panel1->Controls->Add(this->label8);
				this->panel1->Font = (gcnew System::Drawing::Font(L"Century Gothic", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					static_cast<System::Byte>(0)));
				this->panel1->Location = System::Drawing::Point(-5, 15);
				this->panel1->Name = L"panel1";
				this->panel1->Size = System::Drawing::Size(663, 74);
				this->panel1->TabIndex = 4;
				this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel1_Paint_1);
				// 
				// label8
				// 
				this->label8->AutoSize = true;
				this->label8->Font = (gcnew System::Drawing::Font(L"Century Gothic", 25));
				this->label8->Location = System::Drawing::Point(152, 16);
				this->label8->Name = L"label8";
				this->label8->Size = System::Drawing::Size(440, 40);
				this->label8->TabIndex = 0;
				this->label8->Text = L"Leather Defect Detection";
				this->label8->Click += gcnew System::EventHandler(this, &MyForm::label8_Click);
				// 
				// button2
				// 
				this->button2->Location = System::Drawing::Point(12, 46);
				this->button2->Name = L"button2";
				this->button2->Size = System::Drawing::Size(75, 23);
				this->button2->TabIndex = 6;
				this->button2->Text = L"Browse";
				this->button2->UseVisualStyleBackColor = true;
				this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
				// 
				// panel2
				// 
				this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				this->panel2->Controls->Add(this->button4);
				this->panel2->Controls->Add(this->textBox5);
				this->panel2->Controls->Add(this->textBox4);
				this->panel2->Controls->Add(this->textBox3);
				this->panel2->Controls->Add(this->textBox1);
				this->panel2->Controls->Add(this->label7);
				this->panel2->Controls->Add(this->label6);
				this->panel2->Controls->Add(this->label5);
				this->panel2->Controls->Add(this->label4);
				this->panel2->Controls->Add(this->label3);
				this->panel2->Location = System::Drawing::Point(476, 115);
				this->panel2->Name = L"panel2";
				this->panel2->Size = System::Drawing::Size(170, 315);
				this->panel2->TabIndex = 7;
				// 
				// textBox5
				// 
				this->textBox5->Location = System::Drawing::Point(92, 145);
				this->textBox5->Name = L"textBox5";
				this->textBox5->Size = System::Drawing::Size(65, 20);
				this->textBox5->TabIndex = 8;
				this->textBox5->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox5_TextChanged);
				// 
				// textBox4
				// 
				this->textBox4->Location = System::Drawing::Point(92, 117);
				this->textBox4->Name = L"textBox4";
				this->textBox4->Size = System::Drawing::Size(65, 20);
				this->textBox4->TabIndex = 7;
				// 
				// textBox3
				// 
				this->textBox3->Location = System::Drawing::Point(92, 87);
				this->textBox3->Name = L"textBox3";
				this->textBox3->Size = System::Drawing::Size(65, 20);
				this->textBox3->TabIndex = 6;
				this->textBox3->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox3_TextChanged);
				// 
				// textBox1
				// 
				this->textBox1->Location = System::Drawing::Point(92, 60);
				this->textBox1->Name = L"textBox1";
				this->textBox1->Size = System::Drawing::Size(65, 20);
				this->textBox1->TabIndex = 5;
				this->textBox1->Text = L"DSC03812";
				this->textBox1->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged_1);
				// 
				// label7
				// 
				this->label7->AutoSize = true;
				this->label7->Location = System::Drawing::Point(7, 148);
				this->label7->Name = L"label7";
				this->label7->Size = System::Drawing::Size(77, 13);
				this->label7->TabIndex = 4;
				this->label7->Text = L"Defective area";
				// 
				// label6
				// 
				this->label6->AutoSize = true;
				this->label6->Location = System::Drawing::Point(7, 120);
				this->label6->Name = L"label6";
				this->label6->Size = System::Drawing::Size(81, 13);
				this->label6->TabIndex = 3;
				this->label6->Text = L"Type of defects";
				// 
				// label5
				// 
				this->label5->AutoSize = true;
				this->label5->Location = System::Drawing::Point(7, 90);
				this->label5->Name = L"label5";
				this->label5->Size = System::Drawing::Size(74, 13);
				this->label5->TabIndex = 2;
				this->label5->Text = L"No. of defects";
				// 
				// label4
				// 
				this->label4->AutoSize = true;
				this->label4->Location = System::Drawing::Point(7, 63);
				this->label4->Name = L"label4";
				this->label4->Size = System::Drawing::Size(67, 13);
				this->label4->TabIndex = 1;
				this->label4->Text = L"Image Name";
				// 
				// label3
				// 
				this->label3->AutoSize = true;
				this->label3->Location = System::Drawing::Point(61, 21);
				this->label3->Name = L"label3";
				this->label3->Size = System::Drawing::Size(39, 13);
				this->label3->TabIndex = 0;
				this->label3->Text = L"Details";
				// 
				// panel3
				// 
				this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				this->panel3->Controls->Add(this->label1);
				this->panel3->Controls->Add(this->button2);
				this->panel3->Controls->Add(this->button1);
				this->panel3->Location = System::Drawing::Point(89, 115);
				this->panel3->Name = L"panel3";
				this->panel3->Size = System::Drawing::Size(195, 315);
				this->panel3->TabIndex = 8;
				this->panel3->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel3_Paint);
				// 
				// label1
				// 
				this->label1->AutoSize = true;
				this->label1->Location = System::Drawing::Point(33, 21);
				this->label1->Name = L"label1";
				this->label1->Size = System::Drawing::Size(112, 13);
				this->label1->TabIndex = 7;
				this->label1->Text = L"Choose the test image";
				this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
				// 
				// panel4
				// 
				this->panel4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				this->panel4->Controls->Add(this->button3);
				this->panel4->Controls->Add(this->pictureBox1);
				this->panel4->Controls->Add(this->label2);
				this->panel4->Location = System::Drawing::Point(290, 115);
				this->panel4->Name = L"panel4";
				this->panel4->Size = System::Drawing::Size(180, 315);
				this->panel4->TabIndex = 8;
				this->panel4->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel4_Paint);
				// 
				// button3
				// 
				this->button3->Location = System::Drawing::Point(58, 277);
				this->button3->Name = L"button3";
				this->button3->Size = System::Drawing::Size(75, 23);
				this->button3->TabIndex = 4;
				this->button3->Text = L"Next";
				this->button3->UseVisualStyleBackColor = true;
				this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
				// 
				// pictureBox1
				// 
				this->pictureBox1->Location = System::Drawing::Point(12, 46);
				this->pictureBox1->Name = L"pictureBox1";
				this->pictureBox1->Size = System::Drawing::Size(154, 225);
				this->pictureBox1->TabIndex = 3;
				this->pictureBox1->TabStop = false;
				// 
				// label2
				// 
				this->label2->AutoSize = true;
				this->label2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
				this->label2->Location = System::Drawing::Point(42, 21);
				this->label2->Name = L"label2";
				this->label2->Size = System::Drawing::Size(91, 13);
				this->label2->TabIndex = 2;
				this->label2->Text = L"Detected Defects";
				this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
				// 
				// panel5
				// 
				this->panel5->BackColor = System::Drawing::Color::DimGray;
				this->panel5->Location = System::Drawing::Point(-2, -6);
				this->panel5->Name = L"panel5";
				this->panel5->Size = System::Drawing::Size(80, 462);
				this->panel5->TabIndex = 9;
				// 
				// button4
				// 
				this->button4->Location = System::Drawing::Point(29, 192);
				this->button4->Name = L"button4";
				this->button4->Size = System::Drawing::Size(114, 23);
				this->button4->TabIndex = 9;
				this->button4->Text = L"Update in Database";
				this->button4->UseVisualStyleBackColor = true;
				this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
				// 
				// MyForm
				// 
				this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				this->BackColor = System::Drawing::Color::White;
				this->ClientSize = System::Drawing::Size(658, 453);
				this->Controls->Add(this->panel4);
				this->Controls->Add(this->panel1);
				this->Controls->Add(this->panel2);
				this->Controls->Add(this->panel3);
				this->Controls->Add(this->panel5);
				this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
				this->Name = L"MyForm";
				this->Text = L"MyForm";
				this->panel1->ResumeLayout(false);
				this->panel1->PerformLayout();
				this->panel2->ResumeLayout(false);
				this->panel2->PerformLayout();
				this->panel3->ResumeLayout(false);
				this->panel3->PerformLayout();
				this->panel4->ResumeLayout(false);
				this->panel4->PerformLayout();
				(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
				this->ResumeLayout(false);

			}
	#pragma endregion
		private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		}
		private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		}
		private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
		}
		private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e) 
		{
			//system("cd / &  cd Users/SOUJANARI/Downloads/darkflow-master/darkflow-master & python flow --imgdir images/test --model cfg/tiny-yolo-voc_1c.cfg --load -1 --threshold 0.15 --json");
			/*this->Hide();
			MyForm3^ f3 = gcnew MyForm3();
			f3->ShowDialog();*/
			using namespace System::Diagnostics;
			//Process::Start("C:/Users/SOUJANARI/Downloads/darkflow-master/darkflow-master/JSONread.py");

			
			vector<int>tlx;
			vector<int>tly;
			vector<int>brx;
			vector<int>bry;
			vector<int> height, width;
			vector<Rect> rectarray;
			float size;
			float vals;
			{
				//std::experimental::filesystem::path dir("C:\\Users\\SOUJANARI\\Downloads\\darkflow-master\\darkflow-master\\images\\test");
				//std::experimental::filesystem::path file("DSC03821");

				System::String ^path = "C:\\Users\\SOUJANARI\\Downloads\\darkflow-master\\darkflow-master\\images\\test";
				cli::array<System::String ^>^ a = System::IO::Directory::GetFiles(path);

				System::String ^path2 = "C:\\Users\\SOUJANARI\\Downloads\\darkflow-master\\darkflow-master\\images";
				cli::array<System::String ^>^ b = System::IO::Directory::GetFiles(path2, "*.txt");

				System::String ^d = "C:\\Users\\SOUJANARI\\Downloads\\darkflow-master\\darkflow-master\\images\\test\\outputimages\\";

				System::String ^c;
				//cli::array<System::String ^>^ anew = a;
				//cli::array<System::String ^>^ anew2 = a;
				//cli::array<System::String ^>^ anew3 = a;

				//MessageBox::Show(a[0]);

				auto length = a->Length;
				//MessageBox::Show(length.ToString());

				for (int k = 0; k < length;)
				{
					System::String^ localManaged = a[k];
					std::string unmanaged = msclr::interop::marshal_as<std::string>(localManaged);
					MessageBox::Show(a[k]);
					Mat draw2 = imread(unmanaged);

					if (draw2.empty())
					{
						MessageBox::Show("img not opening");
					}
					cv::Size imgsize(3264, 2448);//the dst image size,e.g.100x100
					Mat draw;//dst image
					resize(draw2, draw, imgsize);//resize 
					

					System::String^ localManaged2 = b[k];					

					std::string unmanaged2 = msclr::interop::marshal_as<std::string>(localManaged2);
					ifstream fid(unmanaged2);
					if (!fid.good())
					{
						MessageBox::Show("txt not opening");
					}
					fid >> size;

					MessageBox::Show(localManaged2);
					for (int i = 0; i < size; i++)
					//i = 0;
					//label:
					{
						for (int j = 0; j < 4; j++)
						{
							fid >> vals;
							if (j == 0)
							{
								tlx.push_back(vals);
							}
							if (j == 1)
							{
								tly.push_back(vals);
							}
							if (j == 2)
							{
								brx.push_back(vals);
							}
							if (j == 3)
							{
								bry.push_back(vals);
							}
						}

						width.push_back(abs(brx[i] - tlx[i]));
						height.push_back(abs(bry[i] - tly[i]));
						rectarray.push_back(Rect(tlx[i], tly[i], width[i], height[i]));
					}

					int thresh = 1;
					for (int i = 0; i < size - 1; i++)
					{
						for (int j = i + 1; j > i && j < size;)
						{
							Rect rector = rectarray[i] | rectarray[j];
							Rect rectand = rectarray[i] & rectarray[j];
							float perc = (float(rectand.area()) / float(rector.area()));

							if (perc > thresh)
							{
								rectarray[i] = rector;
								for (int k = j + 1; k < size; k++)
								{
									rectarray[k - 1] = rectarray[k];

								}
								size--;

							}

							else
							{
								j++;
							}
						}
					}

					float rectarea = 0;
					for (int i = 0; i < size; i++)
					{
						rectangle(draw, rectarray[i], Scalar(200, 200, 0), 10);
						rectarea = rectarray[i].area() + rectarea;
					}

					float wholearea = draw.size[0] * draw.size[1];
					perc = (rectarea / wholearea) * 100;
					cin.get();
					StringWriter^ sw = gcnew StringWriter();

					//sw->Write("The percentage of area is, {0}.", perc);
					//MessageBox::Show(sw->ToString(), "Poetry", MessageBoxButtons::OK);


					//MessageBox::Show("The percentage of defect is" + perc);

					//namedWindow("rectangles", WINDOW_NORMAL);
					//imshow("rectangles", draw);

					//string newstr = a[i]->ToString();
					//array<wchar_t>^ MyChar = { ".", "J", "P", "G" };
					//System::String^ NewString = (a[i]->TrimEnd(MyChar));
				
					//MessageBox::Show(a[i]);
					//MessageBox::Show(anew[i]);
					//MessageBox::Show(a[i]);

					Char charsToTrim = {'G'};
					a[k] = a[k]->Trim(charsToTrim);	
					//MessageBox::Show(a[i]);

					charsToTrim = {'P'};
					a[k] = a[k]->Trim(charsToTrim);
					
					charsToTrim = {'J'};
					a[k] = a[k]->Trim(charsToTrim); 

					charsToTrim = { '.' };
					a[k] = a[k]->Trim(charsToTrim);
					

					/*anew2[i] = anew[i] + "txt";
					
					
					//System::String^ localManaged3 = anew[i];
					anew3[i] = anew[i] + "new.JPG";
					MessageBox::Show(a[i]);*/
					//size_t lastindex = a[i].find_last_of(".");
					//string rawname = fullname.substr(0, lastindex);

					//a[k] = a[k] + "new.JPG";
					c = d + k + "new.JPG";
					

					System::String^ localManaged3 = c;
					std::string unmanaged3 = msclr::interop::marshal_as<std::string>(localManaged3);
					imwrite(unmanaged3, draw);

					System::String^ filenamemanaged = a[k];
					std::string filenamestring = msclr::interop::marshal_as<std::string>(filenamemanaged);
					
					size--;
					namedWindow("rectangles", WINDOW_NORMAL);
					imshow("rectangles", draw);

					this->pictureBox1->Size::set(Drawing::Size(300, 200));
					this->pictureBox1->SizeMode = PictureBoxSizeMode::StretchImage;
					//MessageBox::Show(a[i]);
					this->pictureBox1->Image = Image::FromFile(c);

					//Mat img;
					//img = imread(openFileDialog1->FileName, CV_LOAD_IMAGE_COLOR);

					/*System::Drawing::Graphics^ graphics = pictureBox1->CreateGraphics();
					System::IntPtr ptr(draw.ptr());
					System::Drawing::Bitmap^ b = gcnew System::Drawing::Bitmap(draw.cols, draw.rows, draw.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);
					MessageBox::Show("OK");
					System::Drawing::RectangleF rect(0, 0, pictureBox1->Width, pictureBox1->Height);
					graphics->DrawImage(b, rect);*/

					//this->pictureBox1->Image = draw;
					this->textBox1->Text = gcnew System::String(filenamestring.c_str());
					this->textBox3->Text = gcnew System::String(size.ToString());
					this->textBox5->Text = gcnew System::String(perc.ToString());

					/*if (buttonClicked == true) 
					{
						i++;
						MessageBox::Show(i.ToString());
						//goto label;
					}*/
					//MessageBox::Show("Do you want to continue?", "Notification", MessageBoxButtons::OKCancel, MessageBoxIcon::Asterisk);
					if (MessageBox::Show("Do you want to continue?", "My Application", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes)
					{
						k++;
						//MessageBox::Show(i.ToString());
						//Application::Exit();
					}

				}
			}

		}
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) 
	{
	}
private: System::Void pictureBox1_Click_1(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void folderBrowserDialog1_HelpRequest(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void panel1_Paint_1(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
}
private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) 
{	

}
private: System::Void panel4_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
}
private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void label8_Click(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void pictureBox2_Click(System::Object^  sender, System::EventArgs^  e) 
{
}
private: System::Void panel3_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
}
private: System::Void textBox1_TextChanged_1(System::Object^  sender, System::EventArgs^  e) 
{

}
private: System::Void textBox3_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}
private: System::Void textBox5_TextChanged(System::Object^  sender, System::EventArgs^  e) {
}

private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) 
{
	buttonClicked = true;
}
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
}
};
}
