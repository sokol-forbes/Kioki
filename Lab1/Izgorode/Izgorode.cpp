
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
    char** ptrarray = new char* [key]; 
    for (int count = 0; count < key; count++)
        ptrarray[count] = new char[std::strlen(cWord)];


    
    for (int count_row = 0; count_row < key; count_row++)
        for (int count_column = 0; count_column < std::strlen(cWord); count_column++)
            ptrarray[count_row][count_column] = '*'; 
   
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

    
    for (int count = 0; count < key; count++)
        delete[]ptrarray[count];
    return C;
}
string  decrypt(int key, vector<char> encrypt)
{
    std::string str = "";
    bool down = true;
    char** ptrarray = new char* [key-1]; 
    for (int count = 0; count < key; count++)
        ptrarray[count] = new char[encrypt.size()]; 


    
    for (int count_row = 0; count_row < key; count_row++)
        for (int count_column = 0; count_column < encrypt.size(); count_column++)
            ptrarray[count_row][count_column] = '*'; 
   
    std::cout << "\n";

    for (int count_column = 0, count_row = 0; count_column < encrypt.size(); count_column++)
    {
        ptrarray[count_row][count_column] = '@';
        if (count_column % (key - 1) == 0 && count_column != 0)
            down = !down;
        if (down) count_row++;
        else count_row--;

    }
  
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