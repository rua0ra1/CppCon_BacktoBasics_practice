/* using tempelate meta programming for polymorphisim to avoid
virtual table overhead */
#include<iostream>
#include<memory>

using namespace std;
template<typename D>

class BaseFilter{
public:
void activate(){
    D& derived=static_cast<D&>(*this);
    derived.derivedActivate();
}
};
class FilterBright:public BaseFilter<FilterBright>
{
    public:
    void derivedActivate()
    {
        cout<<"Activate Bright"<<endl;
    }
};

class FilterDark:public BaseFilter<FilterDark>
{
    public:
    void derivedActivate()
    {
        cout<<"Activate Dark"<<endl;
    }
};

int main(){
    BaseFilter<FilterBright> f1;
    f1.activate();
    BaseFilter<FilterDark> f2;
    f2.activate();

}