#include<iostream>
#include<memory>
#include<fstream>

struct Logger
{
    virtual void LogMessage(char const* message)=0;
    virtual ~Logger()=default;
};

struct ConsoleLogger final:Logger
{
    virtual void LogMessage(char const* message) override{
        std::cout<<message<<'\n';
    }
};
struct FileLogger final: Logger{
   

    FileLogger(char const* filename):
    output_{filename}{}

    virtual void LogMessage(char const * message) override{
        output_<<message<<'\n';
    }

    private:
    std::ofstream output_;

};

void LogHelloWorld(Logger& logger){
    logger.LogMessage("Hello,World");
}

int main(){
    //example 1
    auto logger =std::make_unique<ConsoleLogger>();
    Logger* logger_ptr=logger.get();
    logger_ptr->LogMessage("Hello ,World");

    //example 2
    //creating a unique pointer tp dervied class console logger
     auto logger2 =std::make_unique<ConsoleLogger>();
     // passing above dervied class console logger pointer as raw pointer
     // to below function
    LogHelloWorld(*logger2);
    //type casting dervied class to base class logger and passing that object
    LogHelloWorld(*static_cast<Logger*>(logger2.get()));

    //example 3
    auto cl{ConsoleLogger{}};
    auto fl{FileLogger{"logfile.text"}};
    LogHelloWorld(cl);
    LogHelloWorld(fl);

    /* scoots challenge
    Lizard liz1;
    Lizard liz2;
    Animal *pAnimal1= &liz1;
    Animal *pAnimal2=&liz2;
    *pAnimal1=*pAnimal2; // it causes slicing
    what is slicing?
    refer slicingecample.cpp

     */


}