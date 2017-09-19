#include <bits/stdc++.h>

using namespace std;

const int N = 1e3;
int n, A[N];

bool fun(int x){		//bool and takes an int parameter
	return x%2==0;		//returns 1 if x is even
}

int main(){
	scanf("%d", &n);		//read an int 'n'
	for(int i = 0 ; i < n ; ++i)
		scanf("%d", &A[i]);		//read element i of an int array A
	
	/****************************count & count_if******************************/
	//number of occurences
	
	printf("Count returned %d\n", count(A, A+n, 1));		//O(N)
	printf("Count if returned %d\n", count_if(A, A+n, fun));		//O(N)
	
	/****************************min_element & max_element******************************/
	
	printf("The minimum element is %d\n", *min_element(A, A+n));		//returns an iterator //O(N)
	printf("The index of the maximum element is %d\n", max_element(A, A+n) - A);		//returns an iterator //O(N)
	
	/****************************fill******************************/
	//we can use memset if we want to fill an "ARRAY" with 0 or -1 //O(log)
	
	vector<int> v(10);		//vector contains 10 Zeros
	fill(v.begin(), v.end(), 3);	//now it contains 10 Threes	//O(N)
	printf("After filling :");
	for(int x : v)
		printf("%d ", x);
	puts("");
	
	/****************************reverse******************************/
	
	string str = "Hello world";
	reverse(str.begin(), str.end());		//O(N/2)
	printf("Here is the reversed string %s\n", str.c_str());	//stringname.c_str() -> deals with stringname as an char arr
	
	/****************************sort******************************/
	
	sort(A, A+n);	//sorts this range Ascendingly	//O(Nlog(N))
	printf("The sorted array is : ");
	for(int i = 0 ; i < n ; ++i)
		printf("%d ", A[i]);
	puts("");

	/****************************copy******************************/
	
	int B[N];
	copy(A, A+n, B);
	puts("Here are the values in B:");
	for(int i = 0 ; i < n ; ++i)
		printf("%d ", B[i]);
	puts("");
	
	/****************************unique******************************/
	
	int last = unique(B, B+n)-B;		//last indicates the new size
	puts("Array B after using unique:");
	for(int i = 0 ; i < last ; ++i)
		printf("%d ", B[i]);
	puts("");
	
	/****************************binary_search******************************/
	//given a sorted range	//O(Log)
	
	if(binary_search(A, A+n, 5))		//returns 0 | 1		//O(log)
		puts("Found");
	else
		puts("Not Found");
	
	/****************************lower_bound & upper_bound & equal_range******************************/
	//given a sorted range	//O(Log)
	
	printf("Lower bound returned %d\n", *lower_bound(A, A+n, 3));		//an iterator on the first >=
	printf("Upper bound returned %d\n", *upper_bound(A, A+n, 3));		//an iterator on the first >
	auto itr = equal_range(A, A+n, 3);		//pair of iterators ~ lower&upper
	printf("The equal range returned %d\n", itr.second-itr.first);
	
	/****************************next_permutation & prev_permutation******************************/
	//given a lexicographically sorted range makes all the possible permutations
	
	string text = "Lol";
	sort(text.begin(), text.end());		//Ascendingly
	printf("Here is next permutation :D :\n");
	do{
		printf("%s\n", text.c_str());
	}while(next_permutation(text.begin(), text.end()));		//each call is in O(N/2)
	
	//Here the text is sorted again
	//you can try it with prev_permutation ;)
	return 0;
}
