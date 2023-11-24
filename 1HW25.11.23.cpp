#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	char text[50];
	char text2[50];
	setlocale(LC_ALL, "Russian");

	// создание файла и запись в него "Hello Worlld!"
	ofstream file;
	file.open("text.txt");
	// или ofstream file("text.txt"); (заменяет две строки выше)
	file << "Hello World!";
	file.close();

	// чтение и вывод данных файла
	ifstream file1("text.txt");
	if (!file1.is_open())
		cout << "файл не найден" << endl;
	else
	{
		//выведет только первое слово из файла
		file1 >> text;
		cout << text << endl;
		//выведет записи из файла
		file1.getline(text, sizeof(text));
		cout << text << endl;
		file.close();
	}

	// добавление записей в файл
	ofstream file2;
	file2.open("text1.txt", std::ios_base::app);
	file2 << "Hi";

	// удаление записей из файла
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
		cout << "Не удалось открыть файл." << endl;
	}

	// исправление записей в файле
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
		cout << "Не удалось открыть файл.!" << endl;
		return 0;
	}
}