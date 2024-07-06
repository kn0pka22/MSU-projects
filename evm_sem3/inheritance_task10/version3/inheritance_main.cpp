 
#include <iostream>
#include "inheritance.hpp"


int main(){
    Array Ar(10);
    Array B(Ar);
    size_t s=B.Size();
    for (size_t i=0;i<s;++i) B[i]=i*i;
    B.print();
    
    /*
    std::cout<<"AddConstant(7): "<<std::endl;
    AddConstant AddConst(7);
    Ar = AddConst.Process(B);
    Ar.print();
    
    std::cout<<"Clip(20,70): "<<std::endl;
    Clip clip(20,70);
    Ar=clip.Process(B);
    Ar.print();
    
    try {
    	std::cout<<"Log: "<<std::endl;
			Log log;
			Ar=log.Process(B);
			Ar.print();
 		}
 		catch(const char* e) {
 			std::cout << "Got an exception. Reason: " << e << std::endl;
 		}
    */
    
    Pipeline pl;
    
    pl.AddOperator(new AddConstant(10));
    pl.AddOperator(new Clip(1, 200));
    
    
			pl.AddOperator(new Log());
 		
    
    Ar = pl.Process(B);
    Ar.print();
    return 0;
}
