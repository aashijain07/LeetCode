class LRUCache {
public:
    unordered_map<int,int>m; //main map {key, value}
    list<int>l; // doubly linked list
    unordered_map<int,list<int>::iterator>address; //mapping {key,address of node} so that we reduce our time of iterating each time of particular list node.
    int size,cnt;//for global;

    LRUCache(int capacity) {
        cnt=capacity;
        size=0;    
    }
    
    int get(int key) {
        if(m.find(key)==m.end())return -1; //if not fount {key, value};
        //if {key, value present, firstly we did most significant node so that we maintain our Cache}
        auto it=address[key];
        l.erase(it); // delete node from our list using address;
        address.erase(key);// delete that key address;
        l.push_front(key); // adding to most significant node i.e. to front.
        address[key]=l.begin(); //now to store new address;
        return m[key]; //now return our answer;
    }
    
    void put(int key, int value) {
        //case-1= if {key,value} is already present;
        if(m.find(key)!=m.end()){
            auto it=address[key];
            l.erase(it);
            address.erase(key);
            m.erase(key);
            size--;
        }

        //case-2= if size is equal to the capacity
        if(size==cnt){
            int k=l.back(); // least significant i.e. last node of our list;
            auto it=address[k];
            l.erase(it);
            //OR l.pop_back();
            address.erase(k);
            m.erase(k);
            size--;
        }

        //case-3= putting new {key,value} in our main map;
        l.push_front(key);// adding to most significant nodde i.e to front; 
        address[key]=l.begin(); // storing its new address;
        m[key]=value; // adding in main map;
        size++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */