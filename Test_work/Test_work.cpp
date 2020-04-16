//Записная книжка(как вариант : журнал студентов, пункт проката, склад оборудования).
//Основная запись должна содержать поля(не менее четырех) различных типов.
//Реализовать операции вставки, удаления, сортировки, поиска по одному из полей.
//Для хранения множества записей использовать массив.

#define _CRT_SECURE_NO_WARNINGS

#define DATA "data.txt"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


size_t file_count_lines(const char* filename);
void file_read_to_struct(FILE* file, struct food* shop, int &top);
void file_write(FILE* file, struct food* shop);

void data_print(struct food* shop, int &top);

struct food data_add(const char* name, unsigned qty, float price);

struct food* add_to_array(struct food* shop, const char* name, unsigned qty, float price, int &top);

//struct food* remove_from_array(struct food* shop, int index);

struct food {
	char name[20];
	unsigned qty;
	float price;
};

int main()
{
	//FILE* file = fopen(DATA, "a+");
	int top = 0;

	struct food* shop{};

	shop = add_to_array(shop, "batter-0", 11, 12.5,top);
	shop = add_to_array(shop, "batter-1", 11, 12.5, top);
	shop = add_to_array(shop, "batter-2", 11, 12.5, top);
	shop = add_to_array(shop, "batter-3", 11, 12.5, top);
	shop = add_to_array(shop, "batter-4", 11, 12.5, top);
	shop = add_to_array(shop, "batter-5", 11, 12.5, top);
	
	data_print(shop, top);

	for (int i = 3; i <= 5; i++)
	{
		shop[i-1] = shop[i];
		
	}
	top--;

	data_print(shop, top);

	shop = add_to_array(shop, "batter-6", 11, 12.5, top);

	data_print(shop, top);

	printf("Count string = %d\n", top);
	//free(shop);

	printf("Press any key\n");
	while (!_kbhit());
	printf("\n Key kod - %d\n", _getch());
	//getch();

    return 0;
}

struct food* add_to_array(struct food* shop, const char* name, unsigned qty, float price, int &top)
{
	top++;
	shop = (struct food*)realloc(shop, top * sizeof(struct food));
	shop[top - 1] = data_add(name, qty, price);
	return shop;
}

struct food data_add(const char* name, unsigned qty, float price)
{
	struct food res;
	strcpy(res.name, name);
	res.qty = qty;
	res.price = price;
	return res;
}



void data_print(struct food* shop, int &top)
{
	for (struct food* ptr = shop; ptr < shop + top ; ptr++)
	{
		printf("%s %u %.2f\n", ptr->name, ptr->qty, ptr->price);
	}
	printf("************************************************************\n");
}

void file_write(FILE* file, struct food* shop)
{

}

void file_read_to_struct(FILE* file, struct food* shop,  int &top)
{
	char i = 0;
	
	while (fscanf(file, "%s%u%f", &(shop[i].name), &(shop[i].qty), &(shop[i].price)) != EOF) {
		i++;
	}
	top = i;
}

size_t file_count_lines(const char* filename) {
	FILE* fp;
	size_t cnt = 0u;
	if ((fp = fopen(filename, "r")) == NULL)
		return 0u;
	while (!feof(fp)) {
		fscanf(fp, "%*[^\n]%*c");
		cnt++;
	}
	fclose(fp);
	return cnt;
}


