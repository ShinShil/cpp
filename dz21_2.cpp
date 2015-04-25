#include <iostream>
using namespace std;

class String{
public:
	char *str;
	enum{
		STR_SIZE = 81
	};

	String(void){
		this->size = this->STR_SIZE;
		this->str = new char[this->STR_SIZE];
	}

	String(int in_size){
		if(in_size>0){
			this->size = in_size;
			this->str = new char[in_size];
		}
		else{
			this->size = this->STR_SIZE;
			this->str = new char[this->STR_SIZE];
		}
	}

	String(char* in_str){
		this->size = strlen(in_str);
		this->str = new char[this->size+1];
		for(int i = 0;i<=this->size;++i)
		{
			this->str[i] = in_str[i];
		}
	}


	~String(void){
		delete[] this->str;
	}

	int enter_str(void){
		int counter = 0;
		char temp;
		while(counter<this->size){
			this->str[counter] = getchar();
			if(this->str[counter] == '\n'){
				break;
			}
			++counter;
		}
		if(counter<size-1){
			++counter;
			this->str[counter] = '\0';
		}
		else if(counter == this->size){
			--counter;
			this->str[counter] = '\0';
		}
		else{
			this->str[counter] = '\0';
		}
		return counter;
	}
	int show_str(void){
		int i;
		for(i = 0;i<this->size && this->str[i]!='\0';++i){
			putchar(this->str[i]);
		}
		return i;
	}
	int get_size(void){
		return size;
	}
	
private:
	int size;
};

int main(void){

	String val(2);
	val.enter_str();
	val.show_str();
	printf("\n\n");
	return 0;
}