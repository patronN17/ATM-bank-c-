#pragma once
#include <string>
#include <iostream>

/*
TODO
Сделать проверку пинкодов
Рандомизировать номер счёта в конструкторе(генерируем по цифре и добавляем к строке).
*/
using namespace std;

class ATM
{
private:
	double balance; //Баланс
	string bankAccount; //Банковский счёт
	string name; //Имя человека
	int pin;

public:
	// Конструктор - ввод человеческой информации :
	ATM() {
		cout << "Введи своё имя: ";
		cin >> name;

		cout << "Введи номер счёта: ";
		cin >> bankAccount;

		cout << "Задайте пинкод: ";
		cin >> pin;
	}

	void minMoney() {


	}

	void maxMoney() {

	}

	//Большую сумму или маленькую надо снять?
	void chooseMoney() {
		int naminal;
		cout << "Какими купюрами выдать сумму?" << "\n1 - мелкими" << "\n2 - крупными" << endl;

		while (true)
			switch (naminal)
			{
			case 1:
				minMoney();

			case 2:
				maxMoney();

			default:
				cout << "Введено неверное значение, если хотите выйти - введите 0";
				if (naminal == 0)
				{
					break;
				}
			}
	}

	//Вывод банковской информации о человеке:
	void showData() {
		cout << "Имя: " << name << "\nНомер счёта: " << bankAccount << "\nБаланс: " << balance << endl;
	}

	//Внесение денег на карту:
	void deposit() {
		int money;
		cout << "Введите сумму, которую хотите внести: ";
		cin >> money;
		balance += money;
	}

	//Информация о правильности купюр:
	void information() {
		cout << "Верные купюры для снятия: 50, 100, 500, 1000, 5000";
	}

	//Вывод деньги с карты:
	void withDraw() {

		int money;

		while (true)
		{
			cout << "Введите количество вынесения денег: ";
			cin >> money;

			if (balance > money && money % 50 == 0) {
				balance -= money;
				break;
			}
			if (money % 50 != 0) {
				cout << "Введена неверная сумма\t";
				information();
			}
			else {
				cout << "Недостаточный баланс\t";
				showBalance();
			}
		}
	}

	//Показывает текущий баланс пользователя:
	void showBalance() {
		cout << "Текущий баланс: " << balance << endl;
	}

	void checkPin() {

	}

	//Какие действия можно сделать с деньгами:
	void showOptions() {
		int option;

		cout << "Выберите цифру: " << "\n1 - Показать информацию обо мне" << "\n2 - Внести деньги" << "\n3 - Снять деньги" << "\n4 - Баланс денег";
		cin >> option;

		while (true)
			switch (option)
			{
			case 1:
				showData();

			case 2:
				deposit();

			case 3:
				withDraw();

			case 4:
				showBalance();

			default:
				cout << "Введено неверное значение, если хотите выйти - введите 0";
				if (option == 0)
				{
					break;
				}
			}

	}
};

int main()
{
	setlocale(LC_ALL, "rus");
	ATM atm;
	return 0;
}