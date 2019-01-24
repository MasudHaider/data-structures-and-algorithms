#include<iostream>
using namespace std;
int moves = 0;
void TowerOfHanoi(int n, char from, char to, char via)
{
    moves++;
    //if only 1 disk, make the move and return
    if(n == 1)
    {
        cout<<"Move disk 1 from peg "<<from<<" to peg "<<to<<endl;
        return;
    }
    //Move top n-1 disks from A to B, using C as auxiliary
    TowerOfHanoi(n-1, from, via, to);

    //Move remaining disks from A to C
    cout<<"\nMove disk "<< n <<" from peg "<<from<<" to peg "<< to <<endl;

    //Move n-1 disks from B to C, using A as auxiliary
    TowerOfHanoi(n-1, via, to, from);
}

int main()
{
    int discs;
    cout << "Enter the number of discs: " << endl;
    cin >> discs;
    TowerOfHanoi(discs, 'A', 'B', 'C');
    cout << "It took " << moves << " moves. " << endl;

    return 0;
}
