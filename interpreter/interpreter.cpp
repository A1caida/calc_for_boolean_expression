#include <iostream>
#include <string>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	string line;//вывод на экран выражения
	int owo = 0;//счет
	string lwe;//хранение букв для работы
	bool* elem = new bool[100];//значение элементов
	int ch = 0;//case

	while (ch != 10)
	{
		cout << "___________________" << endl;
		cout << line << endl;
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
			lwe += a.substr(0, 1);

			cout << "Введите значение:";
			
			while (!(cin >> elem[owo]) || (cin.peek() != '\n'))
			{
				cin.clear();
				cin.ignore((numeric_limits<streamsize>::max)(), '\n');
				cout << "Некоректные данные" << endl;
			}

			owo++;
			a.clear();
			
		}; break;
		case 4:
		{
			line.push_back('+');
		}; break;
		case 5:
		{
			line.push_back('*');
		}; break;
		case 6:
		{
			line.push_back('!');
		}; break;
		case 10:
		{
			line.push_back(' ');

			elem[owo] = 1; elem[owo + 1] = 0;
			
			for (size_t i = 1; i < strlen(line.c_str()); i++)
			{
				if (line[i - 1] == '!')
				{
					if (line[i] == '(')
					{
						if (line[i + 2] == '*')
						{
							line.replace(i + 2, 1, "+");
							line.replace(i, 1, "!");							
							string temp = line.substr(i+3,1);
							line.replace(i + 3, 1, "!");
							line.replace(i + 4, 1, temp);
							line.replace(i - 1,1, " ");
							temp = line.substr(i, 5);
							line.erase(i, 5);
							line.replace(i - 1, 1, temp);
							line.push_back(' ');
							break;							
						}
						else
						{
							line.replace(i + 2, 1, "*");
							line.replace(i, 1, "!");
							string temp = line.substr(i + 3, 1);
							line.replace(i + 3, 1, "!");
							line.replace(i + 4, 1, temp);
							line.replace(i - 1, 1, " ");
							temp = line.substr(i, 5);
							line.erase(i, 5);
							line.replace(i - 1, 1, temp);
							line.push_back(' ');
							break;
						}
					}
				}
			}

			for (size_t i = 1; i < strlen(line.c_str()); i++)
			{
				if (line[i - 1] == '!')
				{
					if (line[i] == '!')
					{
						for (size_t j = 0; j < strlen(lwe.c_str()); j++)
						{
							if (line[i + 1] == lwe[j])
							{
								if (elem[j] == 0)
								{
									line.replace(i - 1, 3, "0");
									lwe.replace(j, 1, "0");
								}
								if (elem[j] == 1)
								{
									line.replace(i - 1, 3, "1");
									lwe.replace(j, 1, "1");		
								}
							}
						}
					}
					else
					{
						for (size_t j = 0; j < strlen(lwe.c_str()); j++)
						{
							if (line[i] == lwe[j])
							{
								elem[j] = !elem[j];
								line.erase(i - 1, 1);
								if (elem[j] == 0)
								{
									for (size_t k = 0; k < lwe.length(); k++)
									{
										if (line[i - 1] == lwe[k])
										{
											lwe.replace(k, 1, "0");
											line.replace(i - 1, 1, "0");
										}
									}
								}
								if (elem[j] == 1)
								{
									for (size_t k = 0; k < lwe.length(); k++)
									{
										if (line[i - 1] == lwe[k])
										{
											lwe.replace(k, 1, "1");
											line.replace(i - 1, 1, "1");
										}
									}
								}
							}
						}
					
					}
				}
			}

			while (line.find('*') != string::npos)
			{
				for (size_t i = 1; i < strlen(line.c_str()); i++)
				{
					if (line[i - 1] == '*')
					{
						for (size_t j = 0; j < strlen(lwe.c_str()); j++)
						{
							for (size_t k = 0; k < strlen(lwe.c_str()); k++)
							{
								if ((line[i] == lwe[j]) && (line[i - 2] == lwe[k]))
								{
									if ((elem[j] == 1) && (elem[k] == 1))
									{

										line.replace(i - 2, 3, "1");
										lwe.replace(k, 2, "1");
										for (size_t kekw = k; kekw < line.length() / 2; kekw++) elem[kekw] = elem[kekw + 1];
									}
									else
									{
										line.replace(i - 2, 3, "0");
										lwe.replace(k, 2, "0");
										if (elem[k] == 0)
										{
											for (size_t kekw = j; kekw < line.length() / 2; kekw++) elem[kekw] = elem[kekw + 1];											
										}
										else
										{
											elem[k] = elem[j];
											for (size_t kekw = j; kekw < line.length() / 2; kekw++) elem[kekw] = elem[kekw + 1];											
										}
									}
								}
							}
						}
					}
				}
			}

			while (line.find('+') != string::npos)
			{
				for (size_t i = 1; i < strlen(line.c_str()); i++)
				{
					if (line[i - 1] == '+')
					{
						for (size_t j = 0; j < strlen(lwe.c_str()); j++)
						{
							for (size_t k = 0; k < strlen(lwe.c_str()); k++)
							{
								if ((line[i] == lwe[j]) && (line[i - 2] == lwe[k]))
								{

									if ((elem[j] == 0) && (elem[k] == 0))
									{
										line.replace(i - 2, 3, "0");
										lwe.replace(k, 2, "0");
										for (size_t kekw = k; kekw < line.length() / 2; kekw++) elem[kekw] = elem[kekw + 1];										
									}
									else
									{
										line.replace(i - 2, 3, "1");
										lwe.replace(k, 2, "1");
										if (elem[k] == 1)
										{
											for (size_t kekw = j; kekw < line.length() / 2; kekw++) elem[kekw] = elem[kekw + 1];	
										}
										else
										{
											elem[k] = elem[j];
											for (size_t kekw = j; kekw < line.length() / 2; kekw++) elem[kekw] = elem[kekw + 1];
										}
									}
								}
							}
						}
					}
				}
			}
			cout << "___________________" << endl;
			cout << line << endl;
		}; break;

		case 7:
		{
			elem[owo] = 1;
			owo++;
			line.push_back('1');
			lwe += '1';
		}; break;
		case 2:
		{
			line.push_back('(');
		}; break;
		case 3:
		{
			line.push_back(')');
		}; break;
		case 8:
		{
			elem[owo] = 0;
			owo++;
			line.push_back('0');
			lwe += '0';
		}; break;
		case 9:
		{
			if ((line[line.length() - 1] == '(')|| (line[line.length() - 1] == ')')|| (line[line.length() - 1] == '+')|| (line[line.length() - 1] == '!')|| (line[line.length() - 1] == '*'))
			{
				line.erase(line.length() - 1, 1);
			}
			else
			{
				line.erase(line.length()-1, 1);
				lwe.erase(line.length() - 1, 1);
				owo--;
			}
			
		}; break;
		default:cout << "Неверная команда!" << endl;
			break;
		}
	}

}
