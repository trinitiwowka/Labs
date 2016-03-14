#define _CRT_SECURE_NO_WARNINGS
/*#include<stdio.h>
#include<cstdlib>
#include<string.h>
#include<conio.h>
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

struct Call_tell       //Структура являющаяся звеном списка
{
	char firstName[11];
	char lastName[21];
	char tell[13];

	Call_tell *Next, *Prev; //Указатели на адреса следующего и предыдущего элементов списка
	Call_tell() :firstName("\0"),lastName("\0"),tell("\0") {};
};

struct List   //Создаем тип данных Список
{
	Call_tell *Head, *Tail; //Указатели на адреса начала списка и его конца
	void Add();
	int isNumFree(char temp_num[13]);

	List() :Head(NULL), Tail(NULL) {}; //Инициализируем адреса как пустые
	void Show(); //Функция отображения списка на экране
	void EarceList();
	int Search();
};

void List::EarceList() //Типа Деструктор
{
	while (Head) //Пока по адресу на начало списка что-то есть 
	{
		Tail = Head->Next; //Резервная копия адреса следующего звена списка
		delete Head; //Очистка памяти от первого звена
		Head = Tail; //Смена адреса начала на адрес следующего элемента
	}
}
int List::Search()
{
	if (Head==NULL)
	{
		printf("PUSTO!!!\n");
		return -1;
	}

	Call_tell *tmp = Head;
	char temp_lastname[21];
	int          i = 0;
	printf("Enter last name:\n");
	scanf("%20s", &temp_lastname);
	while (getchar() != '\n');

	while(tmp)
	{
		if (!strcmp(tmp->lastName, temp_lastname))
		{
			printf("Last name found!\n");
			printf("[Note #%d]\n", i);
			printf("First name: %s\n", tmp->firstName);
			printf("Last Name: %s\n", tmp->lastName);
			printf("Tell: %s\n", tmp->tell);
			system("PAUSE");
			return 0;//находит первую встречную фамилию и выходит, чтобы не выходило - закоментить эту строку.
		}
		tmp = tmp->Next;
		++i;
	}
	printf("Last name not found!!!\n");
	system("PAUSE");
	return 1;
}
void List::Add()
{
	Call_tell *temp = new Call_tell; //Выделение памяти под новый элемент структуры
	temp->Next = NULL;  //Указываем, что изначально по следующему адресу пусто
	//
	//temp->x = _x;//Записываем всю херню сюда
	//
	printf("Enter First Name:\n");
	scanf("%10s", &temp->firstName);
	while (getchar() != '\n');

	printf("Enter Last Name:\n");
	scanf("%20s", &temp->lastName);
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
	strcat(temp->tell, tmp_tell);
	while (getchar() != '\n');

	//
	if (Head != NULL) //Если список не пуст
	{
		temp->Prev = Tail; //Указываем адрес на предыдущий элемент в соотв. поле
		Tail->Next = temp; //Указываем адрес следующего за хвостом элемента
		Tail = temp; //Меняем адрес хвоста
	}
	else //Если список пустой
	{
		temp->Prev = NULL; //Предыдущий элемент указывает в пустоту
		Head = Tail = temp; //Голова=Хвост=тот элемент, что сейчас добавили
	}
	printf("Note added!\n");
	system("pause");
}
int List::isNumFree(char temp_num[13])
{
	Call_tell *temp = Head;
	while (temp)
	{
		if (!strcmp(temp->tell, temp_num))
			return 0;
		temp = temp->Next;
	}
	return 1;
}
void List::Show()
{
	//ВЫВОДИМ СПИСОК С КОНЦА
	Call_tell *temp = Head;
	int           i = 0;
	//Временный указатель на адрес последнего элемента
	printf("----------------All Note-------------------\n");
	while (temp != NULL) //Пока не встретится пустое значение
	{
			if (temp->firstName[0] != '\0')
			{
				printf("[Note #%d]\n", i);
				printf("First name: %s\n", temp->firstName);
				printf("Last Name: %s\n", temp->lastName);
				printf("Tell: %s\n", temp->tell);
			}
			printf("\n");
		temp = temp->Next; //Указываем, что нужен адрес предыдущего элемента
		++i;
	}
	printf("-------------------------------------------\n");
	system("pause");

	//ВЫВОДИМ СПИСОК С НАЧАЛА
	//temp = Head; //Временно указываем на адрес первого элемента
	//while (temp != NULL) //Пока не встретим пустое значение
	//{
	//	cout << temp->x << " "; //Выводим каждое считанное значение на экран
	//	temp = temp->Next; //Смена адреса на адрес следующего элемента
	//}
	
}


int main()
{
	system("CLS");
	List lst; //Объявляем переменную, тип которой есть список
	lst.Add(); //Добавляем в список элементы
	lst.Add();
	lst.Search();
	lst.Show(); //Отображаем список на экране
	system("PAUSE");
}
