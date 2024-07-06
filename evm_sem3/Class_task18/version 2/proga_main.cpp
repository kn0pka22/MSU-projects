#include<iostream>
#include"database.hpp"

int main() {


	database A("/home/student/Desktop/3 sem/dz1_classes/version 2/test");
	database B("/home/student/Desktop/3 sem/dz1_classes/version 2/test");

	//database A("/users/2/206/Balakaeva_MI/Рабочий стол/evm_3/test");
	//database B("/users/2/206/Balakaeva_MI/Рабочий стол/evm_3/test");
	
	
	std::cout<<"Base A: "<<std::endl;
	std::cout<<A<<std::endl;
	std::cout<<"Base B: "<<std::endl;
	std::cout<<B<<std::endl;;
	
	database C=A+B;
	std::cout<<"Base C=A+B: "<<std::endl;
	std::cout<<C<<std::endl;
	
	std::cout<<"Base A: "<<std::endl;
	std::cout<<A<<std::endl;

	
	std::cout<<"Base A+=B: "<<std::endl;
	std::cout<<(A+=B)<<std::endl;   
	
	B["Demidovich"]=230000;
	
	std::cout<<"Base B with new person: "<<std::endl;
	std::cout<<B<<std::endl;
	
	B.remove("Sergeev");
	
	std::cout<<"Base B without Sergeev: "<<std::endl;
	std::cout<<B<<std::endl;
	
	B.output_with_limits(20000,25000);
	
	database D=A;
	std::cout<<"D=A: "<<std::endl;
	std::cout<<D<<std::endl;
	
	std::cout<<"D=B: "<<std::endl;
	D=B;
	std::cout<<D<<std::endl; 
	
	return 0;
} 
