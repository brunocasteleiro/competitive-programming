public class FairWorkload
{
    public int getMostWork(int[] folders, int workers)
    {
	int maximum=0, acc=0;
	for(int i=0; i<folders.length; i++)
	{
	    maximum = Math.max(maximum, folders[i]);
	    acc += folders[i];
	}
		
	return bsearch(maximum, acc, folders, workers);
    }
    
    // bsearch can be optimized (iterative instead)
    private int bsearch(int lo, int hi, int[] folders, int workers)
    {
	if(lo < hi)
	{
	    int mid = lo+(hi-lo)/2; // current testing MAX
	    int requiredWorkers = 1;
	    int foldersAcc = 0;
			
	    for(int i=0; i<folders.length; i++)
	    {
		if(foldersAcc+folders[i] <= mid)
		    foldersAcc += folders[i];
		else
		{
		    requiredWorkers++;
		    foldersAcc = folders[i];
		}
	    }
			
	    if(requiredWorkers <= workers)
		// preserve mid since it may be the first valid MAX
		return bsearch(lo, mid, folders, workers);
	    else
		return bsearch(mid+1, hi, folders, workers); 
	}
        
	return lo;
    }
}
