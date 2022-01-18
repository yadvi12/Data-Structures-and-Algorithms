#include <bits/stdc++.h>
using namespace std;

class Food
{
private:
    int ratings;

public:
    char taste_level;

    // CONSTRUCTOR
    // when we define our own constructor, default contructor won't exists anymore
    Food()
    {
        cout << endl
             << "___________DEFAULT CONSTRUCTOR CALLED___________" << endl
             << endl;
    }

    // Parameterised Constructor
    // Food(int ratings)
    // {
    //     this->ratings = ratings;
    // }

    // Copy Constructor
    // copy by reference is used to avoid getting stuck in an infinite loop
    Food(Food &temp)
    {
        cout << "___________COPY CONSTRUCTOR CALLED___________";
        this->ratings = temp.ratings;
        this->taste_level = temp.taste_level;
    }

    void print()
    {
        cout << taste_level << endl;
    }

    //getter and setter functions are used to access and manipulate data members stored in private access modifiers

    // getter functions
    int getratings()
    {
        return ratings;
    }

    char getlevel()
    {
        return taste_level;
    }

    //setter functions
    void setratings(int r)
    {
        ratings = r;
    }

    void setlevel(int level)
    {
        taste_level = level;
    }
};

int main()
{
    // creation of object - INSTANTIATION

    // STATIC ALLOCATION
    Food pasta;

    // pasta.ratings = 5;
    pasta.setratings(4);
    pasta.taste_level = 'A';

    cout << "Rating is " << pasta.getratings() << endl;
    cout << "Taste level is " << pasta.taste_level << endl;

    // Copy Constructor is called - it will be generated automatically
    Food macroni(pasta);

    cout << endl
         << "___________COPY CONSTRUCTOR CALLED___________" << endl
         << endl;

    cout << "Rating is " << macroni.getratings() << endl;
    cout << "Taste level is " << macroni.taste_level << endl;

    // DYNAMIC ALLOCATION
    // Method 1
    Food *momos = new Food;

    // Method 2
    Food *pizza = new Food();

    momos->setratings(5);
    momos->setlevel('A');

    cout << endl
         << "___________METHOD 1 TO ACCESS DATA MEMBERS___________" << endl
         << endl;
    cout << "Ratings is " << (*momos).getratings() << endl;
    cout << "Taste level is " << (*momos).taste_level << endl;

    cout << endl
         << "___________METHOD 2 TO ACCESS DATA MEMBERS___________" << endl
         << endl;

    cout << "Ratings is " << momos->getratings() << endl;
    cout << "Taste level is " << momos->taste_level << endl;
    // cout << "size: " << sizeof(pasta) << endl;

    cout << endl;

    return 0;
}