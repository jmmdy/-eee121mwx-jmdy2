#include <iostream>
#include <cmath>
#include <string>

using namespace std;


template<typename T>
class Pair {
    private:
        T first, second;
    public:
        Pair(T first, T second);
        //Accessor
        T get_first();
        T get_second();

        //mutator
        void set_first(T val);
        void set_second(T val);

        Pair<T> operator+(Pair b);
        Pair<T> operator/(Pair b); //new operator

        void show_pair();
};



template<typename T>
Pair<T>::Pair(T first, T second) {
    this -> first = first;
    this -> second = second;
}

template<typename T>
T Pair<T>::get_first() {
    return this -> first;
}

template<typename T>
T Pair<T>::get_second() {
    return this -> second;
}

template<typename T>
void Pair<T>::set_first(T val) {
    this -> first = val;
}

template<typename T>
void Pair<T>::set_second(T val) {
    this -> second = val;
}

template<typename T>
void Pair<T>::show_pair() {
    cout << this -> first << " and " << this -> second << endl;
}

template<>
void Pair<int>::show_pair() {
    cout << this -> first << endl;
}

template<typename T>
Pair<T> Pair<T>::operator+(Pair b) {
    return Pair(this -> first + b.first,
                this -> second + b.second);
}

template<typename T>
Pair<T> Pair<T>::operator/(Pair b) {
    string finalval, finalvalb;
    if ((first.length()) > (second.length())) { //compare first pair
        finalval = first;
    } else {
        (finalval = second);

    };

    if ((b.first.length()) > (b.second.length())) {// compare second pair
        finalvalb = b.first;
    } else {
        (finalval = b.second);
    };

    if ((finalval.length()) > (finalvalb.length())) { //compare both pairs
        finalval = finalval;
    } else {
        (finalval = finalvalb);
    };

    first = finalval[0]; //get the most recurred value
    // float finallength = finalval.size();
    second = finalval.size(); //get the length of this value

    return Pair(this -> first,
                this -> second);
}

template<>
Pair<int> Pair<int>::operator/(Pair<int> b) {
    float finalval = first + second + b.first + b.second; //average equation
    float finalave = finalval / 4;
    cout << finalave << endl;
    // first = finalave;
    // second = 0;

    // return Pair(this -> first,
    //             this -> second);
};

int main() {
    string input1, input2, input3, input4;
    int input5, input6, input7, input8;
    // Pair<string> p_str = Pair<string>("Banana B1", "Banana B2");
    // Pair<int> p_int = Pair<int>(3,5);

    // p_str.show_pair();
    // p_int.show_pair();
    cin >> input1;
    cin >> input2;
    cin >> input3;
    cin >> input4;
    cin >> input5;
    cin >> input6;
    cin >> input7;
    cin >> input8;
    Pair<string> p1 = Pair<string>(input1, input2);
    Pair<string> p2 = Pair<string>(input3, input4);
    Pair<int> p3 = Pair<int>(input5, input6);
    Pair<int> p4 = Pair<int>(input7, input8);
    (p1/p2).show_pair();
    (p3/p4).show_pair();

    return 0;
}