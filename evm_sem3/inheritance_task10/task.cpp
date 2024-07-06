#include <iostream>



 class Array {
    public:
        Array(size_t size){
            data=new double[size];
            this->size=size;
        }
        
        Array(const Array& other){
            size=other.size;
            for (size_t i=0;i<size;++i){
                data[i]=other.data[i];
            }
        }
        
        ~Array(){
            delete[] data;
        }
        
        Array& operator=(const Array& other){
            if (data) delete[] data;
            data=new double[other.size];
            size=other.size;
            for (size_t i=0;i<size;++i){
                data[i]=other.data[i];
            }
        }
        
        double operator[](size_t index) const{
            return data[index];
        }
        
        double& operator[](size_t index){
             return data[index];
        }
        
        size_t Size() const { return size; }
    private:
        double* data;
        size_t size;
 };
 
 // Базовый класс для всех операций. Метод Process() получает на вход
 // массив данных и возвращает новый массив после применения к исходному
 // массиву требуемой операции.
 class Operator {
    public:
        virtual Array Process(const Array& input) const = 0;
        virtual ~Operator() { }
 };
 
 // В этом классе метод Process должен добавлять константу к каждому элементу
 // входного массива.
 
 class AddConstant : public Operator {
    private:
        double value;
    public:
        AddConstant(double value);
        // Добавить сюда необходимые методы.
 };
 
 // В этом классе метод Process ограничивает элементы входного массива заранее
 // заданными минимальным и максимальным значением. То есть элементы, выходящие
 // за заданные границы заменяются соответствующим граничным значением.
 class Clip : public Operator {
    private:
        double minValue;
        double maxValue;
    public:
        Clip(double minValue, double maxValue);

    // Добавить сюда необходимые методы.
 };
 // В этом классе метод Process должен поэлементно вычислить натуральный логарифм
 // от массива данных.
 class Log : public Operator {
    // Добавить сюда необходимые методы.
 };
 
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
 };

int main(){
    Array Ar(10);
    
    return 0;
}
