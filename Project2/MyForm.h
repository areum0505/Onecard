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
	/// MyForm에 대한 요약입니다.
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: 생성자 코드를 여기에 추가합니다.
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
		/// 사용 중인 모든 리소스를 정리합니다.
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
	private: System::Windows::Forms::ToolStripMenuItem^ 통계ToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ 도움말ToolStripMenuItem;

	private:
		/// <summary>
		/// 필수 디자이너 변수입니다.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 디자이너 지원에 필요한 메서드입니다. 
		/// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->cumLabel = (gcnew System::Windows::Forms::Label());
			this->myTurn = (gcnew System::Windows::Forms::Label());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->통계ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->도움말ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// cumLabel
			// 
			this->cumLabel->AutoSize = true;
			this->cumLabel->BackColor = System::Drawing::Color::Transparent;
			this->cumLabel->Font = (gcnew System::Drawing::Font(L"나눔바른고딕", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
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
			this->myTurn->Font = (gcnew System::Drawing::Font(L"나눔바른고딕", 13, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->myTurn->Location = System::Drawing::Point(12, 346);
			this->myTurn->Name = L"myTurn";
			this->myTurn->Size = System::Drawing::Size(184, 26);
			this->myTurn->TabIndex = 2;
			this->myTurn->Text = L"당신의 차례입니다.";
			// 
			// menuStrip1
			// 
			this->menuStrip1->BackColor = System::Drawing::SystemColors::ControlLight;
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->통계ToolStripMenuItem,
					this->도움말ToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(750, 28);
			this->menuStrip1->TabIndex = 3;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// 통계ToolStripMenuItem
			// 
			this->통계ToolStripMenuItem->Name = L"통계ToolStripMenuItem";
			this->통계ToolStripMenuItem->Size = System::Drawing::Size(53, 24);
			this->통계ToolStripMenuItem->Text = L"통계";
			this->통계ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::통계ToolStripMenuItem_Click);
			// 
			// 도움말ToolStripMenuItem
			// 
			this->도움말ToolStripMenuItem->Name = L"도움말ToolStripMenuItem";
			this->도움말ToolStripMenuItem->Size = System::Drawing::Size(68, 24);
			this->도움말ToolStripMenuItem->Text = L"도움말";
			this->도움말ToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::도움말ToolStripMenuItem_Click);
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
			this->Text = L"원카드";
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
		System::Windows::Forms::Button^ btn = (System::Windows::Forms::Button^)sender;	// 클릭한 버튼

		// 버튼의 이름("1", "2", "3"...)을 int로
		std::string s = "";
		int i = 0;
		MarshalString(btn->Name, s);
		std::stringstream ssInt(s);
		ssInt >> i;

		if (!order) return;		// 내 순서가 아니면 return;

		order = false;			// 내 순서이니 다음 순서는 ai라서 false로
		this->myTurn->Visible = false;

		if (player2.Count > 0 && p2->put(p2->getCard(i), cum_card)) {	// 내 카드가 1장 이상이고 카드를 낼 수 있는 경우
			playPutSound();	// 카드 내는 효과음

			// 누적 카드 더하기
			if (cum_card == 1) {
				cum_card += checkAttack(card->getPutLast()) - 1;
				if (cum_card != 1)
					cumLabel->Text = "X " + cum_card;
			}
			else {
				cum_card += checkAttack(card->getPutLast());
				cumLabel->Text = "X " + cum_card;
			}

			// 버튼과 버튼리스트에서 버튼 제거
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

		if (card->checkJack(card->getPutLast()) || card->checkKing(card->getPutLast())) {	// 낸 카드가 J이나 K면
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

		cum_card = 1;		// 카드를 먹었으니 누적 카드는 1장

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

		if (card->checkJack(card->getPutLast()) || card->checkKing(card->getPutLast())) {	// 낸 카드가 J이나 K면
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
			writeResult("패");
			if (MessageBox::Show("Computer 승리") == System::Windows::Forms::DialogResult::OK) {
				start = true;
				Application::Restart();
			}
		}
		else if (player2.Count <= 0) {
			writeResult("승");
			if (MessageBox::Show("Player 승리") == System::Windows::Forms::DialogResult::OK) {
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
			if (MessageBox::Show("종료하면 패배로 기록됩니다.\n종료하시겠습니까?", "게임 종료", MessageBoxButtons::YesNo) ==
				System::Windows::Forms::DialogResult::Yes) {
				writeResult("패");
			}
			else {
				e->Cancel = true;
			}
		}
	}
	private: System::Void 통계ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		int gameCount = 0, winCount = 0, con_vic = 0, con_def = 0;
		bool win, preWin;
		float rate = 0.f;

		std::string result;

		std::ifstream fin("statistics.txt");
		while (fin >> result) {
			gameCount++;

			if (result == "승") {
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
				if (result == "승")
					con_vic++;
				else
					con_def++;
			}

			preWin = win;
		}

		fin.close();

		rate = ((float)winCount / (float)gameCount) * 100.f;
		MessageBox::Show("     게임 횟수 : " + gameCount + "     \n     이긴 게임 횟수 : " + winCount + "     \n     승률 : "
			+ rate + "%     \n     연승 기록 : " + con_vic + "     \n     연패 기록 : " + con_def, "통계");
	}
	private: System::Void 도움말ToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("갖고 있는 카드를 모두 버리세요.\n - 이전에 나온 카드와 같은 숫자나 같은 모양의 카드를 내세요." + 
			"\n - 없을 경우 덱에서 카드를 가져옵니다.\n\n특수카드\n - 2 : 상대방에게 2장 공격합니다.\n" + 
			" - A : 상대방에게 3장 공격합니다.(♠는 5장)\n - J : 다음 사람의 턴을 건너뜁니다.\n - Q : 방향을 전환합니다.\n" + 
			" - K : 카드를 한 장 더 냅니다.", "도움말");
	}
};
}

