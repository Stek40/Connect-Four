#include <iostream>


int main()
{
    Board b = Board(10,15);

    b.update(1);
    b.print();
    b.update(1);
    b.print();
    b.update(2);
    b.print();
    b.update(2);
    b.print();
    b.update(3);
    b.print();
    b.update(3);
    b.print();
    b.update(4);
    if (b.win()) 
    {
        int a;
        std::cin>>a; //here it must stop because it is vertical win 
    };
    b.print();
    b.update(2);
    b.print();


    return 0;
}
