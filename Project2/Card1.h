#pragma once

#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <Windows.h>

namespace Card {

	public ref class Card
	{
	private:
		System::Collections::Generic::List<System::String^> num;
		System::Collections::Generic::List<System::String^> deck;
	public:
		System::Collections::Generic::List<System::String^> putCard;

		Card() {
			for (int i = 1; i <= 10; i++)
				num.Add(i.ToString());
			num.Add("J"); num.Add("Q"); num.Add("K");

			System::String^ s = "";
			for (int i = 0; i < 4; i++) {
				switch (i)
				{
				case 0: s = "a"; break;
				case 1: s = "b"; break;
				case 2: s = "c"; break;
				case 3: s = "d"; break;
				}
				for (int j = 0; j < 13; j++) {
					deck.Add(s + num[j]);
				}
			}

			shuffle();

			putCard.Add(deck[deck.Count - 1]);
			deck.RemoveAt(deck.Count - 1);
		}

		void shuffle() {
			std::srand((unsigned int)time(0));

			System::String^ temp;
			int idx1, idx2;

			for (int i = 0; i < 100; i++) {
				idx1 = rand() % deck.Count;
				idx2 = rand() % deck.Count;
				temp = deck[idx1];
				deck[idx1] = deck[idx2];
				deck[idx2] = temp;
			}
		}

		System::String^ getPutLast() {
			return putCard[putCard.Count - 1];
		}

		System::String^ division() {
			System::String^ s = deck[deck.Count - 1];
			deck.RemoveAt(deck.Count - 1);
			return s;
		}

		System::String^ pop() {
			if (deck.Count < 1) {
				System::String^ lastCard = getPutLast();
				putCard.RemoveAt(putCard.Count - 1);

				for each (System::String ^ var in putCard)
				{
					deck.Add(var);
				}
				putCard.Clear();
				putCard.Add(deck[deck.Count - 1]);

				shuffle();
			}

			System::String^ s = deck[deck.Count - 1];
			deck.RemoveAt(deck.Count - 1);
			return s;
		}

		int getLength() {
			return deck.Count;
		}

		bool checkJack(System::String^ c) {
			if (c[c->Length - 1] == 'J') {
				return true;
			}
			return false;
		}
		bool checkQueen(System::String^ c) {
			if (c[c->Length - 1] == 'Q') {
				return true;
			}
			return false;
		}
		bool checkKing(System::String^ c) {
			if (c[c->Length - 1] == 'K') {
				return true;
			}
			return false;
		}
	};

	public ref class Player {
	protected:
		System::Collections::Generic::List<System::String^> card;
		Card^ c;
	public:
		int attack;

		Player() { }
		Player(Card^ c) {
			this->c = c;
			for (int i = 0; i < 7; i++) {
				card.Add(c->division());
			}
			attack = 1;
		}

		int getLength() {
			return card.Count;
		}

		System::String^ getCard(int i) {
			return card[i];
		}

		void put(System::String^ put_card) {    // ³»±â

		}

		void take() {   // ¸Ô±â

		}

		int findCard(System::String^ s) {
			for (int i = 0; i < card.Count; i++) {
				if (card[i] == s) {
					return i;
				}
			}
			return -1;
		}

		void checkAttack(System::String^ c) {
			if (c[c->Length - 1] == '1')
				if (c[0] == 'a')
					attack = 5;
				else
					attack = 3;
			else if (c[c->Length - 1] == '2')
				attack = 2;
			else
				attack = 1;
		}
		bool isAttack(System::String^ c) {
			if (c[c->Length - 1] == '1' || c[c->Length - 1] == '2')
				return true;
			else
				return false;
		}
	};

	public ref class Person : public Player {
	public:
		Person() : Player() { }
		Person(Card^ c) : Player(c) { }

		bool put(System::String^ put_card, int attack) {
			if (attack > 1) {
				if (!isAttack(put_card))
					return false;
			}

			if ((put_card[0] == c->getPutLast()[0])) {
				c->putCard.Add(put_card);
				card.RemoveAt(findCard(put_card));
				checkAttack(put_card);
				return true;
			}
			else if ((put_card[put_card->Length - 1] == c->getPutLast()[c->getPutLast()->Length - 1])) {
				c->putCard.Add(put_card);
				card.RemoveAt(findCard(put_card));
				checkAttack(put_card);
				return true;
			}
			return false;
		}

		void take() {
			card.Add(c->pop());
		}
	};

	public ref class Computer : public Player {
	public:
		int lastIndex;

		Computer() : Player() { }
		Computer(Card^ c) : Player(c) { }

		bool put(System::String^ put_card) {
			if (put_card == "") {
				return false;
			}

			lastIndex = findCard(put_card);

			c->putCard.Add(put_card);
			card.RemoveAt(findCard(put_card));

			checkAttack(put_card);

			return true;
		}

		void take() {
			card.Add(c->pop());
		}

		System::String^ find_card(int attack) {
			System::Collections::Generic::List<System::String^> put_cards;
			System::String^ putc = c->putCard[c->putCard.Count - 1];
			for (int i = 0; i < card.Count; i++) {
				System::String^ s = card[i];
				if (s[0] == putc[0] || s[s->Length - 1] == putc[putc->Length - 1]) {
					put_cards.Add(s);
				}
			}

			if (put_cards.Count > 0) {
				int i = rand() % put_cards.Count;
				if (attack > 1) {
					if (!isAttack(put_cards[i]))
						return "";
				}
				
				return put_cards[i];
			}
			else
				return "";
		}
	};
}


