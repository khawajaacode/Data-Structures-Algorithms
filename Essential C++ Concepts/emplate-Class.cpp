#include <iostream>

using namespace std;

template<class T>
class Arthimetic{
    private:
    T a;
    T b;
    public:
    Arthimetic(T a, T b);
        T add();
        T sub();
    

};

template<class T>
   Arthimetic<T>::Arthimetic(T a, T b){
        this->a = a;
        this->b = b;
    }
template<class T>
    T Arthimetic<T>::add() {
        T c;
        c = a + b;
        return c;
    }
    
template<class T>
    T Arthimetic<T>::sub() {
        T d;
        d = a - b;
        return d;
    }


int main()
{
    Arthimetic<char> ar('a','b');

    cout<< "ADD " <<(int) ar.add() <<endl;
    cout << "Subtract " << (int) ar.sub();
    

    return 0;
}