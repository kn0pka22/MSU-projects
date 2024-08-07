 
#include <iostream>
#include "inheritance.hpp"


int main(){
    Array Ar(10);
    Array B(Ar);
    size_t s=B.Size();
    for (size_t i=0;i<s;++i) B[i]=i*i;
    B.print();
    
    std::cout<<"AddConstant(7): "<<std::endl;
    AddConstant AddConst(7);
    Ar = AddConst.Process(B);
    B.print();
    
    std::cout<<"Clip(20,70): "<<std::endl;
    Clip clip(20,70);
    clip.Process(B);
    B.print();
    
    Pipeline pl;
    
    pl.AddOperator(new AddConstant(10));
    //pl.AddOperator(new Clip(1, 20));
    //pl.AddOperator(new Log());
    
    //A = pl.Process(B);
    return 0;
}
