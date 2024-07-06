#include<iostream>
#include<cstring>
#include <fstream>
#include "database.hpp"




	database::database() {
		//std::cout << "constructor type 0 "<<std::endl;
		n = 0;
		ptr = nullptr;
		
	}

	database::database(int m) {
		//std::cout << "constructor type 1, ord " << std::endl;
		n = m;
		ptr = new person[n];
	}

	database::database(const char* name) {
		//std::cout << "constructor type 2 " << std::endl;
		char name_from[32];
		double salary_from;
		int i = 0;
		int amount;
	

		std::ifstream f(name);
		if (f.is_open())
		{
			f >> amount;
			ptr = new person[amount];
			while ((!f.eof()) && (i<amount))
			{
				f >> name_from;
				strcpy(ptr[i].last_name, name_from);
				f >> salary_from;
				ptr[i].salary = salary_from;
				i++;
			}		
			n = i;
			f.close();
		
		}
		else{std::cout<<"file not opened"<<std::endl;}
		

	}

	int database::get_size() const{
		//std::cout<<"in get_size()"<<std::endl;
		return n;
	}




	database::database(const database& d){
		int w = d.get_size();
		ptr = new person[w];
		n=w;
	//	std::cout << "constructor copy, ord 2" <<std::endl;
		for (int i = 0; i < w; ++i) {
			strcpy(ptr[i].last_name, d.ptr[i].last_name);
			ptr[i].salary = d.ptr[i].salary;
		}
	} 

	


	

	bool database::string_comparison(char* str1, char* str2) const{
		return (strcmp(str1,str2)==0);
	}


	
	bool database::operator==(const database& other) const {
		double eps=0.00000001; 
		if (ptr == nullptr && other.ptr == nullptr) return true;
		if ((ptr == nullptr) || (other.ptr == nullptr)) return false;
		for (int i = 0; i < n; ++i) {
			if ((string_comparison( ptr[i].last_name, other.ptr[i].last_name ) == false) || (abs(ptr[i].salary- other.ptr[i].salary))>eps) return false; 
		}
		return true;
	}
	
	bool database::operator!=(const database& other) const {
		return ((*this==other)==false);	
	}
	


	void database::print() {
		std::cout << "serial number       last name:            Salary" << std::endl;
		for (int i = 0; i < n; ++i)
			
			std::cout <<i<<"              " <<ptr[i].last_name << "               " << ptr[i].salary << std::endl;
	
	}
	
	database database::operator+(const database& other){
		int n1=get_size();
		int n2=other.get_size();
		int nn=n1+n2;
		database C(nn);
		
		
		for (int i=0;i<n1;++i){
			strcpy(C.ptr[i].last_name,this->ptr[i].last_name);
			C.ptr[i].salary=this->ptr[i].salary;
		}
		
		for (int i=n1;i<nn;++i){
			strcpy(C.ptr[i].last_name,other.ptr[i-n1].last_name);
			C.ptr[i].salary=other.ptr[i-n1].salary;	
		}
		
		
		
		
		return C;	
	}
	
	
	database& database::operator+=(const database& other){
		int n1=get_size();
		int n2=other.get_size();
		int n=n1+n2;
		
		person* p=new person[n];
	
		for (int i=0;i<n1;++i){
			strcpy(p[i].last_name,this->ptr[i].last_name);
			p[i].salary=this->ptr[i].salary;
		}
		
		
		delete[] this->ptr;
		this->ptr=new person[n];
				
		for (int i=0;i<n1;++i){
			strcpy(this->ptr[i].last_name,p[i].last_name);
			this->ptr[i].salary=p[i].salary;
		}
		
		for (int i=n1;i<n;++i){
			strcpy(this->ptr[i].last_name,other.ptr[i-n1].last_name);
			this->ptr[i].salary=other.ptr[i-n1].salary;	
		}
		
		delete[] p;
		this->n=n;
	
		return *this;
	
	}
	
	
	database& database::operator[](const char* name){
		person* p=new person[n];
		for (int i=0;i<n;++i){
			strcpy(p[i].last_name,this->ptr[i].last_name);
			p[i].salary=this->ptr[i].salary;
		}
		delete[] this->ptr;
		
		this->ptr=new person[n+1];
		
		for (int i=0;i<n;++i){
			strcpy(this->ptr[i].last_name,p[i].last_name);
			this->ptr[i].salary=p[i].salary;	
		}
		delete[] p;
		
		strcpy(this->ptr[n].last_name,name);
		this->ptr[n].salary=-12345;
		this->n++;

		return *this;
	}
	
	database& database::operator=(double value){
	
	
		double mrot=23508;
		(value>=mrot) ? (ptr[n-1].salary=value) : (this->n--);
		return *this;
	}
	
	database& database::remove(const char* name){
	int ii=-1;
	int k=0;
		for(int i=0;i<n;++i){
			if (strcmp (ptr[i].last_name,name)==0){
				ii=i;
				break;
			} 
		}
		
		if (ii!=-1){
			person* p=new person[n-1];
			for (int i=0;i<n;++i){
				if (i!=ii){ 
					strcpy(p[k].last_name,this->ptr[i].last_name);
					p[k].salary=this->ptr[i].salary;
					k++;
				}
			}
			delete[] this->ptr;
			this->ptr=new person[n-1];
			
			for (int i=0;i<n-1;++i){
				strcpy(this->ptr[i].last_name,p[i].last_name);
				this->ptr[i].salary=p[i].salary;	
			}
			
			delete[] p;
			this->n=n-1;
		}

		
		return *this;
	}
	
	database& database::operator= (const database& other){
		
		if (ptr) delete[] ptr;
		int m=other.get_size();
		ptr=new person[m];
		for (int i=0;i<m;++i){
			strcpy(ptr[i].last_name,other.ptr[i].last_name);
			ptr[i].salary=other.ptr[i].salary;
		}
		this->n=m;
		return *this;
	}
	
	
		std::ostream& operator<<(std::ostream& out, const database& dd) {
			database d=dd;
			int t=0;
			char temp[32];
			double d_temp;
			for (int i=0;i<dd.get_size();++i){
				for (int j=0;j<dd.get_size();++j){
					if ((int)d.ptr[i].last_name[t]<(int)d.ptr[j].last_name[t]){
						strcpy(temp,d.ptr[i].last_name);
						d_temp=d.ptr[i].salary;
						
						strcpy(d.ptr[i].last_name,d.ptr[j].last_name);
						d.ptr[i].salary=d.ptr[j].salary;
						
						strcpy(d.ptr[j].last_name,temp);
						d.ptr[j].salary=d_temp;
					}
					else if((int)d.ptr[i].last_name[t]==(int)d.ptr[j].last_name[t]){
						t++;
						while (((int)d.ptr[i].last_name[t]==(int)d.ptr[j].last_name[t]) && (d.ptr[i].last_name[t]!='\0') && (d.ptr[j].last_name[t]!='\0')) t++;
						if ((int)d.ptr[i].last_name[t]<(int)d.ptr[j].last_name[t]){
							strcpy(temp,d.ptr[i].last_name);
							d_temp=d.ptr[i].salary;
							
							strcpy(d.ptr[i].last_name,d.ptr[j].last_name);
							d.ptr[i].salary=d.ptr[j].salary;
							
							strcpy(d.ptr[j].last_name,temp);
							d.ptr[j].salary=d_temp;
						}
						
						t=0;
					}
				
				}
			}
			
			std::cout << "\033[1;31mord\033[0m  ";
			std::cout << "\033[1;31mlast name\033[0m                          ";
			std::cout << "\033[1;31msalary\033[0m\n";
		  for (int i=0;i<d.get_size();++i) {
		    
		  	std::cout.setf(std::ios::left);
				std::cout.width(3);
		  	out<<i+1<<": ";
		  	
		  	
		  	std::cout.setf(std::ios::left);
				std::cout.width(32);
		  	out<<d.ptr[i].last_name<<"   ";
		  	
		  	std::cout.setf(std::ios::left);
				std::cout.width(32);
		  	out<<d.ptr[i].salary<<std::endl;
		  }
			return out;
		}
	
	void database::output_with_limits(double a,double b){
		
		person* p=new person[n];
		int k=0;
		for (int i=0;i<n;++i){
			if ((ptr[i].salary>=a) && (ptr[i].salary<=b)){	
				strcpy(p[k].last_name,ptr[i].last_name);
				p[k].salary=ptr[i].salary;
				k++;
			}
		}
		
		database C(k);
		for (int i=0;i<k;++i){
			strcpy(C.ptr[i].last_name,p[i].last_name);
			C.ptr[i].salary=p[i].salary;
		
		}
		delete[] p;
		
		std::cout<<"employees whose salary ranges from "<<a<<" to "<<b<<": "<<std::endl;
		std::cout<<C<<std::endl;
	
	
	}
	

	database::~database() {

		//std::cout << "destructor"<<  std::endl;
		if (ptr!=nullptr) {
			delete[] ptr;
			ptr=nullptr;
			}
			
	}
	
		  






