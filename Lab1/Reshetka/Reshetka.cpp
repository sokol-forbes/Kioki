// Reshetka.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>

char** rotate_90(char** m_in, int n, int m);
char** rotate_270(char** m_in, int n, int m);
int reshetka[5][5] = {
		{1,2,3,4,1},
		{4,5,6,5,2},
		{3,6,7,6,3},
		{2,5,6,5,4},
		{1,4,3,2,1}
};
char** cryptography(std::vector<int> pl, std::string word)
{
	char** crypt;
	crypt = new char* [5];
	for (int j = 0; j < 5; j++)
		crypt[j] = new char[5];
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{

			crypt[i][j] = '*';

		}

	}
	int rotateCount = (word.size() < 14 ? (word.size() > 7 ? 2 : 1) : (word.size() > 19 ? 4 : 3 ));
	char* cWord = &word[0];
	for(int i=0;i<4;i++)
	{
		if (i == 0)
		{
			for (int j = 0; j < 7/*, j<word.size() */ ; j++)
			{
				crypt[(int)(pl.at(j) / 10)][(int)(pl.at(j) % 10)] = cWord[j];
			}
		}
		else{
			for (int j = 0; j < 6/*, (7 + j + (i - 1) * 6)<word.size()*/; j++)
				crypt[pl.at(j) / 10][pl.at(j) % 10]=cWord[7+j+(i-1)*6];
		}
		crypt=rotate_90(crypt, 5, 5);

			
	}
	
	
	return crypt;
}
std::string decryptography(std::vector<int> pl, char** crypt)
{
	
	int wordSize = 0;
	
	
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			if (crypt[i][j] != '*')wordSize++;
		}
	}
	
	int rotateCount = (wordSize < 14 ? (wordSize > 7 ? 2 : 1) : (wordSize > 19 ? 4 : 3));
	char cWord [25];
	for (int i = 0; i < 4; i++)
	{
		if (i == 0)
		{
			for (int j = 0; j < 7/*, j<wordSize */; j++)
			{
				 cWord[j] = crypt[(int)(pl.at(j) / 10)][(int)(pl.at(j) % 10)] ;
			}
		}
		else {
			for (int j = 0; j < 6/*, (7 + j + (i - 1) * 6)<wordSize*/; j++)
				 cWord[7 + j + (i - 1) * 6] = crypt[pl.at(j) / 10][pl.at(j) % 10] ;
		}
		crypt = rotate_90(crypt, 5, 5);


	}

	std::string word(cWord);
	return word;
}
bool inputCheck(int str, int stb, int index)
{
	
	bool result = (reshetka[str][stb] == index ?  true : false);
	return result;
}
char** rotate_90(char** m_in, int n, int m)
{
	



	char tmp;
	for (int i = 0; i < n / 2; i++)
	{
		for (int j = i; j < n - 1 - i; j++)
		{
			tmp = m_in[i][j];
			m_in[i][j] = m_in[n - j - 1][i];
			m_in[n - j - 1][i] = m_in[n - i - 1][n - j - 1];
			m_in[n - i - 1][n - j - 1] = m_in[j][n - i - 1];
			m_in[j][n - i - 1] = tmp;
		}
	}

	
	return m_in;
}
char** rotate_270(char** m_in, int n, int m)
{
	
	char tmp;
	for (int i = 0; i < n / 2; i++)
	{
		for (int j = i; j < n - 1 - i; j++)
		{
			tmp = m_in[i][j];
			m_in[i][j] = m_in[j][n - 1 - i];
			m_in[j][n - 1 - i] = m_in[n - 1 - i][n - 1 - j];
			m_in[n - 1 - i][n - 1 - j] = m_in[n - 1 - j][i];
			m_in[n - 1 - j][i] = tmp;
		}
	}

	return m_in;
}
int main()
{
    //std::cout << "Hello World!\n";
	
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	int stroka, stolbec;
	char ch;
	std::vector<int> places;
	char **crypt;
	crypt = new char* [5];
	for (int j = 0; j < 5; j++)
		crypt[j] = new char[5];
	
	/*char crypt [5][5] = {
		{'1','2','3','4','5'},
		{'1','2','3','4','5'},
		{'1','2','3','4','5'},
		{'1','2','3','4','5'},
		{'1','2','3','4','5'},
	};*/
	/*char **crt1 = rotate_90(crypt, 5, 5);
	for (int i = 0; i < 5; i++)
	{
		
		for (int j = 0; j < 5; j++)
		{
			std::cout << crt1[i][j] << " ";
		}
		std::cout << "\n";
	}
	 crt1 = rotate_90(crt1, 5, 5);
	for (int i = 0; i < 5; i++)
	{

		for (int j = 0; j < 5; j++)
		{
			std::cout << crt1[i][j] << " ";
		}
		std::cout << "\n";
	}*/
	/*char crypt[5][5] = {
		{'*','*','*','*','*'},
		{'*','*','*','*','*'},
		{'*','*','*','*','*'},
		{'*','*','*','*','*'},
		{'*','*','*','*','*'}
	};*/
	int reshetka[5][5] = {
		{1,2,3,4,1},
		{4,5,6,5,2},
		{3,6,7,6,3},
		{2,5,6,5,4},
		{1,4,3,2,1}
						};
	std::cout << "   ";
	for (int j = 0; j < 5; j++)
	{
		std::cout << ' ' << j ;
	}
	std::cout << "\n";
	std::cout << "    —————————\n";
	for(int i=0;i<5;i++)
	{
		std::cout << i<<" | ";
		for(int j=0;j<5;j++)
		{
			std::cout << reshetka[i][j] << " ";
		}
		std::cout <<"\n";
	}

	std::cout << "Выберите положение элементов\n";
	for(int index = 1;index<8;)
	{
		std::cout << "Введите строку и столбец для "<<index<<"\n";
		std::cin >> stroka;
		std::cin >> stolbec;
		if(inputCheck(stroka,stolbec,index))
		{
			places.push_back(stroka*10+stolbec);
			index++;
		}
		else { std::cout << "Неверный ввод. Повторите попытку"; }
	}
	for (int i = 0; i < 7; i++)
	{
		std::cout<<places.at(i)<<" ";
	}
	std::string word;

	std::cout << "Введите слово!\n";
	
	getline(std::cin, word);
	int size = word.size();
	if(size > 25 || size < 1)
	{
		while (word.size() > 25 || word.size() < 1)
		{
			std::cout << "Слово не может быть более 25 символов! Повторите ввод.\n";
			getline(std::cin, word);
		}
	}
	
	
	crypt = cryptography(places, word);


	for (int i = 0; i < 5; i++)
	{
		
		for (int j = 0; j < 5; j++)
		{
			std::cout << crypt[i][j] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
	word= decryptography(places, crypt);
	for (int i = 0; word[i]!='\0'; i++)
	{
		std::cout << word[i];
	}
	
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
