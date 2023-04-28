#include<iostream>
#include<algorithm>
using namespace std;

struct Point{
    int x, y;
};
bool cmpX(const Point& p1, const Point& p2){
    return (p1.x < p2.x);
}
bool cmpY(const Point& p1, const Point& p2){
    return (p1.y < p2.y);
}

int main(){
    int n;
    cin>>n;
    vector<Point> red(n);
    for(int i=0; i<n; i++){
        cin>>red[i].x>>red[i].y;
    }

    int m;
    cin>>m;
    vector<Point> blue(m);
    for(int i=0; i<m; i++){
        cin>>blue[i].x>>blue[i].y;
    }

    sort(blue.begin(), blue.end(), cmpX); //sort blue points based on x-coordinates

    int maxArea=0;
    for(int i=0; i<n; i++){
        int leftHighY=-1, leftLowY=-1, rightHighY=-1, rightLowY=-1;
        for(int j=0; j<m; j++){
            if(blue[j].x<red[i].x){ //blue point is to left of the red poits
                if(leftHighY==-1||blue[j].y>blue[leftLowY].y){
                    leftHighY=j;
                }
                if(leftLowY==-1||blue[j].y<blue[leftLowY].y){
                    leftLowY=j;
                }
            }else{ //blue point is to the right of red point
                if(rightHighY==-1||blue[j].y>blue[rightHighY].y){
                    rightHighY=j;
                }
                if(rightLowY==-1||blue[j].y<blue[rightLowY].y){
                    rightHighY=j;
                }
            }
        }
        int leftWidth, rightWidth, height;

        if(leftHighY==-1) leftWidth=0;
        else leftWidth=(blue[leftHighY].x - red[i].x);

        if(rightLowY==-1) rightWidth=0;
        else rightWidth=(red[i].x - blue[rightLowY].x);

        if(leftHighY==-1||rightHighY==-1) height=0;
        else height=max(blue[leftHighY].y, blue[rightHighY].y) - red[i].y;

        int area=(leftWidth+rightWidth)*height;
        maxArea=max(maxArea, area);

    }
    cout<<maxArea<<endl;
    return 0;
}
