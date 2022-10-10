#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

#include <string>
using namespace std;

class ItemToPurchase {
   public:
      ItemToPurchase();
      void SetName(string name);
      void SetQuantity(int quantity);
      void SetPrice(double price);
      
      string GetName();
      int GetQuantity();
      double GetPrice();
      
   private:
   string itemName;
   double itemPrice;
   int itemQuantity;
};
   
#endif
