#include <cstdlib>
#include <iostream>
#include <string>

#include "HashTable.h"

using namespace std;


int main(int argc, char** argv) {

    Hash HashObj;

    HashObj.addItem("Mohamed", "Hot Chocolate");
    HashObj.addItem("Adam", "White Chocolate");
    HashObj.addItem("Ahmed", "Locha");
    HashObj.addItem("Omar", "Iced Mocha");
    HashObj.addItem("Sarah", "Strawberry Smoothy");
    HashObj.addItem("Iqra", "Passion Tea");
    HashObj.addItem("Ibtisam", "Caramel Mocha");
    HashObj.addItem("Yousra", "Chai Tea");
    HashObj.addItem("Fatima", "Apple Cider");
    HashObj.addItem("Mouna", "Apple Cider");
    HashObj.addItem("Amanda", "Skinny Latte");
    HashObj.addItem("Kristi", "Water");
    HashObj.addItem("Sveta", "Green Tea");

    HashObj.printTable();

    //HashObj.findDrink("Omar");
    //HashObj.findDrink("Axmed");

    HashObj.removeItem("Omar");
    HashObj.removeItem("Ali");


    return 0;
}