class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size(), col = board[0].size();
        int i = 0;
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        for(int j = 0; j < row; j++)
        {
            for(int k = 0; k < col; k++) //Iterate over the whole 2d array for the search
            {
                if(dfs(board, word, visited, i, j, k))
                {
                    return true;
                }
            }
        }
        return false;
    }


private:
    bool dfs(vector<vector<char>>& board, string& word, vector<vector<bool>>& visited, int i, int r, int c) 
    //visited is to make sure we don't revisit a tile we have visited, c ,r = column, row
    {
        if(i == word.size()) //It means we found all the letters in the word
        {
            return true;
        }
        if(r < 0  || c < 0  || //if i is smaller than r or c, then we are accessing out of bounds index, return false
           board[0].size() <= c || board.size() <= r || //if c or r is bigger than what is given, then return false
           word[i] != board[r][c] || // If the letter is not what we are looking for, then return false
           visited[r][c] ) //If we were from that position, then reutrn false
        {
            return false;
        }

        visited[r][c] = true; //This means, that we were at position r and c, when beginning the search
                              //To make sure we don't go back to the positon we mark it as true
        bool found = dfs(board, word, visited, i + 1, r + 1, c) || //Check infront 1 row, and iterate the next index        recursively
                     dfs(board, word, visited, i + 1, r -1, c) || //Check behind 1 row, and iterate the next index recursively
                     dfs(board, word, visited, i + 1, r, c + 1) || //Check infront 1 column, and iterate the next index recursively
                     dfs(board, word, visited, i + 1, r, c - 1); //Check behind 1 column, and iterate the next index recursively
        //If any of these dfs are true then it means we found the word that we want
        
        visited[r][c] = false; //Unmark it because we have moved on from this position
        return found; //If we managed to find the word, then we get found = true, if we dont, thne found = fals         
    }
};