// Number of one in binary representation of a number is called as Hamming weight of that number

// Code
      int hammingWeight(uint32_t n) {
        int sum = 0;
        while (n != 0) {
            sum++;
            n &= (n - 1);
        }
        return sum;
    }
    
    
// also this

    int hammingWeight(uint32_t n) {
        int count = 0;
        
        uint32_t mask = 0x00000001;
        for(int i = 0; i < 32; ++i) {
            if(n & mask) {
                ++count;
            }
            n = n >> 1;
        }
        
        return count;
    }
