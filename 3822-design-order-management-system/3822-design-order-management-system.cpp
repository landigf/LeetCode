struct Order {
    string orderType;
    int price;
};

class OrderManagementSystem {
    map<int,Order> mapOrders;
    map<string,set<int>> reverseMap;

public:
    OrderManagementSystem() {
        
    }
    
    void addOrder(int orderId, string orderType, int price) {
        mapOrders[orderId] = {orderType, price};
        reverseMap[orderType+to_string(price)].insert(orderId);
    }
    
    void modifyOrder(int orderId, int newPrice) {
        string orderType = mapOrders[orderId].orderType;
        int price =  mapOrders[orderId].price;
        reverseMap[orderType+to_string(price)].erase(orderId);
        mapOrders[orderId].price = newPrice;
        reverseMap[orderType+to_string(newPrice)].insert(orderId);
    }
    
    void cancelOrder(int orderId) {
        string orderType = mapOrders[orderId].orderType;
        int price =  mapOrders[orderId].price;
        reverseMap[orderType+to_string(price)].erase(orderId);
        mapOrders.erase(orderId);
    }
    
    vector<int> getOrdersAtPrice(string orderType, int price) {
        return vector<int> (reverseMap[orderType+to_string(price)].begin(),
            reverseMap[orderType+to_string(price)].end());
    }
};

/**
 * Your OrderManagementSystem object will be instantiated and called as such:
 * OrderManagementSystem* obj = new OrderManagementSystem();
 * obj->addOrder(orderId,orderType,price);
 * obj->modifyOrder(orderId,newPrice);
 * obj->cancelOrder(orderId);
 * vector<int> param_4 = obj->getOrdersAtPrice(orderType,price);
 */