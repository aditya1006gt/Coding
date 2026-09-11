class EventManager {
public:
    unordered_map<int,int>mpp;
    set<pair<int,int>>st;
    EventManager(vector<vector<int>>& events) {
        for(auto& i:events) {
            mpp[i[0]]=i[1];
            st.insert({-1*i[1],i[0]});
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        int pri=mpp[eventId];
        st.erase({-pri,eventId});

        st.insert({-1*newPriority,eventId});
        mpp[eventId]=newPriority;
    }
    
    int pollHighest() {
        if(st.empty()) return -1;

        auto he=*st.begin();
        int eventId=he.second;

        st.erase(st.begin());
        mpp.erase(eventId);
        
        return eventId;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */