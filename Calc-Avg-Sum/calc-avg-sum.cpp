
// More robust version of the program
/*****************************************************************
program calc_avg_sum

This program calculates the average and sum of various predefined
arrays as specified by the test cases.

After the test cases have been processed, the user may continue 
running the program in user input mode. The user inputs custom 
boundary values to test their validity against array "XREG".

Warning: Boost library must be installed
*****************************************************************/

#include <algorithm>
//#include <concepts>
#include <boost/lexical_cast.hpp>
#include <boost/type_index.hpp>
#include <boost/typeof/typeof.hpp>
#include <boost/mp11.hpp>
#include <boost/callable_traits.hpp>
#include <iostream>
#include <tuple>
#include <typeinfo>
#include <type_traits>
#include <string>
#include <vector>
using namespace std;
using namespace boost;

template <typename T>
string getArrayType()
{
    return typeid(typename remove_extent<T>::type).name();
}
template <class T>
struct type_identity
{
    using type = T;
};
template <typename T> void arrType()
{
    typename T::value_Type s;
}

struct b
{
    double f();
};

// CONSTANTS

const double XBASE[] = { 1.0, 10.0, 6.25, 5000.0, 7.77, 2.25, 1265.29, 999.23,
   2145.24, 4999.99, 1.01, 2.22, 3.33, 4.44, 44.44, 444.44, 4444.44, 1.11,
    11.11, 111.11, 1111.11, 3750.0, 800.0, 6.66, 420.69 };

const double XLOW[] = { 1.0, 10.0, 6.25, 5000.0, 7.77, 2.25, 1265.29, 999.23,
   2145.24, 4999.99, 1.01, 2.22, 3.33, 4.44, 44.44, 444.44, 4444.44, 1.11,
    11.11, 111.11, 1111.11, 3750.0, 800.0, 6.66, 0.99 };

const double XHIGH[] = { 1.0, 10.0, 6.25, 5000.0, 7.77, 2.25, 1265.29, 999.23,
   2145.24, 4999.99, 1.01, 2.22, 3.33, 4.44, 44.44, 444.44, 4444.44, 1.11,
    11.11, 111.11, 1111.11, 3750.0, 800.0, 6.66, 5000.01 };

const double XREG[] = { 234.56, 123.45, 366.25, 500.0, 277.77, 625.25, 1265.29, 999.23,
   215.97, 999.99, 125.01, 327.67, 133.33, 444.44, 555.55, 666.66, 777.77, 163.83,
    888.88, 111.11, 1111.11, 375.0, 800.0, 655.35, 420.69 };

const double FLEX1[] = { 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
                  20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 19.9 };

const double FLEX2[] = { 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20,
                  20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 50.0 };

const double FLEX3[] = { 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
                    10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10 };

const int XINT[] = { 1,2,3,4,5,6,7,8,9,10,11,22,33,44,55,66,77,88,99,111,222,333,444,555,777 };

const string BAD[] = { "1","2","3","4","5","6","7","8","9","10","11","22","33",
            "44","55","66","77","88","99","111","222","333","444","555","777" };

const string* const BADARRAY = BAD;

const static int SIZE = 25;

template <class T>
void eval_type(const T& z)
{
    cout << boost::typeindex::type_id<T>() << endl;
}
template <class T>
void f(T)
{
    cout << boost::typeindex::type_id<T>().pretty_name();
}
template <class T>
string f2(T)
{
    return boost::typeindex::type_id<T>().pretty_name();
}

string f1(double d)
{
    string s;
    try
    {
        s = boost::lexical_cast<double>(d);
    }
    catch (const boost::bad_lexical_cast& e)
    {
        std::cerr << e.what() << '\n' << '\n';
    }
    return s;
}

bool bad_bounds(double lb, double ub)
{
    bool flag = (lb < 1.0 || ub > 5000.0 || ub <= lb);
    if (flag)
    {
        cout << "\nBounds must obey rule: 1.0 <= lb < ub <= 5000.0 ";
    }
    return flag;
}

bool verify_bounds(double j, double k, double lb, double ub)
{
    return (!bad_bounds(lb, ub) && lb <= j && ub >= k);
}

pair<double, double> calc_avg_sum(vector<double> X, double x = 0, double y = 0)
{
    pair<double, double> a;
    pair<double, double> bound = pair<double, double>(x, y);
    vector<double> Z;
    double sum;
    bool valid1, valid2;

    if (X.size() != SIZE)
    {
        cout << "\n******ERROR: Array to calculate is invalid size: " << X.size()
            << "******\n";
        return a;
    }
    if (!is_same_v<decay_t<decltype(X)>, decay_t<decltype(Z)>>)
    {
        cout << "\n***ERROR: Array has invalid data type: ";
        f(X.at(0));
        cout << "******\n";
        return a;
    }

    if (bound.first == 0 || bound.second == 0)
    {
        do
        {
            valid1 = true;
            valid2 = true;
            cout << "\nEnter the lower bound (LB): ";
            if (!(cin >> bound.first))
            {
                cin.clear();
                cin.ignore();
                valid1 = false;
                cout << "\nERROR: LB has invalid data type: " << f2(f1(bound.first))
                    << "\nTry again ";
            }

            cout << "\nEnter the upper bound (UB): ";
            if (!(cin >> bound.second))
            {
                cin.clear();
                cin.ignore();
                valid2 = false;
                cout << "\nERROR: UB has invalid data type: " << f2(f1(bound.second))
                    << "\nTry again ";
            }

        } while (!valid1 || !valid2 || bad_bounds(bound.first, bound.second));
    }

    stable_sort(X.begin(), X.end());
    cout << "\nUsing bounds: LB = " << bound.first << ", UB = " << bound.second;
    if (!verify_bounds(X.front(), X.back(), bound.first, bound.second))
    {
        cout << (X.front() <= bound.first ? "\nThere was a value smaller than the LB "
            : "\nThere was a value larger than the UB ")
            << "\n******The calculation has been compromised******\n";
        a = pair<double, double>(-1, -1);
        return a;
    }
    for (double y : X)
    {
        sum += y;
    }
    a.first = sum / 25.0;
    a.second = sum;
    cout << "\nAverage = " << a.first;
    cout << "\nSum = " << a.second << "\n******Compute Successful******\n";
    return a;
}

void optQuit()
{
    char c;
    cout << "\nContinue? (y/n) ";
    cin >> c;
    if (tolower(c) != 'y' || !cin)
    {
        cin.clear();
        cin.ignore();
        cout << "Exit code or invalid char received. Terminating program...\n";
        exit(0);
    }
}

void optContinue(vector<double>& X)
{
    char c;
    for (;;)
    {
        cout << "\nContinue? (y/n) ";
        cin >> c;
        if (tolower(c) != 'y' || !cin)
        {
            cin.clear();
            cin.ignore();
            cout << "Exit code or invalid char received. Terminating program...\n";
            exit(0);
        }
        calc_avg_sum(X);
    }
}

int main()
{
    vector<double> X;
    vector<string> Y;
    vector<int> Z;
    X.assign(XREG, XREG + 25);
    cout << "\nComputing normal (operational) test case for avg_sum (TC 12, 20)"
        << "\n(Using bounds LB = 100.0, UB = 2500.0) ";
    calc_avg_sum(X, 100, 2500);
    //optQuit();
    X.assign(XBASE, XBASE + 25);
    cout << "\nComputing boundary (operational) test case for avg_sum (TC 10, 15)"
        << "\nUsing specific bounds (LB = 1.0, UB = 5000.0) ";
    calc_avg_sum(X, 1, 5000);
    //optQuit();
    X.push_back(1000.0);
    cout << "\nComputing ERROR case with n=26 elements (Test case 1) ";
    calc_avg_sum(X);
    //optQuit();
    X.assign(XBASE, XBASE + 24);
    cout << "\nComputing ERROR case with n=24 elements (Test case 2) ";
    calc_avg_sum(X);
    //optQuit();
    X.assign(FLEX1, FLEX1 + 25);
    cout << "\nComputing ERROR case with an x-value lower than LB (Test case 3) ";
    calc_avg_sum(X, 20.0, 5000.0);
    //optQuit();
    X.assign(FLEX2, FLEX2 + 25);
    cout << "\nComputing ERROR case with an x-value higher than UB (Test case 4) ";
    calc_avg_sum(X, 1.0, 49.9);
    //optQuit();
    X.assign(XREG, XREG + 25);
    cout << "\nComputing ERROR case with LB = UB (Test cases 6, 14) ";
    calc_avg_sum(X, 5000.0, 5000.0);
    calc_avg_sum(X, 100.0, 100.0);
    //optQuit();
    cout << "\nComputing ERROR case with UB > 5000.0 (Test cases 7, 19) ";
    calc_avg_sum(X, 1.01, 5000.01);
    calc_avg_sum(X, 6.0, 5000.01);
    //optQuit();
    cout << "\nComputing ERROR case with LB < 1.0 (Test cases 9, 18) ";
    calc_avg_sum(X, 0.99, 5000.0);
    calc_avg_sum(X, 0.99, 1.21);
    //optQuit();
    cout << "\nComputing ERROR case with LB < 1.0 and UB > 5000.0 (Test cases 11, 16) ";
    calc_avg_sum(X, -10, 9000);
    calc_avg_sum(X, 0.99, 5000.01);
    //optQuit();
    cout << "\nComputing ERROR case with LB > UB (Test case 13) ";
    calc_avg_sum(X, 1000.0, 999.99);
    //optQuit();
    cout << "\nComputing CONDITIONAL case with LB ≈ UB (Test case 17) ";
    calc_avg_sum(X, 9.99, 10.00);
    X.assign(FLEX3, FLEX3 + 25);
    cout << "\nComputing CONDITIONAL Test case 17 but all array values = 10 ";
    calc_avg_sum(X, 9.99, 10.00);
    calc_avg_sum(X, 10.00, 10.00);
    //optQuit();
    X.assign(XHIGH, XHIGH + 25);
    cout << "\nComputing ERROR case with an Xvalue > 5000.0 (high) for avg_sum ";
    calc_avg_sum(X, 1, 5000);
    //optQuit();
    X.assign(XLOW, XLOW + 25);
    cout << "\nComputing ERROR case with an Xvalue < 1.0 (low) for avg_sum ";
    calc_avg_sum(X, 1, 5000);
    optQuit();
    X.assign(XINT, XINT + 25);
    cout << "\nComputing case with Xvalues as ints for avg_sum ";
    calc_avg_sum(X);
    // does not compile if using string array as input
    Y.assign(BADARRAY, BADARRAY + 25);
    //cout << "\nComputing ERROR case with Y as a string vector (TC 5)";
    //calc_avg_sum(Y);
    Z.assign(XINT, XINT + 25);
    //cout << "\nComputing ERROR case with Z as an int vector ";
    //calc_avg_sum(Z);
    X.assign(XREG, XREG + 25);
    optContinue(X);
    cout << "\n";

    return 0;
}

/****************************************************************/
