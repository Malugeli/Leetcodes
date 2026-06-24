struct Solution{
    int characterReplacement(std::string s, int k){
        int result{};

        for(int left = 0; left < s.size() - 1; ++left){
            int right = left + 1;
            int amount = 1;

            std::array<int, 26> characters{};
            std::string sub = "";

            sub += s[left];
            characters[s[left] - 'A']++;
            int formula = sub.length() - std::ranges::max(characters);
            
            while(right < s.size()){
                sub += s[right];
                characters[s[right] - 'A']++;
                formula = sub.length() - std::ranges::max(characters);
                if(formula <= k) amount++; else break;
                right++;
            }
            result = std::max(amount, result);
        }
        return result;

    }
};