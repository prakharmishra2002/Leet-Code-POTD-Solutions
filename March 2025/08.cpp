class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        queue<char> blockQueue;
        int numWhites = 0;

        // Initiate queue with first k values
        while (blockQueue.size() < k) {
            char currentChar = blocks[blockQueue.size()];
            if (currentChar == 'W') numWhites++;
            blockQueue.push(currentChar);
        }

        // Set initial minimum
        int numRecolors = numWhites;
        for (int i = k; i < blocks.size(); i++) {
            // Remove top element from queue and update current number of white
            // blocks
            if (blockQueue.front() == 'W') numWhites--;
            blockQueue.pop();

            // Add current element to queue and update current number of white
            // blocks
            if (blocks[i] == 'W') numWhites++;
            blockQueue.push(blocks[i]);

            // Update minimum
            numRecolors = min(numRecolors, numWhites);
        }
        return numRecolors;
    }
};
