#include <locale.h>
#include <iostream>
using namespace std;


int main()
{
	setlocale(LC_ALL, "ru");
	char a;
    cout << "Привет, я Леха и я не умею пользоваться гитом, но Ваня сейчас учится" << endl;
	cin >> a;
	if (a == a)
	{
		cout << "Ты пидор  " << a << endl;
	}

	return(0);
}
