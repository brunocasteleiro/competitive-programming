int magicBook(std::string s)
{
    using namespace std;
    set<char> chars (begin(s), end(s));
    int nchars=chars.size(), len=s.length(), sol=0;
    for(ch:s)
        sol += distance(begin(chars), chars.lower_bound(ch)) * pow(nchars, --len);
    return sol;
}
