// sDES.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
#include <fstream>

const int P10[10] = {3,5,2,7,4,10,1,9,8,6};
const int P8[8] = {6,3,7,4,8,5,10,9};
const int shift1[5] = { 1,2,3,4,0 };
const int shift2[5] = { 2,3,4,0,1 };
int inKey[10]={1,1,1,1,1,1,1,1,1,1};
int key1[8];
int key2[8];

int grand(int gr,int number = 10 )
{
	int  result = 1;
	
	
	for (int c = 0; c < gr; c++) result *= number;
	return result;
}
void keyGen()
{
	int key[10];

	
	
	for(int i=0;i<10;i++)//перестановка по Р10
	{
		
		key[i]=inKey[P10[i]-1];
	}
	std::memcpy(inKey, key, sizeof(int) * 10);

	//сдвиг на 1
	for(int i=0;i<5;i++)
	{
		key[i] = inKey[shift1[i]];
		key[i+5] = inKey[shift1[i]+5];
	}
	
	//генерация К1
	for(int i=0;i<8;i++)
	{
		key1[i] = key[P8[i]-1];
	}
	std::memcpy(inKey, key, sizeof(int) * 10);
	//сдвиг на 2
	for (int i = 0; i < 5; i++)
	{
		key[i] = inKey[shift2[i]];
		key[i + 5] = inKey[shift2[i]+5];
	}

	//генерация К2
	for (int i = 0; i < 8; i++)
	{
		key2[i] = key[P8[i]-1];
	}
	
}
char* readPlain(int position=0, int count=6830) {
	std::ifstream file;
	file.open("C:\\Users\\DELL\\source\\repos\\KIOKI\\Lab2\\sDES\\plainText.txt", std::ios_base::binary);

	if (!file) std::cout << "Файл не открыт\n\n";
	else std::cout << "Все ОК! Файл открыт!\n\n";

	
	if (!file.is_open()) return 0;
	
	if (file.eof()) return 0;
	char* buffer = new char[count];
	file.read(buffer, count);
	file.close();
	return buffer;
}
void CharToByte(char* chars, byte* bytes, unsigned int count) {
	for (unsigned int i = 0; i < count; i++)
		bytes[i] = (byte)chars[i];
}

void ByteToChar(byte* bytes, char* chars, unsigned int count) {
	for (unsigned int i = 0; i < count; i++)
		chars[i] = (char)bytes[i];
}
void crypt()
{
	std::ifstream file;
	file.open("C:\\Users\\DELL\\source\\repos\\KIOKI\\Lab2\\sDES\\plainText.txt", std::ios_base::binary);

	if (!file) std::cout << "Файл не открыт\n\n";
	else std::cout << "Все ОК! Файл открыт!\n\n";


	
	char* buffer = new char[6830];
	file.read(buffer, 6830);


	char** cryptArr = new char *[854];
	for(int i=0;i<854;i++)
	{
		cryptArr[i] = new char[8];
	}


	
	file.close();



	
}
int main()
{
	setlocale(LC_ALL, "RU");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
 //   std::cout << "Введите ключ!\n";
	//int inputKey;
	//
	//std::cin >> inputKey;

	//for(int i=0,j=9;i<10;i++,j--)
	//{
	//	inKey[j] = (int)inputKey % 10;
	//	inputKey /= 10;
	//}
	//keyGen();
	//
	//std::cout << "К1: \n";
	//for (int i = 0; i < 8; i++)//перестановка по Р10
	//{
	//	std::cout << key1[i];
	//}

	//std::cout << "\nК2: \n";
	//for (int i = 0; i < 8; i++)//перестановка по Р10
	//{
	//	std::cout << key2[i];
	//}
	std::ifstream file;
	file.open("C:\\Users\\DELL\\source\\repos\\KIOKI\\Lab2\\sDES\\plainText.txt");

	char* plainText = readPlain();


	for(int i=0;i<6830;i++)
	{
		std::cout << plainText[i];
	}
	
	
	file.close();
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
