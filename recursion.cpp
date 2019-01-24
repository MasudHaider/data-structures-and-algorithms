#include<iostream>

void TowerOfHanoi(int n, char from, char to, char via)
{
    //if only 1 disk, make the move and return
    if(n == 1)
    {
        std::cout<<"Move disk 1 from peg "<<from<<" to peg "<<to<<std::endl;
        return;
    }
    //Move top n-1 disks from A to B, using C as auxiliary
    TowerOfHanoi(n-1, from, via, to);

    //Move remaining disks from A to C
    std::cout<<"\nMove disk "<< n <<" from peg "<<from<<" to peg "<< to <<std::endl;

    //Move n-1 disks from B to C, using A as auxiliary
    TowerOfHanoi(n-1, via, to, from);
}

int main()
{
    TowerOfHanoi(4,'A','B','C');
    return 0;
}
