class ExamTracker {
public:
    unordered_map<int,long long>scores;
    // unordered_map<int,long long>times;
    vector<int>times;
    int pt=-1;
    ExamTracker() {
        
    }
    
    void record(int time, int score) {
        scores[time]=score;
        if(pt!=-1) scores[time]+=scores[pt];
        // times[time]=(pt==-1)?0:pt;
        times.push_back(time);
        pt=time;
    }
    
    long long totalScore(int startTime, int endTime) {
        if(times.empty()) return 0;
        int n=times.size();

        int eti=upper_bound(times.begin(),times.end(),endTime)-times.begin();
        int sti=lower_bound(times.begin(),times.end(),startTime)-times.begin();
        
        long long esum=0;
        if(eti>0) esum=scores[times[eti-1]];

        long long ssum=0;
        if(sti>0) ssum=scores[times[sti-1]];

        return esum-ssum;
    }
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */