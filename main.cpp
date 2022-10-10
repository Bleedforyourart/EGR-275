#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

int main() {
   
   ItemToPurchase item1, item2;
   string name; 
   int quantity;
   double price;
   
   cout<< "Item 1" << endl;
   cout<< "Enter the item name:"<<endl;
   getline(cin, name);
   cout<<"Enter the item price:"<<endl;
   cin >> price;
   cout<<"Enter the item quantity:"<<endl;
   cin >> quantity;
   
   item1.SetName(name);
   item1.SetQuantity(quantity);
   item1.SetPrice(price);
   cout<<endl;

   
   cout<< "Item 2" << endl;
   cout<< "Enter the item name:"<<endl;
   cin.ignore();
   getline(cin, name);
   cout<<"Enter the item price:"<<endl;
   cin >> price;
   cout<<"Enter the item quantity:"<<endl;
   cin >> quantity;
   
   item2.SetName(name);
   item2.SetQuantity(quantity);
   item2.SetPrice(price);
   cout<<endl;
   
   double item1Cost = item1.GetQuantity() * item1.GetPrice();
   double item2Cost = item2.GetQuantity() * item2.GetPrice();
   
   cout<<"TOTAL COST"<<endl;
   cout<< item1.GetName() << " " << item1.GetQuantity() << " @ $" << item1.GetPrice() << " = $" << item1Cost <<endl;
   cout<< item2.GetName() << " " << item2.GetQuantity() << " @ $" <<item2.GetPrice() << " = $" << item2Cost <<endl;
   cout<<endl;
   cout<<"Total: $" << item1Cost + item2Cost<<endl;
   
   return 0;
}
