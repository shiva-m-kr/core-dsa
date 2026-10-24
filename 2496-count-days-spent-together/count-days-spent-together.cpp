class Solution {
public:
    int ans(string date ,const vector<int>& arr){
        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));
        return arr[month - 1] + day;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> arr = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
        
        int date1 = ans(arriveAlice,arr);
        int date2 = ans(leaveAlice,arr);

        int date3 = ans(arriveBob,arr);
        int date4 = ans(leaveBob,arr);

        int start = max(date1,date3);
        int end = min(date2,date4);

        if(start <= end){
            return end-start+1;       
        }

        return 0;
    }
};