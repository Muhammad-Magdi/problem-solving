pointers & iterators , begin, end, Lexicographical
count(begin, end, val)		  	   //returns number of occurences of val         //O(N)
count_if(begin, end, f)	  	     //returns number of occurences that satisfy f //O(N)
min_element(begin, end)		       //returns an iterator                         //O(N)
max_element(begin, end)		       //returns an iterator                         //O(N)
max(val, val)                    //returns the maximum value
min(val, val)                    //returns the minimum value
copy(begin1, end1, begin2)	     //iterator		                                 //O(N)
fill(begin, end, val)		                                                       //O(N)
reverse(begin, end)			                                                       //~O(N)
sort(begin, end, f)			         //Ascendignly                                 //O(NLog(N))
nth_element(begin, nth_element_itr, end)                                       //O(N)

unique(begin, end)			         //iterator	                                   //O(N)
find(begin, end, val)            //iterator                                    //O(N)
binary_search(begin, end, val)   //bool                                        //O(Log(N))
lower_bound(begin, end, val)		 //iterator >=	                               //O(Log(N))
upper_bound(begin, end, val)		 //iterator > 	                               //O(Log(N))
equal_range(begin, end, val)		 //pair<iterator, iterator>		                 //O(Log(N))

next_permutation(begin, end)		 //bool	                                       //O(N)
prev_permutation(begin, end)		 //bool	                                       //O(N)
