#include <iostream>

using namespace std;


class counter
{
public:
	counter(void)
	{
		set_min();
	}

	void set_max(void)
	{
		value = MAX_VAL;
	}

	void set_min(void)
	{
		value = MIN_VAL;
	}

	void incr(void)
	{
		if(value == MAX_VAL)
		{
				set_min();
				++value;
		}
		else
			++value;
	}

	int curr_val(void)
	{
		return value;
	}

private:
	short int value;

	enum
	{
		MAX_VAL = 100,
		MIN_VAL = 0
	};
	
};

int main(void)
{
	counter k;
	int k_incr;

	cout<<"Initialize counter. . ."<<endl;
	cout<<"Beginning meaning:"<<k.curr_val()<<endl<<endl;

	do
	{
		cout<<"Enter the amount for increment: ";
		cin>>k_incr;
	}
	while(k_incr<=0);
	cout<<endl;

	cout<<"Counter is increasing. . ."<<endl;
	while(k_incr>0)
	{
		k.incr();
		--k_incr;
	}
	cout<<"Current meaning: "<<k.curr_val()<<endl<<endl;

	cout<<"Set MAX. . ."<<endl;
	k.set_max();
	cout<<"MAX_VALUE: "<<k.curr_val()<<endl<<endl;

	cout<<"Set MIN. . ."<<endl;
	k.set_min();
	cout<<"MIN_VALUE: "<<k.curr_val()<<endl;

	cout<<endl;
	return 0;
}