std::string CollatzConjecture(int n) {
    std::string out = n==1 ? "" : std::to_string(n);
    while(n!=1)
    {
        if(n%2!=0)
            out += " " + std::to_string( (n=3*n+1) );
        else
        {
            if(n/2!=1)
                out += " " + std::to_string( n/2 );
            n/=2;
        }
    }
    return out;
}
