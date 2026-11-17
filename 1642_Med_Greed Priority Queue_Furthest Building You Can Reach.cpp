class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size(); //Amount of heights
        vector<int> DiffH; //We are gonna make an vector with just the difference in height from building to building
        int i; //Iterator
        int furthest = 0; //Furthest we can get
        for(i = 0; i + 1 < n; i++) //Check all of the buildings, and i + 1, so we dont access anything out of the vector
        {
            int Diff = heights.at(i + 1) - heights.at(i); //Difference in height between the buildings
            DiffH.insert(DiffH.begin() + i, Diff); //Insert into out new vector
            
        }
        //sort(DiffH.begin(), DiffH.end()); //Sort it from lowest to highest, because we only want to use ladders for the highest ones
        n = DiffH.size(); //Update n to the size of DiffH
        priority_queue<int> pq; //Make a priority queue to see which is the tallest
        for(i = 0; i < n ; i++) //try all possibilities of difference in height
        {
            if(DiffH.at(i) <= 0) //If it is less or equal than 0 means we dont need any bricks or ladders
            {
                furthest++;
                continue;
            }

            else if(bricks >= DiffH.at(i)) //If there are enough bricks, make the climp
            {
                bricks -= DiffH.at(i);
                pq.push(DiffH.at(i)); //Keep this just in case we need to refund it for a ladder
                furthest++;
            }
            else if(bricks < DiffH.at(i) && ladders != 0) //If we aren't out of ladders and that we ran out of bricks, refund the biggest climb we saw with a ladder
            {
                pq.push(DiffH.at(i)); //Keep this just in case we need to refund it for a ladder
                bricks += pq.top(); //Get top of pq
                pq.pop(); // Remove the top of pq
                ladders--;

                //Iterate over this loop like normal
                bricks -= DiffH.at(i);
                furthest++;
            }
            else
            {
                break;
            }

        }
    return furthest;
   }
};