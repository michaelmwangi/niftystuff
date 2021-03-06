#include <iostream>
#include <algorithm>
#include <map>
#include <limits>
std::string reverse(std::string thestring){
    std::reverse(thestring.begin(), thestring.end());
    return thestring;
}

bool isVowel(char let){
    char vowels[] = {'a','e','i','o','u'};
    for(int i=0; i < 5;i ++)
        if (let == vowels[i])
            return true;
    return false;
}

int countVowels(std::string str){
    int count = 0;
    count += std::count_if(str.begin(), str.end(),isVowel);
    return count;
}


bool isPalindrome(std::string str){
    if(str == reverse((str)))
        return true;
    else
        return false;
}

void eatWhite(std::string::iterator &it){
    while(isspace(*it)){
        ++it;
    }
}

int numWords(std::string str){
    int wordlen = 0;
    int numwords = 0;
    std::string::iterator it = str.begin();
    while(it != str.end()){
        wordlen = 0;
        if(isspace(*it))
            eatWhite(it);
        else if(isalnum(*it)){
            while(isalnum(*it)){
                ++it;
                ++wordlen;
            }
        }
        if(wordlen){
            ++numwords;
        }
    }
    return numwords;
}

std::string pigLatin(std::string str){
    std::string::iterator initbeg,beg;
    std::string::iterator end = str.end();
    initbeg=beg= str.begin();
    while( !isVowel(*beg) && beg != end){
        ++beg;
    }
    if(beg == end)
        return str + "ay";
    else{
        std::string piglatin(beg,end);
        std::string cons(initbeg,beg);
        return piglatin + cons + "ay";
    }
}

void getFirtNoRepeatCharacter(const std::string &str, std::map<char, int> &thechar){
    int pos = 0;
    for(auto const &it : str){
        if(thechar.find(it) == thechar.end() && thechar.empty()){
            thechar[it] = pos;
        }
        else{
            thechar.erase(it);
        }
        pos++;
    }

}
void fibonacci(long int cur, long int prev=1, int count=0, int stopcount=10){
    if(count == stopcount)
        return;
    count++;
    std::cout<<cur<<std::endl;
    long int newcur = prev + cur;
    fibonacci(newcur, cur, count);
}

bool simplePatternMatch(const std::string &text, const std::string &pattern){
    //return true if pattern occurs otherwise false
    auto pat_it = pattern.begin();
    std::string::const_iterator it = text.begin();
    for(; it != text.end(); it++){
        if(*it == *pat_it){
            auto internal_it = it + 1;
            pat_it++;
            for(; internal_it != text.end();internal_it++){
                if( *internal_it == *pat_it)
                    pat_it++;
                else{
                    //a partial match occured so begin again to look for a match
                    pat_it = pattern.begin();
                    break;
                }
                if(pat_it == pattern.end())
                    return true;

            }

        }
    }
    //if we reach here there was no match
    return false;
}

int main()
{
    //fibonacci(1);
    auto t = "CCAT";
    auto p = "CAT";
    std::cout<<simplePatternMatch(t, p);
    return 0;
}

