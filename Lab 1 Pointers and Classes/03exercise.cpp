// Create a class called Inventory having relevant data members and methods such as
// addToInventory () and viewInventory (). Then create a class called Item having relevant data
// members as well as functions. An Inventory has many items. By making use of class array/s
// and the concept of has a relationship, write a program in C++.
// Note: Constructors and getter/setters are mandatory.

#include <iostream>

using namespace std;

class Inventory{
private:
    string inventoryName;
    int itemCount;
    public:
    void addToInventory(string name, int count) {
        inventoryName = name;
        itemCount = count;
    }
    void viewInventory() {
        cout << "Inventory Name: " << inventoryName << endl;
        cout << "Item Count: " << itemCount << endl;
    }

};

class Item {
private:
    string itemName;
    int itemID;
public:
    Item(string name, int id) : itemName(name), itemID(id) {}

    string getItemName() const {
        return itemName;
    }

    int getItemID() const {
        return itemID;
    }

    void setItemName(const string& name) {
        itemName = name;
    }

    void setItemID(int id) {
        itemID = id;
    }
};

int main()
{
    Inventory inventory;
    inventory.addToInventory("Warehouse A", 10);
    inventory.viewInventory();
    Item item1("Widget", 101);
    cout << "Item Name: " << item1.getItemName() << endl;
    cout << "Item ID: " << item1.getItemID() << endl;
    item1.setItemName("Gadget");
    item1.setItemID(102);
    cout << "Updated Item Name: " << item1.getItemName() << endl;
    cout << "Updated Item ID: " << item1.getItemID() << endl;
    Item item2("Gizmo", 103);
    cout << "Item Name: " << item2.getItemName() << endl;
    cout << "Item ID: " << item2.getItemID() << endl;
    item2.setItemName("Thingamajig");
    item2.setItemID(104);
    cout << "Updated Item Name: " << item2.getItemName() << endl;
    cout << "Updated Item ID: " << item2.getItemID() << endl;
    

    return 0;
}