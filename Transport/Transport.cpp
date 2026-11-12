#include <iostream>
#include <string>
using namespace std;

class Transport
{
protected:
    string fuelType;
    int loadCapacity;
    int fuelConsumption;

public:

    Transport(string fType, int capacity, int consumption)
    {
        fuelType = fType;
        loadCapacity = capacity;
        fuelConsumption = consumption;
    }

    virtual ~Transport() {}

    string GetFuelType() 
    { 
        return fuelType; 
    }
    int GetLoadCapacity() 
    { 
        return loadCapacity; 
    }

    void SetFuelType(string newFuel) 
    { 
        fuelType = newFuel; 
    }

    virtual void Print()
    {
        cout << "Fuel: " << fuelType << ", Load Capacity: " << loadCapacity << ", Consumption: " << fuelConsumption << endl;
    }
};

class Car : public Transport
{
public:
    Car() : Transport("Petrol", 500, 8) {} 

    void Print() override
    {
        cout << "[Car] ";
        Transport::Print(); 
    }
};

class Ship : public Transport
{
public:
    Ship() : Transport("Diesel", 50000, 200) {}

    void Print() override
    {
        cout << "[Ship] ";
        Transport::Print();
    }
};

class Airplane : public Transport
{
public:
    Airplane() : Transport("Kerosene", 20000, 500) {}

    void Print() override
    {
        cout << "[Airplane] ";
        Transport::Print();
    }
};

class Motorcycle : public Transport
{
public:
    Motorcycle() : Transport("Petrol", 150, 4) {}

    void Print() override
    {
        cout << "[Motorcycle] ";
        Transport::Print();
    }
};

int main()
{

    Transport* garage[10];
    int count = 0;
    int choice = -1;

    while (choice != 0 && count < 10)
    {
        cout << "\nMENU\n";
        cout << "1. Create Car\n";
        cout << "2. Create Ship\n";
        cout << "3. Create Airplane\n";
        cout << "4. Create Motorcycle\n";
        cout << "5. Show all transport\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1: 
            garage[count++] = new Car(); 
            break;
        case 2: 
            garage[count++] = new Ship();
            break;
        case 3: 
            garage[count++] = new Airplane(); 
            break;
        case 4: 
            garage[count++] = new Motorcycle(); 
            break;
        case 5:
            cout << "\nTransport List:\n";
            for (int i = 0; i < count; i++)
            {
                garage[i]->Print();
            }
            break;
        }
    }

    for (int i = 0; i < count; i++)
    {
        delete garage[i];
    }

    return 0;
}