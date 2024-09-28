// 731. My Calendar II

class MyCalendarTwo {
public:
    vector<pair<int,int>> doubleBooking;
    vector<pair<int,int>> bookings;

    bool checkOverlap(int start1, int end1, int start2, int end2){
        return max(start1, start2) < min(end1, end2);
    }

    pair<int,int> findOverlappedRegion(int start1, int end1, int start2, int end2){
        return {max(start1, start2), min(end1, end2)};
    }

    
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        // check if triple booking is being created or not
        for(pair<int,int> region: doubleBooking){
            if(checkOverlap(region.first, region.second, start, end)){
                return false;
            }
        }


        // check if it double booking
       for(pair<int,int> booking: bookings){
            if(checkOverlap(booking.first, booking.second, start, end)){
                doubleBooking.push_back(findOverlappedRegion(booking.first, booking.second, start, end));
            }
        }


        bookings.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */