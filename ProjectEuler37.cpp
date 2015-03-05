/* // --------- Project Euler Number 37
	//Truncatable Primes
	
	 Problem Statement
	
	The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.

Find the sum of the only eleven primes that are both truncatable from left to right and right to left.

NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.

*/
	
	/* Solution (no code): Based on what's given in the problem statement, we know that 3797, 37, and 797 are going to be truncatable, so we need to look for 8 more. Also, these numbers in general won't end in 5, since they'd then be divisible by multiples of 5, and hence not be prime. Each digit will need to be made up only of prime numbers. Looking at two digit numbers first, we can quickly see that that 23, 53, and 73 are also truncatable and prime from both sides as well, bring our total number of found primes to 7. In three digits, we can also readily see that 313, 317 and 373 are also both primes, bringing us to 9 truncatable primes. Then 3137 and 739397 can be made by considering the available prime digits and those we already found. */
	
	
37
3797
797

23
53
73

313
317
373

3137

739397
