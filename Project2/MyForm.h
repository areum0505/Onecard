#pragma once

#include "Card1.h"
#include <string>
#include <sstream>
#include <time.h>
#include <fstream>
#include <iostream>

namespace Project2 {
	using namespace System;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm�� ���� ����Դϴ�.
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: ������ �ڵ带 ���⿡ �߰��մϴ�.
			//
			FormClosing += gcnew FormClosingEventHandler(this, &MyForm::MyForm_FormClosing);
		}

		void MarshalString(System::String^ s, std::string& os) {
			using namespace Runtime::InteropServices;
			const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
			os = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
		}

	protected:
		/// <summary>
		/// ��� ���� ��� ���ҽ��� �����մϴ�.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Collections::Generic::List< System::Windows::Forms::Label^> player1;
			 System::Collections::Generic::List< System::Windows::Forms::Button^> player2;
			 System::Windows::Forms::Label^ cardLabel;
			 System::Windows::Forms::Button^ cardButton;

			 bool order = true;
			 int cum_card = 1;
			 bool start = true;

			 Card::Card^ card = gcnew Card::Card();
			 Card::Computer^ p1 = gcnew Card::Computer(card);
			 Card::Person^ p2 = gcnew Card::Person(card);

	private: System::Windows::Forms::Label^ cumLabel;
	private: System::Windows::Forms::Label^ myTurn;

	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ ���ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ ����ToolStripMenuItem;

	private:
		/// <summary>
		/// �ʼ� �����̳� �����Դϴ�.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����̳� ������ �ʿ��� �޼����Դϴ�. 
		/// �� �޼����� ������ �ڵ� ������� �������� ������.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->cumLabel = (gcnew System::Windows::Forms::Label());
			this->myTurn = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->���ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->����ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// cumLabel
			// 
			this->cumLabel->AutoSize = true;
			this->cumLabel->BackColor = System::Drawing::Color::Transparent;
			this->cumLabel->Font = (gcnew System::Drawing::Font(L"�����ٸ����", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->cumLabel->Location = System::Drawing::Point(530, 260);
			this->cumLabel->Name = L"cumLabel";
			this->cumLabel->Size = System::Drawing::Size(0, 26);
			this->cumLabel->TabIndex = 1;
			this->cumLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// myTurn
			// 
			this->myTurn->AutoSize = true;
			this->myTurn->BackColor = System::Drawing::Color::Transparent;
			this->myTurn->Font = (gcnew System::Drawing::Font(L"�����ٸ����", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->myTurn->Location = System::Drawing::Point(12, 346);
			this->myTurn->Name = L"myTurn";
			this->myTurn->Size = System::Drawing::Size(184, 26);
			this->myTurn->TabIndex = 2;
			this->myTurn->Text = L"����� �����Դϴ�.";
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::ControlLight;
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->���ToolStripMenuItem,
					this->����ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(750, 28);
			this->menuStrip1->TabIndex = 3;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// ���ToolStripMenuItem
			// 
			this->���ToolStripMenuItem->Name = L"���ToolStripMenuItem";
			this->���ToolStripMenuItem->Size = System::Drawing::Size(53, 24);
			this->���ToolStripMenuItem->Text = L"���";
			this->���ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::���ToolStripMenuItem_Click);
			// 
			// ����ToolStripMenuItem
			// 
			this->����ToolStripMenuItem->Name = L"����ToolStripMenuItem";
			this->����ToolStripMenuItem->Size = System::Drawing::Size(68, 24);
			this->����ToolStripMenuItem->Text = L"����";
			this->����ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::����ToolStripMenuItem_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->ClientSize = System::Drawing::Size(750, 540);
			this->Controls->Add(this->myTurn);
			this->Controls->Add(this->cumLabel);
			this->Controls->Add(this->menuStrip1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"��ī��";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		// ai
		int xPos = 230, yPos = 30;
		for (int x = 0; x < p1->getLength(); x++)
		{
			player1.Add(gcnew Label);
			player1[x]->Location = Point(xPos, yPos);
			player1[x]->Name = x.ToString();
			player1[x]->Size = System::Drawing::Size(90, 125);
			player1[x]->Image = gcnew Bitmap("images/1.jpg");
			this->Controls->Add(player1[x]);
			xPos += 20;
		}

		// person
		xPos = 12; yPos = 305;
		int cardWidth = 630 / p2->getLength();
		for (int x = 0; x < p2->getLength(); x++)
		{
			player2.Add(gcnew Button());
			player2[x]->Location = Point(xPos, yPos);
			player2[x]->Name = x.ToString();
			player2[x]->Click += gcnew System::EventHandler(this, &MyForm::button_Put);
			player2[x]->BackgroundImage = gcnew Bitmap("images/" + p2->getCard(x) + ".jpg");
			player2[x]->BackgroundImageLayout = Windows::Forms::ImageLayout::Zoom;
			this->Controls->Add(player2[x]);
			if (p2->getLength() <= 7) {
				player2[x]->Size = System::Drawing::Size(90, 125);
				xPos += 90;
			}
			else {
				player2[x]->Size = System::Drawing::Size(cardWidth, (int)(cardWidth / 0.72));
				xPos += cardWidth;
			}
		}

		cardLabel = gcnew Label();
		cardLabel->Location = Point(250, 170);
		cardLabel->Name = "cardLabel";
		cardLabel->Size = System::Drawing::Size(90, 125);
		cardLabel->Image = gcnew Bitmap("images/" + card->getPutLast() + ".jpg");
		this->Controls->Add(cardLabel);

		cardButton = gcnew Button();
		cardButton->Location = Point(365, 170);
		cardButton->Name = "cardButton";
		cardButton->Click += gcnew System::EventHandler(this, &MyForm::button_Take);
		cardButton->Size = System::Drawing::Size(90, 125);
		cardButton->Image = gcnew Bitmap("images/1.jpg");
		this->Controls->Add(cardButton);
	}

	private: System::Void button_Put(System::Object^ sender, System::EventArgs^ e)
	{
		System::Windows::Forms::Button^ btn = (System::Windows::Forms::Button^)sender;	// Ŭ���� ��ư

		// ��ư�� �̸�("1", "2", "3"...)�� int��
		std::string s = "";
		int i = 0;
		MarshalString(btn->Name, s);
		std::stringstream ssInt(s);
		ssInt >> i;

		if (!order) return;		// �� ������ �ƴϸ� return;

		order = false;			// �� �����̴� ���� ������ ai�� false��
		this->myTurn->Visible = false;

		if (player2.Count > 0 && p2->put(p2->getCard(i), cum_card)) {	// �� ī�尡 1�� �̻��̰� ī�带 �� �� �ִ� ���
			playPutSound();	// ī�� ���� ȿ����

			// ���� ī�� ���ϱ�
			if (cum_card == 1) {
				cum_card += checkAttack(card->getPutLast()) - 1;
				if (cum_card != 1)
					cumLabel->Text = "X " + cum_card;
			}
			else {
				cum_card += checkAttack(card->getPutLast());
				cumLabel->Text = "X " + cum_card;
			}

			// ��ư�� ��ư����Ʈ���� ��ư ����
			this->Controls->Remove(player2[i]);
			player2.RemoveAt(i);
		}
		else if (player2.Count > 0) {
			order = true;
			myTurn->Visible = true;
			return;
		}

		start = false;

		int xPos = 12, yPos = 305;
		for (int i = 0; i < p2->getLength(); i++) {
			player2[i]->Location = Point(xPos, yPos);
			player2[i]->Name = i.ToString();
			player2[i]->BackgroundImage = gcnew Bitmap("images/" + p2->getCard(i) + ".jpg");
			if (p2->getLength() <= 7) {
				player2[i]->Size = System::Drawing::Size(90, 125);
				xPos += 90;
			}
			else {
				int cardWidth = 630 / p2->getLength();
				player2[i]->Size = System::Drawing::Size(cardWidth, (int)(cardWidth / 0.72));
				xPos += cardWidth;
			}
		}

		cardLabel->Image = gcnew Bitmap("images/" + card->getPutLast() + ".jpg");

		checkWin();

		if (card->checkJack(card->getPutLast()) || card->checkKing(card->getPutLast())) {	// �� ī�尡 J�̳� K��
			order = true;
			myTurn->Visible = true;
			return;
		}

		Delay(1000);

		AI_put();
	}

	private: System::Void button_Take(System::Object^ sender, System::EventArgs^ e)
	{
		if (!order) return;

		start = false;

		playTakeSound();

		order = false;
		this->myTurn->Visible = false;

		cumLabel->Text = "";

		for (int i = 1; i <= cum_card; i++) {
			p2->take();

			int index = player2.Count;
			player2.Add(gcnew Button());
			player2[index]->Name = index.ToString();
			player2[index]->Click += gcnew System::EventHandler(this, &MyForm::button_Put);
			player2[index]->BackgroundImage = gcnew Bitmap("images/" + p2->getCard(index) + ".jpg");
			player2[index]->BackgroundImageLayout = Windows::Forms::ImageLayout::Zoom;
			this->Controls->Add(player2[index]);
		}

		cum_card = 1;		// ī�带 �Ծ����� ���� ī��� 1��

		makeCardButton();

		Delay(1000);

		AI_put();
	}

	private: void makeCardButton() {
		int xPos = 12, yPos = 305;
		int cardWidth = 630 / p2->getLength();
		for (int x = 0; x < p2->getLength(); x++)
		{
			player2[x]->Location = Point(xPos, yPos);
			if (p2->getLength() <= 7) {
				player2[x]->Size = System::Drawing::Size(90, 125);
				xPos += 90;
			}
			else {
				player2[x]->Size = System::Drawing::Size(cardWidth, (int)(cardWidth / 0.72));
				xPos += cardWidth;
			}
		}
	}

	private:void AI_put() {
		if (player1.Count > 0 && p1->put(p1->find_card(cum_card))) {
			playPutSound();

			if (cum_card == 1) {
				cum_card += checkAttack(card->getPutLast()) - 1;
				if (cum_card != 1)
					cumLabel->Text = "X " + cum_card;
			}
			else {
				cum_card += checkAttack(card->getPutLast());
				cumLabel->Text = "X " + cum_card;
			}

			this->Controls->Remove(player1[p1->lastIndex]);
			player1.RemoveAt(p1->lastIndex);
		}
		else if (player1.Count > 0) {
			AI_take();
			return;
		}

		int xPos = 230, yPos = 30;
		for (int x = 0; x < p1->getLength(); x++)
		{
			player1[x]->Location = Point(xPos, yPos);
			player1[x]->Name = x.ToString();
			player1[x]->Image = gcnew Bitmap("images/1.jpg");
			xPos += 20;
		}

		cardLabel->Image = gcnew Bitmap("images/" + card->getPutLast() + ".jpg");

		checkWin();

		if (card->checkJack(card->getPutLast()) || card->checkKing(card->getPutLast())) {	// �� ī�尡 J�̳� K��
			order = false;
			this->myTurn->Visible = false;

			Delay(1000);

			AI_put();
		}

		order = true;
		myTurn->Visible = true;
	}
	private: void AI_take() {
		playTakeSound();

		cumLabel->Text = "";

		for (int i = 1; i <= cum_card; i++) {
			p1->take();

			int index = player1.Count;
			player1.Add(gcnew Label());
			player1[index]->Name = index.ToString();
			player1[index]->Location = Point(0, -125);
			player1[index]->Size = System::Drawing::Size(90, 125);
			player1[index]->Image = gcnew Bitmap("images/1.jpg");
			this->Controls->Add(player1[index]);
		}

		cum_card = 1;

		int xPos = 230, yPos = 30;
		for (int x = 0; x < player1.Count; x++)
		{
			player1[x]->Location = Point(xPos, yPos);
			xPos += 20;
		}

		order = true;
		this->myTurn->Visible = true;
	}

	private: void checkWin() {
		if (player1.Count <= 0) {
			writeResult("��");
			if (MessageBox::Show("Computer �¸�") == System::Windows::Forms::DialogResult::OK) {
				start = true;
				Application::Restart();
			}
		}
		else if (player2.Count <= 0) {
			writeResult("��");
			if (MessageBox::Show("Player �¸�") == System::Windows::Forms::DialogResult::OK) {
				start = true;
				Application::Restart();
			}
		}
	}
	private: void writeResult(std::string result) {
		std::ofstream fout("statistics.txt", std::ios::app);
		fout << result << std::endl;
		fout.close();
	}

	private: int checkAttack(System::String^ c) {
		if (c[c->Length - 1] == '1')
			if (c[0] == 'a')
				return 5;
			else
				return 3;
		else if (c[c->Length - 1] == '2')
			return 2;
		else
			return 1;
	}

	public: static DateTime Delay(int MS) {
		DateTime thisMoment = DateTime::Now;
		TimeSpan^ duration = gcnew TimeSpan(0, 0, 0, 0, MS);
		DateTime afterWards = thisMoment.Add((TimeSpan)duration);

		while (afterWards >= thisMoment) {
			System::Windows::Forms::Application::DoEvents();
			thisMoment = DateTime::Now;
		}

		return DateTime::Now;
	}

	private: void playPutSound() {
		System::Media::SoundPlayer^ player = gcnew System::Media::SoundPlayer("images/put_sound.wav");
		player->Play();
	}
	private: void playTakeSound() {
		System::Media::SoundPlayer^ player = gcnew System::Media::SoundPlayer("images/take_sound.wav");
		player->Play();
	}

	private: void MyForm_FormClosing(System::Object^ sender, FormClosingEventArgs^ e) {
		if (!start) {
			if (MessageBox::Show("�����ϸ� �й�� ��ϵ˴ϴ�.\n�����Ͻðڽ��ϱ�?", "���� ����", MessageBoxButtons::YesNo) ==
				System::Windows::Forms::DialogResult::Yes) {
				writeResult("��");
			}
			else {
				e->Cancel = true;
			}
		}
	}
	private: System::Void ���ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		int gameCount = 0, winCount = 0, con_vic = 0, con_def = 0;
		bool win, preWin;
		float rate = 0.f;

		std::string result;

		std::ifstream fin("statistics.txt");
		while (fin >> result) {
			gameCount++;

			if (result == "��") {
				winCount++;
				win = true;
			}
			else {
				win = false;
			}

			if (gameCount > 1 && win && preWin)
				con_vic++;
			else if (gameCount > 1 && !win && !preWin)
				con_def++;
			else if (gameCount == 1) {
				if (result == "��")
					con_vic++;
				else
					con_def++;
			}

			preWin = win;
		}

		fin.close();

		rate = ((float)winCount / (float)gameCount) * 100.f;
		MessageBox::Show("     ���� Ƚ�� : " + gameCount + "     \n     �̱� ���� Ƚ�� : " + winCount + "     \n     �·� : "
			+ rate + "%     \n     ���� ��� : " + con_vic + "     \n     ���� ��� : " + con_def, "���");
	}
	private: System::Void ����ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("���� �ִ� ī�带 ��� ��������.\n - ������ ���� ī��� ���� ���ڳ� ���� ����� ī�带 ������." + 
			"\n - ���� ��� ������ ī�带 �����ɴϴ�.\n\nƯ��ī��\n - 2 : ���濡�� 2�� �����մϴ�.\n" + 
			" - A : ���濡�� 3�� �����մϴ�.(���� 5��)\n - J : ���� ����� ���� �ǳʶݴϴ�.\n - Q : ������ ��ȯ�մϴ�.\n" + 
			" - K : ī�带 �� �� �� ���ϴ�.", "����");
	}
};
}

