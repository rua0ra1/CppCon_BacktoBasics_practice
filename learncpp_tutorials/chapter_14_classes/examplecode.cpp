#include <iostream>
#include <string>
#include <string_view>

/* example 1 */
// enum AnimalType
// {
//     cat,
//     dog,
//     chicken,
// };

// constexpr std::string_view animalName(AnimalType type){
//     switch(type){
//         case cat: return "cat";
//         case dog: return "dog";
//         case chicken: return "chicken";
//         default: return " ";
//     }
// }

// constexpr int numLegs(AnimalType type){
//     switch (type)
//     {
//     case cat: return 4;
//     case dog: return 4;
//     case chicken: return 2;
//     default:  return 0;
//     }
// }

// int main()
// {
//     constexpr AnimalType animal{ cat };
//     std::cout << "A " << animalName(animal) << " has " << numLegs(animal) <<
//     " legs\n";

//     return 0;
// }

/* Example2  */
// struct Date {
//   int day{};
//   int month{};
//   int year{};
//   void printDate() {
//     std::cout << day << "/" << month << '/' << year;
//   }
// };


// /* example 3 const member function */
// struct Date{
//      const int year{10};
//      const int month{22};
//      const int day{23};

//     void print() const  {
//         std::cout<<year<<'/'<< month<<'/'<<day;
//     }

// };

// void doSomething(const Date& date){
//     date.print();
// }

// /* exampkle 4 access levels work on a per class basis */
// class Person
// {
// private:
//     std::string m_name{};

// public:
//     void kisses(const Person& p) const
//     {
//         std::cout << m_name << " kisses " << p.m_name << '\n';
//     }

//     void setName(std::string name)
//     {
//         m_name = name;
//     }
// };

/* returning data members by lvalue reference */
class Employee{
    std::string m_name{};
    public:
     void setName(std::string_view name){
        m_name=name;
     }

     const std::string& getName(){return m_name;}
};

int main() {
  Employee joe{};
  joe.setName("Joe");
  std::cout<<joe.getName();

  return 0;
}
