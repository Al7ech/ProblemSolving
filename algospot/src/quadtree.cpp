#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

class QuadTree
{
private:
    char value;
    QuadTree *child[4];
public:
    static int const_index;
    QuadTree(char Q[])
    {
        value = Q[const_index++];
        if(value == 'x')
            for(int i=0;i<4;i++)
                child[i] = new QuadTree(Q);
    }
    void print()
    {
        printf("%c",value);
        if(value == 'x')
        {
            child[2]->print();
            child[3]->print();
            child[0]->print();
            child[1]->print();
        }
        delete this;
    }
};

int QuadTree::const_index;

int main()
{

    int C;

    scanf("%d",&C);

    for(int t=0;t<C;t++)
    {
        QuadTree::const_index = 0;
        char Q[1500];
        scanf("%s",Q);
        QuadTree *root = new QuadTree(Q);
        root->print();
        puts("");
    }

    return 0;
}