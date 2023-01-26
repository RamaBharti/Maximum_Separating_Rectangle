//
//It is a variation of the Maximum Inner Rectangle problem and is NP-hard. There is no known polynomial-time algorithm for solving the problem, but there are several approximate and heuristic approaches that have been proposed, including the use of linear programming, genetic algorithms, and branch-and-bound techniques.
//The staircase approach
//The staircase approach is a method that can be used to find the maximum area rectangle that separates a set of red and blue points. 
//The basic idea is to divide the space into a grid of squares, and then iteratively expand the squares in the grid to form rectangles. The rectangles are expanded in a stair-like fashion, starting with the smallest squares and gradually increasing the size of the rectangles. 
//The rectangles are checked for feasibility, meaning that they do not contain any red points on one side and any blue points on the other side. The maximum area feasible rectangle is returned as the solution to the problem.
//This approach can work well in practice, but it can be computationally expensive, especially when the number of points is large. The time complexity of the algorithm is O(n^3), where n is the number of points.

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Point{ 
    int x, y;
    int color; //0 for red, 1 for blue
};
struct Rectangle{
    int x1, y1, x2, y2;
    int area;
};

//function to check if a rectangle is feasible
bool isFeasible(vector<Point>& points, Rectangle rect){
    int redCount =0, blueCount=0;
    for(int i=0; i<points.size(); i++){
        if(points[i].x>=rect.x1 && points[i].x<=rect.x2 && points[i].y>=rect.y1 && points[i].y<=rect.y2){
            if(points[i].color==0) redCount++;
            else blueCount++;
        }
    }
    return (redCount==0||blueCount==0);
}

//function to find the maximum separating rectangle
Rectangle findMaximumSeparatingRectangle(vector<Point>&points){
    //intialize the grid size
    int gridSize=100;
    //initialize the maximum rectangle
    Rectangle maxRect={-1, -1, -1, -1, -1};
    //iterate over the grid
    for(int i=0; i<gridSize; i++){
        for(int j=0; j<gridSize; j++){
            //expand the rectangle in a stair-like fashion
            for(int k=i; k<gridSize; k++){
                for(int l=j; l<gridSize; l++){
                    Rectangle rect = {i, j, k, l, (k-i)*(l-j)};
                    if(isFeasible(points, rect)&&rect.area>maxRect.area){
                        maxRect=rect;
                    }
                }
            }
        }
    }
    return maxRect;
}

int main(){
    //example input
    vector<Point> points = {{1,1,0}, {2,2,0}, {3,3,0}, {4,4,1}, {5,5,1}};
    //find the maximum separating rectangle
    Rectangle maxRect = findMaximumSeparatingRectangle(points);
    //print the maximum rectangle
    cout<<"Maximum rectangle: ("<< maxRect.x1 <<", "<< maxRect.y1 << ") to (" <<maxRect.x2 << ", "<< maxRect.y2 << "), area: "<<maxRect.area <<endl;
    return 0; 
}

//`Point` struct represents a point in the plane with its x and y coordinates and color (0 for red and 1 for blue).
//`Rectangle` struct represents a rectangle with its coordinates (x1, y1, x2, y2) and area.
// the function `isFeasible` checks if a given rectangle separates the red and blue points.