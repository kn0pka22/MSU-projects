#include<iostream>
#include<cstring>
#include <fstream>
#include "inheritance.hpp"

 Array::Array(size_t size){
            data=new double[size];
            this->size=size;
        }
        
        Array::Array(const Array& other){
            size=other.size;
            data=new double[size];
            for (size_t i=0;i<size;++i){
                data[i]=other.data[i];
            }
        }
        
        Array::~Array(){
            delete[] data;
        }
        
        Array& Array::operator=(const Array& other){
            if (data) delete[] data;
            data=new double[other.size];
            size=other.size;
            for (size_t i=0;i<size;++i){
                data[i]=other.data[i];
            }
            return *this;
        }
        
        double Array::operator[](size_t index) const{
            return data[index];
        }
        
        double& Array::operator[](size_t index){
             return data[index];
        }
        
        size_t Array::Size() const { return size; }
        
        void Array::print(){
        	std::cout<<"Size of array: "<<size<<"and elements: "<<std::endl;
        	for (size_t i=0;i<size;++i){
                std::cout<<data[i]<<"  ";
            }
           std::cout<<std::endl;
        }

 
 
 // Базовый класс для всех операций. Метод Process() получает на вход
 // массив данных и возвращает новый массив после применения к исходному
 // массиву требуемой операции.

        Array Operator::Process(const Array& input) const{ return input; }
        Operator::~Operator() { }

 
 // В этом классе метод Process должен добавлять константу к каждому элементу
 // входного массива.
 
        AddConstant::AddConstant(double value) {  this->value=value; }
        Array AddConstant::Process(const Array& input) const {
        	int s=input.Size();
					for (size_t i=0;i<s;++i){
						input.data[i]+=value;
					}        
					return input;
        }
       
 
 
 // В этом классе метод Process ограничивает элементы входного массива заранее
 // заданными минимальным и максимальным значением. То есть элементы, выходящие
 // за заданные границы заменяются соответствующим граничным значением.

        Clip::Clip(double minValue, double maxValue){
        	this->minValue=minValue;
        	this->maxValue=maxValue;
        }
        Array Clip::Process(const Array& input) const {
		      int s=input.Size();
						for (size_t i=0;i<s;++i){
							if (input.data[i]>=maxValue) input.data[i]=maxValue;
							if (input.data[i]<=minValue) input.data[i]=minValue;
						}   
					return input;     
        }


 
 // В этом классе метод Process должен поэлементно вычислить натуральный логарифм
 // от массива данных.
 class Log : public Operator {
    // Добавить сюда необходимые методы.
 };
 /*
 class Pipeline : public Operator {
    private:
        // Произвольные операторы. Двойные указатели нужны для
        // обеспечения полиморфного поведения.
        Operator** ops;
        // Их количество.
        size_t count;
    public:
        // Здесь требуется дописать конструкторы, метод для добавления оператора
        // в цепочку и метод Process() для применения операторов по цепочке.
 };*/


