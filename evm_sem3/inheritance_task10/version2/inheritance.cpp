 
#include<iostream>
#include<cstring>
#include <fstream>
#include "inheritance.hpp"
#include  <cmath>

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
            Array output(input);
        	size_t s=input.Size();
					for (size_t i=0;i<s;++i){
						output[i]+=value;
					}        
					return output;
        }
       
 
 
 // В этом классе метод Process ограничивает элементы входного массива заранее
 // заданными минимальным и максимальным значением. То есть элементы, выходящие
 // за заданные границы заменяются соответствующим граничным значением.

        Clip::Clip(double minValue, double maxValue){
        	this->minValue=minValue;
        	this->maxValue=maxValue;
        }
        Array Clip::Process(const Array& input) const {
            Array output(input);
            size_t s=input.Size();
                for (size_t i=0;i<s;++i){
                    if (output[i]>=maxValue) output[i]=maxValue;
                    if (output[i]<=minValue) output[i]=minValue;
                    }   
                return output;     
        }


 
 // В этом классе метод Process должен поэлементно вычислить натуральный логарифм
 // от массива данных.
 
    Array Log::Process(const Array& input) const {
        size_t s=input.Size();
        Array output(input);
        for (size_t i=0;i<s;++i){
            output[i]=std::log(output[i]);
        }        
		return output;
    }

 
    Pipeline::Pipeline(){
        count=0;
        ops=nullptr;
    }
 
    Array Pipeline::Process(const Array& input) const {
        Array output(input);
        for (size_t i=0;i<count;++i){
            ops[i]->Process(input);
        }  
        return output;
    }
    void Pipeline::AddOperator(Operator* Op){
        Operator** tmp;
        tmp = new Operator*[count + 1];
        
        for (size_t i=0;i<count;++i) tmp[i] = ops[i];
        
        tmp[count]=Op;
        
        delete[] ops;
        ops = tmp;
        count++;
        //return 
    }
    Pipeline::~Pipeline(){
        for (size_t i=0;i<count;++i)
            delete ops[i];
        
        delete[] ops;
    }
