#include<iostream>
#include<cstring>
#include <fstream>




 class Array {
    public:
        Array(size_t size);
        
        Array(const Array& other);
        
        ~Array();
        
        Array& operator=(const Array& other);
        
        double operator[](size_t index) const;
        
        double& operator[](size_t index);
        
        size_t Size() const;
        
        void print();
    private:
        double* data;
        size_t size;
 };

 class Operator {
    public:
        virtual Array Process(const Array& input) const = 0;
        virtual ~Operator();
 };
 
 
 class AddConstant : public Operator {
    private:
        double value;
    public:
        AddConstant(double value);
        Array Process(const Array& input) const override;
 };

 class Clip : public Operator {
    private:
        double minValue;
        double maxValue;
    public:
        Clip(double minValue, double maxValue);
        Array Process(const Array& input) const override;
 };

 class Log : public Operator {
   
 };
 
 class Pipeline : public Operator {
    private:
       
        Operator** ops;

        size_t count;
    public:
        
 };

