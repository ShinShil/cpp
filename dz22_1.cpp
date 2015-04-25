#include <iostream>
using namespace std;

class date{
private:
	int day;
	int month;
	int year;
public:
	date();
	date(int i_day, int i_month,int i_year){
		day = i_day;
		month = i_month;
		year = i_year;
	}
	void show(void){
		cout<<day<<"."<<month<<"."<<year<<"\n";
	}

	//TWO RETURNS
	int operator-(date i_date){
		int res = 0, max_year, min_year,temp;

		if(year>i_date.year){
			max_year = year;
			min_year = i_date.year;
		}
		else{
			max_year = i_date.year;
			min_year = year;
		}
		if(max_year == min_year){
			res = this->days_from_year_begin()-i_date.days_from_year_begin();
			if(res<0){
				res*=-1;
			}
			//RETURN
			return res;
		}
		
		while(min_year!=max_year){
			if(min_year%4 == 0){
				res+=366;
			}
			else{
				res+=365;
			}
			++min_year;
		}
		temp =  this->days_from_year_begin()-i_date.days_from_year_begin();
		if(temp<0){
			temp*=-1;
		}
		res+=temp;
		//RETURN
		return res;
	}

	int days_from_year_begin(void){
		int i = 1, res = 0;
		while(i!=month){
			if(i == 2 && year%4 == 0){
				res+=29;
			}
			else if(i == 2){
				res+=28;
			}
			else if(i%2 == 1){
				res+=31;
			}
			else{
				res+=30;
			}
			++i;
		}
		res+=day;
		return res;
	}
};

int main(void){
	date d1(31,12,2012);
	date d2(1,1,2014);
	int res;
	res = d2-d1;
	cout<<res<<"\n";
	return 0;
}