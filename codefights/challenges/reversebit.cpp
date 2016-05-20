int ReverseBit(int x) {
    std::string r=toReversedBin(x);
    int s=0, p=0;
    for(int i=r.length()-1; i>=0; i--, p++)
        if(r.at(i) == '1')
	    s += (int)pow(2.0, (double)p);
    return s;
}

std::string toReversedBin(int n)
{
    return n ? std::to_string(n%2) + toReversedBin(n/2) : "";
}
