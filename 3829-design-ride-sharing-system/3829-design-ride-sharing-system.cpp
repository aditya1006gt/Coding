class RideSharingSystem {
public:
    queue<int>qrider;
    queue<int>qdriver;
    map<int,int>mpp;
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        qrider.push(riderId);
        mpp[riderId]=0;
    }
    
    void addDriver(int driverId) {
        qdriver.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        if(qrider.empty() || qdriver.empty())
        return {-1,-1};

        int ri=qrider.front();
        qrider.pop();

        while(mpp[ri]==-1) {
            if(qrider.empty()) return {-1,-1};
            mpp.erase(ri);

            ri=qrider.front();
            qrider.pop();
        }

        int di=qdriver.front();
        qdriver.pop();

        mpp.erase(ri);
        return {di,ri};
    }
    
    void cancelRider(int riderId) {
        if(mpp.find(riderId)==mpp.end()) return;

        mpp[riderId]=-1;
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