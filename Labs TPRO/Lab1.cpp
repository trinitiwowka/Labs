#define _CRT_SECURE_NO_WARNINGS
/*#include<stdio.h>
#include<cstdlib>
#include<string.h>
#include<conio.h>
const int LENGTHCALLBOOK = 20;
struct Call_tell
{
	char firstName[11];
	char lastName[21];
	char tell[13];
	Call_tell();
} my_call_tell[LENGTHCALLBOOK];

int search_index_free()
{
	for (int i = 0; i<LENGTHCALLBOOK; ++i)
	{
		if (my_call_tell[i].firstName[0] == '\0')
			return i;
	}
	return -1;
}
int isNumFree(char temp_num[13])
{
	for (int i = 0; i<LENGTHCALLBOOK; ++i)
	{
		if (!strcmp(my_call_tell[i].tell, temp_num))
			return 0;
	}
	return 1;
}
int AddNote()
{
	int index = search_index_free();
	if (index == -1)
	{
		printf("Note NOT added ERROR\n");
		return 1;
	}//book is full

	printf("Enter First Name:\n");
	scanf("%10s", &my_call_tell[index].firstName);
	while (getchar() != '\n');

	printf("Enter Last Name:\n");
	scanf("%20s", &my_call_tell[index].lastName);
	while (getchar() != '\n');

	char tmp_tell[13];
a:
	printf("Enter tell num:\n");
	scanf("%12s", &tmp_tell);//add function clean character
	if (!isNumFree(tmp_tell))
	{
		printf("Numper NOT FREE\n");
		goto a;
	}
	strcat(my_call_tell[index].tell, tmp_tell);
	while (getchar() != '\n');
	printf("Note added!\n");
	system("pause");
	return 0;//All Ok Note Add
}
void PrintAll()
{
	printf("----------------All Note-------------------\n");
	for (int i = 0; i<LENGTHCALLBOOK; ++i)
		if (my_call_tell[i].firstName[0] != '\0')
		{
			printf("[Note #%d]\n", i);
			printf("First name: %s\n", my_call_tell[i].firstName);
			printf("Last Name: %s\n", my_call_tell[i].lastName);
			printf("Tell: %s\n", my_call_tell[i].tell);
		}
	printf("-------------------------------------------\n");
	system("pause");
}
int SearchNote()
{
	int qwe = 0;
	for (int i = 0; i < LENGTHCALLBOOK; i++)
	{
		if (my_call_tell[i].tell == '\0')qwe++;
	}
	if (qwe == LENGTHCALLBOOK)
	{
		printf("PUSTO");
		return 11;
	}
	char temp_lastname[21];
	printf("Enter last name:\n");
	scanf("%20s", &temp_lastname);
	while (getchar() != '\n');

	for (int i = 0; i < LENGTHCALLBOOK; ++i)
	{
		if (!strcmp(my_call_tell[i].lastName, temp_lastname))
		{
			printf("Last name found!\n");
			printf("[Note #%d]\n", i);
			printf("First name: %s\n", my_call_tell[i].firstName);
			printf("Last Name: %s\n", my_call_tell[i].lastName);
			printf("Tell: %s\n", my_call_tell[i].tell);
			system("PAUSE");
			return 0;
		}
	}
	printf("Last name not found!!!\n");
	system("PAUSE");
	return 1;
}
int DeleteNote()
{
	char tmp_tell[13];
	printf("Enter tell num:\n");
	scanf("%12s", &tmp_tell);
	while (getchar() != '\n');
	for (int i = 0; i < LENGTHCALLBOOK; ++i)
	{
		if (!strcmp(my_call_tell[i].tell, tmp_tell))
		{
			my_call_tell[i].firstName[0] = '\0';
			my_call_tell[i].lastName[0] = '\0';
			my_call_tell[i].tell[0] = '\0';
			printf("DELETE SUCCSESSFULLY!\n");
			system("pause");
			return 0;
		}
	}
	printf("Tell Not Found\n");
	system("PAUSE");
	return 1;
}
Call_tell::Call_tell()
{
	for (int i = 0; i<20; ++i)
	{
		my_call_tell[i].firstName[0] = '\0';
		my_call_tell[i].lastName[0] = '\0';
		my_call_tell[i].tell[0] = '\0';
	}
}
int main()
{
	char tmp_selection;
	printf("hAllo!\n");
	while (true)
	{
		printf("1-Add note\n2-Delete note\n3-Search note\n4-Show all\n5-exit\n");
		scanf("%1c", &tmp_selection);
		while (getchar() != '\n');
		switch (tmp_selection)
		{
		case '1':
			AddNote();
			break;
		case '2':
			DeleteNote();
			break;
		case '3':
			SearchNote();
			break;
		case '4':
			PrintAll();
			break;
		case '5':
			printf("Good BY\n");
			system("pause");
			return 1;
			break;
		default:
			printf("Invalid choice\n");
			break;
		}
	}
	return 0;
}*/
#include <stdlib.h>
#include <iostream>
using namespace std;
struct Call_tell       //Структура являющаяся звеном списка
{
	char firstName[11];
	char lastName[21];
	char tell[13];
	Call_tell *Next, *Prev; //Указатели на адреса следующего и предыдущего элементов списка
};

struct List   //Создаем тип данных Список
{
	Call_tell *Head, *Tail; //Указатели на адреса начала списка и его конца

	List() :Head(NULL), Tail(NULL) {}; //Инициализируем адреса как пустые
	void Show(); //Функция отображения списка на экране
};

void EarceList(List* _deleteList) //Деструктор
{
	while (_deleteList->Head) //Пока по адресу на начало списка что-то есть 
	{
		_deleteList->Tail = _deleteList->Head->Next; //Резервная копия адреса следующего звена списка
		delete _deleteList->Head; //Очистка памяти от первого звена
		_deleteList->Head = _deleteList->Tail; //Смена адреса начала на адрес следующего элемента
	}
}

void AddList(int x, List* _newItem)
{
	Call_tell *temp = new Call_tell; //Выделение памяти под новый элемент структуры
	temp->Next = NULL;  //Указываем, что изначально по следующему адресу пусто
	
	//temp->x = x;//Записываем всю херню сюда

	if (_newItem->Head != NULL) //Если список не пуст
	{
		temp->Prev = _newItem->Tail; //Указываем адрес на предыдущий элемент в соотв. поле
		_newItem->Tail->Next = temp; //Указываем адрес следующего за хвостом элемента
		_newItem->Tail = temp; //Меняем адрес хвоста
	}
	else //Если список пустой
	{
		temp->Prev = NULL; //Предыдущий элемент указывает в пустоту
		_newItem->Head = _newItem->Tail = temp; //Голова=Хвост=тот элемент, что сейчас добавили
	}
}

void List::Show()
{
	//ВЫВОДИМ СПИСОК С КОНЦА
	Call_tell *temp = Tail;
	//Временный указатель на адрес последнего элемента
	while (temp != NULL) //Пока не встретится пустое значение
	{
		//cout << temp->x << " "; //ВыводиМ тут эту херню
		temp = temp->Prev; //Указываем, что нужен адрес предыдущего элемента
	}
	cout << "\n";

	//ВЫВОДИМ СПИСОК С НАЧАЛА
	temp = Head; //Временно указываем на адрес первого элемента
	while (temp != NULL) //Пока не встретим пустое значение
	{
		cout << temp->x << " "; //Выводим каждое считанное значение на экран
		temp = temp->Next; //Смена адреса на адрес следующего элемента
	}
	cout << "\n";
}

int main()
{
	system("CLS");
	List lst; //Объявляем переменную, тип которой есть список
	lst.Add(100); //Добавляем в список элементы
	lst.Add(200);
	lst.Add(900);
	lst.Add(888);

	lst.Show(); //Отображаем список на экране
	system("PAUSE");
}
