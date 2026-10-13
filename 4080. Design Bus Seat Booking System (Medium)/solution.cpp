short short check[4][100000];
class BusBooking {
public:
    int minTime = 0, totalTime = 0;
    BusBooking(int n) {
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < n; j++){
                check[i][j] = 0;
            }
        }
    }
    
    void toggle(string seat) {
        int col = seat[0]-'A';
        int row = stoi(seat.substr(1))-1;
        int po = col;
        if(po==3) po--;
        else if(po==0) po++;
        if(col==0 || col==3){
            if(check[po][row]==0){
                if(check[col][row]==0){
                    totalTime++;
                    minTime++;
                    check[col][row]=1;
                } else {
                    totalTime -= check[col][row];
                    minTime--;
                    check[col][row]=0;
                }
            } else {
                if(check[col][row]==0){
                    check[col][row] = 3;
                    totalTime += 3;
                    minTime++;
                } else {
                    totalTime -= check[col][row];
                    minTime--;
                    check[col][row]=0;
                }
            }
        } else {
            if(check[col][row]==0){
                check[col][row]=1;
                minTime++;
                totalTime++;
            } else {
                totalTime -= check[col][row];
                check[col][row]=0;
                minTime--;
            }
        }
    }
    
    int getTotalTime() {
        return totalTime;
    }
    
    int getMinTime() {
        return minTime;
    }
};

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */