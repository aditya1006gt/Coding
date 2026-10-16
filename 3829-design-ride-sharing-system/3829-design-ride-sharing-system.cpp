class RideSharingSystem {
public:
    queue<int>rider;
    queue<int>driver;
    set<int>st;
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        rider.push(riderId);
        if(st.find(riderId)!=st.end()) st.erase(riderId);
    }
    
    void addDriver(int driverId) {
        driver.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        if(rider.empty() || driver.empty())
        return {-1,-1};

        int ri=rider.front(); rider.pop();
        while(st.find(ri)!=st.end() && !rider.empty()) {
            ri=rider.front(); 
            rider.pop();
        }
        if(st.find(ri)!=st.end()) return {-1,-1};
        int di=driver.front(); driver.pop();
        return {di,ri};
    }
    
    void cancelRider(int riderId) {
        if(st.find(riderId)!=st.end()) return;

        st.insert(riderId);
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */