#include <iostream>
int main() {
    int A,B,C,r;
    std::cin>>A>>B>>C;
    r=( C <= B ) ? -1 : (1 + A / (C-B) );
    std::cout<<r;
}
