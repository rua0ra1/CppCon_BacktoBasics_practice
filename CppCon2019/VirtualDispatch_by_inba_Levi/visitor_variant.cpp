#include <variant>
#include <string>
#include <cassert>
#include <iostream>

using namespace std;


struct FilterBright{};
struct FilterDark{};

struct VisitActivate{
  void operator()(FilterBright& filter){cout<<"Filter Bright";}
  void operator()(FilterDark& filter){cout<<"Filter Dark";}

};


int main(){
    std::variant<FilterBright,FilterDark> MyFilter{FilterBright()};
    std::visit(VisitActivate(),MyFilter);
}