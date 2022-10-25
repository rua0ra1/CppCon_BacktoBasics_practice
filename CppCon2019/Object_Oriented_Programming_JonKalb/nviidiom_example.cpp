
/*non virtual interface idiom  */
#include<iostream>
#include<memory>
#include<fstream>

struct Logger
{
    virtual void LogMessage(char const* message)=0;
    virtual ~Logger()=default;
};

struct NVILogger{
virtual void LogMessage(char const* message){
    /* do pre */
    DoLogMessage(message);
    /* do finish*/
}
virtual ~NVILogger()=default;

private:
virtual void DoLogMessage(char const*message)=0;

};