#include<iostream>
#include<cstring>
#include <fstream>

struct person {
	char last_name[32]="\0";
	double salary=-1;
};

class database {
private:
	int n;
	person* ptr;
public:
	database();

	database(int m);

	database(const char* name);
	
	database& operator=(const database& other);

	database& operator= (double val);
	
	database operator+(const database& other);
	
	database& operator[](const char* name);
	
	database& operator+=(const database& other);

	int get_size() const;

	database(const database& d);
	
	database& remove(const char* name);

	bool string_comparison(char* str1, char* str2) const;
	
	bool operator==(const database& other) const;
	
	bool operator!=(const database& other) const;
	
	void print();
	
	void output_with_limits(double a,double b);
	
	friend std::ostream& operator<< (std::ostream& out, const database& dd);
	
	~database();
};




