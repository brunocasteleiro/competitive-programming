public class SortEstimate
{
    public double howMany(int c, int time)
    {
	double lo=1;
	double hi=time+1;
		
        for(int i=0; i<150; i++)
	{
	    double mid = lo+(hi-lo)/2;
	    double r   = (double)c*mid*(Math.log(mid)/Math.log(2));
			
	    if(r <= (double)time)
		lo = mid;
	    else
		hi = mid;
	}
		
	return lo;
    }
}
