#include <iostream>
#include <string>

using namespace std;

class MyString
{
public:

	MyString()
	{
		str = nullptr;
	}

	MyString(const char* str)
	{
		int length = strlen(str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = str[i];
		}

		this->str[length] = '\0';
	}

	~MyString()
	{
		delete[] this->str;


	}

	MyString& operator = (const MyString& other)
	{
		if (this->str != nullptr)
		{
			delete[] str;
		}

		int length = strlen(other.str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}

		this->str[length] = '\0';

		return *this;
	}

	MyString operator +(const MyString& other)
	{
		MyString newStr;

		int thisLength = strlen(this->str);
		int otherLength = strlen(other.str);

		newStr.str = new char[thisLength + otherLength + 1];
		int i = 0;
		for (; i < thisLength; i++)
		{
			newStr.str[i] = this->str[i];
		}

		for (int j = 0; j < otherLength; j++)
		{
			newStr.str[i] = other.str[j];
		}

		newStr.str[thisLength + otherLength] = '\0';

		return newStr;
	};

	MyString(const MyString& other)
	{
		int length = strlen(other.str);
		this->str = new char[length + 1];

		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}

		this->str[length] = '\0';
	}


	void Print()
	{
		cout << str;
	}

private:
	char* str;
};

int main()
{
	MyString str("Hello");
	MyString str2("World");

	MyString result;
	result = str + str2;


	return 0;
}