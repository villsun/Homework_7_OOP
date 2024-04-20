#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using namespace std;

class String
{
private:
	char* p_str;
public:
	String()
	{
		p_str = (char*)malloc(80 * sizeof(char));
		strcpy(p_str, "None");
	}
	String(int size)
	{
		p_str = (char*)malloc(size * sizeof(char));
		strcpy(p_str, "None");
	}
	String(char* str)
	{
		p_str = (char*)malloc(strlen(str) * sizeof(char) + 1);
		strcpy(p_str, str);
	}
	String(String& old_str)
	{
		p_str = (char*)malloc(strlen(old_str.p_str) * sizeof(char) + 1);
		strcpy(p_str, old_str.p_str);
	}

	void Show_Str()
	{
		cout << p_str << endl;
	}

	void Enter_Str()
	{
		char p_str[200];
		cin >> p_str;
		this->p_str = (char*)realloc(this->p_str, strlen(p_str) * sizeof(char) + 1);
		strcpy(this->p_str, p_str);
	}

	int Get_Size()
	{
		return strlen(p_str);
	}

	void Clear_Str()
	{
		strcpy(p_str, "");
	}

	char& operator [](int index)
	{
		return p_str[index];
	}

	int operator ()(char value)
	{
		int index = -1;
		for (int i = 0; i < strlen(p_str); i++)
		{
			if (value == p_str[i])
			{
				index = i;
				break;
			}
		}

		return index;
	}

	/*String& operator =(String& old_string)
	{
		if (this != &old_string)
		{
			free(p_str);
			p_str = (char*)malloc(strlen(old_string.p_str) * sizeof(char) + 1);
			strcpy(p_str, old_string.p_str);
		}
		
		return *this;
	}*/

	String* operator +(String& str)
	{
		String *temp = new String;
		int new_size = strlen(this->p_str) + strlen(str.p_str);
		temp->p_str = (char*)(malloc(new_size * sizeof(char) + 1));

		strcpy(temp->p_str, this->p_str);
		strcat(temp->p_str, str.p_str);

		return temp;
	}

	String& operator +=(String& str)
	{
		int new_size = strlen(this->p_str) + strlen(str.p_str) + 1;
		this->p_str = (char*)realloc(this->p_str, new_size * sizeof(char)); 

		strcat(this->p_str, str.p_str);

		return *this;
	}

	bool operator ==(String& str)
	{
		int result = strcmp(this->p_str, str.p_str);
		return result == 0 ? true : false;
	}

	bool operator !=(String& str)
	{
		int result = strcmp(this->p_str, str.p_str);
		return result != 0 ? true : false;
	}

	~String()
	{
		free(p_str);
	}
};

void Func(String str_new)
{
	str_new.Show_Str();
}

int main()
{
	String str((char*)"Kola");
	str.Show_Str();
	/*str.Clear_Str();*/
	int size = str.Get_Size();

	String str_temp((char*)"Kolaaa");
	String *fdg;

	if (str == str_temp)
	{
		cout << "True\n";
	}
	else
	{
		cout << "False\n";
	}

	if (str!=str_temp)
	{
		cout << "True\n";
	}
	else
	{
		cout << "False\n";
	}

	/*fdg = str + str_temp;
	fdg->Show_Str();
	delete fdg;*/
	/*str += str_temp;
	str.Show_Str();*/

	/*str.Enter_Str();
	str.Show_Str();
	Func(str);*/

	/*String temp = str;
	temp.Show_Str();*/

	/*cout << str[0] << endl;*/

	/*cout << str('N') << endl;*/

	return 0;
}