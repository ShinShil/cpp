#include <iostream>
using namespace std;

#define SUCCESS 0
#define FAIL -1
class person{
public:
	person(void){
		this->name[0] = '\0';
		//FAIL defined as -1
		this->age = FAIL;
		this->phone_number = FAIL;
		this->sex = FAIL;
	}
	int set_name(char* in_name){
		if(!in_name){
			return FAIL;
		}
		int i;
		for(i = 0;i<STR_SIZE && in_name[i]!='\0';++i){
			this->name[i] = in_name[i];
		}
		this->name[i] = '\0';
		return SUCCESS;
	}
	int set_age(int in_age){
		if(in_age<0 && in_age!=-1){
			return FAIL;
		}
		this->age = in_age;
		return SUCCESS;
	}
	int set_sex(int in_sex){
		if(in_sex!= 1 && in_sex!=0 && in_sex!=FAIL){
			return FAIL;
		}
		this->sex = in_sex;
		return SUCCESS;
	}
	int set_phone_number(int in_phone_number){
		if(in_phone_number<0 && in_phone_number!=-1){
			return FAIL;
		}
		this->phone_number = in_phone_number;
		return SUCCESS;
	}
	void show(void){
		(name[0]=='\0')?(printf("1.Name: not defined\n")):(printf("1.Name: %s\n", this->name));
		(age == -1)?(printf("2.Age: not defined\n")):(printf("2.Age: %d\n", this->age));
		(sex == -1)?
			(printf("3.Sex: not defined\n"))
			:
			((this->sex == MALE)?(printf("3.Sex: male\n")):(printf("3.Sex: female\n")));
		(phone_number == -1)?(printf("4.Phone number: not defined\n")):(printf("4.Phone nubmer: %d\n", this->phone_number));		
	}
	int GET_STR_SIZE(){
		return this->STR_SIZE;
	}

private:
	enum{
		MALE = 0,
		FEMALE = 1,
		STR_SIZE = 30
	};
	char name[STR_SIZE];
	int age;
	int sex;
	int phone_number;
};

int enter(int* q, int bottom_val, int top_val);
int main(void){

	person pers;
	int choice;
	char *for_name = new char[pers.GET_STR_SIZE()];
	int for_age, for_sex = -1, for_phone_number;

	for(;;){
		system("cls");
		printf("PERSON\n\n");
		
		printf("-----------------------------\n");
		pers.show();
		printf("5.Refresh options\n");
		printf("6.Enter 5 for exit\n");
		printf("-----------------------------\n");
		printf("\nEnter option: ");
		enter(&choice,1,5);
		switch(choice){
		case 1:{
			printf("Enter name(ENTER-key for clean): ");
			fgets(for_name,pers.GET_STR_SIZE(),stdin);
			for_name[strlen(for_name)-1] = '\0';
			pers.set_name(for_name);
			break;
			   }
		case 2:{
			printf("Enter age(-1 for clean): ");
			enter(&for_age,0,INT_MAX);
			pers.set_age(for_age);
			break;
				}
		case 3:{
			
			printf("1.Male\n");
			printf("2.Female\n");
			printf("Your choice(-1 or 0 for clean): ");
			enter(&choice, -1, 2);
			if(choice == -1)
				++choice;
			pers.set_sex(choice - 1);
			break;
				}
		case 4:{
			printf("Enter phone number(for example 1256987): ");
			enter(&for_phone_number,0,INT_MAX);
			pers.set_phone_number(for_phone_number);
			break;
			   }
		case 5:{
			pers.set_age(FAIL);
			for_name[0] = '\0';
			pers.set_name(for_name);
			pers.set_phone_number(FAIL);
			pers.set_sex(FAIL);
			break;
			}
		case 6:{
			delete[] for_name;
			return 0;
			   }
		}	
	}
	printf("\n\n");
	return 0;
}

int enter(int* q, int bottom_val, int top_val)
{
	char ch_temp;

	if (bottom_val>top_val)
	{
		return FAIL;
	}

	for (;;)
	{
		if (scanf("%d", q) != 1)
		{
				printf("\nEnter error, try one more time:");
				while (getchar() != '\n');
				continue;
		}

		if (*q<bottom_val || *q>top_val)
		{
				printf("\nBad value, try one more time:");
				while (getchar() != '\n');
				continue;
		}


		if (getchar() != '\n')
		{
			ch_temp = ' ';
			while(ch_temp!='\n')
			{
				ch_temp = getchar();
				if(ch_temp !=' ' && ch_temp!='\n')
				{
					printf("\nEnter error, try one more time:");
					continue;
				}
			}	
		}

		return SUCCESS;
	}
}