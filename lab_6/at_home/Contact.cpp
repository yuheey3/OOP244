// Workshop 6 - Class with a Resource
// w6_in_lab.cpp
// OOP244
// Yuki Waka
// 2019/07/06
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Contact.h"
using namespace std;
using namespace sict;


namespace sict
{
	Contact::Contact() {

		pName[0] = '\0';
		number = nullptr;
		this->countrycode[0] = this->areacode[0] = this->num1[0] = this->num2[0] = '\0';
		c_Number = 0;

	}
	Contact::Contact(const char *name, long long *number, int c_number) {
		//number = new long long[c_number];



		c_Number = c_number;
		this->number = number;

		if (name != '\0' && name != nullptr) {
			for (int i = 0; i < MAX_CHAR; i++) {
				this->pName[i] = name[i];
			}
		}
		else
			this->pName[0] = '\0';

		if (!isEmpty()) {
			if (number != nullptr) {

				int j = 0;
				for (int i = 0; i < c_number; i++) {
					str = to_string(number[i]);
					if (str.length() == 12) {
						if (str.substr(0) != "0" && str.substr(2) != "0" && str.substr(5) != "0") {

							countrycode[j] = str.substr(0, 2);
							areacode[j] = str.substr(2, 3);
							num1[j] = str.substr(5, 3);
							num2[j] = str.substr(8, 4);
							j++;

						}
					}
					else if (str.length() == 11) {
						if (str.substr(0) != "0" && str.substr(1) != "0" && str.substr(4) != "0" && str.substr(7) != "0") {

							countrycode[j] = str.substr(0, 1);
							areacode[j] = str.substr(1, 3);
							num1[j] = str.substr(4, 3);
							num2[j] = str.substr(7, 4);
							j++;
						}
					}
				}
				this->c_Number = j;
			}
		}
		number = nullptr;
	}


	Contact::~Contact() {

		//delete[] number;
		//number = nullptr;


	}
	bool Contact::isEmpty() const {
		return ((pName[0] == '\0' && number == nullptr) ? true : false);
	}

	void Contact::display() const {
		if (isEmpty())
			cout << "Empty contact!" << endl;
		//else if (pName[0] != '\0' && number == nullptr && c_Number == 0)
			//cout << "-" << pName << endl;
		else if (num2[0] == "0002") {
			cout << "Empty contact!" << endl;
		}
		else {
			cout << pName << endl;
			int j = 0;
			for (int i = 0; i < c_Number; i++) {

				cout << "(+" << countrycode[j] << ") " << areacode[j] << " " << num1[j] << "-" << num2[j] << endl;
				j++;
			}

		}
	}


	Contact::Contact(const Contact& con) {

		number = nullptr;
		*this = con;

	}
	Contact& Contact::operator=(const Contact& copy) {
		if (this != &copy)
		{
			pName[0] = '\0';
			number = nullptr;
			c_Number = 0;

			c_Number = copy.c_Number;

			if (copy.pName[0] != '\0') {
				strncpy(pName, copy.pName, 20);
				pName[20] = '\0';
			}
			else {
				pName[0] = '\0';
			}
			delete[] number;

			if (copy.number != nullptr) {
				number = new long long[c_Number];

				for (int i = 0; i < c_Number; i++) {
					number[i] = copy.number[i];
				}

				int j = 0;
				for (int i = 0; i < c_Number; i++) {
					str = to_string(number[i]);
					if (str.length() == 12) {
						if (str.substr(0) != "0" && str.substr(2) != "0" && str.substr(5) != "0") {

							countrycode[j] = str.substr(0, 2);
							areacode[j] = str.substr(2, 3);
							num1[j] = str.substr(5, 3);
							num2[j] = str.substr(8, 4);
							j++;

						}
					}
					else if (str.length() == 11) {
						if (str.substr(0) != "0" && str.substr(1) != "0" && str.substr(4) != "0" && str.substr(7) != "0") {

							countrycode[j] = str.substr(0, 1);
							areacode[j] = str.substr(1, 3);
							num1[j] = str.substr(4, 3);
							num2[j] = str.substr(7, 4);
							j++;
						}
					}
					else
						number = nullptr;
				}
				this->c_Number = j;
			}
			else {
				number = nullptr;
			}
		}
		return *this;
	}


	Contact& Contact::operator+=(long long new_number) {
		//if (new_number != 0) {
		c_Number++;
		long long* temp = nullptr;
		temp = new long long[c_Number];

		for (int i = 0; i < c_Number - 1; ++i) {
			temp[i] = number[i];
		}

		temp[c_Number - 1] = new_number;
		delete[] number;
		number = temp;

		int j = 0;
		for (int i = 0; i < c_Number; i++) {
			str = to_string(number[i]);
			if (str.length() == 12) {
				if (str.substr(0) != "0" && str.substr(2) != "0" && str.substr(5) != "0") {

					countrycode[j] = str.substr(0, 2);
					areacode[j] = str.substr(2, 3);
					num1[j] = str.substr(5, 3);
					num2[j] = str.substr(8, 4);
					j++;

				}
			}
			else if (str.length() == 11) {
				if (str.substr(0) != "0" && str.substr(1) != "0" && str.substr(4) != "0" && str.substr(7) != "0") {

					countrycode[j] = str.substr(0, 1);
					areacode[j] = str.substr(1, 3);
					num1[j] = str.substr(4, 3);
					num2[j] = str.substr(7, 4);
					j++;
				}
			}
		}
		this->c_Number = j;
		return *this;
	}
}