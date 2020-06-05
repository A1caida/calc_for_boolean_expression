#include <iostream>
#include <string>

using namespace std;

void calc(string& lwe)
{
	un:
	while (lwe.find('!') != string::npos)
	{
		if (lwe[lwe.find('!')+1] == '!')
		{
			lwe.erase(lwe.find('!'), lwe.find('!') + 2); goto un;
		}
		else
		{		
			if (lwe[lwe.find('!') + 1] == '1')
			{
				lwe.replace(lwe.find('!'), 2, "0"); goto un;
			}
			else
			{
				lwe.replace(lwe.find('!'), 2, "1"); goto un;
			}											
		}
	}
	b:
	while (lwe.find('*') != string::npos)
	{
		if ((lwe[lwe.find('*') + 1] == '1') && (lwe[lwe.find('*') + 1] == '1'))
		{
			lwe.replace(lwe.find('*') - 1, 3, "1"); goto b;
		}
		else
		{
			lwe.replace(lwe.find('*') - 1, 3, "0");	goto b;
		}														
	}
	a:
	while (lwe.find('+') != string::npos)
	{	
		if ((lwe[lwe.find('+') + 1] == '0') && (lwe[lwe.find('+') - 1] == '0'))
		{
			lwe.replace(lwe.find('+') - 1, 3, "0"); goto a;
		}
		else
		{
			lwe.replace(lwe.find('+') - 1, 3, "1"); goto a;
		}													
	}	
}

int main()
{
	setlocale(LC_ALL, "Russian");
	string line;//вывод на экран выражения
	int owo = 0;//счет
	string lwe;//хранение букв для работы
	string elem;//значение элементов
	int ch = 0;//case
	
	while (ch != 10)
	{
		cout << "___________________" << endl;
		cout << line << endl;
		cout << lwe << endl;
		cout << "1. Любая буква" << endl;
		cout << "2. (" << endl;
		cout << "3. )" << endl;
		cout << "4. +" << endl;
		cout << "5. *" << endl;
		cout << "6. !" << endl;
		cout << "7. 1" << endl;
		cout << "8. 0" << endl;
		cout << "9. Удалить послединй элемент." << endl;
		cout << "10. Выполнить упрощение." << endl;		
		cout << "Выберите что вводить: ";
		
		while (!(cin >> ch) || (cin.peek() != '\n'))
		{
			cin.clear();
			cin.ignore((numeric_limits<streamsize>::max)(), '\n');
			cout << "Некоректные данные" << endl;
		}

		switch (ch)
		{
		case 1:
		{
			cout << "При вводе больше одной буквы, засчитываться будет 1-ая." << endl;
			cout << "Введите букву:";
				
			string a;cin >> a;

			line += a.substr(0, 1);

			cout << "Введите значение:"; cin >> elem;
			while ((elem[0] != '0') && (elem[0] != '1'))
			{
				cout << "Некоректные данные, введите 0 или 1." << endl;
				elem.clear();
				cin >> elem;
			}
			
			lwe += elem.substr(0, 1);
			owo++;
			a.clear(); elem.clear();
			
		}; break;
		case 4:
		{
			line.push_back('+'); lwe.push_back('+');
		}; break;
		case 5:
		{
			line.push_back('*'); lwe.push_back('*');
		}; break;
		case 6:
		{
			line.push_back('!'); lwe.push_back('!');
		}; break;
		case 10:
		{
			int temp = 0, temp1 = 0;
			while (lwe.find('(') != string::npos)
			{
				for (size_t i = 1; i < strlen(lwe.c_str()); i++)
				{
					for (size_t i = 0; i < lwe.size(); i++)
					{
						if (line[i] == '(')
						{
							temp = i;
						}
						if (line[i] == ')')
						{
							temp1 = i; goto uwu;
						}
					}
				}
			uwu:
				int tempuwu = temp1 - temp - 1;
				int tempowo = temp + 1;
				string nyami;
				nyami.assign(lwe, tempowo, tempuwu);
				calc(lwe);
				tempuwu = tempuwu + 2;
				lwe.replace(temp, tempuwu, nyami);
			}
			calc(lwe);
			cout << "___________________" << endl;
			cout << line << "=";
			cout << lwe << endl;
		}; break;
		
		case 7:
		{
			owo++;
			line.push_back('1');
			lwe += '1';
		}; break;
		case 2:
		{
			line.push_back('('); lwe.push_back('(');
		}; break;
		case 3:
		{
			line.push_back(')'); lwe.push_back(')');
		}; break;
		case 8:
		{
			owo++;
			line.push_back('0');
			lwe += '0';
		}; break;
		case 9:
		{
			if ((line[line.length() - 1] == '(')|| (line[line.length() - 1] == ')')|| (line[line.length() - 1] == '+')|| (line[line.length() - 1] == '!')|| (line[line.length() - 1] == '*'))
			{
				line.erase(line.length() - 1, 1); lwe.erase(lwe.length() - 1, 1);
			}
			else
			{
				line.erase(line.length()-1, 1);
				lwe.erase(lwe.length() - 1, 1);
				owo--;
			}
			
		}; break;
		default:cout << "Неверная команда!" << endl;
			break;
		}
	}
}
