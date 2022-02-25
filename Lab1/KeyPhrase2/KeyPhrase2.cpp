// KeyPhrase2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <Windows.h>
#include <map>


std::map <char, int> alphaMap = {
	{ 'а', 1}, 
    { 'б', 2},
    { 'в', 3},
    { 'г', 4},
    { 'д', 5},
    { 'е', 6},
    { 'ё', 7},
    { 'ж', 8},
    { 'з', 9},
    { 'и', 10},
    { 'й', 11},
    { 'к', 12},
    { 'л', 13},
    { 'м', 14},
    { 'н', 15},
    { 'о', 16},
    { 'п', 17},
    { 'р', 18},
    { 'с', 19},
    { 'т', 20},
    { 'у', 21},
    { 'ф', 22},
    { 'х', 23},
    { 'ц', 24},
    { 'ч', 25},
    { 'ш', 26},
    { 'щ', 27},
    { 'ъ', 28},
    { 'ы', 29},
    { 'ь', 30},
    { 'э', 31},
    { 'ю', 32},
    { 'я', 33}
};

int indexOfLetter(char c)
{
    
    for (auto it = alphaMap.begin(); it != alphaMap.end(); ++it)
    {
        if (it->first == c)
            return  it->second;
           
    }
    
    
}


int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    std::string str = "",key ="";
    std::map <char, int> alphaMap;
    char ch;
    std::cout << indexOfLetter('а')+3 << "\n";
    std::cout << indexOfLetter('г') << "\n";
    std::cout << indexOfLetter('я') << "\n";
  
    std::cout << "Введите исходный текст!\n";
    std::getline(std::cin, str);
    std::cout << "Введите ключ!\n";
    std::getline(std::cin, key);
    std::cout << std::endl;

    std::map <int, int> keyMap;
    std::map <char,int> ::iterator it = alphaMap.begin();
    for (int i = 0,k=-1; i < key.length(); ++i)
    {
        /*keyMap.insert(std::pair<char, int>(key[i], alphaMap.find(key[i] )));*/
        for (int j = 0; it != alphaMap.end(); it++,j++)
        {
            if (it->first == key[i])
            {
                k = it->second;

                keyMap.insert({ i,k });
            	break;
            }
        }

    	
        
    	
    }
    std::map <int, int> ::iterator it2 = keyMap.begin();
    for (int j = 0; it2 != keyMap.end(); it++, j++)
    {
        std::cout << it2->first << " -ая буква ключа соответствует " << it2->second << " алфавита";
    }

	
    int str_count, stb_count;
    str_count = (int)(str.length() / key.length() + 1);
    stb_count = key.length();
    
    char** table = new char* [str_count]; 
    for (int count = 0; count < str_count; count++)
        table[count] = new char[stb_count];

	
    for (int i = 0,k=0;k<str.length(); i++) {
        for (int j = 0; j < stb_count; j++)
        {
            //table[i][j] = str[i * (key.length()-1) + j];
            table[i][j] = str[k++];
            std::cout << table[i][j];
        	if(k == str.length())break;
        }
        std::cout << "\n";
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
