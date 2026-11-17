class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int Left = 0, Right = n - 1; //Left and right arrows in the container
        int width, maxArea = 0, area, length;
        while(Left != Right)
        {
            width = Right - Left;
            length = min(height.at(Left), height.at(Right)); //Height is always the smaller one
            area = length * width;
            maxArea = max(maxArea, area);
            cout << maxArea << endl;
            if(height.at(Left) < height.at(Right)) //if Right side is bigger, move the left arrow to the right
            {
                Left++;
            }
            else //if Left side is bigger, move the right arrow to the left
            {
                Right-- ;
            }
        }
        return maxArea;
    }
};