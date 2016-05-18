int magicBook(std::string s)
{
    using namespace std;
    set<char> chars;
    int len=s.length();
    
    for(int i=0; i<len; i++)
        chars.insert( s.at(i) );
    
    int nchars = chars.size();
    
    int sols = 0;
    for(int i=0; i<len; i++)
    {
        int nsmall=0;
        for(set<char>::iterator it=chars.begin(); it!=chars.end() && *it<s.at(i); it++)
            nsmall++;
            
        sols += (i==len-1) ? nsmall : nsmall*mpow(nchars, len-(i+1));
    }
    
    return sols;
}

int mpow(int b, int e)
{
    return (e==1) ? b : b*mpow(b, e-1);
}
