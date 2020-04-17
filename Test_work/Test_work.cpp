#include "Header.h"


void start(struct human* students, int &top);
void info();

void data_print(struct human* students, int &top);
void data_bubble_sort(struct human* students, int& top);
size_t data_search(struct human* students, int &top);
struct human data_add();
struct human* data_add_to_array(struct human* students, int& top);
struct human* data_remove_from_array(struct human* students, int &top);

struct human* load_test_data(struct human* students, int& top);
struct human* test_data_add_to_array(struct human* students, const char* name, const char* surname, const char* faculty, unsigned course, unsigned age, int &top);
struct human test_data_add(const char* name, const char* surname, const char* faculty, unsigned course, unsigned age);


int main()
{
	setlocale(LC_ALL, "Russian");
	system("mode 100,40");

	int top = 0; // счётчик количества записей

	students = load_test_data(students, top);

	start(students,top);

	free(students);

    return 0;
}

void start(struct human* students, int &top)
{
	info();

	while (true)
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case ESC:
						exit(0);
						break;
			case ENTER: 
						system("cls");
						data_print(students, top);
						break;
			case SHIFT_A: 
						printf("You press key Shift+A. \n The function of adding a new record has been launched...\n");
						students = data_add_to_array(students, top);
						system("cls");
						data_print(students, top);
						break;
			case SHIFT_D: 
						printf("You press key Shift+D.\n The function of deleting a record by number has been launched...\n");
						students = data_remove_from_array(students, top);
						system("cls");
						data_print(students, top);
						break;
			case SHIFT_I: printf("You press key Shift+I.\n ");
						system("cls");
						info();
						break;
			case SHIFT_Q: 
						printf("You press key Shift+Q.\n The function of searching for a record by the name of the student has been launched...\n");
						data_search(students, top);
						break;
			case SHIFT_S: printf("You press key Shift+S.\n Sort by student last name launched...\n");
						data_bubble_sort(students, top);
						data_print(students, top);
						break;
			}
		}
		
	}
}

void info()
{
	printf("\n\t\t\tИнформатика и программирование Ч-1. Контрольная работа.\n\n");
	printf("Задание : \n");
	printf("          Записная книжка(как вариант : журнал студентов, пункт проката, склад оборудования).\n");
	printf("          Основная запись должна содержать поля(не менее четырех) различных типов.\n");
	printf("          Реализовать операции вставки, удаления, сортировки, поиска по одному из полей.\n");
	printf("          Для хранения множества записей использовать массив.\n\n");
	printf("          Для входа в программу нажмите | Enter |\n");
}

void data_print(struct human* students, int &top)
{
	printf("\n -------------------------------------------------------------------------------------------\n");
	printf(" | Enter -> Load or Reload      | Shift+A -> Add new      | Shift+D -> Delete record       |\n");
	printf(" | Shift+S -> Sort by surname   | Shift+Q -> Find record  | ESC -> Exit | Shift+I -> Info  |\n");
	printf(" -------------------------------------------------------------------------------------------\n");

	size_t n = 1;
	printf("\n -------------------------------------------------------------------------------------------\n");
	printf(" |  №  |        Name            |        Surname          |     Faculty     | Course | Age |\n");
	printf(" -------------------------------------------------------------------------------------------\n");
	for (struct human* ptr = students; ptr < students + top ; ptr++ , n++)
	{
		printf(" | %3d |\t%-10s\t| |\t%-10s\t| |\t%-10s\t| %2u | \t%2u |\n", n, ptr->name, ptr->surname, ptr->faculty, ptr->course, ptr->age);
	}
	printf(" -------------------------------------------------------------------------------------------\n\n");
}

void data_bubble_sort(struct human* students, int& top)
{
	for (int i = 0; i < top-1; i++) 
	{
		for (int j = (top - 1); j > i; j--)
		{
			if (students[j - 1].surname[0] > students[j].surname[0])
			{
				struct human tmp = students[j - 1];
				students[j - 1] = students[j];
				students[j] = tmp;
			}
		}
	}
}

size_t data_search(struct human* students, int &top)
{
	char search_name[20];
	size_t i = 0;
	printf("Enter student surname for search entry: -> ");
	scanf("%s", &search_name);
	//size_t tmp;
	while (i < top-1)
	{
		size_t tmp = (strcmp(students[i].surname, search_name));
		if (tmp != 0)
		{
			i++;
		}
		else {
			printf("First matches found in string %d. \nFor delete record press Shift+D and enter %d \n\n", i+1, i+1);
			return i;
		}
	}
}

struct human data_add()
{
	struct human res;

	char name[20];
	char surname[20];
	char faculty[50];
	unsigned course, age;

	printf("Enter name surname faculty course age for new student : ->  \n");
	scanf("%s %s %s %u %u", &name, &surname, &faculty, &course, &age);

	strcpy(res.name, name);
	strcpy(res.surname, surname);
	strcpy(res.faculty, faculty);
	res.course = course;
	res.age = age;
	return res;
}

struct human* data_add_to_array(struct human* students, int& top)
{
	top++;
	students = (struct human*)realloc(students, top * sizeof(struct human));
	students[top - 1] = data_add();
	return students;
}

struct human* data_remove_from_array(struct human* students, int& top)
{
	size_t index;
	printf("Enter record number to delete : ->  ");
	scanf("%d", &index);
	for (int i = index; i < top; i++)
	{
		students[i - 1] = students[i];
	}
	top--;
	return students;
}

struct human* load_test_data(human* students, int& top)
{
	students = test_data_add_to_array(students, "Zara", "Smitt", "Management", 1, 19, top);
	students = test_data_add_to_array(students, "Maks", "Karter", "Legal", 1, 18, top);
	students = test_data_add_to_array(students, "Tod", "Dormer", "Technological", 2, 20, top);
	students = test_data_add_to_array(students, "Mary", "Spilberg", "Technological", 4, 22, top);
	students = test_data_add_to_array(students, "Sarah", "Connor", "Management", 3, 21, top);
	students = test_data_add_to_array(students, "Alice", "Barton", "Legal", 5, 22, top);
	students = test_data_add_to_array(students, "Hakeem", "Whitehead", "Legal", 3, 22, top);
	students = test_data_add_to_array(students, "Allen", "Beasley", "Management", 5, 22, top);
	students = test_data_add_to_array(students, "Charles", "Jimenez", "Technological", 4, 22, top);
	students = test_data_add_to_array(students, "Victor", "Hogan", "Technological", 4, 21, top);
	return students;
}

struct human* test_data_add_to_array(struct human* students, const char* name, const char* surname, const char* faculty, unsigned course, unsigned age, int &top)
{
	top++;
	students = (struct human*)realloc(students, top * sizeof(struct human));
	students[top - 1] = test_data_add(name, surname, faculty, course, age);
	return students;
}

struct human test_data_add(const char* name, const char* surname, const char* faculty, unsigned course, unsigned age)
{
	struct human res;
	strcpy(res.name, name);
	strcpy(res.surname, surname);
	strcpy(res.faculty, faculty);
	res.course = course;
	res.age = age;
	return res;
}






