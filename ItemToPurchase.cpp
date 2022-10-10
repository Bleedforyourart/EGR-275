#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

ItemToPurchase::ItemToPurchase(){
   itemName = "none";
   itemPrice = 0.0;
   itemQuantity = 0;
}

void ItemToPurchase::SetName(string name) {
   itemName = name;
}
void ItemToPurchase::SetQuantity(int quantity) {
    itemQuantity = quantity;
}
void ItemToPurchase::SetPrice(double price) {
   itemPrice = price;
}
string ItemToPurchase::GetName(){
   return itemName;
}
int ItemToPurchase::GetQuantity(){
   return itemQuantity;
}
double ItemToPurchase::GetPrice(){
   return itemPrice;
}
