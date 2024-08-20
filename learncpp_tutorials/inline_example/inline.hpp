#pragma once
/* 
It's most beneficial for small, frequently used functions and 
is often used in header files to prevent multiple definition errors. 
However, the compiler ultimately decides whether or not to inline a function. */
inline int sum(const int a,const int b){
    return a+b;
}