/* Chris Levantis 321-2020110
H ασκηση έχει υλοποιηθει με εναν πινακα
*/
#include <iostream>
#include <typeinfo>
#define N 10
using namespace std;

/////////////////////////////CAR///////////////////////////////////////////
class Car
{
    string model;
    string brand;
    int xronologia;

public:
    void set_car(string model, string brand, int xronologia);
    string get_model();
    string get_brand();
    int get_xronologia();

    void set_model(string model);
    void set_brand(string brand);
    void set_xronologia(int xronologia);
};
void Car::set_car(string model, string brand, int xronologia)
{
    this->model = model;
    this->brand = brand;
    this->xronologia = xronologia;
}
string Car::get_model()
{
    return model;
}
string Car::get_brand()
{
    return brand;
}
int Car::get_xronologia()
{
    return xronologia;
}

void Car::set_model(string model)
{
    this->model = model;
}
void Car::set_brand(string brand)
{
    this->brand = brand;
}
void Car::set_xronologia(int xronlogia)
{
    this->xronologia = xronlogia;
}
////////////////////////////BIKE////////////////////////////////////////////
class Bike
{
    string model;
    string cc;
    int hp;

public:
    void set_bike(string model, string cc, int hp);
    void set_model(string model);
    void set_cc(string cc);
    void set_hp(int hp);
    string get_model();
    string get_cc();
    int get_hp();
};
void Bike::set_bike(string model, string cc, int hp)
{
    this->model = model;
    this->cc = cc;
    this->hp = hp;
}
string Bike::get_model()
{
    return model;
}
string Bike::get_cc()
{
    return cc;
}
int Bike::get_hp()
{
    return hp;
}
void Bike::set_model(string model)
{
    this->model = model;
}
void Bike::set_cc(string cc)
{
    this->cc = cc;
}
void Bike::set_hp(int hp)
{
    this->hp = hp;
}
///////////////////////////GARAGE/////////////////////////////////////////
template <typename T>
class Garage
{
    T *grg_array = new T[N]; // dynamic array
public:
    int count = 0; // public counter for print function--metrao me auto ta oximata pou exi to Garage

    void print_Elements(); // --> den zitite apo tin askisi alla to ekana gia eukolia dikia mou...(kai gia na dite tin object_delete() pos douleui)

    void object_add(int pos, string a, string b, int c);
    void object_delete(int pos);
    void print() // tiponi ta oximata sto Garage me tin boithia tou counter...
    {
        cout << "Objects --> " << count << endl;
    }
    
    /// + Overloading
    int operator+(Garage<Bike> bike)
    {
        return this->count + bike.count;
    }

    /// == Overloading
    bool operator==(Garage<Bike> &y)
    {
        if (this->count == y.count)
        {
            return true;
        }
        else
            return false;
    }
};
template <> /// print the elements of the Garage ONLY FOR CAR
void Garage<Car>::print_Elements()
{
    for (int i = 0; i < N; i++)
    {
        if (grg_array[i].get_brand() != "")
        {
            cout << grg_array[i].get_brand() << endl;
            cout << grg_array[i].get_model() << endl;
            cout << grg_array[i].get_xronologia() << endl;
            cout << "\n";
        }
    }
}
template <> /// print the elements of the Garage ONLY FOR BIKE
void Garage<Bike>::print_Elements()
{
    for (int i = 0; i < N; i++)
    {
        if (grg_array[i].get_model() != "")
        {
            cout << grg_array[i].get_model() << endl;
            cout << grg_array[i].get_cc() << endl;
            cout << grg_array[i].get_hp() << endl;
            cout << "\n";
        }
    }
}

template <> /// -> for Add Car
void Garage<Car>::object_add(int pos, string a, string b, int c)
{
    grg_array[pos].set_car(a, b, c);
    count++;
}
template <> /// -> for Add Bike
void Garage<Bike>::object_add(int pos, string a, string b, int c)
{
    grg_array[pos].set_bike(a, b, c);
    count++;
}

template <> /// delete ONLY CAR
void Garage<Car>::object_delete(int pos)
{
    grg_array[pos].set_brand("EMPTY");
    grg_array[pos].set_model("EMPTY");
    grg_array[pos].set_xronologia(NULL);
    count--; // mionoume kai ton metriiti count giati "feugi" ena amazi apo to Garage
}
template <> /// delete ONLY BIKE
void Garage<Bike>::object_delete(int pos)
{
    grg_array[pos].set_model("EMPTY");
    grg_array[pos].set_cc("EMPTY");
    grg_array[pos].set_hp(NULL);
    count--; // mionoume kai ton metriiti count giati "feugi" ena bike apo to Garage
}

int main()
{
    cout<<"////////////////////////////////////////"<<endl;
    Garage<Car> car;
    car.object_add(0, "Honda", "s2000", 2002);
    car.object_add(3, "Chevrolet", "Camaro", 1990);
    car.object_add(2, "Mitsubishi", "Pajero", 2005);
    cout << "--Elements Cars with values -->" << endl;
    car.print_Elements();
    cout << "--Cars OBJECTS THAT ARE IN THE GARAGE--\n";
    car.print();
    cout<<"--Elements Print after the deletion of the thrird(3) element of the Array, and the second car int the Garage (Camaro)."<<endl;
    car.object_delete(3);
    cout<<"-- Car Objects now in the Garage, after the deletion of the Camaro"<<endl;
    car.print_Elements();

    car.print();
    cout<<"////////////////////////////////////////"<<endl;
    Garage<Bike> bike;
    bike.object_add(1, "KTM DUKE", "1290", 180);
    bike.object_add(4, "Ducati Hypermotard", "1100", 100);
    bike.object_add(6, "Suzuki GSX-R", "1000", 180);
    cout << "Elements Bikes with values -->" << endl;
    bike.print_Elements();
    cout << "--Bikes OBJECTS THAT ARE IN THE GARAGE--\n";
    bike.print();
    
    cout<<"////////////////////////////////////////"<<endl;
    // Operator overloading
    cout << "--Operator overloading--" << endl;
    cout << "Comparing car and bike objects in Garage ('==')." << endl;
    if (car == bike)
    {
        cout << "(Overloading operation) yes they are the same..." << endl;
    }
    else
    {
        cout << "(Overloading operation) No they are not the same..." << endl;
    }

    cout << "\n\nALL OBJECTS IN GARAGE (CAR AND BIKES) --> " << car + bike << endl;

    return 0;
}
