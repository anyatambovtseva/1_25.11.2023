#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	char text[50];
	char text2[50];
	setlocale(LC_ALL, "Russian");

	// �������� ����� � ������ � ���� "Hello Worlld!"
	ofstream file;
	file.open("text.txt");
	// ��� ofstream file("text.txt"); (�������� ��� ������ ����)
	file << "Hello World!";
	file.close();

	// ������ � ����� ������ �����
	ifstream file1("text.txt");
	if (!file1.is_open())
		cout << "���� �� ������" << endl;
	else
	{
		//������� ������ ������ ����� �� �����
		file1 >> text;
		cout << text << endl;
		//������� ������ �� �����
		file1.getline(text, sizeof(text));
		cout << text << endl;
		file.close();
	}

	// ���������� ������� � ����
	ofstream file2;
	file2.open("text1.txt", std::ios_base::app);
	file2 << "Hi";

	// �������� ������� �� �����
	ifstream inputFile("input.txt");
	ofstream outputFile("output.txt");
	string line;
	string lineToDelete = "deldeldel";

	if (inputFile.is_open())
	{
		while (getline(inputFile, line))
		{
			if (line != lineToDelete)
			{
				outputFile << line << endl;
			}
		}
		inputFile.close();
		outputFile.close();
	}
	else
	{
		cout << "�� ������� ������� ����." << endl;
	}

	// ����������� ������� � �����
	ifstream input("in.txt");
	ofstream output("out.txt");
	string line11;
	string lineToReplace = "deldeldel";
	string line1 = "asdd";
	if (input.is_open())
	{
		while (getline(input, line11))
		{
			if (line11 != lineToReplace)
			{
				output << line11 << endl;
			}
			if (line11 == lineToReplace)
			{
				output << line1 << endl;
			}
		}
		input.close();
		output.close();
	}
	else
	{
		cout << "�� ������� ������� ����.!" << endl;
		return 0;
	}
}