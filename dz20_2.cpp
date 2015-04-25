#include <iostream>
using namespace std;

class student
{
public:
	student(void)
	{
	}
	student(char* in_name, double in_medium_mark, int in_birth_year, int in_index)
	{
		int i;
		for(i = 0; i<name_len - 1 && in_name[i]!='\0';++i)
		{
			name[i] = in_name[i];
		}
		name[i] = '\0';

		medium_mark = in_medium_mark;
		birth_year = in_birth_year;
		index = in_index;
	}

	void change_info(char* in_name, double in_medium_mark, int in_birth_year, int in_index)
	{
		int i;
		for(i = 0; i<name_len - 1 && in_name[i]!='\0';++i)
		{
			name[i] = in_name[i];
		}
		name[i] = '\0';

		medium_mark = in_medium_mark;
		birth_year = in_birth_year;
		index = in_index;
	}

	int show_info(void)
	{
		//name is enough as fields are private and initialized anly together
		if(!name)
			return ERROR_NOT_EXISTED_VAL;
		cout<<name<<" "<<medium_mark<<" "<<birth_year<<endl;
		return SUCCESS;
	}
private:
	enum
	{
		SUCCESS = 0,
		ERROR_NOT_EXISTED_VAL = 1,
		name_len = 21
	};
	char name[name_len];
	double medium_mark;
	int birth_year;
	int index;
};

class student_group
{
public:
	student_group(int in_amount)
	{
		curr_student_for_add = 0;
		amount  = in_amount;
		students = new student*[in_amount];
	}
	int add_student(char* in_name, double in_medium_mark, int in_birth_year)
	{
		if(curr_student_for_add>=amount)
			return ERROR_FULL;
		students[curr_student_for_add]->change_info(in_name, in_medium_mark, in_birth_year, curr_student_for_add);
		++curr_student_for_add;
		return SUCCESS;
	}
	int add_student(student* in_st)
	{
		if(curr_student_for_add>=amount)
			return ERROR_NOT_EXISTED_VAL;
		students[curr_student_for_add] = in_st;
		++curr_student_for_add;
		return SUCCESS;
	}
	~student_group(void)
	{
		delete students;
	}
	int show_one(int number)
	{
		if(curr_student_for_add == 0)
		{
			return ERROR_EMPTY;
		}
		if(number<0||number>=amount)
		{
			return ERROR_NOT_EXISTED_VAL;
		}
		students[number]->show_info();
		return SUCCESS;
	}
	int show_all(void)
	{
		int i;
		if(curr_student_for_add == 0)
		{
			return ERROR_EMPTY;
		}
		for(i = 0;i<curr_student_for_add;++i)
		{
			students[i]->show_info();
		}
		return SUCCESS;
	}
private:
	int amount;
	int curr_student_for_add;
	student** students;	
	enum
	{
		SUCCESS = 0,
		ERROR_NOT_EXISTED_VAL = 1,
		ERROR_EMPTY = 2,
		ERROR_FULL = 3
	};
};

int main(void)
{
	student_group group(3);

	char temp[20] = "str\0";

	student st(temp, 8, 1998,0);
	//group.add_student(temp,7,1997);
	while(group.add_student(&st)!=1);
	group.show_all();
	
	cout<<endl;
	return 0;
}