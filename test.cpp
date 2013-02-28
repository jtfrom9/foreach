#include "foreach.hpp"
#include<iostream>

using namespace std;

class D
{
    int _n;

public:
    D(int n): _n(n) {}

    friend ostream& operator<<(ostream& os, D& d);
};

ostream& operator<<(ostream& os, D& d) 
{
    os << d._n;
    return os;
}

int main()
{
    vector<int> v;
    v.push_back(0);
    v.push_back(1);
    v.push_back(2);
    VECTOR_FOREACH(int, x, v) {
        cout << x << endl;
    }
    
    list<D*> l;
    l.push_back(new D(0));
    l.push_back(new D(1));
    l.push_back(new D(2));
    LIST_FOREACH(D*, pd, l) {
        cout << *pd << endl;
        delete pd;
    }
    l.clear();
}
