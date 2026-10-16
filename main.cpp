#include <iostream>
using namespace std;

//================= Part 1: Basics of a Function =================
/*
Functions are blocks of code that perform a specific task. They can take inputs (parameters) and return outputs (return values).
The advantage of using functions is that they allow for code reuse and better organization.
Code in functions are only run if the function is called.
Here is a simple function that prints a message to the console:
*/


// void means the function does not return a value
// printMessage is the name of the function
// Any inputs, aka parameters, would be defined in the parentheses
void printMessage() { // This part of the function is called the "declaration"
    // Code inside the function is called the "body" or "definition"
    cout << "This is a message from the printMessage function." << endl;
}

// This function makes use of parameters 
// Now it will print a personalized introduction message for ANY name!
void introduction(string name) {
    cout << "Hello, my name is " << name << endl;
}

// This function takes two integers as parameters and returns their sum
int calculateSum(int a, int b) {
    return a + b; 
}


// You can use the formula: Fahrenheit = (Celsius * 9/5) + 32
double celsiusToFah(double celsius) {
    return (celsius * 9/5) + 32;
}
// Practice 2: Create a function that takes two numbers and returns the larger of the two.
int larger(int a, int b) {
    if (a > b){
        return a;
    }else {
        return b;
    }
}

// Practice 3: Create a function that prints the the sum of the first n natural numbers.
int sumNatural(int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    cout << sum << endl;
    return sum;
}

// Practice 4: Create a function that returns the number of times a specific number appears in an array.
int frequency(int arr[], int size, int x) {
    int count = 0;
    for (int i = 0; i < size; i++){
        if (x == arr[i]){
            count += 1;
        }
    }
    return count;
}

// Practice 5: Write a function that returns true or false if the array is sorted in ascending order.
bool isSorted(int arr[], int size) {
    for (int i = 1; i < size; i ++){
        if (arr[i] < arr[i-1]){
            return false;
        }
    }
    return true;
} 



//================= Part 2: Scope =================
/*
Scope refers to the visibility of variables in different parts of the code
Variables defined inside a function are local to that function and cannot be accessed outside of it.
However, global variables can be accessed from anywhere in the code.
*/
int globalVariable = 20;
void scopeExample() {
    int localVariable = 10; // This variable is local to this function
    cout << "Local variable inside scopeExample: " << localVariable << endl;
}






//================= Part 3: Classes and OOP =================
/*
Classes are blueprints for creating objects. 
Objects are "instances" of classes that contain data and functions.
For example, we can create a class called "Car" that has properties like brand, model, and year.
It also has methods (functions), such as displaying car information.
*/
class Car {
public :
    // Properties or attributes of the Car class
    string brand;
    string model;
    int year;
};

/*
However isn't it redundant to secify all the properties of the Car class every time we create a new car?
We can use a constructor to initialize the properties of the Car class when we create a new object.

A constructor is a special function that is ALWAYS called when an object of the class is created.
They also have the same name as the class and do not have a return type.
*/

class ImprovedCar {
public:
    // Properties or attributes of the Car class
    string brand;
    string model;
    int year;

    // Constructor to initialize the properties of the Car class
    // Notice that the constructor has the same name as the class and has no return type
    ImprovedCar(string carBrand, string carModel, int carYear) {
        brand = carBrand;
        model = carModel;
        year = carYear;
    }
    // Method to display car information
    void displayInfo() {
        cout << "Car Brand: " << brand << ", Model: " << model << ", Year: " << year << endl;
    }
};

/* 
Practice 1: Look at the code below and try to explain what it does. Explain what data it contains and what methods it has.
Once you understand it, try to create an object of the BankAccount class and use its methods.
Bonus: Add a method to withdraw money from the account. 
Make sure to check if the withdrawal amount positive and if there are sufficient funds in the account.
*/
class BankAccount {
private:
    string accountHolderName;
    int accountNumber;
    double balance;

public:
    BankAccount(string name, int accNo, double initialBalance) {
        accountHolderName = name;
        accountNumber = accNo;
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }


    void displayBalance() const {
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Current Balance: $" << balance << endl;
    }
};

/*
Practice 2: Create a class called "Student" that has properties like name, age, and grade.
Create a method to display student information.
Create a method that can update their grade.
*/



//================== 4) Extra Topics =================
/*
Encapsulation: This is the concept of restricting access to certain parts of an object.
Why is this important?
1. Ease of use: In some cases, we don't ever need to access certain properties of an object.
2. Security: If we never plan on accessing a property, we can make it private to prevent accidental changes.

In the example below, the year property of the EncapsulatedCar class is private.
This means that it cannot be accessed directly from outside the class.
Instead, we provide a public method to access it, which CAN be accessed from outside the class.
*/
class EncapsulatedCar {
private:
    int year;
public:
    // Constructor 
    EncapsulatedCar(int carYear) {
        year = carYear;
    }

    // Method to display car information
    int getCarYear() {
        return year;
    }
};

/*
Inheritance: This is the concept of creating a new class based on an existing class.
This allows us to reuse code for efficiency and organization.
The following example uses the example of animals to demonstrate inheritance.

Here are some of the advantages of inheritance:
1. Code Reusability: Derived classes inherit properties and methods from base classes, reducing code duplication.
3. Unique Properties: Derived classes can have their own unique properties in addition to inherited ones.
2. Polymorphism: Derived classes can override base class methods, allowing for customized behavior.

In the following example, we have a base class called Animal and two derived classes: Pig and Dog.
Both Pig and Dog inherit the animalSound method.
Pig also has its own property called animalType.
Dog overrides the animalSound method to provide a specific sound for dogs. (polymorphism)
*/

// Base or Parent class
class Animal {
  public:
    void animalSound() {
      cout << "The animal makes a sound \n";
    }
};

// Derived or Child class
class Pig : public Animal {
  public:
    string animalType = "Pig";
};

// Derived class
class Dog : public Animal {
  public:
    void animalSound() {
      cout << "The dog says: bark bark \n";
    }
};

/*
The 3 core aspects of OOP are:
1. Encapsulation: Restricting access to certain parts of an object.
2. Inheritance: Creating a new class based on an existing class.
3. Polymorphism: Allowing methods to be overridden in derived classes for customized behavior.
*/

/*
Practice 1: Create a class called "Shape" with a method to calculate the area.
Then create two derived classes: "Circle" and "Rectangle" that override the area method.
*/




// int frequency(int arr[], int size, int x) {
//     int count = 0;
//     for (int i = 0; i < size; i++){
//         if (x == arr[i]){
//             count += 1;
//         }
//     }
//     return count;
// }

// // Practice 5: Write a function that returns true or false if the array is sorted in ascending order.
// bool isSorted(int arr[], int size) {
//     for (int i = 1; i < size; i ++){
//         if (arr[i] < arr[i-1]){
//             return false;
//         }
//     }
//     return true;
// } 

// bool isSorted2(int arr[], int size) {
//     // {1,2,3,4}
//     int n=arr[0];
//     for(int i=1;i<size;i++) {
//         cout << i << endl;
//         if (n<arr[i]) {
//             n=arr[i];
//         } else {
//             cout << i <<"arr[i]"<< arr[i] << "n:"<< n << endl;
//             return false;
//         }
//     }
//     return true;
// }

int main() {
    // int testarry[] = {1,2,3,4,5};
    // isSorted2(testarry, 5);
    // cout 
    // frequency(testarry, 5, 2);
    // printMessage(); // Calling the function to execute its code

/* 
    // Data that is inputed into the function are called arguments
    introduction("Alice");
    introduction("Bob");
    introduction("Charlie"); 
*/


/* 
    int sum = calculateSum(5, 10);
    cout << "The sum of 5 and 10 is: " << sum << endl; 
*/


/* 
    scopeExample();
    cout << "Global variable that can be used anywhere: " << globalVariable << endl;
    cout << "Local variable inside scopeExample: " << localVariable << endl; 
*/


    // Creating an object of the Car class
    Car myCar;
    myCar.brand = "Toyota";
    myCar.model = "Corolla";    
    // // // You can also explicity get the properties of the object
    cout << "My car's brand is: " << myCar.brand << endl;


    // // string brand = "Tesla"; 
    // // int year = 2021;
    // // cout << "second car's brand is: " << brand << endl;


    // // // Creating an object of the ImprovedCar class using the constructor
    ImprovedCar myImprovedCar("Honda", "Civic", 2021);
    myImprovedCar.displayInfo();
    // ImprovedCar anotherCar("Ford", "Mustang", 2022);
    // // // Displaying car information using the method
    // myImprovedCar.displayInfo();
    // anotherCar.displayInfo();

    // BankAccount mybank("liamBank", 12345, 9);
    // mybank.deposit(10);
    // mybank.displayBalance();
    

/* 
    EncapsulatedCar myEncapsulatedCar(2023);
    cout << "The year of the encapsulated car is: " << myEncapsulatedCar.year << endl;
    //cout << "The year of the encapsulated car is: " << myEncapsulatedCar.getCarYear() << endl;
*/
    

/* 
    Pig myPig;
    myPig.animalSound(); // it inherits the methods from its parent!
    cout << "This is a " << myPig.animalType << endl; // But it also has its own properties!

    Dog myDog;
    // Dog overrides the animalSound method to provide a specific sound for dogs. (Polymorphism)
    myDog.animalSound(); 
*/
    return 0;
}
