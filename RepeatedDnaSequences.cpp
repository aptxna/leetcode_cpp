/*
 * Repeated DNA Sequences
 *
 * All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG".
 * When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.
 *
 * Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.
 *
 * For example,
 *
 * Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
 *
 * Return:
 * ["AAAAACCCCC", "CCCCCAAAAA"].
 *
 */



class RepeatedDnaSequences {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        vector<string> result;
        map<long, int> dna;
        
        for (int i=0; i<n-9; i++) {
            long index = str2long(s.substr(i, 10));
            if (dna.find(index) == dna.end())
                dna[index] = 1;
            else
                dna[index] += 1;
        }
        
        for (auto it = dna.begin(); it != dna.end(); it++) {
            if (it->second > 1)
                result.push_back(long2str(it->first));
        }
        
        return result;
    }
    
    long str2long(string s) {
        long sl = 0;
        for (int i=0; i<10; i++) {
            switch(s[i]) {
                case 'A': sl = sl*10 + 1; break;
                case 'C': sl = sl*10 + 2; break;
                case 'G': sl = sl*10 + 3; break;
                case 'T': sl = sl*10 + 4; break;
                default: break;
            }
        }
        return sl;
    }
    
    string long2str(long s) {
        string ls;
        while (s > 0) {
            int d = s % 10;
            switch(d) {
                case 1: ls = 'A' + ls; break;
                case 2: ls = 'C' + ls; break;
                case 3: ls = 'G' + ls; break;
                case 4: ls = 'T' + ls; break;
                default: break;
            }
            s = s / 10;
        }
        return ls;
    }
};