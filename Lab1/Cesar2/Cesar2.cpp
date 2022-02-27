// Cesar.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

#include "Windows.h"


int keyGenEnglish(int kE)
{
    
    for (int kD = 2;; kD++) {
        if ((kE * kD) % 26 == 1)
            return kD;
    }
}
int keyGenRu(int kE)
{
    for (int kD = 2;; kD++) {
        if ((kE * kD) % 256 == 1)
            return kD;
    }
}

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    std::string str = "";
    int key;

    /*td::cout << "Введите фразу!\n";
    std::getline(std::cin, str);
    std::cout << "Введите ключ!\n";
    std::cin>> key;*/


    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int i = 0, j = 0, k;
    char ABC[] = { 'А','Б','В','Г','Д','Е','Ж','З','И',
                'Й','К','Л','М','Н','О','П','Р','С',
                'Т','У','Ф','Х','Ц','Ч','Ш','Щ','Ъ',
                'Ы','Ь','Э','Ю','Я','а','б','в','г',
                'д','е','ж','з','и',
                'й','к','л','м','н','о','п','р','с',
                'т','у','ф','х','ц','ч','ш','щ','ъ',
                'ы','ь','э','ю','я','_','.',',','0',
                '1','2','3','4','5','6','7','8','9' };
    char XYZ[] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
                  'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
                  '_','.',',','0','1','2','3','4','5','6','7','8','9' };

    std::cout << "Введите фразу!\n";
    std::getline(std::cin, str);
    std::cout << "Введите ключ!\n";
    std::cin >> key;
    std::cout << std::endl;
    char* begin = ABC;
    char* end = ABC + sizeof(ABC);
    char* beginE = XYZ;
    char* endE = XYZ + sizeof(XYZ);
    
    int kD;
    char* buff = new char[str.length() + 1];
    strcpy_s(buff, str.length() + 1, str.c_str());
    if (std::find(begin, end, buff[i]) != end) {
        
        kD = keyGenRu(key);
        for (; buff[i]; ++i)
        {

           
            char* ch = std::find(begin, end, buff[i]);
            if (ch != end)
            {
                buff[i] = ABC[((ch - begin) * key) % sizeof(ABC)];
	           
            }
        }
    }
    else
    {
        kD = keyGenEnglish(key);
        for (; buff[i]; ++i)
        {
            char* ch = std::find(beginE, endE, buff[i]);
            if (ch != endE)  buff[i] = XYZ[((ch - beginE) * key) % sizeof(XYZ)];
        }
    }
    std::cout << "Полученное закодированное сообщение: " << std::endl;
    std::cout << buff << std::endl;


    /*for(int i=0;i<str.length();i++)
    {
        if(()buff[i]=>65&&buff[i]<=90)
        buff[i] += key;
    }*/
    /*std::cout << buff;*/
    if (std::find(begin, end, buff[j]) != end) {
        for (; buff[j]; ++j)
        {
            char* ch = std::find(begin, end, buff[j]);
            if (ch != end) buff[j] = *(begin + (ch - begin - key + sizeof(ABC)) % sizeof(ABC));
        }
    }
    else
    {
        for (; buff[j]; ++j)
        {
            char* ch = std::find(beginE, endE, buff[j]);
            if (ch != endE) buff[j] = *(beginE + (ch - beginE - key + sizeof(XYZ)) % sizeof(XYZ));
        }
    }
    std::cout << "Полученное декодированное сообщение: " << std::endl;
    std::cout << buff << std::endl;
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
