//// Izgorode.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
////
//
//#include <iostream>
//#include <vector>
//
//int main()
//{
//	
//	
//
//	
//}
//
//// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
//// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"
//
//// Советы по началу работы 
////   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
////   2. В окне Team Explorer можно подключиться к системе управления версиями.
////   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
////   4. В окне "Список ошибок" можно просматривать ошибки.
////   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
////   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
#include <iostream>
#include <iomanip>
#include <windows.h>

#include <cstring>
#include <fstream>
#include <vector>
#include <exception>
#include <string>
using namespace std;


std::vector<char> encrypt(int key, char* cWord)
{
    bool down = true;
    vector<char> C;
    char** ptrarray = new char* [key]; // две строки в массиве
    for (int count = 0; count < key; count++)
        ptrarray[count] = new char[std::strlen(cWord)]; // и пять столбцов


    // заполнение массива
    for (int count_row = 0; count_row < key; count_row++)
        for (int count_column = 0; count_column < std::strlen(cWord); count_column++)
            ptrarray[count_row][count_column] = '*'; //заполнение массива 
    // вывод массива
    std::cout << "\n";



    for (int count_column = 0, count_row = 0; count_column < std::strlen(cWord); count_column++)
    {
        ptrarray[count_row][count_column] = cWord[count_column];
        if (count_column % (key - 1) == 0 && count_column != 0)
            down = !down;
        if (down) count_row++;
        else count_row--;

    }

    for (int count_row = 0; count_row < key; count_row++)
    {
        for (int count_column = 0; count_column < std::strlen(cWord); count_column++)
            cout << setw(4) << setprecision(2) << ptrarray[count_row][count_column] << "   ";
        cout << endl;
    }

    for (int count_row = 0; count_row < key; count_row++)
    {
        for (int count_column = 0; count_column < std::strlen(cWord); count_column++)
            if (ptrarray[count_row][count_column] != '*')
                C.push_back(ptrarray[count_row][count_column]);
    }
    for (vector<char>::iterator it = C.begin(); it != C.end(); ++it)
        cout << *it;

    // удаление двумерного динамического массива
    for (int count = 0; count < key; count++)
        delete[]ptrarray[count];
    return C;
}
string  decrypt(int key, vector<char> encrypt)
{
    std::string str = "";
    bool down = true;
    char** ptrarray = new char* [key-1]; // две строки в массиве
    for (int count = 0; count < key; count++)
        ptrarray[count] = new char[encrypt.size()]; // и пять столбцов


    // заполнение массива
    for (int count_row = 0; count_row < key; count_row++)
        for (int count_column = 0; count_column < encrypt.size(); count_column++)
            ptrarray[count_row][count_column] = '*'; //заполнение массива 
    // вывод массива
    std::cout << "\n";

    for (int count_column = 0, count_row = 0; count_column < encrypt.size(); count_column++)
    {
        ptrarray[count_row][count_column] = '@';
        if (count_column % (key - 1) == 0 && count_column != 0)
            down = !down;
        if (down) count_row++;
        else count_row--;

    }
    /*for (int count_row = 0; count_row < key; count_row++)
    {
        for (int count_column = 0; count_column < encrypt.size(); count_column++)
            cout << setw(4) << setprecision(2) << ptrarray[count_row][count_column] << "   ";
        cout << endl;
    }*/
    int n = 0;
    for (int count_row = 0; count_row < key; count_row++)
    {
        for (int count_column = 0; count_column < encrypt.size(); count_column++) {
            if (ptrarray[count_row][count_column] == '@') {
            	
                ptrarray[count_row][count_column] = encrypt.at(n);
                n++;
            }
               
        }
               
    }
    for (int count_row = 0; count_row < key; count_row++)
    {
        for (int count_column = 0; count_column < encrypt.size(); count_column++)
            cout << setw(4) << setprecision(2) << ptrarray[count_row][count_column] << "   ";
        cout << endl;
    }

    for (int count_column = 0, count_row = 0; count_column < encrypt.size(); count_column++)
    {
        str += ptrarray[count_row][count_column];
         
        if (count_column % (key - 1) == 0 && count_column != 0)
            down = !down;
        if (down) count_row++;
        else count_row--;

    }
    return str;

	
}
int main(int argc, char** argv)
{
    
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    
    int k = 0;
    
   
    int key,n;
   
    setlocale(LC_ALL, "Russian");
    std::string word;
    
    
    
    
   
       std::cout << "Введите слово!\n";
       getline(cin, word);
      
    char* cWord = &word[0];
    
    
   
    std::cout << "\n";
    std::cout << "Введите ключ!\n";
    
    try
    {
        while (!(cin >> key) || (cin.peek() != '\n')|| key<2 || key>word.size())
        {
            cin.clear();
            while (cin.get() != '\n');
            cout << "Input error! Retry input" << endl;
        }

    	
    	
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << "\n";
    }
	 catch (const char* exception)
	 {
        std::cerr << "Error: " << exception << '\n';
	 }
	 catch (std::overflow_error err)
     {
        std::cout << "Overflow_error: " << err.what() << std::endl;
     }
	 catch (std::runtime_error err)
     {
        std::cout << "Runtime_error: " << err.what() << std::endl;
     }
	 
     /**/
     vector<char> C =  encrypt(key, cWord);
     std::cout << "Расшифровка\n";
     std::cout << decrypt(key,C);
     
    
    return 0;
}